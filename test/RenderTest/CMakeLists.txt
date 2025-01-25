add_executable(render_test render_test.cpp)

target_include_directories(render_test PUBLIC ${PROJECT_SOURCE_DIR}/include/
                            ${SDL2_SOURCE_DIR}/include ${SDL2_BINARY_DIR}/include
                            ${SDL2_Image_SOURCE_DIR}/include ${SDL2_Image_BINARY_DIR}/include
                            ${SDL2_ttf_SOURCE_DIR} ${SDL2_ttf_BINARY_DIR}/include
                            ${SDL2_Mixer_SOURCE_DIR}/include ${SDL2_Mixer_BINARY_DIR}/include)

target_link_libraries(render_test PUBLIC SDL2 SDL2_image SDL2_ttf SDL2_mixer basic_textures)