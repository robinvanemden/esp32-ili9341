file(GLOB_RECURSE SOURCES "./src/*.c" "./src/*.cpp")

idf_component_register(
    SRCS
        ${SOURCES}
    INCLUDE_DIRS 
        "./src" 
)