#include "Consumer.h"
#include <sys/mman.h>
#include <sys/time.h>
#include <fcntl.h>
#include <iostream>
//#include <pthread>
#include <thread>
using namespace std;

Consumer::Consumer(double Interval, int type) {

	this->interval = Interval;
	this->data_type = type;
	curr_val = 404;

	/*
		read the parameters

	*/

}


Consumer::~Consumer() {
	/*
		void
	*/
}

void Consumer::consume(Database* d){

	while (true)
	{
		if(this->data_type == FUEL)
		{
			this->curr_val = d->fuel_coms[interval];
			cout << "FUEL: " << curr_val << endl;
		}
		else if(this->data_type == RPM)
		{
			this->curr_val = d->rpm[interval];
			cout << "RPM: " << curr_val << endl;
		}
		else if(this->data_type == TEMP)
		{
			this->curr_val = d->temp[interval];
			cout << curr_val << endl;

		}
		else if(this->data_type == GEAR)
		{
			this->curr_val = d->gear[interval];
			cout << curr_val << endl;

		}
		else if(this->data_type == SPEED)
		{
			this->curr_val = d->speed[interval];
			cout << curr_val << endl;

		}
		break;
	//place timer here
	}
}


