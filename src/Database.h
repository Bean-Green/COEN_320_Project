#include <iostream>
#include <vector>
using namespace std;

class Database
{
public:
	Database();
	Database(int length);
	vector<double> fuel_coms;
	vector<double> rpm;
	vector<double> temp;
	vector<double> gear;
	vector<double> speed;
};

