add_library(basic_textures login.cpp)

target_include_directories(basic_textures PUBLIC ${PROJECT_SOURCE_DIR}/include/Textures/
                            ${SDL2_SOURCE_DIR}/include ${SDL2_BINARY_DIR}/include
                            ${SDL2_Image_SOURCE_DIR}/include ${SDL2_Image_BINARY_DIR}/include
                            ${SDL2_ttf_SOURCE_DIR} ${SDL2_ttf_BINARY_DIR}/include
                            ${SDL2_Mixer_SOURCE_DIR}/include ${SDL2_Mixer_BINARY_DIR}/include)

target_compile_definitions(basic_textures PUBLIC TEXTURE_PATH="${PROJECT_SOURCE_DIR}/internal/res/")

target_link_libraries(basic_textures PUBLIC SDL2 SDL2_image SDL2_ttf SDL2_mixer)