find_path(INTL_INCLUDE_DIRS libintl.h)
find_library(INTL_LIBRARIES intl)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Intl DEFAULT_MSG INTL_LIBRARIES INTL_INCLUDE_DIRS)
