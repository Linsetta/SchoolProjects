/*
 * List.h
 *
 *  Created on: Feb 24, 2018
 *      Author: linsetta
 */
#ifndef LIST_H_
#define LIST_H_

#include <string>
#include <iostream>
#include <ostream>

#include <assert.h>
#include <cstddef> //for NULL
using namespace std;

template <class listdata>
class List {

private:
    struct Node {
        listdata data;
        Node*    next;
        Node*    prev;

        Node(listdata newData){
            data = newData;
            next = NULL;
            prev = NULL;
        }
    };

    Node* first;
    Node* last;
    Node* iterator;
    int length;

public:

    /**Constructors and Destructors*/

    // Default constructor; initializes and empty list
    // Return: new List
    // Precondition:
    // Postcondition: the list with length 0 must be created
    List();

    // Destructor. Frees memory allocated to the list
    // Return:
    // Precondition:
    // Postcondition: memory previously allocated to the list must be freed
    ~List();

    /**Accessors*/

    // Returns the first data in the list
    // Return: the first data in the list
    // Precondition: the list must not be empty
    // Postcondition: the returned value is the first data in the list
    listdata getFirst() const;

    // Returns the last data in the list
    // Return: the last data in the list
    // Precondition: the list must not be empty
    // Postcondition: the return value is the last data in the list
    listdata getLast() const;

    // Returns the last data in the list
    // Return: the last data in the list
    // Precondition: the list must not be empty
    // Postcondition: the return value is the last data in the list
    listdata getStop() const;

    // Determines true if the list is empty, false otherwise.
    // Return: true if the list is empty, false otherwise
    // Precondition:
    // Postcondition:
    bool isEmpty() const;

    // Returns the size of the list
    // Return: the size of the list
    // Precondition:
    // Postcondition:
    int getLength() const;

    /**Manipulation Procedures*/

    // Removes the value stored in first node in the list
    // Return:
    // Precondition: the list must not be empty
    // Postcondition: the first element must be a new value, the length of list must be decremented by 1. ??
    void removeFirst();

    // Removes the value stored in the last node in the list
    // Return:
    // Precondition:the list must not be empty ??
    // Postcondition:the last element must be a new value, the length of list must be decremented by 1. ??
    void removeLast();

    // Inserts a new data at the beginning of the list
    // If the list is empty, the new data becomes both first and last
    //
    // Return:
    // Precondition:
    //Postcondition:the beginning of the list must have a new value??
    void insertFirst (listdata data);

    // Inserts a new data at the end of the list
    // If the list is empty, the new data becomes both first and last
    //
    // Return:
    // Precondition:
    // Postcondition: at the end of the list must a new data
    void insertLast(listdata data);

    /**Additional List Operations*/

    // Prints to the console the value of each data in the list sequentially
    // and separated by a blank space
    // Prints nothing if the list is empty
    // Prints a empty newline character if it's empty..
    //
    // Return:
    // Precondition:
    // Postcondition:
    void printList(ostream& out);

    // Performs a shallow copy to create a new list.
    // Return: a new list that is equal to this list.
    // Precondition:
    // Postcondition: the returned list equals (==) the original list
    List copy();

    // Initializes the list's iterator to the first node in the list.
    // Return: void
    // Precondition: the list is not empty
    // Postcondition: the iterator is pointing to the first node in the list
    void startIterator();

    // Removes the node pointed at by the iterator.
    // Return: void
    // Precondition: the iterator is not off of the end of the list (!offEnd)
    // Postcondition: the list length is one less (--)
    void removeIterator();

    // Inserts a new node initialized with the given data as the next node after the iterator.
    // Return: void
    // Precondition: the iterator is not off of the end of the list (!offEnd)
    // Postcondition: the list length is one more (++)
    void insertIterator(listdata data);

    // Moves the iterator one node toward the end of the list.
    // Return: void
    // Precondition: the iterator is not off of the end of the list (!offEnd)
    // Postcondition: the iterator is pointing at the node that is the next node of the previous iterator pointer
    void advanceIterator();

    // Moves the iterator one node toward the beginning of the list.
    // Return: void
    // Precondition: the iterator is not off of the end of the list
    // Postcondition: the iterator is pointing at the node that is the previous (prev) node of the previous (in time) iterator pointer.
    void reverseIterator();

    // Returns the data stored in the node pointed to by the iterator.
    // Return: the data stored in the node pointed to by the iterator
    // Precondition: the list is not empty AND the iterator is not off of the end of the list
    // Postcondition: the returned value is the data stored in the node pointed to by the iterator
    listdata getIterator();

    // Returns true if the iterator is null, false otherwise.
    // Return: true if the iterator is null, false otherwise
    // Precondition:
    // Postcondition: the returned value is true if the iterator is null, false otherwise
    bool offEnd();

    // Prints a numbered list with each data printed on a separate line.
    // Return: void
    // Precondition:
    // Postcondition: the numbered list is printed
    void printNumberedList();

    // Returns true if the data in each list is equal (==).
    // Return: true if the data in each list is equal (==)
    // Precondition:
    // Postcondition:
    bool operator==(List list);

};

template <class listdata>
List<listdata>::List() {
    first = NULL;
    last = NULL;
    iterator = NULL;
    length = 0;
}

