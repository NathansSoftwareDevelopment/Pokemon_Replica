cmake_minimum_required(VERSION 4.0.2)
project(PokemonReplica)

set(CMAKE_CXX_STANDARD 20)

# Find all YOUR source files recursively
file(GLOB_RECURSE SOURCES
    "*.cpp"
    "Pokemon_Species/**/*.cpp"
    "!build/**"
)

# Specifically exclude the CMake compiler identification file
list(FILTER SOURCES EXCLUDE REGEX "CMakeFiles/[0-9]+\\.[0-9]+\\.[0-9]+/CompilerIdCXX/CMakeCXXCompilerId\\.cpp$")

include_directories(.)
include_directories(Pokemon_Species/**)

add_executable(${PROJECT_NAME} ${SOURCES})