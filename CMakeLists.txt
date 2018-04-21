cmake_minimum_required(VERSION 3.9)
project(01_C_Libraries_libft C)

set(CMAKE_C_STANDARD 99)


#########################################################
# I wrote this part to make Intellisense work properly. #
#       (CLion is a fully CMake dependant IDE).         #
#########################################################

# Bring the headers into the project
include_directories(inc)

# Bring the sources
file(GLOB SOURCES
        "src/basics/chars/*/*.c"
        "src/basics/maths/*.c"
        "src/basics/memory/*/*.c"
        "src/basics/numbers/*/*.c"
        "src/basics/numbers/output/*/*.c"
        "src/basics/strings/*/*.c"
        "src/containers/*/*.c"
        "src/utils/*/*.c"
        "inc/libft/basics/*.h"
        "inc/libft/containers/*.h"
        "inc/libft/utils/*.h")

# Generate the static library from the sources
add_library(01_C_Libraries_libft STATIC ${SOURCES})


# I run my make commands with the plugin
# https://victor.kropp.name/projects/makefile/