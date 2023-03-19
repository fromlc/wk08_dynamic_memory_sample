//------------------------------------------------------------------------------
// Pr13-12.cpp : demos a class with a destructor
// 
// Author: Tony Gaddis, Gaddis 9E pp. 768-769
// Modified by: Prof. Linda C
//------------------------------------------------------------------------------
#include "Contact.h"


#define NDEBUG		// comment this line to disable asserts
#include <cassert>
#include <iostream>
#include <vector>

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::cout;
using std::string;
using std::vector;

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
void displayEntry(Contact*);

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

	string names[] = {
		"Kristen Lee",
		"Boo Radley",
		"George Bailey",
		"Baby Huey",
	};

	string phones[] = {
		"550-0000",
		"551-1111",
		"552-2222",
		"553-3333",
	};

	// determine how many contacts in entries array
	int nameCount = sizeof(names) / sizeof(string);
	int phoneCount = sizeof(phones) / sizeof(string);

	// number of names and number of phones must match
	assert(nameCount == phoneCount);

	// store addresses of dynamically allocated ContactInfo instances
	vector<Contact*> vPci;
	vPci.reserve(nameCount);

	// store contacts in vector
	for (int i = 0; i < nameCount; ++i) {

		// step down into C char buffers
		Contact* pEntry = new Contact(names[i].c_str(), phones[i].c_str());

		// store this entry's address
		vPci.push_back(pEntry);
	}

	// display the contacts with range-based for loop
	for (Contact* p : vPci) {

		cout << "Name: " << p->getName() << '\n';
		cout << "Phone: " << p->getPhone() << '\n';

		// release this Contact's memory
		delete p;

		cout << '\n';
	}

	return 0;
}