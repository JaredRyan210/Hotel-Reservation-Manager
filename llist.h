//CS311 Yoshii S22 llist.h
//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

// =======================================================
// HW#: HW3P1 llist
// Your name: Jared Ryan
// Compiler:  g++ 
// File type: headher file  llist.h
//=======================================================


// alias el_t : element type definition
//char el_t;  // int for now but can change later
#include "elem.h"
//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

  // untility function to move to a specified node position
  void moveTo(int, Node*&);
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //PURPOSE: Check if list is empty. If so return true, if not, return false.
  //PARAMETER: No parameter since it is simply checking if there exists elements in the list
  bool isEmpty();
    
  //PURPOSE: Loop through the list, and print the Elem value of each node.
  //PARAMETER: No parameter
  void displayAll();

  //PURPOSE: This function adds a new node to the front of the list. 2 case: if list is empty and
  // if list is not empty
  //PARAMETER:  NewNum;  this is the Elem value we are adding to the node.
  void addFront(el_t);
    
  //PURPOSE: This function adds a new node to the rear of the list
  //If list is not empty, create a new node and make it front while moving other nodes down.
  //PARAMETER: NewNum; this is the Elem value we are adding to the node.
  void addRear(el_t);

  //PURPOSE: This function deletes the node at the beginning of the list. 3 Cases
  //PARAMETER: OldNum; this is the Elem value we are deleting from the node.
  void deleteFront(el_t&);
  
  //---------------------------------------
    
  //PURPOSE: This function deletes the node at the rear of the list. 3 cases.
  //PARAMETER: OldNum; this is the Elem value we are deleting from the node.
  void deleteRear(el_t&);
    
  //PURPOSE: This function deletes a node wherever the user wants in the list. 4 Cases
  //PARAMETER: I; tells the function what node to move to.
  //          OldNum; this is the Elem value we are deleting from the node.
  void deleteIth(int, el_t&);  // calls moveTo

  //PURPOSE: This function inserts a node one node before wherever the user wants in the list. 4 Cases
  //PARAMETER: I; tells the function what node to move to.
  //          newNum; this is the Elem value we are inserting to the inserted node.    
  void insertIth(int, el_t);   // calls moveTo

  //Copy Constructor to allow pass by value and return by value of a llist
  llist(const llist&);
  
  //Overloading of = (returns a reference to a llist)
  llist& operator=(const llist&); 

};
