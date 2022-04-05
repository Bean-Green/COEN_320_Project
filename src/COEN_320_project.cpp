#include "Producer.h"

#include <math.h>
#include "Consumer.h"
#include "PeriodicTimer.h"
#include <iostream>
#include <thread>
using namespace std;

int current_time = 0;

extern "C"{
	sigset_t sigst1;
}

int main()
{
	cout << "welcome to COEN 320 Project Repo!!!" << endl;
	vector<int> timeframe;

	//create database
	Database bro = Database();
	Database* DB_ptr = &bro;

	cout << "Database Created" << endl;

	//create shared memory
	SharedMem sm = SharedMem();
	SharedMem* SM_ptr = &sm;

	//setting up period for each interested value
	cout << "Input desired FUEL period: ";
	double period;
	cin>> period;

	timeframe.push_back(period);
	Producer p1 = Producer(period*ONE_MILLION, FUEL, DB_ptr, SM_ptr);
	cout << "Input desired RPM period: ";
	cin>> period;

	timeframe.push_back(period);
	Producer p2 = Producer(period*ONE_MILLION, RPM, DB_ptr, SM_ptr);
	cout << "Input desired TEMP period: ";
	cin>> period;

	timeframe.push_back(period);
	Producer p3 = Producer(period*ONE_MILLION, TEMP, DB_ptr, SM_ptr);
	cout << "Input desired GEAR period: ";
	cin>> period;

	timeframe.push_back(period);
	Producer p4 = Producer(period*ONE_MILLION, GEAR, DB_ptr, SM_ptr);
	cout << "Input desired SPEED period: ";
	cin>> period;

	timeframe.push_back(period);
	Producer p5 = Producer(period*ONE_MILLION, SPEED, DB_ptr, SM_ptr);

	PeriodicTimer Ptime;

	cout << "Input desired CONSUMER period: ";
	cin>> period;
	timeframe.push_back(period);
	Consumer c1 = Consumer(period*ONE_MILLION, SM_ptr);

	Ptime.start_periodic_timer(1, 1*ONE_MILLION, &sigst1);
	while(1){
		Ptime.wait_next_activation(&sigst1);
		current_time = Ptime.getTime();
		if(current_time%timeframe[0] == 0 )
			p1.start();
		if(current_time%timeframe[1] == 0 )
			p2.start();
		if(current_time%timeframe[2] == 0 )
			p3.start();
		if(current_time%timeframe[3] == 0 )
			p4.start();
		if(current_time%timeframe[4] == 0 )
			p5.start();
		if(current_time%timeframe[5] == 0 )
			c1.start();

	}
	return 0;
}
