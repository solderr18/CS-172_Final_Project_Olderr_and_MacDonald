///SARAH OLDERR AND PAUL MACDONALD
///FINAL PROJECT CS172 SPRING2017
#include<iostream>
#include<string>
#include<ctime>
#include<vector>
#include"Suspect.h"
using namespace std;

/*
TO DO :
------------------------
=WRITE INTRO

=WRITE QUESTIONS IN
void setAnswers(vector<Suspect*> &s)

=SET NAMES IN
void createSuspects(vector<Suspect*> &s)
Suspect* whichSuspectTalkTo(vector<Suspect*> &s)
void guess(vector<Suspect*> &s)


also,, could add in check for invalid entered type iE if char/string entered instead of int
			or if double (mainly decimal) is entered
------------------------
check: unsigned int needed infront of choice
is this because ->size() returns unsigned int?
run into a lot of problems w/o it...tho not
rlly a pressing problem
^^not an issue, program works.
*/

void createSuspects(vector<Suspect*> &s);
void setAnswers(vector<Suspect*> &s);
void chooseGuiltyPerson(vector<Suspect*> &s);
void introduction();
Suspect* whichSuspectTalkTo(vector<Suspect*> &s);
int interview(Suspect* interviewee);
void guess(vector<Suspect*> &s);

int main()
{
	vector<Suspect*> Suspects;

	createSuspects(Suspects);
	setAnswers(Suspects);

	// CHOOSE GUILTY SUSPECT
	srand(time(NULL));
	chooseGuiltyPerson(Suspects);

	introduction();

	int stillTalking = 1;
	while (stillTalking == 1)
	{
		Suspect* interviewee = whichSuspectTalkTo(Suspects);
		stillTalking = interview(interviewee);
	}

	guess(Suspects);

	for (int i = 0; i < Suspects.size(); i++)
	{
		delete Suspects[i];
	}

	return 0;
}

void createSuspects(vector<Suspect*> &s)
{
	// CREATE "BOB"
	Suspect* bob = new Suspect("Bob");
	s.push_back(bob);

	// CREATE "LEANNE"
	Suspect* leanne = new Suspect("LeAnne");
	s.push_back(leanne);

	//THREE BLANK CHARACTORS
	Suspect* person3 = new Suspect("Person 3");
	s.push_back(person3);

	Suspect* person4 = new Suspect("Person 4");
	s.push_back(person4);

	Suspect* person5 = new Suspect("Person 5");
	s.push_back(person5);

	// TODO create three more suspects (AND PUT THEM IN WHERE LISTS ARE PRINTED)
}

void setAnswers(vector<Suspect*> &s)
{
	// SET BOB'S ANSWERS
	s[0]->setGuiltyAnswer("Um... in the bathtub, enjoying a good soak.");
	s[0]->setGuiltyAnswer("Didn't know the guy. Couldn't stand his dog, though... Nasty little bugger keeps me up all night.");

	s[0]->setInnocentAnswer("Presenting my research in Spain. Wanna see some sweet pics?");
	s[0]->setInnocentAnswer("Saw him around some, good guy.");

	// SET LEANNE'S ANSWERS
	s[1]->setGuiltyAnswer("Night shift. Witnesses? No, actually, I was the last one to leave the office.");
	s[1]->setGuiltyAnswer("Didn't know them.");

	s[1]->setInnocentAnswer("I was at my weekly sitar class meeting.");
	s[1]->setInnocentAnswer("Hey! I knew them! They were in my weekly sitar class! What did you say happened to them?");


	//Blank responses for last three blank characters
	//PERSON 3
	s[2]->setGuiltyAnswer("Person 3 guilty answer 1");
	s[2]->setGuiltyAnswer("Person 3 guilty answer 2");

	s[2]->setInnocentAnswer("Person 3 innocent answer 1");
	s[2]->setInnocentAnswer("Person 3 innocent answer 2");

	//PERSON 4
	s[3]->setGuiltyAnswer("Person 4 guilty answer 1");
	s[3]->setGuiltyAnswer("Person 4 guilty answer 2");

	s[3]->setInnocentAnswer("Person 4 innocent answer 1");
	s[3]->setInnocentAnswer("Person 4 innocent answer 2");

	//PERSON 5
	s[4]->setGuiltyAnswer("Person 5 guilty answer 1");
	s[4]->setGuiltyAnswer("Person 5 guilty answer 2");

	s[4]->setInnocentAnswer("Person 5 innocent answer 1");
	s[4]->setInnocentAnswer("Person 5 innocent answer 2");

	// TODO SET ANSWERS FOR THREE OTHER SUSPECTS!!!
}

void chooseGuiltyPerson(vector<Suspect*> &s)
{
	int randomIndex = rand() % s.size() + 1;
	s[randomIndex]->setGuiltyFlag(true);
}

void introduction()
{
	// TODO write intro
}

Suspect* whichSuspectTalkTo(vector<Suspect*> &s) 
{
	unsigned int choice;
	cout << "Which suspect would you like to talk to? (enter number)\n" << endl;
	cout << "1. Bob\n2. LeAnne\n3. Person 3\n4. Person 4\n5. Person 5\n";
	do {
		cin >> choice;
		if (choice > s.size() || choice == 0)
			cout << "INVALID OPTION\n Please enter number next to name.\n";
	} while (choice > s.size() || choice == 0);
	return s[choice - 1];
}

int interview(Suspect* interviewee)
{
	unsigned int choice;
	cout << "Choose a question to ask (1 or 2): " << endl;
	cout << "1. Where were you at the time of the murder?" << endl;
	cout << "2. What was your relation to the victim?" << endl;
	do {
		cin >> choice;
		if (choice < 1 || choice > 2)
			cout << "INVALID OPTION\n Please choose 1 or 2\n";
	} while (choice < 1 || choice > 2);


	cout << interviewee->getAnswer(choice) << endl << endl;

	int cont;
	cout << "Type 1 if you want to keep interviewing suspects." << endl;
	cout << "Type 2 if you want to stop interviewing and make your guess." << endl;
	do {
		cin >> cont;
		if (cont != 1 && cont != 2)
			cout << "INVALID OPTION\n Please choose 1 or 2\n";
	} while (cont != 1 && cont != 2);
	return cont;
}

void guess(vector<Suspect*> &s)
{
	unsigned int choice; //errors went away when i did this, dont know why
	cout << "WHO'S THE KILLER?" << endl;
	cout << "1. Bob\n2. LeAnne\n3. Person 3\n4. Person 4\n5. Person 5\n" << endl;
	do {
		cin >> choice;
		if (choice > s.size() || choice == 0)
			cout << "INVALID OPTION\n Please enter number next to name.\n";
	} while (choice > s.size() || choice == 0);

	if (s[choice - 1]->getGuiltyFlag() == true)
		cout << "Congratulations! You win! " << s[choice - 1]->getName() << " is the murderer! You win!" << endl;

	if (s[choice - 1]->getGuiltyFlag() == false)
		cout << "So sorry... " << s[choice - 1]->getName() << " was actually innnocent, and you sent them to jail for no reason." << endl <<
		"YOU'RE FIRED!" << endl;
}