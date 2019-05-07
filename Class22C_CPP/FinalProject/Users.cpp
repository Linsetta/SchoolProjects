#include "Users.h"
#include <iostream>
#include <iomanip>

Users::Users(){}
Users::Users(const Users &users)
{
    firstname = users.firstname;
    lastname = users.lastname;
    city = users.city;
    password = users.password;
    login = users.login;
    friends = users.friends;
    interests = users.interests;
    ido = users.ido;
}

Users::Users(string fn, string ln, string c, string log, string pw, int id, BST<string> *f, List<string> *i) {
    firstname = fn;
    lastname = ln;
    city = c;
    password = pw;
    login = log;
    ido = id;
    friends = f;
    interests = i;
}

/**Access Functions*/


string Users::get_first_name() {
    return firstname;
}

string Users::get_last_name() {
    return lastname;
}

string Users::get_city() {
    return city;
}

string Users::get_login() {
    return login;
}

string Users::get_password() {
    return password;
}
int Users::get_id()
{
    return ido;
}


/**Manipulation Procedures*/
void Users::set_id(int id)
{
    ido = id;
}

void Users::set_first_name(string fn){
    firstname = fn;
}

void Users::set_last_name(string ln) {
    lastname = ln;
}

void Users::set_city(string c){
    city = c;
}

void Users::set_login(string log){
    login = log;
}
void Users::set_password(string pw) {
    password = pw ;
}

/**Additional Functions*/


bool Users::operator==(const Users& users)
{
    return (firstname== users.firstname && lastname == users.lastname);
}
ostream& operator<<(ostream& os, const Users& users){
    os << "ID: " << users.ido << endl;
    os << "first name: "<<users.firstname<< endl;
    os << "last name: " <<users.lastname << endl;
    os << "Login: " << users.login<< endl;
    os << "Password: "<<users.password << endl;
    os << "City: " << users.city << endl;
    os << "list of friends: " << endl;
    users.friends->inOrderPrint(os);
    os << endl; // added by nina
    os << "list of interests: ";
    users.interests->printList(os);
    os << endl; // added by nina
    return os;
    
}
bool Users::operator>(const Users& users)
{
    bool status;
    if(firstname[0] > users.firstname[0])
        status = true;
    else if (firstname == users.firstname && lastname[0] > users.lastname[0])
        status = true;
    else
        status = false;
    return status;
}

bool Users::operator <(const Users& users)
{
    bool status;
    if(firstname[0] < users.firstname[0])
        status = true;
    else if(firstname == users.firstname && lastname[0] < users.lastname[0])
        status = true;
    else
        status = false;
    return status;
}

void Users::add_bst(Users user)
{
    friends->insert(user.get_first_name() + " " + user.get_last_name());
}

void Users::add_interest(string interest)
{
    //interests->insertLast(interest);
}

bool Users::searchBst(Users user)
{
    if(friends->search(user.get_first_name()+ " " +user.get_last_name()))
        return true;
    
    return false;
}

void Users::remove_bst(Users user)
{
    //friends->remove(user);
}





/*#include "Users.h"
 #include <iostream>
 #include <iomanip>
 
 
 Users::Users(string fn, string ln, string c, string log, string pw, BST<string> *f, List<string> i) {
 firstname = fn;
 lastname = ln;
 city = c;
 password = pw;
 login = log;
 friends = f;
 interests = i;
 }
 
 
 string Users::get_first_name() {
 return firstname;
 }
 
 string Users::get_last_name() {
 return lastname;
 }
 
 string Users::get_city() {
 return city;
 }
 
 string Users::get_login() {
 return login;
 }
 
 string Users::get_password() {
 return password;
 }
 
 */
List<string> Users::get_listofinterest()
{
    List<string> listofinterest;
    interests->startIterator();
    while (! interests->offend())
    {
        string interest = interests->getIterator();
        listofinterest.insertLast(interest);
        interests->advanceIterator();
    }
    return listofinterest;
}

