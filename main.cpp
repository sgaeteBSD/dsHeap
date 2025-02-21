/*
 * Data Structures Heap
 *
 * 2/19/25
 * Santiago Gaete
 */

#include <iostream>
#include <fstream>
#include "Node.h"
#include <cmath>

using namespace std;

void add(Node* tree[], int newVal);
void addManual(Node* tree[]);
//void addFile();
//void removeLargest();
//void removeAll();
void print(Node* tree[], int pos, int depth, int size);

void recursift(Node* tree[], int index);

int main() {
  //srand
  Node* tree[100]; //create 100-element array

  fstream HeapNumbers("heap-numbers.txt");
  int heapNum;
  
  
  for (int a = 0; a < 101; a++) {
    tree[a] = NULL;
  }
  for (int a = 1; a < (10); a++) { //init array slots to null
    //int randVal = (rand() % 999);
    int randVal;
    HeapNumbers >> randVal;
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
      addManual(tree);
    }
    else if (strcmp(command, "ADD_FILE") == 0) {

    }
    else if (strcmp(command, "PRINT") == 0) {
      int treeSize = 1;
      bool treeCheck = false;
      if (tree[1] == NULL) {
	treeCheck = true;
	cout << "There is no root element in your heap." << endl;
      }
      while (treeSize <= 101 && treeCheck == false) {
	if (tree[treeSize] == NULL) {
	  treeCheck = true;
	}
	treeSize++;
      }
      cout << "size: " << treeSize << endl;
      if (treeSize > 1) {
	print(tree, 1, 0, treeSize-2);
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
  int index = 1;
  while (index < 101 && tree[index] != NULL) {
    index++;
  }
    if (index < 101) {
      Node* newNode = new Node(newVal);
      tree[index] = newNode;
      recursift(tree, index);
    }
  
  //now sift around for heap property
}
//Parent: i
//Child 1: 2i
//Child 2: 2i+1
//Grandparent: [(i)/2] //take the first integer. if its 3.5, take 3. if its 6.5, take 6.

void recursift(Node* tree[], int index) {
  cout << index << endl;
  if (index > 1) {
    int parentSlot = index / 2;
    cout << parentSlot << endl;
    if (tree[index]->getVal() > tree[parentSlot]->getVal()) {
      Node* temp = tree[parentSlot];
      tree[parentSlot] = tree[index];
      
      tree[index] = temp;
      
      recursift(tree, parentSlot);
    }
  }
}

void print(Node* tree[], int pos, int depth, int size) {
  if ((pos)*2+1 < size) { //check right not NULL
    print(tree, (pos)*2+1, depth+1, size); //recurse right
  }
  for (int a = 0; a < depth; a++) {
    cout << '\t';
  }
  cout << tree[pos]->getVal() << endl;
  if ((pos)*2 < size) { //check left not NULL
    print(tree, (pos)*2, depth+1, size); //recurse left
  }
}

void addManual(Node* tree[]) {
  if (tree[100] != NULL) {
    cout << "Your tree is already full (100), sorry!" << endl;
    cout << endl;
  }
  else {
    int newVal = 0;
    cout << "What number would you like to add?" << endl;
    cin >> newVal;
    add(tree, newVal);
    cout << newVal << " has been added to the heap." << endl;
    cout << endl;
  }
}
