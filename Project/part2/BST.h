#include <iostream>
#include "CLQueue.h"

struct TNode {
  public:
  Laptop_Data item; // sort by item.Laptop_ID
  TNode *left;
  TNode *right;
};

enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};


class BST {
  public:
  BST();
  BST(const BST& originalBST); //(Deep-)Copy constructor
  ~BST(); //Destructor
  
  
  //main BST functions that call helper functions using the root Node
  Laptop_Data GetItem(int gitem);
  void PutItem(Laptop_Data newitem);
  void DeleteItem(int ditem);
  int GetLength();
  void MakeEmpty();
  bool IsEmpty();
  bool IsFull();
  void PrintTree();
  void ResetTree(OrderType order);
  Laptop_Data GetNextItem();
  bool TravEmpty();

  
  private:
  //helper functions called to recursively view/manipulate sub-tree elements
  void Insert (TNode* &curnode, Laptop_Data newitem);
  Laptop_Data FindItem(TNode* curnode, int gitem);
  void Delete(TNode* &curnode, int ditem);
  void DeleteNode(TNode* &curnode);
  int CountNodes(TNode* curnode);
  void PrintNodes(TNode* curnode);
  void CopyNodes(TNode*& copyNode, const TNode* origNode);
  void DestroyNodes(TNode*& curNode);
  void PreNodes(TNode* curNode);
  void InNodes(TNode* curNode);
  void PostNodes(TNode* curNode);
  
  TNode *root;
  CLQueue *TravQueue;
};
