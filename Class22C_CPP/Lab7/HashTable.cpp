/*
 * HashTable.cpp
 *
 *  Created on: Feb 22, 2018
 *      Author: linsetta
 */

#include "HashTable.h"
#include "List.h"
#include "Book.h"
#include <iostream>
#include <assert.h>

int HashTable::hash(string key) const {
	int sum = 0;
	for (int i = 0; i < (int) key.length(); i++) {
		sum += key[i];
	}
	return sum % SIZE;
}

void HashTable::insert(Book b) {
	// cout << "HashTable.insert: here.\n";
	int hashValue = hash(b.get_title() + b.get_author());
	List<Book>* tableList = &(Table[hashValue]); // get correct bucket (List)
	tableList->insertLast(b); // insert Book into correct bucket (at the end of the List)
}

void HashTable::printBucket(ostream& out, int index) const {
	assert((0 <= index) && (index < SIZE));
	List<Book>* bucket = (List<Book>*) &(Table[index]);
	bucket->printList(out);
}

//counts the number of Books at this index
//returns the countcountBucket(index);

//pre: 0 <= index < SIZE
int HashTable::countBucket(int index) const {
	assert((0 <= index) && (index < SIZE));
	List<Book>* bucket = (List<Book>*) &(Table[index]);
	return bucket->getLength();
}

//Searches for b in the table
//returns the index at which b is located
//returns -1 if b is not in the table
int HashTable::search(Book b) const {
    string      key       = b.get_title() + b.get_author();
	int         hashValue = hash(key);
    List<Book>* list      = (List<Book>*) &(Table[hashValue]);
	if (list->isEmpty()) {
		return -1;
	}
    list->startIterator();
    while (! list->offEnd()) {
    	Book b = list->getIterator();
    	if (b.get_title() + b.get_author() == key) {
    		return hashValue;
    	}
    	list->advanceIterator();
    }
    return -1;
}

void HashTable::remove(Book b){
   //removes b from the table
   //calls the hash function on the key to determine
   //the correct bucket
   //pre: b is in the table
    string      key       = b.get_title() + b.get_author();
	int         hashValue = hash(key);
    List<Book>* list      = (List<Book>*) &(Table[hashValue]);
	if (list->isEmpty()) {
		return;
	}
    list->startIterator();
    while (! list->offEnd()) {
    	Book b = list->getIterator();
    	if (b.get_title() + b.get_author() == key) {
            list->removeIterator();
    		return;
    	}
    	list->advanceIterator();
    }
    return;



}
