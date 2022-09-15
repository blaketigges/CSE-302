#include <iostream>
#include "LLUList.h"

int main(int argc, char** argv) {	
	LLUList TestList;
	
	std::cout<<"Newly Created List: ";
	TestList.PrintList();
	for (int i=0; i<10; i++)
	  TestList.PutItem(100-i*10);
	std::cout<<"List after 'PutItem' calls: ";
	TestList.PrintList();
	std::cout<<"Length after 'PutItem' calls: " <<TestList.GetLength() <<std::endl;
	std::cout<<"IsFull after 'PutItem' calls? " <<TestList.IsFull() <<std::endl;
	TestList.DeleteItem(50);
	std::cout<<"List after 'DeleteItem' call: ";
	TestList.PrintList();
	std::cout<<"Length of List: ";
	std::cout<<TestList.GetLength()<<std::endl;
	std::cout<<"mean of List: ";
	std::cout<<TestList.getMean()<<std::endl;
	std::cout<<"stdev of List: ";
	std::cout<<TestList.getStdev()<<std::endl;
	std::cout<<"IsFull after 'DeleteItem' call? " <<TestList.IsFull() <<std::endl;
	std::cout<<"Index of value 80: "<<TestList.GetItem(80)<<std::endl;
	std::cout<<"Index of value 25: "<<TestList.GetItem(25)<<std::endl;
	TestList.MakeEmpty();
	std::cout<<"List after 'MakeEmpty': ";
	TestList.PrintList();	
	TestList.ResetList();
	try {	
		TestList.GetNextItem();
	} catch (...) {	
		std::cout<<"No items in list to iterate through."<<std::endl;
	}
	return 0;
}
