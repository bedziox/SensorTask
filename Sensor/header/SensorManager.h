#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

#include <vector>
#include <iostream>
#include <fstream>
#include "Sensor.h"
#include "SensorBuilder.h"
#include <filesystem>
#include "json.hpp"
#include <thread>
#define CONFIG_FILE "D:\\Dev\\SensorTask\\sensorConfig.json"

using json = nlohmann::json;

class SensorManager {
public:
	std::vector<std::shared_ptr<Sensor>> Sensors;
	SensorManager();
	std::vector<std::shared_ptr<Sensor>> parseSensors(json data);
	void generateResults();

private:
	SensorBuilder _sensorBuilder;
	json _sensorFile;
};

#endif