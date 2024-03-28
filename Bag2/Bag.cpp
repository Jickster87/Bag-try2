#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {
	// how do you turn this thing on :)) 

	//if (arrayCapacity <= 0) {
	//	throw exception();
	//}
	this->arrayCapacity = arrayCapacity;
	this->bagSize = 0;
	this->elements = new TElem[arrayCapacity];
}


void Bag::add(TElem elem) {

	//resize
	if (this->bagSize == this->arrayCapacity) {
		this->arrayCapacity *= 2;
		TElem* newArray = new TElem[this->arrayCapacity];

		int index = 0;
		while (index < this->bagSize) {
			newArray[index] = this->elements[index];
			index++;
		}

		delete this->elements; // delete inside array, but not array itself??
		this->elements = newArray;
	}

	//search elem

	int index = 0;
	int occurrence = 0; // not sure this is right, which occurrence am I incrementing?
	while (index < this->bagSize) {
		if (this->elements[index] == elem) {
			occurrence += 1;
		}
		index++;
	}

	//insert elem
	//TO DO 


	this->bagSize++;
}


bool Bag::remove(TElem elem) {
	//TODO - Implementation
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
	int nrOccurrences = 0;
	int index = 0;
	while (index < this->bagSize) {
		if (this->elements[index] == elem) {
			nrOccurrences += 1;
		}
		index++;
	}
	return nrOccurrences; 
}


int Bag::size() const {
	int totalOccurrences = 0;
	int index = 0;
	while (index < this->bagSize) {
		totalOccurrences += this->elements[index];
		index++;
	}
	return totalOccurrences;
}


bool Bag::isEmpty() const {
	return this->bagSize == 0;
}


BagIterator Bag::iterator() const {
	return BagIterator(*this);
}


Bag::~Bag() {
	delete[] this->elements; //does this delete all arrays inside??
}

