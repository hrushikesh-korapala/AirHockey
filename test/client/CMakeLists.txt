add_executable(client_test client.cpp)

target_include_directories(client_test PRIVATE %{PROJECT_SOURCE_DIR}/include)

target_link_libraries(client_test PUBLIC udp_client)