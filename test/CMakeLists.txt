add_executable(SDLTest SDL_TEST.cpp)

target_link_directories(SDLTest PUBLIC ${SDL2_SOURCE_DIR}/include ${SDL2_BINARY_DIR}/include)

target_link_libraries(SDLTest PUBLIC SDL2::SDL2)

add_subdirectory(client)
add_subdirectory(server)