//------------------------------------------------------------------------------
// Contact.h : class declaration and definition
//------------------------------------------------------------------------------
#ifndef CONTACTINFO_H
#define CONTACTINFO_H

#include <iostream>
#include <string.h>		// strlen(), strcpy_s()

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::cout;

//------------------------------------------------------------------------------
// Contact
//------------------------------------------------------------------------------
class Contact {
private:
    char* pName;
    char* pPhone;

public:
    // Constructor
    Contact(const char* _pName, const char* _pPhone) {

        // count memory bytes needed
        rsize_t _nameLen = strlen(_pName) + 1;
        rsize_t _phoneLen = strlen(_pPhone) + 1;

        // allocate memory for name plus zero terminator
        pName = new char[_nameLen];
        // copy name to newly allocated memory
        strcpy_s(pName, _nameLen, _pName);

        // allocate enough memory for phone plus zero terminator
        pPhone = new char[_phoneLen];
        // copy number to newly allocated memory
        strcpy_s(pPhone, _phoneLen, _pPhone);
    }

    // Destructor
    ~Contact() {

        cout << "Destructor: " << pName << '\n';

        // memory was allocated with square bracket array syntax
        delete[] pName;
        delete[] pPhone;
    }

    // return pointer to contact name
    const char* getName() const { return pName; }

    // return pointer to contact phone
    const char* getPhone() const { return pPhone; }
};
#endif  // CONTACTINFO_H