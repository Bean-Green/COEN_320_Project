#include "Database.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;


Database::Database()
{

	ifstream myFile("dataset.csv");
	if(!myFile.good()){
		cout << "Failed to find file" << endl;
	}

	int fuel_column = 0;

	int rpm_column = 12;

	int temp_column = 17;

	int gear_column = 33;

	int speed_column = 43;

	int count = 0;
	string row;
	string value;
	int position;

	//pull row
	while (getline(myFile, row, '\n') && myFile.good())
	{
		//cout << row << " ROW" << endl;;
		position = 0;
		stringstream column(row);

		//skip first row
		if (count >= 1)
		{
			//split row by ','
			while (getline(column, value, ',') && column.good())
			{

				if (position == fuel_column)
				{
					fuel_coms.push_back(stod(value));
					//cout << "FUEL: " << value << endl;
				}
				else if (position == rpm_column)
				{
					rpm.push_back(stod(value));
					//cout << "RPM: " << value << endl;
				}
				else if (position == temp_column)
				{
					temp.push_back(stod(value));
					//cout << "TEMP: " << value << endl;
				}
				else if (position == gear_column)
				{
					gear.push_back(stod(value));
					//cout << "GEAR: " << value << endl;
				}
				else if (position == speed_column)
				{
					speed.push_back(stod(value));
					//cout << "SPEED: " << value << endl;
				}
				position++;
			}
		}
		count++;
	}
}

//Tester Database
Database::Database(int length)
{
	for (int i = 0; i < length; i++)
	{
		fuel_coms.push_back(length - i);
		rpm.push_back(length + i);
		temp.push_back(length - i);
		gear.push_back(i);
		speed.push_back(i);
	}

}

