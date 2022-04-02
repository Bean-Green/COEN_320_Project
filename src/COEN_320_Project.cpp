#include "Consumer.h"
#include <iostream>
#include <thread>
using namespace std;

int main()
{
	cout << "welcome to COEN 320 Project Repo!!!" << endl;

	Database bro = Database();
	Database* DB_ptr = &bro;

	cout << "done" << endl;

//	for (int i = 0; i < 10; i++)
//	{
//		cout << bro.fuel_coms[i] << endl;;
//	}



	Consumer C1 = Consumer(5, FUEL, DB_ptr);
	Consumer C2 = Consumer(5, RPM, DB_ptr);
	C1.start();
	C2.start();


	return 0;

}
