cmake_minimum_required(VERSION 3.10)
project(engine)

# Find SDL2 library
find_package(SDL2 REQUIRED)

# Find GLM library
find_package(glm CONFIG REQUIRED)

# Add source files
set(ENGINE_SRC
    src/Engine.cpp
    src/Engine.h
)

# Create static library
add_library(${PROJECT_NAME} STATIC ${ENGINE_SRC})

# Specify include directories for the Engine target
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Link SDL2 & glm to the Engine library
target_link_libraries(${PROJECT_NAME} SDL2::SDL2main SDL2::SDL2 glm::glm)

# Specify the source directory containing header files
set(HEADER_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Specify the destination include directory
set(HEADER_DEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Get all header files in the src directory (you can adjust the pattern if needed)
file(GLOB_RECURSE HEADERS_TO_COPY ${HEADER_SRC_DIR}/*.h)

# Copy all headers to the include directory
foreach(HEADER ${HEADERS_TO_COPY})
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${HEADER}
        ${HEADER_DEST_DIR}
    )
endforeach()

# Create the include directory if it doesn't exist
add_custom_command(
    TARGET ${PROJECT_NAME} PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${HEADER_DEST_DIR}
)
