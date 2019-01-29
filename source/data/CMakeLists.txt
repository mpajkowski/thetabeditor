project( thetadata )

set( files
    tunings.json
)

theta_copyfiles(
    NAME thetadata
    DESTINATION ${THETA_DATA_DIR}
    INSTALL ${THETA_DATA_INSTALL_DIR}
    FILES ${files}
)
