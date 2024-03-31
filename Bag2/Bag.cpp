#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {
	// how do you turn this thing on
	//if (arrayCapacity <= 0) {
	//	throw exception();
	//}
    
	this->arrayCapacity = 1; // ?? seems to be ok :)
	this->bagSize = 0;
	this->elements = new TElem[arrayCapacity];
}


void Bag::add(TElem elem) {

	// Resize
	if (this->bagSize == this->arrayCapacity) {
		this->arrayCapacity *= 2;
		TElem* newArray = new TElem[this->arrayCapacity];
		for (int i = 0; i < this->bagSize; i++) {
			newArray[i] = this->elements[i];
		}
		delete[] this->elements;
		this->elements = newArray;
	}

	// Insert elem 
	this->elements[this->bagSize] = elem; //this has a warning of buffer overrun, don't understand this yet
	this->bagSize++;
}


bool Bag::remove(TElem elem) {
	//TODO - Implementation
    // take last element and switch with found element and decrement bag --
    int index = 0;
    while (index < this->bagSize) {
        if (this->elements[index] == elem) {
            this->elements[index] = this->elements[bagSize - 1]; // is [index-1] last element in the bag?
			this->bagSize--;
			return true;
		}
		index++;
    }   
    //downsize if half of the array is empty
    //if (this->bagSize < this->arrayCapacity/2) {
         //TO DO (similar to add but reverse-ish)
    //    }
	return false; 
}


bool Bag::search(TElem elem) const {
	int index = 0;
	while (index < this->bagSize) {
		if (this->elements[index] == elem) {
			return true;
		}
		index++;
	}
  	return false;
}

int Bag::nrOccurrences(TElem elem) const {
	int count = 0;
	int index = 0;
	while (index < this->bagSize) {
		if (this->elements[index] == elem) {
			count += 1;
		}
		index++;
	}
	return count;
}


int Bag::size() const {
	return this->bagSize;
}


bool Bag::isEmpty() const {
	return this->bagSize == 0;
}


BagIterator Bag::iterator() const {
	return BagIterator(*this);
}


Bag::~Bag() {
	delete[] this->elements; 
}

