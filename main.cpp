/*
 * Data Structures Heap
 * Enter integer data from console input or user inputted file. Data is sorted in a max heap.
 * 2/21/25
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
void quitter(bool &input);

int getSize(Node* tree[]);
void recurswim(Node* tree[], int index);
void recursink(Node* tree[], int index);

int main() {
  Node* tree[100]; //create 100-element array
  
  for (int a = 1; a < 101; a++) { //init 100 elements to null
    tree[a] = NULL;
  }
  cout << "Initialized 100 tree slots to null." << endl;
  cout << endl;
  
  bool input = true;
  while (input == true) { //command selector
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
	print(tree, 1, 0, treeSize-2); //print
      }
      else { //if size 0
	cout << "Your heap is empty!" << endl;
      }
    }
    else if (strcmp(command, "REMOVE_ROOT") == 0) {
      int treeSize = getSize(tree);
      if (treeSize > 1) {
	removeRoot(tree, treeSize); //remove largest value (root)
      }
      else { //if size 0
	cout << "Your heap is empty!" << endl;
      }
    }
    else if (strcmp(command, "REMOVE_ALL") == 0) {
      removeAll(tree); //remove all
    }
    else if (strcmp(command, "SIZE") == 0) {
      cout << "Size: " << getSize(tree) << endl;
    }
    else if (strcmp(command, "QUIT") == 0) {
      quitter(input);
    }
    else {
      cout << "Invalid input! Try again." << endl;
    }
  }
}

void add(Node* tree[], int newVal) { //general add func, used by addManual and addFile
  int index = 1;
  while (index < 101 && tree[index] != NULL) {
    index++; //walk to last element
  }
    if (index < 101) {
      Node* newNode = new Node(newVal);
      tree[index] = newNode;
      recurswim(tree, index); //go swim up and find your spot
    }
}

//Parent: i
//Child 1: 2i
//Child 2: 2i+1
//Grandparent: [(i)/2] //take the first integer. if its 3.5, take 3. if its 6.5, take 6.

void recurswim(Node* tree[], int index) {
  if (index > 1) { //stop if root
    int parentSlot = floor(index / 2); //find your parent's slot
    if (tree[index]->getVal() > tree[parentSlot]->getVal()) { //if you're greater than your parent
      Node* temp = tree[parentSlot];
      tree[parentSlot] = tree[index];
      tree[index] = temp;
      
      recurswim(tree, parentSlot); //after swap, see if you can swim up again
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
  if ((getSize(tree)) > 99) { //if tree is already full
    cout << "Your tree is already full (100), sorry!" << endl;
    cout << endl;
  }
  else {
    int newVal = 0;
    cout << "Input a number to add." << endl;
    cin >> newVal;
    cin.ignore();
    add(tree, newVal); //add number
    cout << newVal << " has been added to the heap." << endl;
    cout << endl;
  }
}

void addFile(Node* tree[]) { //read from file
  cout << "Please enter the full name of your file. (ex: 'heap-numbers.txt')" << endl;
  string fileName;
  int fileVal;
  cin >> fileName;
  cin.ignore();
  fstream HeapNumbers(fileName);
  int heapNum;
  while (HeapNumbers >> fileVal) { //read from file, spaces separating
    add(tree, fileVal);
  }
  HeapNumbers.close();

  cout << "Numbers from " << fileName << " have been added." << endl;
  cout << endl;
}

void removeRoot(Node* tree[], int size) {
    if (size < 1 || tree[1] == NULL) return; //prevent errors

    cout << "Deleting root: " << tree[1]->getVal() << endl;
    delete tree[1];

    if (size > 1) {
        tree[1] = tree[size]; //move last valid node to root
        tree[size] = NULL;    //remove old reference
        recursink(tree, 1);   //sink the new root
    } else {
        tree[1] = NULL; //if only root exists, just remove it
    }
}

void removeAll(Node* tree[]) {
    while (getSize(tree) > 0) { //while size is valid
        int size = getSize(tree);
        removeRoot(tree, size);
    }
    cout << "All heap elements have been deleted." << endl;
}

void recursink(Node* tree[], int index) {
    int left = 2 * index;
    int right = 2 * index + 1;
    int largest = index;

    //find the largest of root, left, and right child
    if (left < 100 && tree[left] != NULL && tree[left]->getVal() > tree[largest]->getVal()) {
        largest = left;
    }
    if (right < 100 && tree[right] != NULL && tree[right]->getVal() > tree[largest]->getVal()) {
        largest = right;
    }

    //if largest is not the root, swap and try to sink again
    if (largest != index) {
        swap(tree[index], tree[largest]);
        recursink(tree, largest);
    }
}

int getSize(Node* tree[]) {
    int lastValidIndex = 0; //track last valid index

    for (int i = 1; i < 100; i++) {
        if (tree[i] != NULL) {
            lastValidIndex = i; //update last seen valid index
        }
    }

    return lastValidIndex; //last valid index in use
}

void quitter(bool &input) { //quit
  cout << "Goodbye!" << endl;
  input = false;
}

