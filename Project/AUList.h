#define MAXSIZE 200

struct BigMacPriceRecord {
std::string date;
std::string curr_code;
std::string name;
double local_price;
double dollar_ex;
double dollar_price;	
};

class AUList
{
public:
  
  AUList(); // Constructor
  
  void MakeEmpty();  // Returns the list to the empty state.
    
  bool IsFull() const; //Determines whether list is full. (Precondition -- list has been initialized).  Return value of "True" indicates class is full.
  
  int GetLength() const; //Determines the number of elements in list.

  void PutItem(BigMacPriceRecord); //Adds the item to the list.
    
  void ResetList();  //Initializes iterator's current position for an iteration through the list.

  BigMacPriceRecord GetNextItem(); //Gets the next element in the list.

  bool HasNextItem();
  
  void PrintList();  //Print all elements of the list in a readable format.
  
    

private:
  int length;
  BigMacPriceRecord ListItems[MAXSIZE];
  int currentPos;
};

