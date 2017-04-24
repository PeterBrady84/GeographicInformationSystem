//
//  Created by Peter Brady on 13/03/2017
//  Copyright (c) 2017 Peter Brady.
//  X00115070
//
#include "City.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	cout << "Create Cities" << endl;
	City city1 = City("Orlando", make_pair(28.5383, -81.3792), 255483, 21);
	City city2 = City("Reykjavik", make_pair(64.1265, -21.8174), 119289, 4);
	City city3 = City("Vancouver", make_pair(49.2827, -123.1207), 603500, 9);
	City city4 = City("Lisbon", make_pair(38.7223, -9.1393), 530847, 13);
	City city5 = City("Honolulu", make_pair(21.3069, -157.8583), 337256, 27);
	City city6 = City("London", make_pair(51.5074, -0.1278), 8674000, 11);
	City city7 = City("Havana", make_pair(23.1136, -82.3666), 2105000, 25);	
	City city8 = City("New York", make_pair(40.7128, -74.0059), 8406000, -1);
	City city9 = City("Dublin", make_pair(53.3498, -6.2603), 527612, 10);
	City city10 = City("Dallas", make_pair(32.7767, -96.7970), 1258000, 17);	
	City city11 = City("Edmonton", make_pair(53.5444, -113.4909), 812200, -6);	
	City city12 = City("Seattle", make_pair(47.6062, -122.3321), 608660, 11);	

	BinarySearchTree cityTree = BinarySearchTree();

	cout << "Insert Cities Into Tree" << endl;
	cityTree.insert(city1);
	cityTree.insert(city2);
	cityTree.insert(city3);
	cityTree.insert(city4);
	cityTree.insert(city5);
	cityTree.insert(city6);
	cityTree.insert(city7);
	cityTree.insert(city8);
	cityTree.insert(city9);
	cityTree.insert(city10);
	cityTree.insert(city11);
	cityTree.insert(city12);
	cout << "Insert City Into Tree Where Coordinates Already Exist" << endl;
	cityTree.insert(city8);		// throws duplicate coordinates error

	//cityTree.showInOrder();
	cout << endl << endl;
	cout << "Print Tree" << endl;
	cout << setfill('=') << setw(30) << "=" << setfill(' ') << endl;
	cityTree.prettyPrint();
	cout << endl;

	cout << "Delete Lisbon From Tree (By Name)" << endl;
	cityTree.deleteByName("Lisbon");
	cout << "Print Tree" << endl;
	cout << setfill('=') << setw(30) << "=" << setfill(' ') << endl;
	cityTree.prettyPrint();
	cout << endl;

	cout << "Delete Vancouver From Tree (By Coordinates)" << endl;
	cityTree.deleteByCoord(make_pair(49.2827, -123.1207));
	cout << "Print Tree" << endl;
	cout << setfill('=') << setw(30) << "=" << setfill(' ') << endl;
	cityTree.prettyPrint();
	cout << endl;

	cout << "Search for City By Name" << endl;
	cout << setfill('=') << setw(30) << "=" << setfill(' ') << endl;
	cityTree.searchByName("London");		// true
	cityTree.searchByName("Cork");		// false
	cout << "Search for City By Coordinates" << endl;
	cout << setfill('=') << setw(30) << "=" << setfill(' ') << endl;
	if (!cityTree.searchByCoords(make_pair(21.3069, -157.8583))) {
		cout << "GPS coordinates not found" << endl;
	}
	if (!cityTree.searchByCoords(make_pair(49.2827, -123.1207))) {
		cout << "GPS coordinates not found" << endl;
	}
	cout << endl;

	cout << "Tree Height" << endl;
	cout << setfill('=') << setw(30) << "=" << setfill(' ') << endl;
	cout << "Height : " << cityTree.height() << endl << endl;

	cout << "Tree In Order" << endl;
	cout << setfill('=') << setw(30) << "=" << setfill(' ') << endl;
	cityTree.showInOrder();
	cout << endl << endl;

	cout << "Tree Pre Order" << endl;
	cout << setfill('=') << setw(30) << "=" << setfill(' ') << endl;
	cityTree.showPreOrder();
	cout << endl << endl;

	cout << "Tree Post Order" << endl;
	cout << setfill('=') << setw(30) << "=" << setfill(' ') << endl;
	cityTree.showPostOrder();
	cout << endl << endl;

	cout << "Delete Tree (Destructor)" << endl;
	cityTree.~BinarySearchTree();
	cout << "Print Tree" << endl;
	cout << setfill('=') << setw(30) << "=" << setfill(' ') << endl;
	cityTree.prettyPrint();
	cout << endl;
	cout << "Tree Height" << endl;
	cout << setfill('=') << setw(30) << "=" << setfill(' ') << endl;
	cout << "Height : " << cityTree.height() << endl << endl;
	cout << endl << endl << "END" << endl;
	system("pause");
}