include( CMakeParseArguments )

function ( theta_copyfiles )
    cmake_parse_arguments( THETA_DATA "" "NAME;DESTINATION;INSTALL" "FILES" ${ARGN} )

    set( dest_dir ${THETA_DATA_DESTINATION} )

    set( output_files )
    foreach( src_file ${THETA_DATA_FILES} )
        get_filename_component( filename ${src_file} NAME )
        set( output_file ${dest_dir}/${filename} )
        list( APPEND output_files ${output_file} )

        add_custom_command(
            OUTPUT ${output_file}
            DEPENDS ${src_file}
            COMMAND ${CMAKE_COMMAND} -E make_directory ${dest_dir}
            COMMAND ${CMAKE_COMMAND} -E copy ${src_file} ${dest_dir}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        )
    endforeach ()

    add_custom_target(
        ${THETA_DATA_NAME} ALL
        DEPENDS ${output_files}
    )

    set_target_properties( ${THETA_DATA_NAME} PROPERTIES
        FOLDER data
    )

    if ( THETA_DATA_INSTALL )
        install(
            FILES ${THETA_DATA_FILES}
            DESTINATION ${THETA_DATA_INSTALL}
        )
    endif ()
endfunction ()
