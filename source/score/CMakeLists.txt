project( thetascore )

set( srcs
    alternateending.cpp
    barline.cpp
    chordname.cpp
    chordtext.cpp
    direction.cpp
    dynamic.cpp
    generalmidi.cpp
    irregulargrouping.cpp
    keysignature.cpp
    note.cpp
    player.cpp
    playerchange.cpp
    position.cpp
    rehearsalsign.cpp
    score.cpp
    scoreinfo.cpp
    scorelocation.cpp
    serialization.cpp
    staff.cpp
    system.cpp
    systemlocation.cpp
    tempomarker.cpp
    textitem.cpp
    timesignature.cpp
    tuning.cpp
    viewfilter.cpp
    voice.cpp
    voiceutils.cpp

    utils/directionindex.cpp
    utils/repeatindexer.cpp
    utils/scoremerger.cpp
    utils/scorepolisher.cpp
)

set( headers
    alternateending.h
    barline.h
    chordname.h
    chordtext.h
    direction.h
    dynamic.h
    fileversion.h
    generalmidi.h
    irregulargrouping.h
    keysignature.h
    note.h
    player.h
    playerchange.h
    position.h
    rehearsalsign.h
    score.h
    scoreinfo.h
    scorelocation.h
    serialization.h
    staff.h
    system.h
    systemlocation.h
    tempomarker.h
    textitem.h
    timesignature.h
    tuning.h
    utils.h
    viewfilter.h
    voice.h
    voiceutils.h

    utils/directionindex.h
    utils/repeatindexer.h
    utils/scoremerger.h
    utils/scorepolisher.h
)

theta_library(
    NAME thetascore
    SOURCES ${srcs}
    HEADERS ${headers}
    PCH precompiled.h
    DEPENDS
        boost
        boost_date_time
        boost_regex
        thetautil
        rapidjson
)
