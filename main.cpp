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

//void add();
//void addManual();
//void addFile();
//void removeLargest();
//void removeAll();
//void print();

int main() {
  Node* tree[99]; //create 100-element array
  
  for (int a = 0; a < (100); a++) { //init array slots to null
    tree[a] = NULL;
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
      //printer(table, tblSize);
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
