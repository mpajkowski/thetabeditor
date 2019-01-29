project( thetawidgets )

set( srcs
    clickablelabel.cpp
    common.cpp
    mixer/mixer.cpp
    mixer/mixeritem.cpp
    playback/playbackwidget.cpp
)

set( headers
    clickablelabel.h
    mixer/mixer.h
    mixer/mixeritem.h
    playback/playbackwidget.h
)

set( moc_headers
    clickablelabel.h
    playback/playbackwidget.h
)

set( forms
    mixer/mixeritem.ui
    playback/playbackwidget.ui
)

theta_library(
    NAME thetawidgets
    SOURCES ${srcs}
    HEADERS ${headers}
    MOC_HEADERS ${moc_headers}
    FORMS ${forms}
    DEPENDS
        thetascore
        Qt5::Widgets
)
