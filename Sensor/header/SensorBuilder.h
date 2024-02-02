#ifndef SENSOR_BUILDER_H
#define SENSOR_BUILDER_H

#include <iostream>
#include "json.hpp"
#include "Sensor.h"

class SensorBuilder {
public:
	Sensor buildSensor(nlohmann::json data);
	static SensorBuilder& getInstance() {
		static SensorBuilder instance;
		return instance;
	}
};
#endif


