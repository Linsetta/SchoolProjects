/*
 * Catalogue.cpp
 *
 *  Created on: Feb 22, 2018
 *      Author: linsetta
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstddef>
#include <assert.h>
#include "HashTable.h"
#include "BST.h"

using namespace std;

#define LAB7_PART3

#ifdef LAB7_PART3

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

int main(){

    HashTable ht;
    BST<Book> bst;

	string name, author, s;
	double price;
	int isbn;

	ifstream infile;

	infile.open("./catalogue.txt");

	if ( infile.fail())
    {
        cout << "\nPlease check the name of the input file and try again later!\n";
        exit(EXIT_FAILURE);
    }

   	while (!infile.eof()) // reading questions and answers using class methods.
	{
		getline(infile, name);
		getline(infile, author);
		infile >> price;
		getline(infile, s);
		infile >> isbn;
		getline(infile, s);
		getline(infile, s);

		Book c(name, author, price, isbn);
		bst.insert(c);
		ht.insert(c);
	}
	infile.close();

    cout<< "Welcome to the Best Reads App! \n";

    bool ex = false;

    do
    {
        cout << "\nWhat would you like to do? \n";
        cout << "1. Browse catalogue by title \n";
        cout << "2. Insert a new book \n";
        cout << "3. Remove a book \n";
        cout << "4. Search for a book \n";
        cout << "5. Quit \n\n";

        cout << "Enter your choice: ";
        cin >> s;

        if(!is_number(s)) {
            cout << "Please enter numbers not letters\n\n";
        }

        int option = atoi(s.c_str());

        switch(option) {
            case 1 :
                cout << "\nHere is an alphabetical list of the books in our catalogue:\n\n";
                bst.inOrderPrint(cout);
                break;
            case 2 :
                {
                    cout << "\nEnter the title: ";
                    getline(cin >> std::ws, name);
                    cout << "\nEnter the author: ";
                    getline(cin >> std::ws, author);
                    cout << "\nEnter the price: ";
                    cin >> price; getline(cin, s);
                    cout << "\nEnter the isbn: ";
                    cin >> isbn; getline(cin, s);
                    Book cc (name, author, price, isbn);
                    bst.insert(cc);
                    ht.insert(cc);
                    cout << "\n" << name << " has been added to the catalogue\n";
                }
                break;
            case 3 :
                {
                    cout << "\nEnter the title of the book to remove: ";
                    getline(cin >> std::ws, name);
                    cout << "Enter the author: ";
                    getline(cin >> std::ws, author);
                    Book cc(name, author, 0, 0);
                    ht.remove(cc);
                    bst.remove(cc);
                    cout << "\n" << name << " has been removed from the catalogue\n";
                }
                break;
            case 4 :
                {
                    cout << "\nEnter the title of the book: ";
                    getline(cin >> std::ws, name);
                    cout << "Enter the author: ";
                    getline(cin >> std::ws, author);
                    Book cc(name, author, 0, 0);
                    if (ht.search(cc)>=0)
                        cout << "\n" << name << " is in the catalogue\n";
                    else
                        cout << "\n" << name << " is not in the catalogue\n";
                }
                break;
            case 5 :
                {
                    ex = true;
                    ofstream outputFile;
                    outputFile.open("./catalogue2.txt");
                    bst.inOrderPrint(outputFile);
                    outputFile.close();
                    cout << "\n\nHappy reading!\n\n";
                }
                break;

            default:
                cout << "\nInvalid input.\n";
        }


    } while (!ex);

}



#endif // LAB7_PART3


