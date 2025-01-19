add_library(udp_client udp_client.cpp)

target_include_directories(udp_client PRIVATE ${PROJECT_SOURCE_DIR}/include/)

target_link_libraries(udp_client PUBLIC)