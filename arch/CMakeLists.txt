link_directories(${GTKMM_LIBRARY_DIRS})

include_directories(
    ${GTKMM_INCLUDE_DIRS}
    ..
    )

file(GLOB_RECURSE PROJ_FILES
    *.cpp
    *.h
    *.hpp
)

add_library( arch STATIC ${PROJ_FILES} )
