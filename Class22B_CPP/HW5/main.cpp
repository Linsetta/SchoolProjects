/*****************************************************************
This program is a variation of the Trivia Game for two
players with the winner of the end.
Each player must answer 3 questions.Display the winner.

/****************************************************************

using namespace std;

/********************************
Function open input file and read data from input file  into
Questions passing by reference.

INPUT:address, where will store pointer to array of Questions.
OUTPUT: number of initialized questions (could be diffrent from
number of defined questions in first line of file)
*********************************
*/

#include "Question.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

int readData(Question*& Questions) //pointer to a question type
{
	string s;
	int n;
	ifstream infile;
	infile.open("TriviaQuestions.txt");
	string infileName;

    // prompt user for filename
    cout << "\nPlease enter the name of the file that holds the data. \n";
    cin >> infileName;

    infile.open(infileName.c_str()); // /home/linsetta/Desktop/home/HW5Problem5B/TriviaQuestions.txt
	  if ( infile.fail())
    {
        cout << "\nPlease check the name of the input file and try again later!\n";
        exit(EXIT_FAILURE);
    }


	if (!infile.eof())
	{
		infile >> n; // get number of questiones,  defined in the inut  file
		getline(infile, s); // read the line fro the current position till the end // next line
	}

	cout << n << endl;

	Questions = new Question[n];  // create dynamically allocate the array of questions

	int i = 0;
	while (!infile.eof() && i <n) // reading questions and answers using class methods.
	{
		getline(infile, s);
		Questions[i].setquestion(s); // i call this function for for the i element.
		for (int k = 0; k < 4; k++)
		{
			getline(infile, s);
			Questions[i].setanswer(k, s);
		}
		i++;
	}
	infile.close();
	return i;
}

/*******************************************************************************
Function Randomize the array of questions before playing the game.

INPUT: size of the array of Questions and pointers to the array of Questions.
OUTPUT:void


***********************************************************************************
*/

void shuffle(int totalq, Question* Questions)
{
	srand(time(NULL)); // set generator of random numbers

	// shuffle of the addressess of questionsns  - 100 times
	for (int k = 1; k < 100; k++)
	{
		int randNum1 = (rand() % totalq);
		int randNum2 = (rand() % totalq);
		Question temp;
		temp = Questions[randNum1];
		Questions[randNum1] = Questions[randNum2];
		Questions[randNum2] = temp;
	}

}

int main()
{
	string Player1, Player2;

	cout << "Player 1, enter your name please: ";
	cin >> Player1;
	cout << "Player 2, enter your name please: ";
	cin >> Player2;

	Question *Questions; // question type pointer,doesnot point for smth yet
	int totalq = readData(Questions);
	shuffle(totalq, Questions);

	int l = 0; // index of current question
	int p1 = 0;// number of correct answers for player1
	int p2 = 0;// number of correct answers for player1
	for (int k = 0; k < 3; k++)
	{
		p1 += Questions[l++].play(Player1); //
		p2 += Questions[l++].play(Player2);
	}

	if (p1 > p2)
		cout << "Player " << Player1 << " won!";
	if (p1 < p2)
		cout << "Player " << Player2 << " won!";
	if (p1 == p2)
		cout << "Draw!";

    return 0;
}

/*OUTPUT
Player 1, enter your name please: Nina
Player 2, enter your name please: Leo

Please enter the name of the file that holds the data.
/home/linsetta/Desktop/home/HW5Problem5B/TriviaQuestions.txt
14

Player Nina question:
An object is not a class, but it is
0)  Code that specifies the functions that a class may have
1)  An instance of a class
2)  A description of a class
3)  Code that specifies the attributes that a class may have
Your answer is: 1
Correct

Player Leo question:
A class is not an object, but it is
0)  A description of an object
1)  An instance of an object
2)  Code that specifies the attributes that a particular type of object may have
3)  Code that specifies the functions that a particular type of object may have
Your answer is: 2
Correct answer is: A description of an object

Player Nina question:
To dynamically allocate an object we can use
0)  a pointer
1)  a default constructor
2)  constructor
3)  the class specification file
Your answer is: 3
Correct answer is: a pointer

Player Leo question:
The complete name of the operator that identifies the function as a member of a class is
0)  Identification operator
1)  Scope identification operator
2)  Scope resolution operator
3)  Scope operator
Your answer is: 3
Correct answer is: Scope resolution operator

Player Nina question:
Some programmers refer to accessors as
0)  Setter functions
1)  Getter functions
2)  Mutators functions
3)  Change functions
Your answer is: 1
Correct

Player Leo question:
Data hiding refers to an object�s ability to
0)  Hide its data
1)  Hide its procedures
2)  Hide its data from code that is inside the object
3)  Hide its data from code that is outside the object
Your answer is: 3
Correct
Player Nina won!
Process returned 0 (0x0)   execution time : 89.762 s
Press ENTER to continue.

*/
