/*
 * Data Structures Heap
 *
 * 2/19/25
 * Santiago Gaete
 */

#include <iostream>
#include <fstream>
#include "Node.h"

using namespace std;

void add(Node* tree[], int newVal);
//void addManual();
//void addFile();
//void removeLargest();
//void removeAll();
void print(Node* tree[], int pos, int depth, int size);

void recursift(Node* tree[], int index);

int main() {
  Node* tree[99]; //create 100-element array
  
  for (int a = 0; a < 100; a++) {
    tree[a] = NULL;
  }
  for (int a = 0; a < (20); a++) { //init array slots to null
    int randVal = (rand() % 999);
    add(tree, randVal);
  }
  cout << "Initialized 100 tree slots to null." << endl;

  bool input = true;
  while (input == true) {
    cout << "Your commands are ADD_MANUAL, ADD_FILE, PRINT, REMOVE_BIG, REMOVE_ALL, and QUIT." << endl;
    cout << endl;
    cout << "Input a command." << endl;
    char command[15] = ""; //make sure to fit chars + 1 terminating

    cin >> command; 
    cin.ignore();
    if (strcmp(command, "ADD_MANUAL") == 0) {
      //Student* newStu = new Student(true); //create new student (constructor will prompt input)
      //adder(newStu, table, tblSize);
    }
    else if (strcmp(command, "ADD_FILE") == 0) {

    }
    else if (strcmp(command, "PRINT") == 0) {
      int treeSize = 0;
      bool treeCheck = false;
      if (tree[0] == NULL) {
	treeCheck = true;
	cout << "There is no root element in your heap." << endl;
      }
      while (treeSize <= 100 && treeCheck == false) {
	if (tree[treeSize] == NULL) {
	  treeCheck = true;
	}
	treeSize++;
      }
      if (treeSize > 0) {
	print(tree, 1, 0, treeSize-1);
      }
    }
    else if (strcmp(command, "REMOVE_BIG") == 0) {
      //int deleteID; //get ID to look for
        //cout << "Enter the ID of the student to be deleted: ";
        //cin >> deleteID;
        //deleter(table, deleteID, tblSize);
    }
    else if (strcmp(command, "REMOVE_ALL") == 0) {

    }
    else if (strcmp(command, "QUIT") == 0) {
      //quitter(input);
    }
    else {
      cout << "Invalid input! Try again." << endl;
    }
  }
}

void add(Node* tree[], int newVal) {
  int index = 0;
  while (index < 100 && tree[index] != NULL) {
    index++;
  }
    if (index < 100) {
      Node* newNode = new Node(newVal);
      tree[index] = newNode;
      recursift(tree, index);
    }
  
  //now sift around for heap property
}
//Parent: i
//Child 1: 2i+1
//Child 2: 2i+2
//Grandparent: [(i-1)/2] //take the first integer. if its 3.5, take 3. if its 6.5, take 6.

void recursift(Node* tree[], int index) {
  if (index > 0) {
    int parentSlot = int((index-1)/2);
    if (tree[index]->getVal() > tree[parentSlot]->getVal()) {
      Node* temp = tree[parentSlot];
      tree[parentSlot] = tree[index];
      
      tree[index] = temp;
      
      
      recursift(tree, parentSlot);
    }
  }
}

void print(Node* tree[], int pos, int depth, int size) {
  if (pos*2+1 < size) { //check right not NULL
    print(tree, pos*2+1, depth+1, size); //recurse right
  }
  for (int a = 0; a < depth; a++) {
    cout << '\t';
  }
  cout << tree[pos]->getVal() << endl;
  if (pos*2 < size) { //check left not NULL
    print(tree, pos*2, depth+1, size); //recurse left
  }
}
