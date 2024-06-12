// CS311 Yoshii S22 slist.cpp
// Complete all functions with their comments
// NEVER delete my comments!!
// ====================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: Jared Ryan
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"slist.h" 


// ** Make sure llist constructor and destructors have couts in them


// do not change this one
slist::slist() {
  //cout << "slist constructor:" << endl;
}



el_t slist::search2(el_t X) {
  el_t M; // blank
  //X has only the ID part set.
  //In the slist look for matching el_t in Elem (the same code as search)
  //Return the el_t obj or if not found
  //return a blank object M
  Node* ptr;
  ptr = llist::Front;
  while (ptr != NULL) {
    if (ptr->Elem == X) {
      return ptr->Elem;
    }
    ptr = ptr->Next;
  }
  return M;
}


int slist::search(el_t key) {
  Node *P;        //initialize Node P to the front of the list
  P = llist::Front;
  int pos = 1; // positions always start at 1
  while (P != NULL) { //loop through list to see if any node contains the key
    if (P->Elem == key) { //If node contains key, 
      return pos; // return the position of the node
    }
    P = P->Next; //Continue down the list and running loop again
    pos++; //incrament position
  }
  return 0; // key is not in any node 
}

// don't forget to throw OutOfRange for bad pos 
// You must use moveTo to go to the pos
void slist::replace(el_t element, int pos){
  if (pos < 1 || pos > Count) { //if pos is an illegal value, 
    throw OutOfRange();     //throw out of range error
  } else {    //if pos is not illegal
      Node *P;
      llist::moveTo(pos, P); //use moveTo function from llist to go to the correct node
      P->Elem = element; //replace the value in P with the new value element
  }
}

// if not the same length, return false immediately
// if the same lengths,
//check each node to see if the elements are the same
bool slist::operator==(const slist& OtherOne) {
  if (this->Count != OtherOne.Count) { //If this->Count and OtherOne.Count are not the same,
  return false;       //return false
  } else {          //if both count are the same,
    Node *P = this->Front; //initialze P for original list
    Node *Q =OtherOne.Front; //initialize Q for OtherOne list
    for (int i = 0; i < Count; i++) { // Loop through the list count times
      if (P->Elem != Q->Elem) { //comapare elem in P against elem in Q.
        return false;           //if they dont match, return false
      } else {            //if they do match,
          P = P->Next;   //let P move to the next node 
          Q = Q->Next;   //let Q move to the next node
      } 
    }
  }
return true;  //if the two lists match, return true
}
