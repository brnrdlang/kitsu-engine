add_library(painter
    painter.cpp
    SceneTree.cpp)

if(WIN32)
    include_directories("${PROJECT_SOURCE_DIR}/external/SDL2-2.0.4/include/")
    target_link_libraries(painter "${PROJECT_SOURCE_DIR}/external/SDL2-2.0.4/lib/x64/SDL2.lib")
else()
    target_link_libraries(painter SDL2)
endif()
install(TARGETS painter DESTINATION bin)
install(FILES painter.h DESTINATION include)
