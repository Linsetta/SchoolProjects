/*
 * HashTest.cpp
 *
 *  Created on: Feb 24, 2018
 *      Author: linsetta
 */

#include <iostream>
#include <cstddef>
#include <assert.h>
#include "HashTable.h"

using namespace std;

//#define LAB7_PART2

#ifdef LAB7_PART2

int main() {
	Book pp("Pride and Prejudice", "Jane Austen", 4.95, 1234567);
	Book c("Contact", "Carl Sagan", 9.95, 99993339);
	Book hg("The Hunger Games", "Suzanne Collins", 13.55, 12388888);
	Book hp("Harry Potter", "J.K. Rowlings", 12.99, 55555678);
	Book mhc("The Man in the High Castle", "Philip K Dick", 15.95, 95959595);
	Book bh("Bleak House", "Charles Dickens", 8.00, 473890238);

	cout << "Testing Book Overloaded Operators: <, >, and <<:\n";

	bool less_than_result = (hg < c);
	if (less_than_result) {
		cout << "Failure!  hg is less than c!\n";
	} else {
		cout << "Success!  hg is not less than c!\n";
	}

	bool greater_than_result = (hg > c);
	if (greater_than_result) {
		cout << "Success!  hg is greater than c!\n";
	} else {
		cout << "Failure!  hg is not greater than c!\n";
	}

	cout << "Testing << operator for Book:\n";
	cout << hg;

	cout << "Testing HashTable Functions:\n";

	cout << "Testing HashTable constructor:\n";
	HashTable ht;

	cout << "Testing HashTable.hash:\n";
	int hashValue1 = ht.hash("");
	cout << "hash() = " << hashValue1;
	if (hashValue1 == 0) {
		cout << "  Success!\n";
	} else {
		cout << "  Failure!\n";
	}

	int hashValue2 = ht.hash("a");
	cout << "hash(a) = " << hashValue2;
	if (hashValue2 == 7) {
		cout << "  Success!\n";
	} else {
		cout << "  Failure!\n";
	}

	int hashValue3 = ht.hash(pp.get_title() + pp.get_author());
	cout << "hash(" + pp.get_title() + pp.get_author() + ") = " << hashValue3;
	if (hashValue3 == 2) {
		cout << "  Success!\n";
	} else {
		cout << "  Failure!\n";
	}

	cout << "Testing HashTable.insert:\n";
	ht.insert(pp);
	ht.insert(c);
	ht.insert(hg);
	ht.insert(mhc);
	ht.insert(bh);
	for (int i = 0; i < 10; i++) {
		cout << "Testing HashTable.printBucket(" << i << "):\n";
		ht.printBucket(cout, i);
	}

	cout << "Testing countBucket \n";
	for (int i = 0; i < 10; i++) {
		cout << "Testing HashTable.countBucket (" << i << ")" << " has "
				<< ht.countBucket(i) << " book(s)\n";
	}

	cout << "Testing delete \n";
	ht.remove(pp);

	cout << "Testing search\n";
	int searchResult     = ht.search(pp);
	int searchFoundValue = ht.hash(pp.get_title() + pp.get_author());
	cout << "searchResult = " << searchResult << endl;
	cout << "searchFoundValue = " << searchFoundValue << endl;
	if (searchResult == searchFoundValue) {
		cout << "Failure!  Book should not be found in table.\n";
	} else {
	    cout << "Success!  Book is correctly not in the table.\n";
	}

	return 0;
}

#endif // LAB7_PART2
