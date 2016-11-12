# Mash3_Template
Template for 3rd task on computer graphics

__Place your source files in "source" directory and headers in "include"__

## Usage:

1) Install appropriate libraries:

> sudo apt-get install freeglut3-dev libglew-dev libglu1-mesa-dev

3) Clone this repository with:

> git clone https://github.com/BorisLestsov/Mash3_Template.git

4) To compile everything run in the project directory:

> make

__To run the project, go to bin and run:__

> ./mash3 

## Possible errors:

If you get error:
```
Shader: 0:1(10): error: GLSL 3.30 is not supported. Supported versions are: 1.10, 1.20, 1.30, 1.00 ES, and 3.00 ES

COMPILATION ERROR | Line: 22 File: shaders/grass.vert
```
Then you sould add this line to the end of ".bashrc" file in your home directory:
```
export MESA_GL_VERSION_OVERRIDE="3.3COMPAT"
```

If you your system does not support GLSL 3.10 - replace "shaders" directory and "main.cpp" with the ones from downgrade.
