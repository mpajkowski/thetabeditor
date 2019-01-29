include( CMakeParseArguments )

function( theta_executable )
    cmake_parse_arguments( THETA_EXE
        "CONSOLE;INSTALL"
        "NAME;PCH"
        "SOURCES;HEADERS;RESOURCES;DEPENDS;PLUGINS;PCH_EXCLUDE"
        ${ARGN}
    )

    set( generated_files )
    if ( THETA_EXE_RESOURCES )
        qt5_add_resources( generated_files ${THETA_EXE_RESOURCES} )
    endif ()

    if ( THETA_EXE_CONSOLE )
        set( win32_flag )
    else ()
        set( win32_flag WIN32 )
    endif ()

    add_executable( ${THETA_EXE_NAME}
        ${win32_flag}
        ${THETA_EXE_SOURCES}
        ${THETA_EXE_HEADERS}
        ${generated_files}
    )

    theta_add_compile_flags( ${THETA_EXE_NAME} )

    target_link_libraries( ${THETA_EXE_NAME} ${THETA_EXE_DEPENDS} )

    # Set output directory for executables.
    set_target_properties( ${THETA_EXE_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${THETA_DEV_BIN_DIR}
        RUNTIME_OUTPUT_DIRECTORY_DEBUG ${THETA_DEV_BIN_DIR}
        RUNTIME_OUTPUT_DIRECTORY_RELEASE ${THETA_DEV_BIN_DIR}
    )
    
    # Set folder name for Visual Studio projects.
    set_target_properties( ${THETA_EXE_NAME} PROPERTIES
        FOLDER executables
    )

    # Add to the install step.
    if ( PLATFORM_WIN OR PLATFORM_OSX )
        set( install_dir . )
    else ()
        set( install_dir bin )
    endif ()

    if ( THETA_EXE_INSTALL )
        install(
            TARGETS ${THETA_EXE_NAME}
            DESTINATION ${install_dir}
        )
    endif ()

    # Copy dlls to the bin directory.
    if ( PLATFORM_WIN )
        theta_find_dlls( ${THETA_EXE_NAME} shared_libs )

        foreach ( lib ${shared_libs} )
            add_custom_command(
                TARGET ${THETA_EXE_NAME}
                POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different ${lib} ${THETA_DEV_BIN_DIR}
            )
        endforeach ()

        if ( THETA_EXE_INSTALL )
            install(
                FILES ${shared_libs}
                DESTINATION ${install_dir}
            )
        endif ()

        foreach ( plugin_target ${THETA_EXE_PLUGINS} )
            get_target_property( src_plugin_path ${plugin_target} IMPORTED_LOCATION_RELEASE )
            get_filename_component( src_plugin_dir ${src_plugin_path} DIRECTORY )
            get_filename_component( plugin_type ${src_plugin_dir} NAME )
            set( plugin_dir ${THETA_DEV_BIN_DIR}/${plugin_type} )
            
            add_custom_command(
                TARGET ${THETA_EXE_NAME}
                POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory ${plugin_dir}
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    $<TARGET_FILE:${plugin_target}>
                    ${plugin_dir}
            )
        endforeach ()
    endif ()
    
    # Set up precompiled header.
    if ( THETA_EXE_PCH )
        theta_precompiled_header(
            TARGET ${THETA_EXE_NAME}
            HEADER ${THETA_EXE_PCH}
            EXCLUDE_FILES ${THETA_EXE_PCH_EXCLUDE}
        )
    endif ()
endfunction ()

# Recursively find shared libraries that a target depends on.
function ( theta_find_dlls target output_list )
    if ( NOT TARGET ${target} )
        return ()
    endif ()

    get_target_property( child_targets ${target} INTERFACE_LINK_LIBRARIES )
    set( all_libs )
    if ( child_targets )
        foreach ( child_target ${child_targets} )
            theta_find_dlls( ${child_target} child_libs )
            list( APPEND all_libs ${child_libs} )
        endforeach ()
    endif ()

    get_target_property( target_type ${target} TYPE )
    if ( ${target_type} MATCHES SHARED_LIBRARY )
        list( APPEND all_libs "$<TARGET_FILE:${target}>" )
    endif ()

    if ( all_libs )
        list( REMOVE_DUPLICATES all_libs )
    endif ()
    set( ${output_list} ${all_libs} PARENT_SCOPE )
endfunction ()
