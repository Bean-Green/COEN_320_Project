#include "Producer.h"
#include <sys/mman.h>
#include <sys/time.h>
#include <fcntl.h>
#include <string>
#include <iostream>
#include <pthread.h>
#include <thread>
#include <cstring>
using namespace std;


Producer::Producer(double Interval, int type, Database* db_ptr, SharedMem* sm_ptr ) {

	this->interval = Interval;
	this->data_type = type;
	curr_val = 404;
	this->DB_ptr = db_ptr;
	this->SM_ptr= sm_ptr;

}

Producer::~Producer() {
	/*
		void
	*/
}

void* Producer::produce(void* arg){

	double tmp;
	int sum  = interval;
	while (true)
	{
		if(this->data_type == FUEL)
		{
			this->curr_val = DB_ptr ->fuel_coms[sum -1];
			tmp = this->SM_ptr->access_mem(WRITE, FUEL, curr_val);
			//cout << "FUEL: " << curr_val << endl;
		}
		else if(this->data_type == RPM)
		{
			this->curr_val = DB_ptr->rpm[sum - 1];
			tmp = this->SM_ptr->access_mem(WRITE, RPM, curr_val);
			//cout << "RPM: " << curr_val << endl
		}
		else if(this->data_type == TEMP)
		{
			this->curr_val = DB_ptr->temp[sum - 1 ];
			tmp = this->SM_ptr->access_mem(WRITE, TEMP, curr_val);
			//cout << "TEMP: " << curr_val << endl;

		}
		else if(this->data_type == GEAR)
		{
			this->curr_val = DB_ptr->gear[sum -1];
			tmp = this->SM_ptr->access_mem(WRITE, GEAR, curr_val);
			//cout << "GEAR: "<< curr_val << endl;

		}
		else if(this->data_type == SPEED)
		{
			this->curr_val = DB_ptr->speed[sum -1];
			tmp = this->SM_ptr->access_mem(WRITE, SPEED, curr_val);
			//cout << "SPEED: "<< curr_val << endl;
		}
	sleep(interval);
	sum = sum + interval;
	}
	return NULL;
}

void Producer::start(){
		//thread thread1(&Producer::consume, this, d);
	typedef void * (*THREADFUNCPTR)(void *);
	pthread_t t;
	int rc;
	rc = pthread_create(&t, NULL, (THREADFUNCPTR)&Producer::produce, this);
	if (rc)
	{
		 cout << "Error:unable to create thread," << rc << endl;
		 exit(-1);
	}
}

