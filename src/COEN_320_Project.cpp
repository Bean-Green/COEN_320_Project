#include "Producer.h"

#include <math.h>
#include "Consumer.h"
#include "PeriodicTimer.h"
#include <iostream>
#include <thread>
using namespace std;

int current_time = 0;
//int timer;
mutex CPU;


extern "C"{
	sigset_t sigst1;
}

int main()
{
	cout << "welcome to COEN 320 Project Repo!!!" << endl;
	vector<int> timeframe;

	Database bro = Database();
	Database* DB_ptr = &bro;

	cout << "done creating database" << endl;
	SharedMem sm = SharedMem();
	SharedMem* SM_ptr = &sm;
	cout << "input desired FUEL period"<<endl;
	double period;
	cin>> period;
	timeframe.push_back(period);
	Producer p1 = Producer(period*ONE_MILLION, FUEL, DB_ptr, SM_ptr);
	cout << "input desired RPM period"<<endl;
	cin>> period;
	timeframe.push_back(period);
	Producer p2 = Producer(period*ONE_MILLION, RPM, DB_ptr, SM_ptr);
	cout << "input desired TEMP Period"<<endl;
	cin>> period;
	timeframe.push_back(period);
	Producer p3 = Producer(period*ONE_MILLION, TEMP, DB_ptr, SM_ptr);
	cout << "input desired GEAR period"<<endl;
	cin>> period;
	timeframe.push_back(period);
	Producer p4 = Producer(period*ONE_MILLION, GEAR, DB_ptr, SM_ptr);
	cout << "input desired SPEED period"<<endl;
	cin>> period;
	timeframe.push_back(period);
	Producer p5 = Producer(period*ONE_MILLION, SPEED, DB_ptr, SM_ptr);


	//p1.start();


	//p2.start();


	//p3.start();
	//

	//p4.start();

	PeriodicTimer Ptime;
	//p5.start();
	cout << "input desired CONSUMER period"<<endl;
	cin>> period;
	timeframe.push_back(period);
	Consumer c1 = Consumer(period*ONE_MILLION, SM_ptr);




	int len = timeframe.size();




//	Consumer C1 = Consumer(5, FUEL, DB_ptr);
//	Consumer C2 = Consumer(5, RPM, DB_ptr);
//	C1.start();
//	C2.start();
	//CPU.lock();

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
	//CPU.unlock();


	while (true){sleep(60);}
	return 0;

}
