#include "Consumer.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "welcome to COEN 320 Project Repo!!!" << endl;

	//tester dataset
	Database bro = Database();
	Database* DB_ptr = &bro;

	cout << "done" << endl;

//	for (int i = 0; i < 10; i++)
//	{
//		cout << bro.fuel_coms[i] << endl;;
//	}

	Consumer C1 = Consumer(5, FUEL);
	Consumer C2 = Consumer(5, RPM);
	C1.consume(DB_ptr);
	C2.consume(DB_ptr);





	return 0;

}
