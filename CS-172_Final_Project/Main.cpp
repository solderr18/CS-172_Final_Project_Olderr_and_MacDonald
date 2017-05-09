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
CREATE MORE SUSPECTS
-in setAnswers() set the t&f answers for q1&2
-put in where lists are printed
WRITE INTRODUCTION
------------------------
check: unsigned int needed infront of choice
is this because ->size() returns unsigned int?
run into a lot of problems w/o it...tho not
rlly a pressing problem
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
	cout << "1. Bob\n2. LeAnne\n";
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
	cout << "1. Bob\n2.Leanne\n" << endl;
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