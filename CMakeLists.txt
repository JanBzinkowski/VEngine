cmake_minimum_required(VERSION 3.20)
project(VEngine LANGUAGES CXX)

file(GLOB_RECURSE VENGINE_LIBRARY_SOURCES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Engine/*.cpp"
)

file(GLOB_RECURSE VENGINE_PUBLIC_HEADERS CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp"
)

add_library(VEngineLib STATIC
        ${VENGINE_LIBRARY_SOURCES}
        ${VENGINE_PUBLIC_HEADERS}
)
add_library(VEngine::VEngine ALIAS VEngineLib)

target_compile_features(VEngineLib PUBLIC cxx_std_23)
set_target_properties(VEngineLib PROPERTIES CXX_EXTENSIONS OFF)

target_include_directories(VEngineLib
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

add_executable(VEngine "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")
target_link_libraries(VEngine PRIVATE VEngine::VEngine)
set_target_properties(VEngine PROPERTIES CXX_EXTENSIONS OFF)
