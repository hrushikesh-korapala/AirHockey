add_executable(server_test server.cpp)

target_include_directories(server_test PRIVATE %{PROJECT_SOURCE_DIR}/include)

target_link_libraries(server_test PUBLIC udp_server)