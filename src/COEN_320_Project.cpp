#include "Producer.h"
#include "Consumer.h"
#include <iostream>
#include <thread>
using namespace std;

int main()
{
	cout << "welcome to COEN 320 Project Repo!!!" << endl;

	Database bd = Database();
	Database* DB_ptr = &bd;

	cout << "done creating database" << endl;

	SharedMem sm = SharedMem();
	SharedMem* SM_ptr = &sm;

	Producer p1 = Producer(1, FUEL, DB_ptr, SM_ptr);
	p1.start();

	Producer p2 = Producer(3, RPM, DB_ptr, SM_ptr);
	p2.start();

	Producer p3 = Producer(10, TEMP, DB_ptr, SM_ptr);
	p3.start();
//
	Producer p4 = Producer(7, GEAR, DB_ptr, SM_ptr);
	p4.start();

	Producer p5 = Producer(1, SPEED, DB_ptr, SM_ptr);
	p5.start();


	Consumer c1 = Consumer(2, SM_ptr);
	c1.start();

	while(true)
	{

	}
	return 0;

}
