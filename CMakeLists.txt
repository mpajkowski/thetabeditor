cmake_minimum_required( VERSION 3.1 )

# Target OS X 10.9 and above. This must be set before the first project() call.
set( CMAKE_OSX_DEPLOYMENT_TARGET "10.9"
     CACHE STRING "Minimum OS X deployment version"
)

project( powertabeditor )

set( CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()

set( CMAKE_MODULE_PATH
    ${CMAKE_SOURCE_DIR}/cmake
    ${CMAKE_SOURCE_DIR}/cmake/third_party/modules
)

set( THETA_VERSION 0.0.1-alpha )

include( THETA_Platform )
include( THETA_CompilerFlags )
include( THETA_Paths )
include( THETA_ThirdParty )
include( THETA_CopyFiles )
include( THETA_PrecompiledHeader )
include( THETA_Executable )
include( THETA_Library )

add_subdirectory( source )
add_subdirectory( test )
if ( PLATFORM_LINUX )
    add_subdirectory(xdg)
endif ()
