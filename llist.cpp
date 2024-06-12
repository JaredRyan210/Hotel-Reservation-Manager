//CS311 Yoshii S22 Linked List class

//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//  You can copy from a Word document to emacs (contrl-right click)
//  Highly recommended to copy HW3P1-help as PURPOSE of each function.
//
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//  NEVER delete my comments!!!!
//EMACS HINT:
//  cntr-K cuts and cntr-Y pastes. 
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Jared Ryan
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 

llist::llist() {      //Initailizes Front and Rear to be NULL and sets count at 0.
  //cout << "calling the llist constructor..." << endl;
  Front = NULL;
  Rear = NULL;
  Count = 0;
  }

llist::~llist() {
  el_t x;
  //cout << "calling the llist destructor..." << endl;
  while(!isEmpty()) { //while the list is not empty, call deleteFront repeatedly to delete all nodes.
    deleteFront(x);
  }
}

//PURPOSE: Checks to see if the llist is empty, If it is return true, if not return false.
//PARAMETER: No Parameter
bool llist::isEmpty() {
  if (Front == NULL && Rear == NULL && Count == 0) {
    return true;
  } else {
      return false;
  }
  
} // be sure to check all 3 data members

//PURPOSE: Loops through the entire list displaying the Elem for each pass unitl Front is NULL.
//PARAMETER: No parameter
void llist::displayAll() {
  //cout << "The list contains: ";
  Node *P = Front;
  if (isEmpty()) { // Special Case: if list is empty, display 
    cout << "[empty]" << endl;
  } else { // Regular case: If list is not empty
    cout << "[ ";
      while (P != NULL) { //Loop through list displaying Elem value and each node.
      cout << P->Elem << " ";
      P = P->Next;
    }
    cout << "]" << endl;
  }
}  // be sure to display horizontally in [  ] with
// blanks between elements e.g. [ 1 2 3 4]
// You MUST use while (P != NULL) loop or you will not get the credit!
  
//PURPOSE: This function adds a new node to the rear of the list
//If list is not empty, create a new node and make it front while moving other nodes down.
//PARAMETER: NewNum; this is the Elem value we are adding to the node.
void llist::addRear(el_t NewNum) { //2 Cases
  if (isEmpty()) {    //Special Case: if list is empty, create new node and set both Rear and Front
    Front = new Node; //equal to the new node and update count
    Rear = Front;
    Front->Elem = NewNum;
    Rear->Next = NULL;
    Count++;
  } else {                   //Regular Case: If list is not empty, add a new node at the rear and
      Rear->Next = new Node; //store NewNum in Elem field of NewNum and update count.
      Rear = Rear->Next;
      Rear->Elem = NewNum;
      Rear->Next = NULL;
      Count++;
    }
}

//PURPOSE: This function adds a new node to the front of the list. 2 case: if list is empty and
// if list is not empty
//PARAMETER:  NewNum;  this is the Elem value we are adding to the node.
void llist::addFront(el_t NewNum) {
  if (isEmpty()) {        //Special case: If list is empty, creates new node and make Front and Rear
    Front = new Node;     //point to the new node. Store Elem value NewNum into new nodes Elem field 
    Rear = Front;         // and updates count.
    Front->Elem = NewNum;
    Rear->Next = NULL;
    Count++;
  } else {                    //Regular case: Adds new node to the front of the list and stores NewNum
      Node *temp = new Node;  //in the Elem field of the NewNode and updates count.
      temp->Elem = NewNum;
      temp->Next = Front;
      Front = temp;
      Count++;
  }
} 

//PURPOSE: This function deletes the node at the beginning of the list. 3 Cases
//PARAMETER: OldNum; this is the Elem value we are deleting from the node.
void llist::deleteFront(el_t& OldNum) {
  if (isEmpty()) {          //Error case: If the list is empty, throw Underflow error
    throw Underflow();      //since there is nothing to delete
  } else if(Front == Rear) { //Special case: if this is going to be the very first node,       
      OldNum = Front->Elem;  //you must create a new node and make Front and Rear point to it. Put NewNum in the Elem field
      delete Front;
      Front = NULL;
      Rear = NULL;
      Count--;
  } else {                 //if this is going to make the list empty, give back the front node element through OldNum 
      OldNum = Front->Elem;//	(pass by reference) and also remove the front node. Count is updated.
      Node *Second;
      Second = Front->Next;
      delete Front;
      Front = Second;
      Count--;
  }
} 

//PURPOSE: This function deletes the node at the rear of the list. 3 cases.
//PARAMETER: OldNum; this is the Elem value we are deleting from the node.
void llist::deleteRear(el_t& OldNum){
  if (isEmpty()) {          //Error Case: If empty, throw an exception.
    throw Underflow();
  } else if(Count == 1){    //Special Case: If this is going to make the list empty,
      OldNum = Rear->Elem;  //give back the rear node element through OldNum (pass by reference)
      delete Rear;	        //and also remove the rear node. Count is updated.
      Front = NULL;
      Rear = NULL;
      Count--;
  } else {                  //Regular case: Give back the rear node element through OldNum (pass by reference)
      OldNum = Rear->Elem;  //and also remove the rear node. Count is updated.
      Node *P;
      P = Front;
      while(P->Next != Rear) {
        P = P->Next;
      }
        delete Rear;
        Rear = P;
        Rear->Next = NULL;
        Count--;
  }
} 
 //--- harder ones for case 2 and 3 follow -- 

