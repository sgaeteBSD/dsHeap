#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

Node::Node(int newVal) {
  // constructor
  value = newVal;
  next = NULL; // setting next to null
}
Node::~Node(){
  // destructor
  next = NULL;
}
Node* Node::getNext() {
  return next;
  // return the next variable when going to the next node.
}
int Node::getVal() {
  return value;
}
void Node::setNext(Node* nextNode) {
  next = nextNode;
}
void Node::setVal(int newVal) {
  value = newVal;
}
