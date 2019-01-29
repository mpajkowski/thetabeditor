set( THETA_EXTERNAL_DIR ${CMAKE_SOURCE_DIR}/external )

set( THETA_DEV_BIN_DIR ${CMAKE_BINARY_DIR}/bin )
set( THETA_DATA_DIR ${THETA_DEV_BIN_DIR}/data )

if ( PLATFORM_LINUX )
    set( THETA_DATA_INSTALL_DIR share/powertab/powertabeditor )
else ()
    set( THETA_DATA_INSTALL_DIR data )
endif ()

set( THETA_XDG_APPS_INSTALL_DIR share/applications )
set( THETA_XDG_ICONS_INSTALL_DIR share/icons/hicolor )
set( THETA_XDG_MIME_INSTALL_DIR share/mime/packages )
