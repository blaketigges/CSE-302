#include <iostream>

struct Laptop_Data {
  public:
  int Laptop_ID; // used to sort
  std::string Company;
  std::string Product;
  std::string TypeName;
  double Inches;
  std::string ScreenResolution;
  std::string Cpu;
  std::string Ram;
  std::string Memory;
  std::string Gpu;
  std::string OpSys;
  std::string Weight;
  double Price_euros;
};

struct LNode {
  public:
  Laptop_Data item;
  LNode *next;
};

class CLQueue {
public: 
  CLQueue();
  ~CLQueue();
  void MakeEmpty();
  bool IsEmpty() const;
  bool IsFull() const;
  void Enqueue(Laptop_Data newItem);
  Laptop_Data Dequeue();
//private:
  LNode* QEnd;
};


