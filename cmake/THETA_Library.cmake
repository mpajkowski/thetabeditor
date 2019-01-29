include( CMakeParseArguments )

function( theta_library )
    cmake_parse_arguments( THETA_LIB ""
        "NAME;PCH"
        "SOURCES;HEADERS;MOC_HEADERS;FORMS;DEPENDS;PCH_EXCLUDE"
        ${ARGN}
    )

    set( generated_headers )
    set( moc_files )
    if ( THETA_LIB_FORMS )
        qt5_wrap_ui( generated_headers ${THETA_LIB_FORMS} )
    endif ()
    if ( THETA_LIB_MOC_HEADERS )
        qt5_wrap_cpp( moc_files ${THETA_LIB_MOC_HEADERS} )
    endif ()

    add_library( ${THETA_LIB_NAME} STATIC
        ${THETA_LIB_SOURCES}
        ${THETA_LIB_HEADERS}
        ${generated_headers}
        ${moc_files}
    )

    theta_add_compile_flags( ${THETA_LIB_NAME} )

    target_include_directories( ${THETA_LIB_NAME}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}
    )

    target_link_libraries( ${THETA_LIB_NAME} ${THETA_LIB_DEPENDS} )

    # Set folder name for Visual Studio projects.
    set_target_properties( ${THETA_LIB_NAME} PROPERTIES
        FOLDER libraries
    )
    
    # Set up precompiled header.
    if ( THETA_LIB_PCH )
        theta_precompiled_header(
            TARGET ${THETA_LIB_NAME}
            HEADER ${THETA_LIB_PCH}
            EXCLUDE_FILES ${THETA_LIB_PCH_EXCLUDE}
        )
    endif ()
endfunction ()
