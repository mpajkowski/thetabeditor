project( thetaapp )

set( _version ${THETA_VERSION} )

# Get a version number for development builds.
include( FindGit )
if ( GIT_FOUND )
    execute_process(
        COMMAND ${GIT_EXECUTABLE} describe --tags --long --always
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
        OUTPUT_VARIABLE git_revision
        ERROR_VARIABLE error_var
        RESULT_VARIABLE result_var
    )

    if ( result_var EQUAL 0 )
        string( STRIP "${git_revision}" git_revision )
        set( _version ${git_revision} )
    endif ()
endif ()

message( STATUS "Version number: ${_version}" )
add_definitions( -DVERSION=${_version} )

set( srcs
    appinfo.cpp
    caret.cpp
    clipboard.cpp
    command.cpp
    documentmanager.cpp
    paths.cpp
    thetabeditor.cpp
    recentfiles.cpp
    scorearea.cpp
    settings.cpp
    settingsmanager.cpp
    tuningdictionary.cpp
    viewoptions.cpp
)

set( headers
    appinfo.h
    caret.h
    clipboard.h
    command.h
    documentmanager.h
    paths.h
    thetabeditor.h
    recentfiles.h
    scorearea.h
    settings.h
    settingsmanager.h
    tuningdictionary.h
    viewoptions.h

    pubsub/playerpubsub.h
    pubsub/pubsub.h
    pubsub/clickpubsub.h
)


set( moc_headers
    command.h
    thetabeditor.h
    recentfiles.h
)

theta_library(
    NAME thetaapp
    SOURCES ${srcs}
    HEADERS ${headers}
    MOC_HEADERS ${moc_headers}
    DEPENDS
        thetaactions
        thetaaudio
        thetadialogs
        thetaformats
        thetapainters
        thetawidgets
        thetautil
        boost_filesystem
        Qt5::Widgets
        Qt5::PrintSupport
)
