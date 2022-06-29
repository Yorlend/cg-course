link_directories(${GTKMM_LIBRARY_DIRS})

include_directories(${GTKMM_INCLUDE_DIRS})

file(GLOB_RECURSE PROJ_FILES
    *.cpp
    *.h
    *.hpp
)

add_executable(${PROJECT_NAME} ${PROJ_FILES})

target_link_libraries(${PROJECT_NAME} ${GTKMM_LIBRARIES})
