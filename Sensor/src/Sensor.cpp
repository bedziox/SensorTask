#include "Sensor.h"

void Sensor::setId(unsigned int id) {
    _id = id;
}

unsigned int Sensor::getId() const {
    return _id;
}

void Sensor::setType(const std::string& type) {
    _type = type;
}

std::string Sensor::getType() const {
    return _type;
}

unsigned int Sensor::getFrequency() const {
    return _frequency;
}

void Sensor::setFrequency(unsigned int frequency) {
    _frequency = frequency;
}

std::pair<int, int> Sensor::getRange() const {
    return _range;
}

void Sensor::setRange(const std::pair<int, int>& range) {
    _range = range;
}

void Sensor::setRangeFirst(int first) {
    _range.first = first;
}

void Sensor::setRangeSecond(int second) {
    _range.second = second;
}

void Sensor::setEncoderType(std::string type) {
    _encoderType = type;
}
std::string Sensor::getEncoderType() const {
    return _encoderType;
}
int Sensor::generateData() {
    std::mt19937 rng(std::random_device{}());

    std::uniform_int_distribution<int> distribution(getRange().first, getRange().second);

    return distribution(rng);
}

std::string Sensor::checkQuality(int data) {
    std::string quality = "Normal";
    return quality;
}

void Sensor::generateOutput() {
    
    while (true) {
        int data = generateData();
        std::string quality = checkQuality(data);
        std::cout << "$FIX, " << getId() << ", " << getType() << ", " << data << ", " << quality << "*\n";
        std::this_thread::sleep_for(std::chrono::milliseconds((unsigned char)(1000 / getFrequency())));
    }
}

std::string Sensor::toString() const {
    std::ostringstream oss;

    oss << "Sensor Information:\n";
    oss << "ID: " << getId() << "\n";
    oss << "Type: " << getType() << "\n";
    oss << "Frequency: " << getFrequency() << " Hz\n";
    oss << "Range: [" << getRange().first << ", " << getRange().second << "]\n";
    oss << "Encoder Type: " << getEncoderType() << "\n";

    return oss.str();
}