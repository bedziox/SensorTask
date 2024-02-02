add_library(SENSOR_SRC
    Sensor.cpp
    SensorBuilder.cpp
    SensorManager.cpp
    Util.cpp)

target_include_directories(SENSOR_SRC PRIVATE "${PROJECT_SOURCE_DIR}/Sensor/header" "${PROJECT_SOURCE_DIR}/External/json")