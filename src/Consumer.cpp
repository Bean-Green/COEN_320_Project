/*
 * Consumer.cpp
 *
 *  Created on: Apr. 3, 2022
 *      Author: JBGra
 */

#include "Consumer.h"
#include <pthread.h>
#include <thread>
#include <cstring>

Consumer::Consumer(double interval, SharedMem* sm_ptr ) {
	this->period = interval;
	this->SM_ptr = sm_ptr;

	curr_fuel = 404;
	curr_rpm = 404;
	curr_temp = 404;
	curr_gear = 404;
	curr_speed = 404;

}

Consumer::~Consumer() {
	// TODO Auto-generated destructor stub
}

void* Consumer::consume(void* arg)
{
	while (true)
		{
			cout << "----------" << "time here" << "----------" << endl;
			//read fuel
			this->curr_fuel = this->SM_ptr->access_mem(READ, FUEL, 0);
			cout << "Current FUEL: " << curr_fuel << endl;

			//read rpm
			this->curr_rpm = this->SM_ptr->access_mem(READ, RPM, 0);
			cout << "Current RPM: " << curr_rpm << endl;

//			//read temp
			this->curr_temp = this->SM_ptr->access_mem(READ, TEMP, 0);
			cout << "Current TEMP: " << curr_temp << endl;
//
//			//read gear
			this->curr_gear = this->SM_ptr->access_mem(READ, GEAR, 0);
			cout << "Current GEAR: " << curr_gear << endl;
//
//			//read speed
			this->curr_speed = this->SM_ptr->access_mem(READ, SPEED, 0);
			cout << "Current SPEED: " << curr_speed << endl;

		sleep(period);
		}
	return NULL;
}

void Consumer::start(){
	typedef void * (*THREADFUNCPTR)(void *);
	pthread_t t;
	int rc;
	rc = pthread_create(&t, NULL, (THREADFUNCPTR)&Consumer::consume, this);
	if (rc)
	{
		 cout << "Error:unable to create thread," << rc << endl;
		 exit(-1);
	}
}

