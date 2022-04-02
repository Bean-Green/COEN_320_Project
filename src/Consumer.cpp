#include "Consumer.h"
#include <sys/mman.h>
#include <sys/time.h>
#include <fcntl.h>
#include <iostream>
//#include <pthread>
#include <thread>
using namespace std;

Consumer::Consumer(double Interval, int type, Database* ptr) {

	this->interval = Interval;
	this->data_type = type;
	curr_val = 404;
	this->DB_ptr = ptr;


	/*
		read the parameters

	*/

}


Consumer::~Consumer() {
	/*
		void
	*/
}

void* Consumer::consume(void* arg){
	while (true)
	{
		if(this->data_type == FUEL)
		{
			this->curr_val = DB_ptr ->fuel_coms[interval];
			cout << "FUEL: " << curr_val << endl;
			break;
		}
		else if(this->data_type == RPM)
		{
			this->curr_val = DB_ptr->rpm[interval];
			cout << "RPM: " << curr_val << endl;
			break;
		}
		else if(this->data_type == TEMP)
		{
			this->curr_val = DB_ptr->temp[interval];
			cout << curr_val << endl;

		}
		else if(this->data_type == GEAR)
		{
			this->curr_val = DB_ptr->gear[interval];
			cout << curr_val << endl;

		}
		else if(this->data_type == SPEED)
		{
			this->curr_val = DB_ptr->speed[interval];
			cout << curr_val << endl;

		}
	//place timer here
	}
	return NULL;
}


void Consumer::start(){
		//thread thread1(&Consumer::consume, this, d);
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

