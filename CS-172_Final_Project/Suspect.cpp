#include<iostream>
#include<string>
using namespace std;

#include"Suspect.h"

// CONSTRUCTOR
/*No parameter for guiltyFlag, just automatically set it to false
and then pick one later and set to TRUE with setGuiltyFlag().*/
Suspect::Suspect(string name)
{
	_name = name;
	_guiltyFlag = false;
}

// CONSTRUCTOR FROM A POINTER [MIGHT NOT NEED IT... SEE EXAM 2]
/*Suspect::Suspect(Suspect* suspect) 
{
	if (suspect != NULL)
	{
		_name = suspect->getName();
		_guiltyFlag = suspect->getGuiltyFlag();
		
		_trueAnswers.push_back(suspect->getTrueAnswer(1));
		_trueAnswers.push_back(suspect->getTrueAnswer(2));

		_falseAnswers.push_back(suspect->getFalseAnswer(1));
		_falseAnswers.push_back(suspect->getFalseAnswer(2));
	}
}*/

// SETTERS
void Suspect::setGuiltyFlag(bool guiltyFlag)
{
	_guiltyFlag = guiltyFlag;
}

void Suspect::setGuiltyAnswer(string answer) // takes in a string, pushes it back into _trueAnswers
{
	_guiltyAnswers.push_back(answer);
}

void Suspect::setInnocentAnswer(string answer) // takes in a string, pushes it back into _falseAnswers
{
	_innocentAnswers.push_back(answer);
}

// GETTERS

string Suspect::getName()
{
	return _name;
}

string Suspect::getAnswer(int q) // return answer 1 or 2
{
	if (q >= 1 && q <= 2)
	{
		if (_guiltyFlag == true)
			return _guiltyAnswers[q - 1];

		if (_guiltyFlag == false)
			return _innocentAnswers[q - 1];
	}

	else
		return NULL;
}

bool Suspect::getGuiltyFlag()
{
	return _guiltyFlag;
}