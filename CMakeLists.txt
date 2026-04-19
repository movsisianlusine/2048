cmake_minimum_required(VERSION 3.16)

project(MyQtProject VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the Qt library
find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

# Add your source files here
add_executable(MyQtProject
    main.cpp
    game_field.h game_field.cpp game_field.ui
)

# Link the Qt Widgets library
target_link_libraries(MyQtProject PRIVATE Qt6::Widgets)
