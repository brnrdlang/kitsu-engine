add_library(painter
    painter.cpp
    Shapes.cpp)

find_package(GLEW REQUIRED)
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(${GLEW_INCLUDE_DIRS})
include_directories(${SDL2_INCLUDE_DIR})
include_directories(${OPENGL_INCLUDE_DIR})

target_link_libraries(painter ${SDL2_LIBRARY})
target_link_libraries(painter ${OPENGL_LIBRARIES})
target_link_libraries(painter ${GLEW_LIBRARIES})

install(TARGETS painter DESTINATION bin)
install(FILES painter.h DESTINATION include)
