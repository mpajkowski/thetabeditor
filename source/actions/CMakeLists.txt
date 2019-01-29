project( thetaactions )

set( srcs
    addalternateending.cpp
    addbarline.cpp
    addchordtext.cpp
    adddirection.cpp
    adddynamic.cpp
    addirregulargrouping.cpp
    addmultibarrest.cpp
    addnote.cpp
    addnoteproperty.cpp
    addplayer.cpp
    addplayerchange.cpp
    addpositionproperty.cpp
    addrehearsalsign.cpp
    addrest.cpp
    addstaff.cpp
    addsystem.cpp
    addtempomarker.cpp
    addtextitem.cpp
    adjustlinespacing.cpp
    editbarline.cpp
    editfileinformation.cpp
    editkeysignature.cpp
    editnoteduration.cpp
    editplayer.cpp
    editstaff.cpp
    edittabnumber.cpp
    edittimesignature.cpp
    editviewfilters.cpp
    insertnotes.cpp
    polishscore.cpp
    polishsystem.cpp
    removealternateending.cpp
    removebarline.cpp
    removechordtext.cpp
    removedirection.cpp
    removedynamic.cpp
    removeirregulargrouping.cpp
    removenote.cpp
    removenoteproperty.cpp
    removeplayer.cpp
    removeplayerchange.cpp
    removeposition.cpp
    removepositionproperty.cpp
    removerehearsalsign.cpp
    removestaff.cpp
    removesystem.cpp
    removetempomarker.cpp
    removetextitem.cpp
    shiftpositions.cpp
    undomanager.cpp
)

set( headers
    addalternateending.h
    addbarline.h
    addchordtext.h
    adddirection.h
    adddynamic.h
    addirregulargrouping.h
    addmultibarrest.h
    addnote.h
    addnoteproperty.h
    addplayer.h
    addplayerchange.h
    addpositionproperty.h
    addrehearsalsign.h
    addrest.h
    addspecialnoteproperty.h
    addstaff.h
    addsystem.h
    addtempomarker.h
    addtextitem.h
    adjustlinespacing.h
    editbarline.h
    editfileinformation.h
    editkeysignature.h
    editnoteduration.h
    editplayer.h
    editstaff.h
    edittabnumber.h
    edittimesignature.h
    editviewfilters.h
    insertnotes.h
    polishscore.h
    polishsystem.h
    removealternateending.h
    removebarline.h
    removechordtext.h
    removedirection.h
    removedynamic.h
    removeirregulargrouping.h
    removenote.h
    removenoteproperty.h
    removeplayer.h
    removeplayerchange.h
    removeposition.h
    removepositionproperty.h
    removerehearsalsign.h
    removespecialnoteproperty.h
    removestaff.h
    removesystem.h
    removetempomarker.h
    removetextitem.h
    shiftpositions.h
    undomanager.h
)

set( moc_headers
    undomanager.h
)

theta_library(
    NAME thetaactions
    SOURCES ${srcs}
    HEADERS ${headers}
    MOC_HEADERS ${moc_headers}
    DEPENDS
        thetascore
        Qt5::Widgets
)
