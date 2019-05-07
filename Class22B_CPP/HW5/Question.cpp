/*
Implementation file for the Question class.
This version has a constructor.

*/

#include "Question.h"
#include <string>
#include <ctime>
#include <iostream>
#include <cstdlib>

using namespace std;

Question::Question()// constructor
{
    correctAnswer = 0; //  set the first answer as a correct answer
}

void Question::setquestion(string c) // set question string
{
    quest = c.substr(0);
}

void Question::setanswer(int i, string c) // set answer string with index i.
{
    if (i < 4)
    {
        aryAnswer[i] = c.substr(0);
        i++;
    }
}

string Question::getquestion() // return question
{
    return quest;
}

string Question::getanswer(int k)// return answer
{
    return aryAnswer[k];
}

bool Question::isAnswerCorrect(int i) // checking if i is a correct answer/
{
    return i == correctAnswer; //true if answer is correct, false otherwise
}

string Question::getcorrectanswer()
{
    return aryAnswer[correctAnswer]; //return a value of correct answer
}

void Question::randomize() // shaftle of the answers and remember the new index of the correct answer
{
    for (int k = 1; k < 100; k++)
    {
        int randNum1 = (rand() % 4);
        int randNum2 = (rand() % 4);
        string temp;
        temp = aryAnswer[randNum1];
        aryAnswer[randNum1] = aryAnswer[randNum2];
        aryAnswer[randNum2] = temp;
        if (randNum1 == correctAnswer)
            correctAnswer = randNum2;
        else if (randNum2 == correctAnswer)
            correctAnswer = randNum1;
    }
}

bool Question::play(string playerName)
{
    int answer;
    cout << endl << "Player " << playerName << " question:" << endl;
    cout << getquestion() << endl;
    randomize();// shaftle answers
    for (int i = 0; i < 4; i++)
        cout << i << ")  " << getanswer(i) << endl;
    cout << "Your answer is: ";
    cin >> answer;
    if (isAnswerCorrect(answer))//users number of answer
    {
        cout << "Correct" << endl;
        return true;
    }
    else
    {
        cout << "Correct answer is: " << getcorrectanswer() << endl;
        return false;
    }
}