BST<string> Users::get_listoffriends()
{
    BST<string> listfriends(*friends);
    return listfriends;
    
}
/*
 
 
 
 void Users::set_first_name(string fn){
 firstname = fn;
 }
 
 void Users::set_last_name(string ln) {
 lastname = ln;
 }
 
 void Users::set_city(string c){
 city = c;
 }
 
 void Users::set_login(string log){
 login = log;
 }
 void Users::set_password(string pw) {
 password = pw ;
 }
 
 void Users::set_interests(List<string>i) {
 //interests(i);
 
 i.startIterator();
 while(!i.offend())
 {    interests.insertLast(i.getIterator());
 i.advanceIterator();
 }
 
 }
 
 
 
 bool Users::operator==(const Users& users) {
 return (firstname== users.firstname && lastname == users.lastname);
 }
 ostream& operator<<(ostream& os, const Users& users){
 os << "first name: "<<users.firstname<< endl;
 os << "last name: " <<users.lastname << endl;
 os << "Login: " << users.login<< endl;
 os << "Password: "<<users.password << endl;
 os << "City: " << users.city << endl;
 os << "list of friends: ";
 users.friends->inOrderPrint(os);
 os << "list of interests: ";
 users.interests.printList(os);
 return os;
 
 }
 bool Users::operator>(const Users& users){
 bool status;
 if(firstname[0] > users.firstname[0])
 status = true;
 else if (firstname == users.firstname && lastname[0] > users.lastname[0])
 status = true;
 else
 status = false;
 return status;
 }
 
 bool Users::operator <(const Users& users){
 bool status;
 if(firstname[0] < users.firstname[0])
 status = true;
 else if(firstname == users.firstname && lastname[0] < users.lastname[0])
 status = true;
 else
 status = false;
 return status;
 }
 
 void Users::add_bst(Users user){
 //friends->insert(user);
 }
 
 void Users::add_interest(string interest){
 //interests->insertLast(interest);
 }
 
 bool Users::searchBst(Users user){
 //return friends->search(user);
 return false;
 }
 
 void Users::remove_bst(Users user){
 //friends->remove(user);
 }
 
 
 
 
 
 
 
 
 
 
 //get_listOfInterests? needed for Hash_interest insert function
 //Users(string fn, string ln, string c, string log, string pw) only read 5 parametters?
 
 //have to use the app as one of the people in the Users.txt file. since we need the person's friendlist and interests to recommend friends.
 //=> have to type name and have a function to find the person who's using the app
 //open the person profile to add or remove
 
 #include "Users.h"
 #include <iostream>
 #include <iomanip>
 #include<string>
 #include <ostream>
 #include "List.h"
 #include "BST.h"
 
 Users::Users(string fn, string ln, string c, string log, string pw,BST<Users>f, List<string>i) {
 firstname = fn;
 lastname = ln;
 city = c;
 password = pw;
 login = log;
 friends=f;
 interests=i;
 }
 
 
 
 string Users::get_first_name() {
 return firstname;
 }
 
 string Users::get_last_name() {
 return lastname;
 }
 
 string Users::get_city() {
 return city;
 }
 
 string Users::get_login() {
 return login;
 }
 
 string Users::get_password() {
 return password;
 }
 
 List<string>Users::get_listofinterest()
 {
 return interests;
 }
 
 BST<Users> Users::get_friends()
 {
 return friends;
 
 }
 
 
 void Users::set_first_name(string fn){
 firstname = fn;
 }
 
 void Users::set_last_name(string ln) {
 lastname = ln;
 }
 
 void Users::set_city(string c){
 city = c;
 }
 
 void Users::set_login(string log){
 login = log;
 }
 void Users::set_password(string pw) {
 password = pw ;
 }
 
 void Users::set_interests(List<string>i) {
 //interests(i);
 
 i.startIterator();
 while(!i.offend())
 {    interests.insertLast(i.getIterator());
 i.advanceIterator();
 }
 
 }
 
 void Users::set_friends(BST<Users>f)
 {
 friends.copyNode(f);
 }
 
 
 
 
 bool Users::operator==(const Users& users) {
 return (firstname== users.firstname && lastname == users.lastname);
 }
 ostream& operator<<(ostream& os, const Users& users){
 os << "first name: "<<users.firstname<< endl;
 os << "last name: " <<users.lastname << endl;
 os << "Login: " << users.login<< endl;
 os << "Password: "<<users.password << endl;
 os << "City: " << users.city << endl;
 os << "list of friends: ";
 users.friends.inOrderPrint(os);
 os << "list of interests: ";
 users.interests.printList(os);
 return os;
 
 }
 bool Users::operator>(const Users& users){
 bool status;
 if(firstname[0] > users.firstname[0])
 status = true;
 else if (firstname == users.firstname && lastname[0] > users.lastname[0])
 status = true;
 else
 status = false;
 return status;
 }
 
 bool Users::operator <(const Users& users){
 bool status;
 if(firstname[0] < users.firstname[0])
 status = true;
 else if(firstname == users.firstname && lastname[0] < users.lastname[0])
 status = true;
 else
 status = false;
 return status;
 }
 
 void Users::add_bst(Users user){
 friends.insert(user);
 }
 
 void Users::add_interest(string interest){
 interests.insertLast(interest);
 }
 
 bool Users::searchBst(Users user){
 return friends.search(user);
 }
 
 void Users::remove_bst(Users user){
 friends.remove(user);
 }
 
 */

