#include "SensorManager.h"

SensorManager::SensorManager(){
    std::ifstream file;
    _sensorFile = json::basic_json();
    file.open(CONFIG_FILE, std::ios::in);
    _sensorBuilder = _sensorBuilder.getInstance();
    if(!file.is_open()){
        std::cout << "Could not open file with configuration\n";
    }
    else{
        std::cout << "File opened\n";
        try {
            _sensorFile = json::parse(file, nullptr, true, false);
            Sensors = parseSensors(_sensorFile["Sensors"]);
        }
        catch (json::parse_error& ex) {
            std::cerr << "message " << ex.what() << "\n";
        }
    } 
}

std::vector<std::shared_ptr<Sensor>> SensorManager::parseSensors(json data) {
    std::vector<std::shared_ptr<Sensor>> result;
    for (json item : data) {
        Sensor sensor = _sensorBuilder.buildSensor(item);
        result.push_back(std::make_shared<Sensor>(sensor));
    }
    return result;
}

void SensorManager::generateResults() {
    std::vector<std::thread> threads;
    for (const auto& sensor : Sensors) {
        threads.push_back(std::thread([sensor]() {
            sensor->generateOutput();
        }));
    }
    for (std::thread& thread : threads) {
        thread.join();
    }
}

