project ( thetaformats )

set( srcs
    fileformat.cpp
    fileformatmanager.cpp

    gpx/bitstream.cpp
    gpx/documentreader.cpp
    gpx/filesystem.cpp
    gpx/gpximporter.cpp
    gpx/util.cpp

    guitar_pro/document.cpp
    guitar_pro/guitarproimporter.cpp
    guitar_pro/inputstream.cpp

    midi/midiexporter.cpp

    powertab/powertabexporter.cpp
    powertab/powertabimporter.cpp
)

set( headers
    fileformat.h
    fileformatmanager.h

    gpx/bitstream.h
    gpx/documentreader.h
    gpx/filesystem.h
    gpx/gpximporter.h
    gpx/util.h

    guitar_pro/document.h
    guitar_pro/guitarproimporter.h
    guitar_pro/inputstream.h

    midi/midiexporter.h

    powertab/common.h
    powertab/powertabexporter.h
    powertab/powertabimporter.h
)

if ( PLATFORM_WIN )
    set( platform_depends boost_zlib Ws2_32 )
else ()
    set( platform_depends )
endif ()

theta_library(
    NAME thetaformats
    SOURCES ${srcs}
    HEADERS ${headers}
    DEPENDS
        boost_date_time
        boost_iostreams
        ${platform_depends}
        thetamidi
        thetascore
        thetautil
        pugixml
)
