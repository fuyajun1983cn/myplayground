# try to find netlink.h

set(NL_INCLUDE_PATHS "/usr/include/libnl3" "/usr/include")

find_path(
	NL_INCLUDE_DIRS netlink/netlink.h
	PATHS ${NL_INCLUDE_PATHS}
)

set(NL_LIBRARY_PATHS "/usr/lib"  "/usr/lib/i386-linux-gnu/")
# try to find the libnl3 library
find_library(
	NL_CORE_LIBRARIES NAMES nl-3 
	PATHS ${NL_LIBRARY_PATHS}
        )
      find_library(
        NL_GENL_LIBRARIES NAMES nl-genl-3
        PATH ${NL_LIBRARY_PATHS}
  )

if(EXISTS ${NL_INCLUDE_DIRS})
	set(NL_FOUND true)
else()
	set(NL_FOUND false)
endif()

if(${NL_CORE_LIBRARIES} STREQUAL "NL_CORE_LIBRARIES-NOTFOUND")
  set(NL_FOUND false)
endif()

if (${NL_GENL_LIBRARIES} STREQUAL "NL_GENL_LIBRARIES-NOTFOUND")
  set(NL_FOUND false)
endif()



