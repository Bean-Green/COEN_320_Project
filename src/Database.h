#include <iostream>
#include <vector>
using namespace std;

class Database
{
public:
	Database();
	Database(int length);

	vector<vector<double>> all_out;
private:
	vector<double> fuel_coms;
	vector<double> rpm;
	vector<double> temp;
	vector<double> gear;
	vector<double> speed;
};

