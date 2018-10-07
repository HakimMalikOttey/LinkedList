#pragma once
#ifndef templates_h
#define templates_h 1

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


#endif // !Header_h
