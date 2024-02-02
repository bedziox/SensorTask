#ifndef SENSOR_H
#define SENSOR_H
#include <string>
#include "Util.h"
#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <sstream>

class Sensor {
public:
	void setId(unsigned int id);
	unsigned int getId() const;
	std::string getType() const;
	void setType(const std::string& type);
	unsigned int getFrequency() const;
	void setFrequency(unsigned int frequency);
	std::pair<int, int> getRange() const;
	void setRange(const std::pair<int, int>& range);
	void setRangeFirst(int first);
	void setRangeSecond(int second);
	void setEncoderType(std::string type);
	std::string getEncoderType() const;

	void generateOutput();
	int generateData();
	std::string checkQuality(int data);
	std::string toString() const;
private:
	unsigned int _id;
	std::string _type;
	unsigned int _frequency;
	std::pair<int, int> _range;
	std::string _encoderType;
};

#endif
