//
//  Created by Peter Brady on 13/03/2017
//  Copyright (c) 2017 Peter Brady.
//  X00115070
//
#ifndef CITY_H_
#define CITY_H_
#include <string>
using namespace std;

class City {
public:
	City();
	City(string name, pair<string, string> coords, int pop, double temp);
	friend ostream& operator<<(ostream& stream, City& city);
	friend class TreeNode;
	friend class BinarySearchTree;
private:
	string name;
	pair<string, string> gpsCoordinates;
	int population;
	double averageTemperature;
};
#endif // CITY_H_
