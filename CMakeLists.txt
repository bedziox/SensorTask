cmake_minimum_required(VERSION 3.5)

project(Task)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} Main.cpp)

add_subdirectory(Sensor)

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/Sensor/header ${PROJECT_SOURCE_DIR}/External/json)

target_link_libraries(${PROJECT_NAME} PRIVATE
    SENSOR_SRC
)