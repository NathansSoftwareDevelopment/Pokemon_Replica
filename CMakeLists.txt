cmake_minimum_required(VERSION 4.0.2)
project(PokemonReplica)

set(CMAKE_CXX_STANDARD 20)

set(JSON_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

file(GLOB_RECURSE SOURCES
    "*.cpp"
    "!build/**"
)

file(GLOB JSON_FILES "${JSON_SOURCE_DIR}/*.json")

foreach(json_file ${JSON_FILES})
    get_filename_component(filename "${json_file}" NAME)
    configure_file(
        "${json_file}"
        "${CMAKE_CURRENT_BINARY_DIR}/${filename}"
        COPYONLY
    )
endforeach()

# Specifically exclude the CMake compiler identification file
list(FILTER SOURCES EXCLUDE REGEX "CMakeFiles/[0-9]+\\.[0-9]+\\.[0-9]+/CompilerIdCXX/CMakeCXXCompilerId\\.cpp$")

include_directories(.)

add_executable(${PROJECT_NAME} ${SOURCES})