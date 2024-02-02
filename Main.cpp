#include <iostream>
#include <fstream>
#include "SensorManager.h"
#include "json.hpp"


int main()
{
	std::unique_ptr<SensorManager> _manager = std::make_unique<SensorManager>();
	_manager->generateResults();
	return 0;
}
