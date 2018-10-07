#pragma once
#include "stdafx.h"
#include<iostream>
#include <string>

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


template<class T> class datax {
	Node<T> *top;
	Node<T> *bot;
public:
	datax() {
		top = NULL;
		bot = NULL;
		start = NULL;
		finish = NULL;
	}
	~datax() {}
	//Searches the list that has a requested key word
	void find();
	//Inserts into the list a requested word
	void insert();
	//Searches the list for a requested key word and pops it out
	void Delete();
	//Searches for the first value of the list
	void Min();
	//Searches for the last value of the list 
	void Max();
private:
};
template<typename T> void datax<T>::insert() {
	T val;
	struct Node *ptr;
	cin >> val;
	ptr = new Node;
	ptr->record = val;
	ptr->next = NULL;
	if (top != NULL) {
		ptr->next = top;
		//top = ptr;
	}

}
template<typename T>void datax<T>::find() {
	T get;
	Node<T>*ptr;
	T ser = top;
	cin >> get;
	ser = top;
	while (ser != NULL && ser->record != get) {
		ser = ser->next;
	}
	if (ser->record == get) {
		cout << "Found: " << ser << endl;
		//if word is found in this list, store the word in the recent search list for future reference
		ser = start;
		ptr->record = get;
		ptr->next = start;
		if (start != NULL) {
			ptr->next = NULL;
			finish = ptr;
		}
	}
	else {
		cout << "Data not found" << endl;
	}

}

template<typename T> void datax<T>::Delete() {
	T get;
	Node<T>*ptr;
	T ser = top;
	cin >> get;
	ser = top;
	while (ser != NULL && ser->record != get) {
		ser = ser->next;
	}
	if (ser->record == get) {
		cout << "Removing data from " << ser << endl;
		get->next->prev = get->prev;
		delete prev;
	}
	else {
		cout << "Data not found" << endl;
	}
}
