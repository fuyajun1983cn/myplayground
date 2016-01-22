# try to find netlink.h

set(NL_INCLUDE_PATHS "/usr/local/include/libnl3" "/usr/include")

find_path(
	NL_INCLUDE_DIRS netlink/netlink.h
	PATHS ${NL_INCLUDE_PATHS}
)

set(NL_LIBRARY_PATHS "/usr/local/lib"  "/usr/lib/i386-linux-gnu/")
# try to find the libnl3 library
find_library(
	NL_LIBRARIES NAMES nl
	PATHS ${NL_LIBRARY_PATHS}
)
if(NOT NL_LIBRARIES)
	find_library(NL_LIBRARIES nl)
endif()

if(EXISTS ${NL_INCLUDE_DIRS})
	set(NL_FOUND true)
else()
	set(NL_FOUND false)
endif()

if(${NL_LIBRARIES} STREQUAL "NL_LIBRARIES-NOTFOUND")
  set(NL_FOUND false)
endif()
