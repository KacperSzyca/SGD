cmake_minimum_required(VERSION 3.17)
project(sdgProject)

set(CMAKE_CXX_STANDARD 14)

set(SDL2_INCLUDE_DIR /cygdrive/c/Users/user/Desktop/Studia/6/sgd/projekt/SDL2/include)
set(SDL2_LIB_DIR /cygdrive/c/Users/user/Desktop/Studia/6/sgd/projekt/SDL2/lib/x64)
set(SDL2_image_INCLUDE_DIR /cygdrive/c/Users/user/Desktop/Studia/6/sgd/projekt/SDL2_image/include)
set(SDL2_image_LIB_DIR /cygdrive/c/Users/user/Desktop/Studia/6/sgd/projekt/SDL2_image/lib/x64)
set(SDL2_ttf_INCLUDE_DIR /cygdrive/c/Users/user/Desktop/Studia/6/sgd/projekt/SDL2_ttf/include)
set(SDL2_ttf_LIB_DIR /cygdrive/c/Users/user/Desktop/Studia/6/sgd/projekt/SDL2_ttf/lib/x64)

include_directories(${SDL2_INCLUDE_DIR}; ${SDL2_image_INCLUDE_DIR}; ${SDL2_ttf_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR}; ${SDL2_image_LIB_DIR}; ${SDL2_ttf_LIB_DIR})


add_executable(sdgProject main.cpp Zasoby.cpp SWIAT.cpp Aktor.cpp Gracz.cpp Gracz2.cpp)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2 SDL2_image SDL2_ttf)



