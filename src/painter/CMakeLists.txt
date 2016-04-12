add_library(painter painter.cpp)

install(TARGETS painter DESTINATION bin)
install(FILES painter.h DESTINATION include)
