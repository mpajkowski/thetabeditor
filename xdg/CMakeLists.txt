project( xdg )

install(
    FILES powertabeditor.desktop
    DESTINATION ${THETA_XDG_APPS_INSTALL_DIR}
)

install(
    FILES mimeinfo.xml
    RENAME powertabeditor.xml
    DESTINATION ${THETA_XDG_MIME_INSTALL_DIR}
)

install(
    FILES ../source/icons/app_icon.png
    RENAME powertabeditor.png
    DESTINATION ${THETA_XDG_ICONS_INSTALL_DIR}/128x128/apps
)
