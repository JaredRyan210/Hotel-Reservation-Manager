// CS311 Yoshii S22 - hw8client.cpp
//   ** should be completed!!!
//
// Note that the client knows about elem.h functions.
// It can create el_t objects.
// Note that el_t X; will create a blank element X using the regular constructor.  
// Note that the second constructor of el_t can be used to
// create key+other info to add to the table. e.g. el_t X(30, "mary"...);
// NEVER delete my comments!!
//-----------------------------------------------

//============================================
// HW#: HW8 hashing client
// Name: Jared Ryan
// File type: client hw8client.cpp (tester)
//===========================================

using namespace std;
#include "htable.h"
#include <iostream>
#include <fstream>
#include <string>

/*
After some thinking about what I wanted this app to be focused around, I thought of using it
as a tool for my current workplace. I work for a Hyatt hotel here in Carlsbad. Hyatt is a massive hospitality corperation
with hundreds of properties all aroud the world. Each property, like mine, has hundreds of employees with
with a large selection of departments and positions. Though on a much smaller scale, this app poses
as a tool giving the user the ability to view, search, add, or delete employees based off of their assigned key. 
The stored data includes the employees key, last name, department, and their golbal ID, which Hyatts actually use to identify
their employess. **DISCLAIMER: THE GLOBAL ID'S ARE NOT REAL ID'S. THEY ARE JUST EXAMPLES**
*/ 


int main()
{ 
  // cout an explanation of what this App should be used for. 
  cout << "After some thinking about what I wanted this app to be focused around, I thought of using it" << endl;
  cout << "as a tool for my current workplace. I work for a Hyatt hotel here in Carlsbad. Hyatt is a massive hospitality corperation" << endl;
  cout << "with hundreds of properties all aroud the world. Each property, like mine, has hundreds of employees with" << endl;
  cout << "with a large selection of departments and positions. Though on a much smaller scale, this app poses" << endl;
  cout << "as a tool giving the user the ability to view, search, add, or delete employees based off of their assigned key." << endl;
  cout << "The stored data includes the employees key, last name, department, and their golbal ID, which Hyatts actually use to identify" << endl;
  cout << "their employess. **DISCLAIMER: THE GLOBAL ID'S ARE NOT REAL ID'S. THEY ARE JUST EXAMPLES**\n\n";

  htable HT;
  string fname; // file name - decided to get the file name here
            // in the client in case the way I get them is application dependent

  cout << "What is the input file? (.txt file)";
  cin >> fname;
  
  ifstream fin (fname.c_str(), ios::in);
  HT.fillTable(fin);
  // make sure some of elements collide. 
  cout << "\tKEY | LAST NAME | DEPARTMENT | GLOBAL ID" << endl;
  HT.displayTable();
  cout << endl;

  // this is the output file - newout.txt
  ofstream fout ("newout.txt", ios::out);  

  int selection;
  do {

  cout << "MENU: ---- " << endl; 
  cout << "1 Add an element" << endl; 
  cout << "2 Find an element" << endl;
  cout << "3 Delete an element" << endl;
  cout << "4 Display the table" << endl;
  cout << "5 Save the table to a file" << endl;    
  cout << "6 Quit" << endl;
  cout << "Enter your selection here: ";
  cin >> selection;

      int thekey;
      string lastName;
      string department;
      int globalID;
      el_t theelement;
      int s;

    switch (selection) {

    case 1:  // Add and indicate slot
      cout << "What is the key to add?" << endl;
      cin >> thekey;
      cout << "What is the last name?" << endl;
      cin >> lastName;
      //** //  Here get two more pieces of info
      cout << "What is the department name? (if two words, seperate with '_')" << endl;
      cin >> department;
      cout << "What is the 7-digit Global ID number?" << endl;
      cin >> globalID;
      //  Create the element with all the info using the 2nd constructor
	theelement = el_t(thekey, lastName, department, globalID);
      s = HT.add(theelement);
      cout << "Added the element in slot " << s << endl;
      break;

    case 2: // Find and indicate element
      cout << "What is the key to find? ";
      cin >> thekey;
      theelement =  HT.find(thekey); // find based on thekey
      cout << "Found this:" << endl;
      cout << theelement << endl;
      break;      

    case 3: // Delete and indicate slot
      cout << "What is the key to find? ";
      cin >> thekey;
      s  =  HT.deleteIt(thekey); // find and delete it based on thekey
      if (s == -1) cout << "Not found!" << endl; else
      cout << "Found it and deleted it from slot:" << s << endl;
      break;      

    case 4: // Display
      cout << "The current contents are: " << endl;
      cout << "\tKEY | LAST NAME | DEPARTMENT | GLOBAL ID" << endl;
      HT.displayTable();
      break;

    case 5: // Save in the same format as input file
      HT.saveTable(fout);
      cout << "Saved the updated table in newout.txt" << endl;
      break;

    default:
      cout << "bye" << endl;
    }
  }
  while (selection != 6);
  fin.close();
  fout.close();
 }
