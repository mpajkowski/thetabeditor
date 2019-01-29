project ( thetamidi )

set( srcs
    midievent.cpp
    midieventlist.cpp
    midifile.cpp
    repeatcontroller.cpp
)

set( headers
    midievent.h
    midieventlist.h
    midifile.h
    repeatcontroller.h
)

theta_library(
    NAME thetamidi
    SOURCES ${srcs}
    HEADERS ${headers}
    DEPENDS
        thetascore
)
