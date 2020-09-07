cmake_minimum_required(VERSION 3.14.0)
project(espiri-engine VERSION 0.1.0)

add_executable(espiri-engine 
	exe-cpp/main.cpp
	exe-cpp/context.cpp
	exe-cpp/Window.cpp

)

add_subdirectory(external)
include_directories(
	external/glad/include 
	external/glm-0.9.9.8
	header
)

find_package(OpenGL REQUIRED)

target_link_libraries(espiri-engine ${OPENGL_LIBRARY} glfw glad)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
