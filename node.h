#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstring>

using namespace std;

class Node {
 public:
  Node(int newVal);
  ~Node();

  Node* getNext();
  int getVal();

  void setNext(Node* nextNode);
  void setVal(int newVal);
  
 private:
  int value;
  Node* next;
};

#endif
