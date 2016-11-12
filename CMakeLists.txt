cmake_minimum_required(VERSION 2.8)
project(cmake_project)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(SOIL/src)
include_directories(Utility/include)
include_directories(Utility/include/GL)
include_directories(Utility/include/VM)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED) 
find_package(GLEW REQUIRED) 
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})

set(EXECUTABLE_OUTPUT_PATH bin)

add_library(SOIL STATIC SOIL/src/
	SOIL/src/image_DXT.c     
	SOIL/src/image_helper.h  
	SOIL/src/SOIL.h            
	SOIL/src/stb_image_aug.c
	SOIL/src/image_DXT.h     
	SOIL/src/stbi_DDS_aug_c.h  
	SOIL/src/stb_image_aug.h
	SOIL/src/image_helper.c  
	SOIL/src/SOIL.c         
	SOIL/src/stbi_DDS_aug.h 
	SOIL/src/original/stb_image-1.09.c  
	SOIL/src/original/stb_image-1.16.c
)

add_executable(cmake_project
  Utility/src/Camera.cpp
  Utility/src/GL.cpp
  Utility/src/Overall.cpp
  Utility/src/ShaderProgram.cpp
  Utility/src/Texture.cpp
  Utility/src/mat4.cpp
  Utility/src/uvec3.cpp
  Utility/src/vec2.cpp
  Utility/src/vec3.cpp
  Utility/src/vec4.cpp
  source/main.cpp
)

add_custom_target(make COMMAND $(MAKE) -C ${cmake_project_SOURCE_DIR}
        CLION_EXE_DIR=${PROJECT_BINARY_DIR})

set_target_properties(cmake_project PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG   ${CMAKE_SOURCE_DIR}/bin
        RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/bin
        )

target_link_libraries(
    cmake_project
    ${GLUT_LIBRARY}
    ${OPENGL_LIBRARIES} 
    ${GLEW_LIBRARY}
    SOIL
    )