//
//  Created by Peter Brady on 13/03/2017
//  Copyright (c) 2017 Peter Brady.
//  X00115070
//
#include "City.h"

// default constructor for city object
City::City()
	: name(""), gpsCoordinates("", ""), population(0), averageTemperature(0.0) {}

// overloaded constructor for city object
City::City(string name, pair<string, string> coords, int pop, double temp)
	: name(name), gpsCoordinates(coords), population(pop), averageTemperature(temp) {}

// overloaded stream operator for output of a city objects details
ostream & operator<<(ostream & stream, City & city) {
	stream << "\nCity: " << city.name << "\nGPS Coordinates: " << city.gpsCoordinates.first << ", "
		<< city.gpsCoordinates.second << "\nPopulation: " << city.population << "\nAverage Temp: "
		<< city.averageTemperature << endl;
		
	return stream;
}
