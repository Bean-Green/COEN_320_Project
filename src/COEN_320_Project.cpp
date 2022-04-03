#include "Producer.h"
#include <iostream>
#include <thread>
using namespace std;

int main()
{
	cout << "welcome to COEN 320 Project Repo!!!" << endl;

	Database bro = Database();
	Database* DB_ptr = &bro;

	cout << "done creating database" << endl;

	SharedMem sm = SharedMem();
	SharedMem* SM_ptr = &sm;

	Producer p1 = Producer(5, FUEL, DB_ptr, SM_ptr);
	p1.start();

	Producer p2 = Producer(5, RPM, DB_ptr, SM_ptr);
	p2.start();


//	Consumer C1 = Consumer(5, FUEL, DB_ptr);
//	Consumer C2 = Consumer(5, RPM, DB_ptr);
//	C1.start();
//	C2.start();

	sleep(20);
	return 0;

}
