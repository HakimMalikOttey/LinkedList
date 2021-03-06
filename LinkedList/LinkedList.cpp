// LinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <string>
#include<exception>
#include <time.h>
#include"Header.h"
using namespace std;
	int main()
	{
		string take;
		clock_t track;
		int trans;
		datax<int,int,int> m;
		while (true) {
			m.~datax();
			while (true) {
				cout << "\n\n1. Insert\n\n2. Find\n\n3. Delete\n\n4. Show\n\n5. Sort via QuickSort\n\n6. Sort via InsertSort\n\n7. Implement data for sorting\n\n8. Initiate test suite\n\n9.Test sorting(Quicksort)\n\n10.Test sorting(Insertsort)" << endl;
				cin >> trans;
				if (cin.fail()) {
					m.error();
				}
				else {
					switch (trans) {
					case 1:
						//Insert Data into linked list
						cin >> trans;
						m.insert(trans);
						m.show();
						break;
					case 2:
						//Search for data within the linked list
						cin >> trans;
						m.find(trans);
						break;
					case 3:
						//delete data within the linked list
						cin >> trans;
						m.Delete(trans);
						break;
					case 4:
						//show data within the linked list
						m.show();
						break;
					case 5:
						m.quicksort(m.head(), m.end(),m.head());
						m.show();
						break;
					case 6:
						m.insertsort(m.head(), m.head());
						m.show();
						break;
					case 7:
						m.insert(1);
						m.insert(12);
						m.insert(5);
						m.insert(26);
						m.insert(7);
						m.insert(14);
						m.insert(3);
						m.insert(3);
						m.insert(2);
						m.show();
						break;
					case 8:
						cout << "\n\nInserting data into linked list\n\n" << endl;
						m.insert(1);
						m.insert(2);
						m.insert(3);
						m.insert(4);
						m.insert(5);
						m.insert(6);
						m.insert(7);
						m.insert(8);
						m.insert(9);
						m.insert(10);
						m.show();
						cout << "\n\nDeleting data from middle\n\n" << endl;
						m.Delete(2);
						m.Delete(3);
						m.Delete(4);
						m.Delete(5);
						m.Delete(6);
						m.Delete(7);
						m.show();
						cout << "\n\nDeleting head node(1)\n\n" << endl;
						m.Delete(1);
						cout << "\n\nDeleting bottom node(10)\n\n" << endl;
						m.Delete(10);
						cout << "\n\nSearching list (Data that has been deleted before should show up as 'Data not found')\n\n" << endl;
						m.find(1);
						m.find(2);
						m.find(3);
						m.find(4);
						m.find(5);
						m.find(6);
						m.find(7);
						m.find(8);
						m.find(9);
						m.find(10);
						m.show();
						cout << "\n\nThis is the end of the automated testing.\n\n" << endl;
						system("pause");
						system("CLS");
					case 9:
						for (int i = 0; i < 100;i++ ) {
							trans = rand() % 100;
							m.insert(trans);
						}
						cout << "\n\n\n\nUnsorted List:\n\n\n\n" << endl;
						m.show();
						track = clock();
						m.quicksort(m.head(), m.end(), m.head());
						track = clock() - track;
						cout << "\n\n\n\nSorted List:\n\n\n\n" << endl;
						m.show();
						cout << "\n\nQuicksort took " << track << " seconds" << endl;
						break;
					default:
						cout << " That option is not available" << endl;
					}
				}
			}
		}
		return 0;
	}


