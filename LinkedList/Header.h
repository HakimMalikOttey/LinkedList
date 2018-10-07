#pragma once
#ifndef Header_H
#define Header_H
#include "stdafx.h"
#include<iostream>
#include <string>
#include <exception>

template<typename T>
struct Node {
	T record;
	Node<T> *next;
	Node<T> *prev;
	Node() {
		next = NULL;
		prev = NULL;
	}
};


template<class T> 
class datax { 
	Node<T> *top;
	Node<T> *bot;
	//Temporary pointers 
	Node<T> *storeprev;
	Node<T> *storenext;
public:
	datax() {
		top = NULL;
		bot = NULL;
		storeprev = NULL;
		storenext = NULL;
	}
	~datax() {}
	//Searches the list that has a requested key word
	void find();
	//Inserts into the list a requested word
	void insert();
	//Searches the list for a requested key word and pops it out
	void Delete();
	void show();
private:
};

template<typename T>
void datax<T>::show() {
	Node<T> *temp = top;
	while (temp != NULL) {
		cout << temp->record << " -> ";
		temp = temp->next;
	}
	

}
template<typename T>
void datax<T>::Delete() {
	T get;
	Node<T>*ser = top;
	cin >> get;
	//If There is no data in the list or if there is only one element in the list 
	if (ser == NULL||top==NULL|| ser->next == NULL) {
		cout << "Can't access list" << endl;
	}
	else {
		// If the key given by the user matches with the the data within the node at the top of a list
		if (ser == top && ser->record == get) {
			cout << "Removing data from " << ser << endl;
			//Saves the node that comes after the first element
			top = top->next;
			//Pushes element out of list and 
			top->prev = NULL;
			delete ser;
		}
		//If the key is in the middle or end of the list
		if (ser == top && ser->record != get){
			//Searches list until it detects key match
			while (ser->record != get) {	
				ser = ser->next;
			}
			//If in the middle of list
			if (ser->next != NULL) {
				cout << "Removing data from " << ser << endl;
				storenext = ser->next->prev;
				storeprev = ser->prev;
				storenext->prev = storeprev;
				storeprev->next = storenext;
				delete ser;
			}
			//Last node of the list 
			else {
				cout << "Removing data from " << ser << endl;
				ser->prev->next = NULL;
				delete ser;
			}
		}
		//If element is not present within the list 
		else {
			cout << "Data not found" << endl;
		}
	}
	}

template<typename T> 
void datax<T>::insert() {
	T val;
    Node<T> *ptr = new Node<T>;
	cin >> val;
	ptr->record = val;
	ptr->next = NULL;
	//If there is more than one element
	if (bot != NULL) {
		bot->next = ptr;
		ptr->prev = bot;
	}
	//First time putting data into the list ( Creating first node). Won't be used again unless list loses all nodes, which is impossible
	if (top == NULL) {
		top = ptr;
	}
	bot = ptr;
}
template<typename T>
void datax<T>::find() {
	T get;
	Node<T> *ptr= top;
	cin >> get;
	//If no elements in list
	if (ptr == NULL) {
		cout << "Data not found" << endl;
	}
	else {
		while (ptr != NULL && ptr->record != get) {
				ptr = ptr->next;
		}
		//Prints out memory location of key match
		if (ptr != NULL && ptr->record == get) {
			cout << "Found: " << ptr << endl;
		}
		else {
			cout << "Data not found" << endl;
		}
	}

}

#endif // !Header_H
