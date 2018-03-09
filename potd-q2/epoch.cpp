#include "epoch.h"
#include <iostream>
#include <string>
#include <ctime>



std::time_t sec= std::time(nullptr);

int hours(std::time_t){
	return sec/3600;
}

int days(std::time_t){
	return sec/86400;
}
int years(std::time_t){
	return sec/31556926;
}

