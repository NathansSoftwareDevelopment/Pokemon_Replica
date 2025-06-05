cmake_minimum_required(VERSION 4.0.2)
project(PokemonReplica)

set(CMAKE_CXX_STANDARD 20)

# Specifically exclude the CMake compiler identification file
list(FILTER SOURCES EXCLUDE REGEX "CMakeFiles/[0-9]+\\.[0-9]+\\.[0-9]+/CompilerIdCXX/CMakeCXXCompilerId\\.cpp$")

set(MOVE_JSON "${CMAKE_CURRENT_SOURCE_DIR}/Move/Move.json")
set(SPECIES_JSON "${CMAKE_CURRENT_SOURCE_DIR}/Species/Species.json")

configure_file(
    "${MOVE_JSON}"
    "${CMAKE_CURRENT_BINARY_DIR}/Move.json"
    COPYONLY
)

configure_file(
    "${SPECIES_JSON}"
    "${CMAKE_CURRENT_BINARY_DIR}/Species.json"
    COPYONLY
)

include_directories(.
    "./Pokemon_Class"
    "./Nature"
    "./Move"
    "./Type"
    "./Species"
    "./Display"
    "./Battle"
    "./Utils"
    "./Growth_Rate"
    "./Trainer"
    "./Trainer/Player"
)

set(SOURCES
    "./main.cpp"
    "./Pokemon_Class/Pokemon_Class.cpp"
    "./Nature/Nature.cpp"
    "./Move/Move.cpp"
    "./Type/Type.cpp"
    "./Species/Species.cpp"
    "./Display/Display.cpp"
    "./Battle/Battle.cpp"
    "./Growth_Rate/Growth_Rate.cpp"
    "./Trainer/Trainer.cpp"
    "./Trainer/Player/Player.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCES})

add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        "${MOVE_JSON}"
        "${CMAKE_CURRENT_BINARY_DIR}/Move.json"
    COMMAND ${CMAKE_COMMAND} -E copy
        "${SPECIES_JSON}"
        "${CMAKE_CURRENT_BINARY_DIR}/Species.json"
    COMMENT "Copying JSON data files to build directory"
)