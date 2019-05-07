/*
Specification file for the Question class.
This version has a constructor.

*/
#pragma once
#include <string>

using namespace std;

class Question
{
private:
    string quest;//
    string aryAnswer[4];
    int correctAnswer;
    string getquestion();
    string getanswer(int);
    void randomize();
    bool isAnswerCorrect(int);
    string getcorrectanswer();
public:
    Question(); //constructor
    void setquestion(string);
    void setanswer(int, string);
    bool play(string);
};

