add_subdirectory(glfw-3.3.2)
include_directories(glfw-3.3.2/include)


add_library(glad STATIC glad/src/glad.c) 
include_directories(glad/include)

target_link_libraries(glad ${OPENGL_LIBRARY})
