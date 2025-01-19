add_library(udp_server udp_server.cpp)

target_include_directories(udp_server PRIVATE ${PROJECT_SOURCE_DIR}/include/)

target_link_libraries(udp_server PUBLIC)