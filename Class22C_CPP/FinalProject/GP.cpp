#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <ctype.h>

#include <algorithm>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

#include "Users.h"
#include "BST.h"
#include "List.h"
#include "Hash_name.h"
#include "Hash_interest.h"
#include "FileIO.h"

using namespace std;

void printMenu(Users& currentUser)
{
	//cout << "Hi, " << currentUser.get_first_name() << "!" << endl;
	cout << endl;
	cout << "1. List all Users" << endl;
	cout << "2. Search by name" << endl;
	cout << "3. Search by interest" << endl;
	cout << "4. Quit" << endl;
	cout << endl;
	cout << "Enter your choice: ";
    
    
}

void interactWithUser(Users&currentUser,List<Users>&allUser,HashTable_I<Users>& HI,HashTable_N<Users>& HN)
{

	string choice;
	bool quit = false;
	while (! quit) {
		printMenu(currentUser);

		cin >> choice;
		while (!isdigit(choice[0])) {
			cout << "\n\nPlease enter numbers not letters\n" << endl;
			printMenu(currentUser);
			cin >> choice;
		}
		int num = stoi(choice);
		while (!(0 < num) || !(num < 6)) {
			cout << "\n\nInvalid input.\n" << endl;
			printMenu(currentUser);
			cin >> num;
		}
		if (num == 4) {
			ofstream out;
			out.open("User2.txt");
			//bst.inOrderPrint(cout);
			break;
		}

		switch (num) {
		case 1: { // Print all users
			cout << "\nUser List:" << endl << endl;
			//bst.inOrderPrint(cout);
			allUser.printList(std::cout);
			break;
		}
		case 2: { // search by name
			string fn, ln;
			cout << "Enter the first name of the User: ";
			cin >> fn;
			cout << "Enter the last name of the User: ";
			cin >> ln;
			transform(fn.begin(), fn.end(), fn.begin(), ::tolower);
			transform(ln.begin(), ln.end(), ln.begin(), ::tolower);

			int index = HN.hash(fn + ln);

			if (HN.countBucket(index) == 0) {
				cout << fn << " is not a User of Marvel Book" << endl;
			} else {
				List<Users> usersWithName;
				cout << endl << " This's a list of users whose name is " << fn
					 << " " << ln << endl << endl;
				List<Users>& bucket = (List<Users>&)HN.getBucket(index);
				bucket.startIterator();
				int count = 1;
				while (! bucket.offend()) {
					Users user = (Users)bucket.getIterator();
					// check actual lowercase names are correct to avoid hash collisions
					string user_fn = user.get_first_name();
					string user_ln = user.get_last_name();
					transform(user_fn.begin(), user_fn.end(), user_fn.begin(), ::tolower);
					transform(user_ln.begin(), user_ln.end(), user_ln.begin(), ::tolower);
					//cout << "fn = '" << fn << "'" << endl;
					//cout << "ln = '" << ln << "'" << endl;
					//cout << "user_fn = '" << user_fn << "'" << endl;
					//cout << "user_ln = '" << user_ln << "'" << endl;

					if (fn == user_fn && ln == user_ln) {
						cout << count << "." << endl << user << endl;
						usersWithName.insertLast(user);
						count ++;
					}
					bucket.advanceIterator();
				}
				if (! usersWithName.isEmpty()) {
					char choice;

					cout << "Would you like to add a user from the searched list? Enter Y or N: ";

					cin >> choice;
					if (choice == 'Y' || choice == 'y') {
						cout << endl << "Choose number of user listed to add: ";
						int numU;

						cin >> numU;
						int index = 0;
						Users userToAdd;
						usersWithName.startIterator();
						while (index < numU && ! usersWithName.offend()) {
							Users user = usersWithName.getIterator();
							if (index == numU - 1) {
								userToAdd = user;
								break;
							}
							usersWithName.advanceIterator();
						}

						cout << "The user to be added is: " << endl << endl << userToAdd << endl;
						// add user to currentUsers' friends
						currentUser.add_bst(userToAdd);
                      cout << boolalpha <<   currentUser.searchBst(userToAdd);
						cout << endl << "OK, " << userToAdd.get_first_name()
						     << " added to your friends, " << currentUser.get_first_name()
							 << "." << endl;
					} else {
						cout << endl << "OK" << endl;
					}
				}
			}
			break;
		}
		case 3: { // search by interest
			const int interest_count = 18;
			string possibleInterests[interest_count] = {
				"Technology",
				"Money",
				"Fighting Evil",
				"Working out",
				"Old movies",
				"Studies",
				"Food",
				"Combat",
				"Biology",
				"Street fighting",
				"Hammer",
				"Stealing",
				"Tricks",
				"Physics",
				"Photography",
				"Pranks",
				"Killing",
				"Fashion Design"
			};

			cout << "*** All Possible Marvel Book Interests ***" << endl;
			for (int i = 0; i < interest_count; i++) {
				cout << "  " << i + 1 << ". " << possibleInterests[i] << endl;
			}
			cout << "******************************************" << endl;

			int num;
			cout << "Please choose an interest to search for (1 -- " << interest_count << "): ";
			cin >> num;
			while (cin.fail() || num <= 0 || num > 18) {
                cin.clear();
                cin.ignore(1000, '\n');
				cout << "Invalid input.  Please enter a number (1 -- " << interest_count << "): ";
				cin >> num;
			}
			string searchInterest = possibleInterests[num - 1];
			cout << "OK, searching for users with " << searchInterest << " as an interest." << endl;
			int inde = HI.hash(searchInterest);
			if (HI.countBucket(inde) == 0) {
				cout << "No User matched" << endl << endl;
			} else {
				cout << endl
				     << "This is a list of users with interest as searched"
					 << endl << endl;

				List<Users>& bucket = HI.getBucket(inde);
				List<Users> usersWithInterest;
				int count = 1;
				bucket.startIterator();
				while (! bucket.offend()) {
					Users        user            = bucket.getIterator();
					bool         userHasInterest = false;
					List<string> userInterests   = user.get_listofinterest();
					userInterests.startIterator();
					while (! userInterests.offend()) {
						string userInterest = userInterests.getIterator();
						if (userInterest == searchInterest) {
							userHasInterest = true;
							break;
						}
						userInterests.advanceIterator();
					}
					if (userHasInterest) {
						cout << count << "." << endl;
						cout << user << endl;
						usersWithInterest.insertLast(user);
						count ++;
					}
					bucket.advanceIterator();
				}

				if (! usersWithInterest.isEmpty()) {
					char choice;
					cout << endl
							<< "Would you like to add a user from the searched list? Enter Y or N : ";

					cin >> choice;
					if (choice == 'Y' || choice == 'y') {
						cout << endl << "Chose number of user listed to add: ";
						int numU;
						cin >> numU;

						//HI->UserToAdd(index,numU);//user to be added

						//to test UserToAdd
						Users userToAdd;
						bool foundUser = false;
						int count = 1;
						usersWithInterest.startIterator();
						while (! usersWithInterest.offend()) {
							Users user = usersWithInterest.getIterator();
							if (count == numU) {
								userToAdd = user;
								foundUser = true;
								break;
							}
							count ++;
							usersWithInterest.advanceIterator();
						}
						if (! foundUser) {
							cout << "Could not find user" << endl;
						} else {
							cout << "The user to be added is: " << endl;
							cout << userToAdd << endl;
							// add user to currentUsers' friends
							currentUser.add_bst(userToAdd);
                           
                            
							cout << endl << "OK, " << userToAdd.get_first_name()
							     << " added to your friends, " << currentUser.get_first_name()
								 << "." << endl;
						}
					}
				}
			}
			break; // switch
		}
                
           
		case 4:
			quit = true;
			break;
		}
	}
	cout << "Bye " << currentUser.get_first_name() << "!" << endl;
}

int main()
{
	HashTable_I<Users>* HI      = new HashTable_I<Users>();
	HashTable_N<Users>* HN      = new HashTable_N<Users>();
	List<Users>*  allUser = new List<Users>();

	FileIO::readFromFile(allUser, HI, HN);
    int id;

	allUser->startIterator();
    cout << "Enter your ID: ";
    cin >> id;
    for(int i =1; i < id; i++)
    {
        allUser->advanceIterator();
    }
	Users currentUser = allUser->getIterator(); // assume current user is first for testing for now.
    cout << "Hi, " << currentUser.get_first_name() << "!" << endl;
	//cout << endl << "Assuming current user is:" << endl << endl << currentUser << endl;
    BST<string> li = currentUser.get_listoffriends();
   // li.inOrderPrint(cout);
    string c= li.getRoot();
    transform(c.begin(), c.end(), c.begin(), ::tolower);
    
    
    

	interactWithUser(currentUser, *allUser, *HI, *HN);
	return 0;
}