template <class listdata>
List<listdata>::~List()
{
    Node* b = first;
    Node* a = NULL; //a stands for "after" (i.e. after b)
    while (b != NULL)
    {
        a = b->next; //move a to node after b
        delete b; //remove b (you know it is not NULL from if)
        b = a; //b "catches up" with a (both point to same place in list)
    }
}

template <class listdata>
void List<listdata>::printList(ostream& out)
{
    Node* temp = first; //create a temporary iterator
    while (temp != NULL) {
    	out << temp->data << endl;
    	temp = temp->next;
    }
}

template <class listdata>
void List<listdata>::insertFirst(listdata data)
{
    Node* N = new Node(data);
    if (length == 0)
    {
        first = N;
        last = N;
    }
    else
    {
        N->next = first;
        first->prev = N;
        first = N;
    }
    length++;
}

template <class listdata>
void List<listdata>::insertLast(listdata data)
{
    Node* N = new Node(data);
    if (length == 0)
    {
        first = N;
        last  = N;
    }
    else
    {
    	N->prev    = last;
    	last->next = N;
    	last       = N;
    }
    length++;
}

template <class listdata>
void List<listdata>::removeFirst()
{
	assert(length != 0);
    if(first->next == NULL)
    {
        delete first;
        first = last = NULL;
        length = 0;
    }
    else
    {
        Node* temp = first;
        first = first->next;
        first->prev = NULL;
        delete temp;
        length--;
    }
}

template <class listdata>
void List<listdata>::removeLast() {
    assert(length != 0);
    if (length == 1) {
        first = last = NULL;
        delete first;
        length = 0;
    } else {
    	Node* temp = last;
    	last = last->prev;
    	last->next = NULL;
    	delete temp;
    	length--;
    }
}

template <class listdata>
bool List<listdata>::isEmpty() const
{
    return length == 0;
}

template <class listdata>
int List<listdata>::getLength() const {
	int count = 0;
	Node* temp = first;
	while(temp != 0) {
		count ++;
		temp = temp->next;
	}
	return count;
}

template <class listdata>
listdata List<listdata>::getFirst() const
{
	assert(length != 0);
    return first -> data;
}

// returns last element of list
template <class listdata>
listdata List<listdata>::getLast() const
{
	assert(length != 0);
    return last -> data;
}

// returns last element of list
template <class listdata>
listdata List<listdata>::getStop() const
{
	assert(length != 0);
    return last -> data;
}

template <class listdata>
List<listdata> List<listdata>::copy() {
	List<listdata> newList = new List<listdata>();
	Node* iter = first;
	while (iter != NULL) {
		newList.insertLast(iter->data);
		iter = iter->next;
	}
	return newList;
}

template <class listdata>
void List<listdata>::startIterator() {
	assert(length != 0);
	iterator = first;
}

template <class listdata>
void List<listdata>::removeIterator() {
	assert(iterator != NULL);
	if (iterator->prev == NULL && iterator->next == NULL) {
		Node* temp = iterator;
		first    = NULL;
		last     = NULL;
		iterator = NULL;
		delete iterator;
	} else if (iterator->prev == NULL) {
		Node* temp = iterator;
		first = first->next;
		first->prev = NULL;
		iterator = NULL;
		delete temp;
	} else if (iterator->next == NULL) {
		Node* temp = iterator;
		last = last->prev;
		last->next = NULL;
		iterator = NULL;
		delete temp;
	} else {
		Node* temp = iterator;
		iterator->prev->next = iterator->next;
		iterator->next->prev = iterator->prev;
		iterator = NULL;
		delete temp;
	}
}

template <class listdata>
void List<listdata>::insertIterator(listdata data) {
	assert(iterator != NULL);
	Node* node = new Node(data);
	if (iterator->next == NULL) {
		node->prev = last;
		last = node;
	} else {
		node->prev = iterator;
		node->next = iterator->next;
		iterator->next->prev = node;
		iterator->next = node;
	}
}

template <class listdata>
void List<listdata>::advanceIterator() {
	assert(iterator != NULL);
	iterator = iterator->next;
}

template <class listdata>
void List<listdata>::reverseIterator() {
	assert(iterator != NULL);
	iterator = iterator->prev;
}

template <class listdata>
listdata List<listdata>::getIterator() {
	assert(iterator != NULL);
	return iterator->data;
}

template <class listdata>
bool List<listdata>::offEnd() {
	return (iterator == NULL);
}

template <class listdata>
void List<listdata>::printNumberedList() {
	int index = 1;
	Node* iter = first;
	while (iter != NULL) {
		cout << "" << index << ". " << iter->data << endl;
		index ++;
		iter = iter->next;
	}
}

template <class listdata>
bool List<listdata>::operator==(List<listdata> list) {
	Node iter1 = first;
	Node iter2 = list->first;
	while (iter1 != NULL && iter2 != NULL) {
		if (iter1->data != iter2->data) {
			return false;
		}
		iter1 = iter1->next;
		iter2 = iter2->next;
	}
	if (iter1 != NULL || iter2 != NULL) {
		return false;
	}
	return true;
}

#endif /* LIST_H_ */
