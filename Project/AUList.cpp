// Implementation file for AUList
#include <iostream>
#include <stdexcept>
#include "AUList.h"


//Many AUList Operations are unaffected!
AUList::AUList() {
  length = 0; 
}
bool AUList::IsFull() const {
  return (length == MAXSIZE); 
}
int AUList::GetLength() const {
  return length;
}

void AUList::MakeEmpty() {
  length = 0; //as with the constructor, we need do nothing to the actual array, as it now "junk" data
}
void AUList::PutItem(BigMacPriceRecord item) { //This function assumes the "IsFull" condition hasn't been met.
  ListItems[length] = item; //Remember that C++ uses 0-indexing.
  length++;
}

void AUList::ResetList() {
  currentPos = -1; //We want the position BEFORE the first element, since incrementation in GetNextItems happens first
}

bool AUList::HasNextItem() {
  return currentPos<(length-1);
}

BigMacPriceRecord AUList::GetNextItem() {
  currentPos++; //Remember that currentPos is a class member variable
  return ListItems[currentPos];
}

void AUList::PrintList() { //simple function to print a list's items in stored order
  for (int loc=0; loc<length; loc++) {
  	BigMacPriceRecord curitem=ListItems[loc];
    std::cout<< "Rec " << loc << ": " <<curitem.date << ", " << curitem.curr_code << ", " 
  << curitem.name << ", " << curitem.local_price << ", " << curitem.dollar_ex << ", " 
  << curitem.dollar_price << std::endl;
  }
}

