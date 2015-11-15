# try to find netlink.h

set(NL3_INCLUDE_PATHS "/usr/local/include/libnl3")

find_path(
	NL3_INCLUDE_DIRS netlink/netlink.h
	PATHS ${NL3_INCLUDE_PATHS}
	NO_DEFAULT_PATH
)
if(NOT EXISTS ${NL3_INCLUDE_DIRS})
	find_path(NL3_INCLUDE_DIRS netlink/netlink.h)
endif()


set(NL3_LIBRARY_PATHS "/usr/local/lib")
# try to find the libnl3 library
find_library(
	NL3_LIBRARIES NAMES nl-3
	PATHS ${NL3_LIBRARY_PATHS}
	NO_DEFAULT_PATH
)
message(STATUS "${NL3_LIBRARIES}")
if(NOT NL3_LIBRARIES)
	find_library(NL3_LIBRARIES libnl-3)
endif()

if(EXISTS ${NL3_INCLUDE_DIRS})
	set(NL3_FOUND true)
else()
	set(NL3_FOUND false)
endif()

if(${NL3_LIBRARIES} STREQUAL "NL3_LIBRARIES-NOTFOUND")
  set(NL3_FOUND false)
endif()
