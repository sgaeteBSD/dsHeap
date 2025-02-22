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
void addFile(Node* tree[]);
void removeRoot(Node* tree[], int size);
void removeAll(Node* tree[]);
void print(Node* tree[], int pos, int depth, int size);

int getSize(Node* tree[]);
void recurswim(Node* tree[], int index);
void recursink(Node* tree[], int index);

int main() {
  //srand
  Node* tree[100]; //create 100-element array

  fstream HeapNumbers("heap-numbers.txt");
  int heapNum;
  
  
  for (int a = 1; a < 101; a++) {
    tree[a] = NULL;
  }
  for (int a = 1; a < 50; a++) { //testing
    int randVal = (rand() % 999);
    add(tree, randVal);
  }
  cout << "Initialized 100 tree slots to null." << endl;
  cout << endl;
  
  bool input = true;
  while (input == true) {
    cout << "Your commands are ADD_MANUAL, ADD_FILE, PRINT, REMOVE_ROOT, REMOVE_ALL, and QUIT." << endl;
    cout << endl;
    cout << "Input a command." << endl;
    char command[15] = ""; //make sure to fit chars + 1 terminating

    cin >> command; 
    cin.ignore();
    if (strcmp(command, "ADD_MANUAL") == 0) {
      addManual(tree);
    }
    else if (strcmp(command, "ADD_FILE") == 0) {
      addFile(tree);
    }
    else if (strcmp(command, "PRINT") == 0) {
      int treeSize = getSize(tree);
      if (treeSize > 1) {
	print(tree, 1, 0, treeSize-2);
      }
    }
    else if (strcmp(command, "REMOVE_ROOT") == 0) {
      int treeSize = getSize(tree);
      if (treeSize > 1) {
	removeRoot(tree, treeSize-3);
      }
    }
    else if (strcmp(command, "REMOVE_ALL") == 0) {
      removeAll(tree);
    }
    else if (strcmp(command, "QUIT") == 0) {
      cout << getSize(tree)-3 << endl;
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
      recurswim(tree, index);
    }
  
  //now sift around for heap property
}
//Parent: i
//Child 1: 2i
//Child 2: 2i+1
//Grandparent: [(i)/2] //take the first integer. if its 3.5, take 3. if its 6.5, take 6.

void recurswim(Node* tree[], int index) {
  if (index > 1) {
    int parentSlot = floor(index / 2);
    if (tree[index]->getVal() > tree[parentSlot]->getVal()) {
      Node* temp = tree[parentSlot];
      tree[parentSlot] = tree[index];
      
      tree[index] = temp;
      
      recurswim(tree, parentSlot);
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
  cout << getSize(tree) << endl;
  if ((getSize(tree)-3) > 99) {
    cout << "Your tree is already full (100), sorry!" << endl;
    cout << endl;
  }
  else {
    int newVal = 0;
    cout << "Input a number to add." << endl;
    cin >> newVal;
    cin.ignore();
    add(tree, newVal);
    cout << newVal << " has been added to the heap." << endl;
    cout << endl;
  }
}

void addFile(Node* tree[]) {
  cout << "Please enter the full name of your file. (ex: 'heap-numbers.txt')" << endl;
  string fileName;
  int fileVal;
  cin >> fileName;
  cin.ignore();
  fstream HeapNumbers(fileName);
  int heapNum;
  while (HeapNumbers >> fileVal) {
    add(tree, fileVal);
  }
  HeapNumbers.close();

  cout << "Numbers from " << fileName << " have been added." << endl;
  cout << endl;
}

void removeRoot(Node* tree[], int size) {
  Node* temp = tree[1];
  tree[1] = NULL;
  cout << "Deleting root: " << temp->getVal() << endl;
  cout << endl;
  delete temp;

  if (size > 1) {
    tree[1] = tree[size-1];
    delete tree[size-1];
    tree[size-1] = NULL;
    recursink(tree, 1);
  }
}

void removeAll(Node* tree[]) {
  while (tree[1] != NULL) {
    int size = getSize(tree);
    removeRoot(tree, size-1);
  }
  cout << "All heap elements have been deleted." << endl;
  cout << endl;
}

void recursink(Node* tree[], int index) {
  if (tree[(2*index)+1] != NULL) {
    if (tree[2*index]->getVal() > tree[index]->getVal()
	|| tree[(2*index)+1]->getVal() > tree[index]->getVal()) {
      if (tree[2*index]->getVal() > tree[(2*index)+1]->getVal()) {
	Node* temp = tree[index];
	tree[index] = tree[2*index];
	tree[2*index] = temp;
	recursink(tree, 2*index);
      }
      else {
	Node* temp = tree[index];
	tree[index] = tree[(2*index)+1];
	tree[(2*index)+1] = temp;
	recursink(tree, (2*index)+1);
      }
    }
  }
}

int getSize(Node* tree[]) {
    int treeSize = 1;

    // Check if the heap is empty
    if (tree[1] == NULL) {
        cout << "There is no root element in your heap." << endl;
        return 0; // Return 0 if empty
    }

    // Iterate until we find the first NULL slot
    while (treeSize < 100 && tree[treeSize] != NULL) {
        treeSize++;
    }

    return treeSize - 1; // Subtract 1 to get the actual last index
}


