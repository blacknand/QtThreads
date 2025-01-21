cmake_minimum_required(VERSION 3.16)

project(satellit_sim VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "/Users/nathanblackburn/Qt/6.8.1/macos")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets SerialPort Core)
qt_standard_project_setup()     # Will still link against Qt6::Core and Qt6::Gui since Widgets depends on them

qt_add_executable(threads
    main.cpp
    mainwindow.cpp
    threads.cpp
)

target_include_directories(threads 
                            PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
                            )

target_link_libraries(threads 
                        PRIVATE Qt6::Widgets 
                        Qt6::SerialPort 
                        Qt6::Core 
                        )

set_target_properties(threads PROPERTIES
    MACOSX_BUNDLE ON 
)   