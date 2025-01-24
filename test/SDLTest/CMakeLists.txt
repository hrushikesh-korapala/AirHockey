add_executable(SDLTest SDL_TEST.cpp)

target_include_directories(SDLTest PUBLIC 
                            ${SDL2_SOURCE_DIR}/include ${SDL2_BINARY_DIR}/include
                            ${SDL2_Image_SOURCE_DIR}/include ${SDL2_Image_BINARY_DIR}/include
                            ${SDL2_ttf_SOURCE_DIR} ${SDL2_ttf_BINARY_DIR}/include
                            ${SDL2_Mixer_SOURCE_DIR}/include ${SDL2_Mixer_BINARY_DIR}/include)

target_link_libraries(SDLTest PUBLIC SDL2 SDL2_image SDL2_ttf SDL2_mixer)