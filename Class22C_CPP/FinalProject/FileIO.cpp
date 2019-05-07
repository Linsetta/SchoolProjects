/*
 * FileIO.cpp
 *
 *  Created on: Mar 9, 2018
 *
 */

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "FileIO.h"


using namespace std;

	static string infileName = "SavedUsers.txt";
	static string outfileName = "outputFile.txt";

	void FileIO::readFromFile(List<Users> *users, HashTable_I<Users> *interest, HashTable_N<Users> *name)
	{

		ifstream in (infileName);
		if (in.fail()){
			cout << "Fail to open the file" << endl;
			return;
		}
		while(!in.eof())
        {
            if(in.eof())
            break;
            string firstname,lastname,login,password,city,friends,interests;
            string id;
            int is;


            getline(in, id);
            is= atoi(id.c_str());

            cout << "ID is " << is << endl;
            getline(in, firstname);
            cout <<"FIRST name: "<< firstname<<endl;
            getline(in, lastname);
            cout <<"Last name: "<< lastname<<endl;
            getline(in, login);
            cout<<"Login: "<<login<<endl;
            getline(in, password);
            cout<<"password: "<<password<<endl;
            getline(in, city);
            cout<<"city: "<<city<<endl;

            BST<string> *t = new BST<string>();
            getline(in, friends);
            istringstream ss(friends);
            string f;
            while(getline(ss, f, ','))
            {
                cout << "Friend: "<<f << '\n';
                t->insert(f);
            }

            List<string> *inter = new List<string>();
            getline(in, interests);
            istringstream iss(interests);
            string i;
            while(getline(iss, i, ','))
            {
                cout << "Interests: "<<i << '\n';
                inter->insertLast(i);
            }
            cout<<endl<<endl;

            Users u (firstname, lastname,city, login, password, is,t,inter);

            interest->insert(u);
            name->insert(u);
            users->insertLast(u);
            cout << "------------" << endl;
        }
	}
	static void writeToFile(List<Users> *Users){

		}
