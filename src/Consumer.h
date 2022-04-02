#include "Database.h"
#pragma once
//#ifndef 1
//CONSUMER_H
///#define CONSUMER_H
//#endif // !1

enum data_enum {
	FUEL = 1,
	RPM = 2,
	TEMP = 3,
	GEAR = 4,
	SPEED = 5
};

class Consumer {
public:

	Consumer(double interval, int type, Database* ptr);
	void ChangePeriod(double time);
	~Consumer();
	void* consume(void* arg);
	void start();
private:
	double interval;
	double curr_val;
	int data_type;
	Database* DB_ptr;
};
