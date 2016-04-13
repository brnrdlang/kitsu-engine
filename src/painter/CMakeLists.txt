add_library(painter painter.cpp)
include_directories("${PROJECT_SOURCE_DIR}/external/SDL2-2.0.4/include/")
target_link_libraries(painter "${PROJECT_SOURCE_DIR}/external/SDL2-2.0.4/lib/x64/SDL2.lib")

install(TARGETS painter DESTINATION bin)
install(FILES painter.h DESTINATION include)
