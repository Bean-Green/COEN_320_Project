
#include <iostream>
#include <vector>
using namespace std;

class Database{
public:
	Database();
	Database(int length);
	vector<double> fuel_coms;
	vector<int> rpm;
	vector<int> temp;
	vector<int> gear;
	vector<int> speed;

};

