project( thetascore_proto )

set( srcs
  gen/track.pb.cc
  gen/tuning.pb.cc
)

theta_library(
    NAME thetascore_proto
    SOURCES ${srcs}
    HEADERS ${headers}
    PCH precompiled.h
)
