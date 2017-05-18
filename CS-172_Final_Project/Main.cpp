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

	// CREATE PENELOPE
	Suspect* penelope = new Suspect("Penelope");
	s.push_back(penelope);

	// CREATE SAM
	Suspect* sam = new Suspect("Sam");
	s.push_back(sam);

	// "GRAB YOURSELF A SLICE O' RUG, JACKSON!!!"
	Suspect* jackson = new Suspect("Jackson");
	s.push_back(jackson);

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


	//PENELOPE //PAUL
	s[2]->setGuiltyAnswer("This is weird and unacceptable! Why would you be asking me something like this?? I'm not a killer! I want my lawyer!");
	s[2]->setGuiltyAnswer("Oh, yeah... Great guy... We, uh, we really got along great..(*clears throat*)");

	s[2]->setInnocentAnswer("What time was it? 11:00? I was at a karaoke party at that time... Just ask the fellas over there. (*The 'fellas' confirm her story, and even show you embarrassing footage of her horrendous singing abilities [or lack thereof] with a datestamp on the video clip.*)");
	s[2]->setInnocentAnswer("As a matter of fact, I don't think I ever met them.");

	//SAM //SARAH
	s[3]->setGuiltyAnswer("Home with my dog... Ask her I was...");
	s[3]->setGuiltyAnswer("All I'm saying is he really should't've said those things about my mom.");

	s[3]->setInnocentAnswer("The in laws had me over for dinner.");
	s[3]->setInnocentAnswer("We were in the same crocheting class but never really hung out.");

	//JACKSON //SARAH
	s[4]->setGuiltyAnswer("Ok look dude... I killed them. Okay? Happy?");
	s[4]->setGuiltyAnswer("No offense but they stole my dance moves and I hate them.");

	s[4]->setInnocentAnswer("Oh that was on the night of my slam poetry reading! We meet up once a month.");
	s[4]->setInnocentAnswer("We were in the same dance class!");

}

void chooseGuiltyPerson(vector<Suspect*> &s)
{
	int randomIndex = rand() % s.size() + 1;
	s[randomIndex]->setGuiltyFlag(true);
}

void introduction() //PAUL
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Murder! There's been a murder at the Hawkshaw Hotel, the hotel where " << endl;
	cout << "all the great detectives stay on their vacations! You yourself are a " << endl;
	cout << "detective, one of the best in the world. The scene of the crime sits " << endl;
	cout << "before you - a bloody mess(quite literally). The body is on the floor, " << endl;
	cout << " there is broken dishware (a sign of a struggle!) and a number of " << endl;
	cout << "rather grotesque knife wounds inflicted on the victim. There is no " << endl;
	cout << "knife to be found, however, so you have no fingerprints to go off of." << endl << endl;

	cout << "There are other tenants at this hotel as well, who are not detectives" << endl;
	cout << "but common, everyday folks. One of these five common, everday folks" << endl;
	cout << "has killed this poor, unfortunate victim, and it is up to you to " << endl;
	cout << "deduce, by means of individual interviews with each tenant, who the " << endl;
	cout << "killer is." << endl << endl;

	cout << "You will have two questions you can ask each suspect - time is of the" << endl;
	cout << "esscence. When you feel you've gathered sufficient information, you " << endl;
	cout << "can make your accusation. But beware---you can only accuse ONCE, so " << endl;
	cout << "make it count!" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl << endl;
}

Suspect* whichSuspectTalkTo(vector<Suspect*> &s)
{
	unsigned int choice;
	cout << "Which suspect would you like to talk to? (enter number)\n" << endl;
	cout << "1. Bob\n2. LeAnne\n3. Penelope\n4. Sam\n5. Jackson\n";
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


	cout << endl << interviewee->getName() << " says: " << interviewee->getAnswer(choice) << endl << endl;

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
	cout << "1. Bob\n2. LeAnne\n3. Penelope\n4. Sam\n5. Jackson\n" << endl;
	do {
		cin >> choice;
		if (choice > s.size() || choice == 0)
			cout << "INVALID OPTION\n Please enter number next to name.\n";
	} while (choice > s.size() || choice == 0);

	if (s[choice - 1]->getGuiltyFlag() == true)
		cout << "Congratulations! You win! " << s[choice - 1]->getName() << " is the murderer! You win!" << endl;

	if (s[choice - 1]->getGuiltyFlag() == false)
		cout << "So sorry detective... " << s[choice - 1]->getName() << " was actually innnocent, and you sent them to jail." << endl <<
		"YOU'RE FIRED!" << endl;
}