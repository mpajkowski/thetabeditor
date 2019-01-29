project( thetabeditor )

set( srcs
    main.cpp
)

set( resources
    resources.qrc
)

set( rc_file )
if ( PLATFORM_WIN )
    set( rc_file build.rc )
endif ()

theta_executable(
    NAME thetabeditor
    INSTALL
    SOURCES ${srcs} ${rc_file}
    RESOURCES ${resources}
    DEPENDS
        boost_program_options
        thetaapp
        thetadialogs
        Qt5::Network
        Qt5::Widgets
        withershins
    PLUGINS
        ${QT5_PLUGINS}
)
