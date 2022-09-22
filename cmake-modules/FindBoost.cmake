

# Usage:
# FIND_PACKAGE(raylib REQUIRED)
# [...]
# TARGET_LINK_LIBRARIES(target_name raylib)

find_package(Boost 1.71.0 REQUIRED system) # QUIET or REQUIRED
if (NOT Boost_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)
  FetchContent_Declare(
    Boost
    URL https://github.com/alisw/boost/archive/refs/tags/v1.74.0.tar.gz
  )
  FetchContent_GetProperties(Boost)
  if (NOT Boost_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(Boost)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    add_subdirectory(${Boost_SOURCE_DIR} ${Boost_BINARY_DIR})
  endif()
endif()
