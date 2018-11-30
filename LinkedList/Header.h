#pragma once
#ifndef Header_H
#define Header_H
#include "stdafx.h"
#include<iostream>
#include <string>
#include <exception>
#include <algorithm>
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


template<typename T, typename K, typename Q> 
class datax { 
	Node<T> *top;
	Node<T> *bot;
	Node<T> *sorted;
	//Temporary pointers 
	Node<T> *storeprev;
	Node<T> *storenext;
public:
	datax() {
		top = NULL;
		bot = NULL;
		sorted = NULL;
		storeprev = NULL;
		storenext = NULL;
	}
	~datax() {}
	//Searches the list that has a requested key word
	void find( T a);
	//Inserts into the list a requested word
	void insert( T a);
	//Searches the list for a requested key word and pops it out
	void Delete( T a);
	void show();
	//Insert Sort
	void insertsort(Node<T>* a, Node<T> *b);
	//Quick Sort
	void quicksort(Node<T>* a, Node<T>* b, Node<T>* c);
	Node<T>* head();
	Node<T>* end();
	T orderch();
	void error();
private:
};

template<typename T, typename K, typename Q>
void datax<T,K,Q>::show() {
	Node<T> *temp = top;
	while (temp != NULL) {
		cout << temp->record << " -> ";
		temp = temp->next;
	}
	

}
template<typename T, typename K, typename Q>
void datax<T, K, Q>::Delete(T a) {
	Node<T>*ser = top;
	//If There is no data in the list or if there is only one element in the list 
	if (ser == NULL||top==NULL|| ser->next == NULL) {
		cout << "Can't access list" << endl;
	}
	else {
		// If the key given by the user matches with the the data within the node at the top of a list
		if (ser == top && ser->record == a) {
			cout << "Removing data from " << ser << endl;
			//Saves the node that comes after the first element
			top = top->next;
			//Pushes element out of list and 
			top->prev = NULL;
			delete ser;
		}
		//If the key is in the middle or end of the list
		else if (ser == top && ser->record != a){
			//Searches list until it detects key match
			while (ser->record != a) {	
				ser = ser->next;
			}
			//If in the middle of list
			if (ser->next != NULL) {
				cout << "Removing data from " << ser << endl;
				storenext = ser->next;
				storeprev = ser->prev;
				storenext->prev = storeprev;
				storeprev -> next = storenext;
				ser = NULL;
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

template<typename T, typename K, typename Q>
void datax<T, K, Q>::insert(T a) {
    Node<T> *ptr = new Node<T>;
	ptr->record = a;
	ptr->next = NULL;
	//If there is more than one element
	if (bot != NULL) {
		bot->next = ptr;
		ptr->prev = bot;
	}
	//First time putting data into the list ( Creating first node). Won't be used again unless list loses all nodes, which is impossible
	if (top == NULL) {
		top = ptr;
		sorted = ptr;
	}
	bot = ptr;
}
template<typename T, typename K, typename Q>
void datax<T, K, Q>::find(T a) {
	Node<T> *ptr= top;
	//If no elements in list
	if (ptr == NULL) {
		cout << "Data not found" << endl;
	}
	else {
		while (ptr != NULL && ptr->record != a) {
				ptr = ptr->next;
		}
		//Prints out memory location of key match
		if (ptr != NULL && ptr->record == a) {
			cout << "Found: " << ptr << endl;
		}
		else {
			cout << "Data not found" << endl;
		}
	}

}

//Insert Sort
template<typename T, typename K, typename Q>
void datax<T, K, Q>::insertsort(Node<T>* a, Node<T> *b) {
	//mov iterates through the entire list
	// temo stays at a given posotion, up until mov reaches the end of the list,
	//where it will then iterate to the next node
	Node<T> *mov = a;
	Node<T> *temp = b;
	int save = 0;
	//If the list is empty
	if (top == NULL) {
		return;
	}
	while (mov->next != NULL) {
		//Sorts  list to make sure the lesser nodes are at the left of the list
		if (temp->record >= mov->record) {
			save = temp->record;
			temp->record = mov->record;
			mov->record = save;
		}
		mov = mov->next;
	}
	//shrinks block of list that is being sorted
	if (temp->next != NULL) {
		temp = temp->next;
		mov = temp;
		insertsort(mov, temp);
	}
	//Final Check
	else {
		mov = bot;
		temp = top;
		while (temp->next != NULL) {
			if (temp->record >= mov->record) {
				save = temp->record;
				temp->record = mov->record;
				mov->record = save;
			}
			temp = temp->next;
		}
		return;
	}
}

//Quick Sort
template<typename T, typename K, typename Q>
void datax<T, K, Q>::quicksort(Node<T>* a, Node<T>* b, Node<T>* c) {
bool change = false;
 int save = 0;
 Node<int> *beg = a;
 Node<int> *end = a;
	//middle of the graph
 Node<int> *pivot = b;
	if (top == NULL) {
		return;
	}
	while (beg != b) {
		if (beg == NULL || end == NULL) {
			return;
		}
		//Makes sure that lesser values are at the left and higher values are to the right
		if (beg->record <= pivot->record) {
			save = beg->record;
			beg->record = end->record;
			end->record = save;
			end = end->next;
		}
		beg = beg->next;
	}
	//The highest value gets put at the end of the list.
	//Value at end of list gets put at the previous space of the higher value
	save = b->record;
	b->record = end->record;
	end->record = save;
	//checks to see if list is ordered
	if (b != NULL && a != b && a != b->next) {
		quicksort(top, pivot->prev,sorted);
		if (sorted->next != NULL) {
			sorted = sorted->next;
			quicksort(pivot->next, bot,sorted);
		}
		else {
			return;
		}
	}
}
//Scans list to see if everything is ordered ( least to greatest)
template<typename T, typename K, typename Q>
T datax<T, K, Q>::orderch() {
	Node<T> *check = top;
	if (top == NULL) {
		return true;
	}
	else {
		while (check->next != NULL){
			if (check->record <= check->next->record) {
				check = check->next;
			}
			else {
				return false;
			}
		}
		return true;
	}
}
template<typename T, typename K, typename Q>
void datax<T, K, Q>::error() {
	cin.clear();
	cin.ignore();
}
// Returns value for top of the list
template<typename T, typename K, typename Q>
Node<T>* datax<T, K, Q>::head() {
	return top;
}
//Returns value for end of the list 
template<typename T, typename K, typename Q>
Node<T>* datax<T, K, Q>::end() {
	return bot;
}

#endif // !Header_H
