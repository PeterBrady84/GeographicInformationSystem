//
//  Created by Peter Brady on 13/03/2017
//  Copyright (c) 2017 Peter Brady.
//  X00115070
//
#include "City.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <iomanip>
#include <chrono>
using namespace std;

BinarySearchTree cityTree;
City city1, city2, city3, city4, city5, city6, city7, city8, city9, city10, city11,
city12, city13, city14, city15, city16, city17, city18, city19, city20, city21, city22,
city23, city24, city25;
clock_t startcputime;

// insert cities method
void insertCities() {
	cityTree.insert(city1);		// Orlando
	cityTree.insert(city2);		// Reykjavik
	cityTree.insert(city3);		// Vancouver
	cityTree.insert(city4);		// Lisbon
	cityTree.insert(city5);		// Honolulu
	cityTree.insert(city6);		// London
	cityTree.insert(city7);		// Havana
	cityTree.insert(city8);		// New York
	cityTree.insert(city9);		// Dublin
	cityTree.insert(city10);	// Dallas
	cityTree.insert(city11);	// Edmonton
	cityTree.insert(city12);	// Seattle
	cityTree.insert(city13);	// Aberdeen
	cityTree.insert(city14);	// Newcastle
	cityTree.insert(city15);	// Belfast
	cityTree.insert(city16);	// Liverpool
	cityTree.insert(city17);	// Nantes
	cityTree.insert(city18);	// Madrid
	cityTree.insert(city19);	// San Francisco
	cityTree.insert(city20);	// Philadelphia
	cityTree.insert(city21);	// Las Vegas
	cityTree.insert(city22);	// Mexico City
	cityTree.insert(city23);	// Caracas
	cityTree.insert(city24);	// Cancun
	cityTree.insert(city25);	// Seville
}

