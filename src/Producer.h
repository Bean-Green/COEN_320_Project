#include "SharedMem.h"
#include "Database.h"
#include "PeriodicTimer.h"

#pragma once


extern int current_time;
extern mutex CPU;



class Producer
{
public:
	Producer(double interval, int type, Database* db_ptr, SharedMem* sm_ptr);
	void ChangePeriod(double time);
	~Producer();
	void* produce(void* arg);
	void start();

private:
	void init_sigst();
	double interval;
	double curr_val;
	int data_type;
	sigset_t* sigsts;
	Database* DB_ptr;
	SharedMem* SM_ptr;
};
