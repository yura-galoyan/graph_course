cmake_minimum_required(VERSION 3.0)

project(Graph)

# Find libraries



# Add source files
set(SOURCES 
    main.cpp
    Graph.cpp
    )


# Add executable
add_executable(graph ${SOURCES})

# Link SFML libraries
target_link_libraries(graph ${SFML})