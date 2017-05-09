#ifndef SUSPECT_H_
#define SUSPECT_H_

#include<string>
#include<vector>
using namespace std;

class Suspect
{
private:
	string _name;
	bool _guiltyFlag; // Default to false. Only one person guilty.

	// ANSWERS FOR IF QUESTIONS GUILTYFLAG IS TRUE:
	vector<string> _guiltyAnswers;

	// ANSWERS FOR QUESTIONS IF GUITLYFLAG IS FALSE:
	vector<string> _innocentAnswers;

public:
	// CONSTRUCTOR
	/*No parameter for guiltyFlag, just automatically set it to false
	and then pick one later and set to TRUE with setGuiltyFlag().*/
	Suspect(string name);

	// CONSTRUCTOR FROM A POINTER
	Suspect(Suspect* suspect);

	// SETTERS
	void setGuiltyFlag(bool guitlyFlag);
	void setGuiltyAnswer(string answer); // takes in a string, and pushes it back into _trueAnswers
	void setInnocentAnswer(string answer); // takes in a string, and pushes it back into _falseAnswers

	// GETTERS
	string getName();
	string getAnswer(int q); // return guilty answer (either answer 1 or answer 2)
	bool getGuiltyFlag();
};

#endif