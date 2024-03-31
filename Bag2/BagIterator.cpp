#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c) : bag(c)
{
	this->currentPosition = 0;
}

void BagIterator::first() {
	this->currentPosition = 0;
}


void BagIterator::next() {
	if (this->currentPosition >= this->bag.bagSize) {
		throw exception();
	}
	this->currentPosition++;
}


bool BagIterator::valid() const {
	return this->currentPosition < this->bag.bagSize;
}


TElem BagIterator::getCurrent() const
{
	// cheatGPT ... but why?
	//if (!valid()) {
    //    return NULL_TELEM;
	//}
    if (this->currentPosition >= this->bag.bagSize){
        throw exception();
    }
    return this->bag.elements[this->currentPosition];
}
