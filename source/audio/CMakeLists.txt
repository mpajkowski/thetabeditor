project( thetaaudio )

set( srcs
    midioutputdevice.cpp
    midiplayer.cpp
    settings.cpp
)

set( headers
    midioutputdevice.h
    midiplayer.h
    settings.h
)

set( moc_headers
    midiplayer.h
)

theta_library(
    NAME thetaaudio
    SOURCES ${srcs}
    HEADERS ${headers}
    MOC_HEADERS ${moc_headers}
    DEPENDS
        thetascore
        thetascore_proto
        Qt5::Core
        rtmidi
)
