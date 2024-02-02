#include "SensorBuilder.h"

Sensor SensorBuilder::buildSensor(nlohmann::json data) {
	Sensor sensor;
	sensor.setId(data["ID"]);
	sensor.setType(data["Type"]);
	sensor.setFrequency(data["Frequency"]);
	sensor.setRangeFirst(data["MinValue"]);
	sensor.setRangeSecond(data["MaxValue"]);
	sensor.setEncoderType(data["EncoderType"]);
	return sensor;
}