// Utility Function to move a local pointer to the Jth node
void llist::moveTo(int J, Node*& temp) { // moves temp J-1 times to go to the Jth node  
  temp = Front;                    // for ( int K = ... ) temp = temp->Next;
  for (int K = 1; K <= J - 1; K++) {
    temp = temp->Next;
  }
}

//PURPOSE: This function deletes a node wherever the user wants in the list. 4 Cases
//PARAMETER: I; tells the function what node to move to.
//          OldNum; this is the Elem value we are deleting from the node.
void llist::deleteIth(int I, el_t& OldNum) { 
  // must use moveTo to move local pointers. Be sure to comment to which node you are moving them. Do not forget to set OldNum.
  // Error cases: If I is an illegal value (i.e. > Count or < 1) throw an exception.
  if(I > Count || I < 1){
    throw OutOfRange();
  } else if(I == 1) {//Special cases: this should simply call deleteFront (I = 1) or deleteRear (I == Count) for some cases.
      deleteFront(OldNum);
  } else if(I == Count) {
      deleteRear(OldNum);
  } else {
      // P is going to point to the Node that is goint to get deleted 
      Node *X;
      moveTo(I, X);
      // X is going to point to the Node before P
      Node *P;
      moveTo(I-1, P);
      OldNum = X->Elem;
      P->Next = X->Next;
      delete X;
      Count--;
  }
}  // must use moveTo to move local pointers. Be sure to comment to which node you are moving them. Do not forget to set OldNum.  

//PURPOSE: This function inserts a node one node before wherever the user wants in the list. 4 Cases
//PARAMETER: I; tells the function what node to move to.
//          newNum; this is the Elem value we are inserting to the inserted node.
void llist::insertIth(int I, el_t newNum) { 
// must use moveTo to move local pointers. Be sure to comment to which node you are moving them.
// Error cases: If I is an illegal value (i.e. > Count+1 or < 1) throw an exception.
  if((I > Count+1) || I < 1) {
    throw OutOfRange();
  }else if (isEmpty()) {
    throw Underflow();
  } else if(I == 1) {// Special cases: this should simply call addFront (I == 1) or addRear (I == Count+1) for some cases.
      addFront(newNum);
  } else if(I == Count+1) {
      addRear(newNum);
  } else {
      // P is going to point to the Node to where we are going to insert a new node before P 
      Node *P;
      moveTo(I, P);
      // X is going to point to the Node before P then to Node N
      Node *X;
      moveTo(I-1, X);
      Node *N;
      N = new Node;
      X->Next = N;
      N->Next = P;
      N->Elem = newNum;
      Count++;
  }
} // must use moveTo to move local pointers. Be sure to comment to which node you are moving them.


//PURPOSE:Constructor to allow pass by value and return by value of a llist
//PARAMETER: Provides a holder Original (pass by ref) to allow pass by value and return by value of a llist
llist::llist(const llist& Original) {
//  this->'s data members need to be initialized here first
Front = NULL;
Rear = NULL;
Count = 0;
//  this-> object has to be built up by allocating new cells
//  and copying the values from Original into each cell as we did with 
//  operator= above. To do this,
el_t x; 
  // First make sure this-> and OtherOne are not the same object.
  // To do this, compare the pointers to the objects .
     if (&Original != this) {  // if not the same
        // this-> object has to be emptied first.
        while (!this->isEmpty()) {
          this->deleteRear(x);  
        }
        // this-> object has to be built up by allocating new cells with OtherOne elements (**)
        Node* P;  // local pointer for OtherOne
        P = Original.Front;
        while (P != NULL) {  // a loop which repeats until you reach the end of OtherOne. 
           this->addRear(P->Elem);    //P’s element is added to this->
           P = P->Next;                         // Go to the next node in OtherOne   
        } 
      }// end of if              
} 
 

//PURPOSE: Overloading of = (returns a reference to a llist) 
//PARAMETER: Provides a holder OtherOne (pass by ref) ehcih returns a reference to a llist
llist& llist::operator=(const llist& OtherOne) { 
  // use my code
  el_t x; 
  // First make sure this-> and OtherOne are not the same object.
  // To do this, compare the pointers to the objects .
     if (&OtherOne != this) { // if not the same
        // this-> object has to be emptied first.
        while (!this->isEmpty()) {
          this->deleteRear(x);  
        }  
        // this-> object has to be built up by allocating new cells with OtherOne elements (**)
        Node* P;  // local pointer for OtherOne
        P = OtherOne.Front;
        while (P != NULL) { // a loop which repeats until you reach the end of OtherOne. 
           this->addRear(P->Elem);    //P’s element is added to this->
           P = P->Next;                         // Go to the next node in OtherOne   
        } 
      }// end of if              
     return *this;    // return the result unconditionally.  Note that the result is returned by reference.
} 
