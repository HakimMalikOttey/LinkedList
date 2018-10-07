// LinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <string>
#include<exception>
#include"Header.h"
using namespace std;
	int main()
	{
		int take;
		datax<int> m;
		while (true) {
			m.~datax();
			cout << "\n\n1. Insert\n\n2.Find\n\n3.Delete\n\n4.Show" << endl;
			cin >> take;
			try {
				switch (take) {
				case 1:
					//Insert Data into linked list
					m.insert();
					m.show();
					break;
				case 2:
					//Search for data within the linked list
					m.find();
					break;
				case 3:
					//delete data within the linked list
					m.Delete();
					break;
				case 4:
					//show data within the linked list
					m.show();
					break;
				default:
					cout << "Error" << endl;
				}
			}
			catch (const exception &e) {
				cout << e.what() << endl;
			}
		}
		return 0;
	}