// main
int main() {
	// create city objects for the binary search tree
	cout << "Create Cities" << endl;
	city1 = City("Orlando", make_pair(28.5383, -81.3792), 255483, 21);
	city2 = City("Reykjavik", make_pair(64.1265, -21.8174), 119289, 4);
	city3 = City("Vancouver", make_pair(49.2827, -123.1207), 603500, 9);
	city4 = City("Lisbon", make_pair(38.7223, -9.1393), 530847, 13);
	city5 = City("Honolulu", make_pair(21.3069, -157.8583), 337256, 27);
	city6 = City("London", make_pair(51.5074, -0.1278), 8674000, 11);
	city7 = City("Havana", make_pair(23.1136, -82.3666), 2105000, 25);
	city8 = City("New York", make_pair(40.7128, -74.0059), 8406000, -1);
	city9 = City("Dublin", make_pair(53.3498, -6.2603), 527612, 10);
	city10 = City("Dallas", make_pair(32.7767, -96.7970), 1258000, 17);
	city11 = City("Edmonton", make_pair(53.5444, -113.4909), 812200, -6);
	city12 = City("Seattle", make_pair(47.6062, -122.3321), 608660, 11);
	city13 = City("Aberdeen", make_pair(57.1526, -2.1100), 492400, 5);
	city14 = City("Newcastle", make_pair(54.5820, -1.3630), 1650000, 3);
	city15 = City("Belfast", make_pair(54.5973, -5.9301), 585996, 4);
	city16 = City("Liverpool", make_pair(53.4084, -2.9916), 465700, 6);
	city17 = City("Nantes", make_pair(47.1305, -1.3310), 292718, 11);
	city18 = City("Madrid", make_pair(40.4168, -3.7038), 6529700, 19);
	city19 = City("San Francisco", make_pair(37.7749, -122.4194), 837442, 14);
	city20 = City("Philadelphia", make_pair(39.9526, -75.1652), 6069875, 14);
	city21 = City("Las Vegas", make_pair(36.1030, -115.0811), 1951269, 14);
	city22 = City("Mexico City", make_pair(19.4326, -99.1332), 8918653, 26);
	city23 = City("Caracas", make_pair(10.4806, -66.9036), 2923959, 28);
	city24 = City("Cancun", make_pair(21.0938, -86.5051), 628306, 10);
	city25 = City("Seville", make_pair(37.3891, -5.9845), 696676, 19);

	// create binary search tree
	cityTree = BinarySearchTree();

	// insert cities
	// and get time to insert cities
	cout << "Insert Cities Into Tree" << endl;
	startcputime = clock();
	insertCities();
	double insert_cpu_duration = (clock() - startcputime) / double(CLOCKS_PER_SEC) * 10;
	
	// insert duplicate city
	cout << "Insert City Into Tree Where Coordinates Already Exist" << endl;
	cityTree.insert(city8);		// throws duplicate coordinates error
	cout << endl;

	// print tree
	cout << "Print Tree" << endl;
	cout << setfill('=') << setw(30) << "=" << setfill(' ') << endl;
	cityTree.prettyPrint();
	cout << endl;
	
	// delete cities by name
	// and get time to delete all cities
	cout << "Delete All Cities From Tree (By Name)" << endl;
	startcputime = clock();
	cityTree.deleteByName("Seattle");
	cityTree.deleteByName("Belfast");
	cityTree.deleteByName("Vancouver");
	cityTree.deleteByName("New York");
	cityTree.deleteByName("Honolulu");
	cityTree.deleteByName("Liverpool");
	cityTree.deleteByName("Aberdeen");
	cityTree.deleteByName("Orlando");
	cityTree.deleteByName("Newcastle");
	cityTree.deleteByName("Madrid");
	cityTree.deleteByName("San Francisco");
	cityTree.deleteByName("Dublin");
	cityTree.deleteByName("Lisbon");
	cityTree.deleteByName("Caracas");
	cityTree.deleteByName("Mexico City");
	cityTree.deleteByName("Cancun");
	cityTree.deleteByName("Nantes");
	cityTree.deleteByName("Philadelphia");
	cityTree.deleteByName("Edmonton");
	cityTree.deleteByName("Reykjavik");
	cityTree.deleteByName("Seville");
	cityTree.deleteByName("London");
	cityTree.deleteByName("Dallas");
	cityTree.deleteByName("Las Vegas");
	cityTree.deleteByName("Havana");
	double delete_by_name_cpu_duration = (clock() - startcputime) / double(CLOCKS_PER_SEC) * 10;

	// re-add cities to binary tree
	insertCities();

	// delete cities by coordinates
	// and get time to delete all cities
	cout << "Delete All Cities From Tree (By Coordinates)" << endl;
	startcputime = clock();
	cityTree.deleteByCoord(make_pair(47.6062, -122.3321));	// Seattle
	cityTree.deleteByCoord(make_pair(54.5973, -5.9301));	// Belfast
	cityTree.deleteByCoord(make_pair(49.2827, -123.1207));	// Vancouver
	cityTree.deleteByCoord(make_pair(40.7128, -74.0059));	// New York
	cityTree.deleteByCoord(make_pair(21.3069, -157.8583));	// Honolulu
	cityTree.deleteByCoord(make_pair(53.4084, -2.9916));	// Liverpool
	cityTree.deleteByCoord(make_pair(57.1526, -2.1100));	// Aberdeen
	cityTree.deleteByCoord(make_pair(28.5383, -81.3792));	// Orlando
	cityTree.deleteByCoord(make_pair(54.5820, -1.3630));	// Newcastle
	cityTree.deleteByCoord(make_pair(40.4168, -3.7038));	// Madrid
	cityTree.deleteByCoord(make_pair(37.7749, -122.4194));	// San Francisco
	cityTree.deleteByCoord(make_pair(53.3498, -6.2603));	// Dublin
	cityTree.deleteByCoord(make_pair(38.7223, -9.1393));	// Lisbon
	cityTree.deleteByCoord(make_pair(10.4806, -66.9036));	// Caracas
	cityTree.deleteByCoord(make_pair(19.4326, -99.1332));	// Mexico City
	cityTree.deleteByCoord(make_pair(21.0938, -86.5051));	// Cancun
	cityTree.deleteByCoord(make_pair(47.1305, -1.3310));	// Nantes
	cityTree.deleteByCoord(make_pair(39.9526, -75.1652));	// Philadelphia
	cityTree.deleteByCoord(make_pair(53.5444, -113.4909));	// Edmonton
	cityTree.deleteByCoord(make_pair(64.1265, -21.8174));	// Reykjavik
	cityTree.deleteByCoord(make_pair(37.3891, -5.9845));	// Seville
	cityTree.deleteByCoord(make_pair(51.5074, -0.1278));	// London
	cityTree.deleteByCoord(make_pair(32.7767, -96.7970));	// Dallas
	cityTree.deleteByCoord(make_pair(36.1030, -115.0811));	// Las Vegas
	cityTree.deleteByCoord(make_pair(23.1136, -82.3666));	// Havana
	double delete_by_coords_cpu_duration = (clock() - startcputime) / double(CLOCKS_PER_SEC) *10;

	// print tree
	cout << "Print Tree" << endl;
	cout << setfill('=') << setw(30) << "=" << setfill(' ') << endl;
	cityTree.prettyPrint();
	cout << endl;

	// re-add cities to binary tree
	insertCities();

	// search for cities by name
	cout << "Search for City By Name" << endl;
	cout << setfill('=') << setw(30) << "=" << setfill(' ') << endl;
	startcputime = clock();
	cityTree.searchByName("Seattle");
	cityTree.searchByName("Belfast");
	cityTree.searchByName("Vancouver");
	cityTree.searchByName("New York");
	cityTree.searchByName("Honolulu");
	cityTree.searchByName("Liverpool");
	cityTree.searchByName("Aberdeen");
	cityTree.searchByName("Orlando");
	cityTree.searchByName("Newcastle");
	cityTree.searchByName("Madrid");
	cityTree.searchByName("San Francisco");
	cityTree.searchByName("Dublin");
	cityTree.searchByName("Lisbon");
	cityTree.searchByName("Caracas");
	cityTree.searchByName("Mexico City");
	cityTree.searchByName("Cancun");
	cityTree.searchByName("Nantes");
	cityTree.searchByName("Philadelphia");
	cityTree.searchByName("Edmonton");
	cityTree.searchByName("Reykjavik");
	cityTree.searchByName("Seville");
	cityTree.searchByName("London");
	cityTree.searchByName("Dallas");
	cityTree.searchByName("Las Vegas");
	cityTree.searchByName("Havana");
	double search_by_name_cpu_duration = (clock() - startcputime) / double(CLOCKS_PER_SEC) * 10;

	// search for non existant city (By Name)
	cout << "Search for City that is not in the BST (By Name)" << endl;
	cityTree.searchByName("Cork");		// false
	cout << endl;	

	// search for cities by coordinates
	cout << "Search for City By Coordinates" << endl;
	cout << setfill('=') << setw(30) << "=" << setfill(' ') << endl;
	startcputime = clock();
	cityTree.searchByCoords(make_pair(47.6062, -122.3321));	// Seattle
	cityTree.searchByCoords(make_pair(54.5973, -5.9301));	// Belfast
	cityTree.searchByCoords(make_pair(49.2827, -123.1207));	// Vancouver
	cityTree.searchByCoords(make_pair(40.7128, -74.0059));	// New York
	cityTree.searchByCoords(make_pair(21.3069, -157.8583));	// Honolulu
	cityTree.searchByCoords(make_pair(53.4084, -2.9916));	// Liverpool
	cityTree.searchByCoords(make_pair(57.1526, -2.1100));	// Aberdeen
	cityTree.searchByCoords(make_pair(28.5383, -81.3792));	// Orlando
	cityTree.searchByCoords(make_pair(54.5820, -1.3630));	// Newcastle
	cityTree.searchByCoords(make_pair(40.4168, -3.7038));	// Madrid
	cityTree.searchByCoords(make_pair(37.7749, -122.4194));	// San Francisco
	cityTree.searchByCoords(make_pair(53.3498, -6.2603));	// Dublin
	cityTree.searchByCoords(make_pair(38.7223, -9.1393));	// Lisbon
	cityTree.searchByCoords(make_pair(10.4806, -66.9036));	// Caracas
	cityTree.searchByCoords(make_pair(19.4326, -99.1332));	// Mexico City
	cityTree.searchByCoords(make_pair(21.0938, -86.5051));	// Cancun
	cityTree.searchByCoords(make_pair(47.1305, -1.3310));	// Nantes
	cityTree.searchByCoords(make_pair(39.9526, -75.1652));	// Philadelphia
	cityTree.searchByCoords(make_pair(53.5444, -113.4909));	// Edmonton
	cityTree.searchByCoords(make_pair(64.1265, -21.8174));	// Reykjavik
	cityTree.searchByCoords(make_pair(37.3891, -5.9845));	// Seville
	cityTree.searchByCoords(make_pair(51.5074, -0.1278));	// London
	cityTree.searchByCoords(make_pair(32.7767, -96.7970));	// Dallas
	cityTree.searchByCoords(make_pair(36.1030, -115.0811));	// Las Vegas
	cityTree.searchByCoords(make_pair(23.1136, -82.3666));	// Havana
	double search_by_coords_cpu_duration = (clock() - startcputime) / double(CLOCKS_PER_SEC) * 10;
	cout << endl;

	// search for non existant city (By Coords)
	cout << "Search for City that is not in the BST (By Coords)" << endl;
	if (!cityTree.searchByCoords(make_pair(49.2827, -123.1307))) {	//false
		cout << "GPS coordinates not found" << endl;
	}
	cout << endl;

	// get and print the height of BST (-1) if empty)
	cout << "Tree Height" << endl;
	cout << setfill('=') << setw(30) << "=" << setfill(' ') << endl;
	startcputime = clock();
	cout << "Height : " << cityTree.height() << endl << endl;
	double tree_height_cpu_duration = (clock() - startcputime) / double(CLOCKS_PER_SEC) * 10;

	// print the BST nodes in order
	cout << "Tree In Order" << endl;
	cout << setfill('=') << setw(30) << "=" << setfill(' ') << endl;
	startcputime = clock();
	cityTree.showInOrder();
	double tree_in_order_cpu_duration = (clock() - startcputime) / double(CLOCKS_PER_SEC) * 10;
	cout << endl << endl;

	// print the BST nodes in pre order
	cout << "Tree Pre Order" << endl;
	cout << setfill('=') << setw(30) << "=" << setfill(' ') << endl;
	startcputime = clock();
	cityTree.showPreOrder();
	double tree_pre_order_cpu_duration = (clock() - startcputime) / double(CLOCKS_PER_SEC) * 10;
	cout << endl << endl;

	// print the BST nodes in post order
	cout << "Tree Post Order" << endl;
	cout << setfill('=') << setw(30) << "=" << setfill(' ') << endl;
	startcputime = clock();
	cityTree.showPostOrder();
	double tree_post_order_cpu_duration = (clock() - startcputime) / double(CLOCKS_PER_SEC) * 10;
	cout << endl << endl;

	// print all the cities within 200km of Dublin
	cout << "Cities within 200km of Dublin" << endl;
	cout << setfill('=') << setw(30) << "=" << setfill(' ') << endl;
	startcputime = clock();
	cityTree.nearByCities(make_pair(53.3498, -6.2603), 200);
	double nearby_cities_cpu_duration = (clock() - startcputime) / double(CLOCKS_PER_SEC) * 10;

	// delete BST
	cout << "Delete Tree (Destructor)" << endl;
	cityTree.~BinarySearchTree();

	// print tree
	cout << "Print Tree" << endl;
	cout << setfill('=') << setw(30) << "=" << setfill(' ') << endl;
	cityTree.prettyPrint();
	cout << endl;

	// get and print the height of BST (-1) if empty)
	cout << "Tree Height" << endl;
	cout << setfill('=') << setw(30) << "=" << setfill(' ') << endl;
	cout << "Height : " << cityTree.height() << endl << endl;

	// print out cpu run times (Note: times are *1000)
	cout << "CPU and WCT Durations" << endl;
	cout << setfill('=') << setw(30) << "=" << setfill(' ') << endl;
	cout << "Finished 'Insert' in " << insert_cpu_duration << " seconds [CPU Clock] " << endl;
	cout << "Finished 'Delete By Name' in " << delete_by_name_cpu_duration << " seconds [CPU Clock] " << endl;
	cout << "Finished 'Delete By Coords' in " << delete_by_coords_cpu_duration << " seconds [CPU Clock] " << endl;
	cout << "Finished 'Search By Name' in " << search_by_name_cpu_duration << " seconds [CPU Clock] " << endl;
	cout << "Finished 'Search By Coords' in " << search_by_coords_cpu_duration << " seconds [CPU Clock] " << endl;
	cout << "Finished 'Tree Height' in " << tree_height_cpu_duration << " seconds [CPU Clock] " << endl;
	cout << "Finished 'Show In Order' in " << tree_in_order_cpu_duration << " seconds [CPU Clock] " << endl;
	cout << "Finished 'Show Pre Order' in " << tree_pre_order_cpu_duration << " seconds [CPU Clock] " << endl;
	cout << "Finished 'Show Post Order' in " << tree_post_order_cpu_duration << " seconds [CPU Clock] " << endl;
	cout << "Finished 'Nearby Cities' in " << nearby_cities_cpu_duration << " seconds [CPU Clock] " << endl;

	cout << endl << endl << "END" << endl;
	system("pause");
}