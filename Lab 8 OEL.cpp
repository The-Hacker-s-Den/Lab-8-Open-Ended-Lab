#include <iostream>
#include <vector>
#include <string>
#include<chrono>
#include<algorithm>
using namespace std;
int welcome();
void Level_1();
void Level_2();
void Level_3();
int timer();
int main_menu();
int totalscore = 0, score_level1 = 0;

int main() {
	welcome();
	int main_menu_choice = main_menu();
	if (main_menu_choice == 1)
	{
		Level_1();
	}
	return 0;
}


int welcome() {
	cout << "  _____   _____   _____   _____  __  __          ___   _____ " << endl;
	cout << " |  __ \\ |  __ \\ |_   _| / ____||  \\/  |        |__ \\ | ____|"<< endl;
	cout << " | |__) || |__) |  | |  | (___  | \\  / |  ______   ) || |__  "<< endl;
	cout << " |  ___/ |  _  /   | |   \\___ \\ | |\\/| | |______| / / |___ \\ "<< endl;
	cout << " | |     | | \\ \\  _| |_  ____) || |  | |         / /_  ___) |"<< endl;
	cout << " |_|     |_|  \\_\\|_____||_____/ |_|  |_|        |____||____/ "<< endl;

	cout << endl;

    return 0;
}

int main_menu() {
	cout << "Options :\n";
	cout << "1. Start the Game" << endl;
	cout << "2. How to play" << endl;
	cout << "3. About" << endl;
	cout << "4. Credits" << endl;
	cout << "5. Exit" << endl;

	cout << "Enter your choice: ";
	int main_menu_choice;
	cin >> main_menu_choice;
	return main_menu_choice;
}

void Level_1() {
	int choice = 0, hintsUsed = 0, incorrect=0;
	
	string answer;
	char hint;
	bool phoneFound = false, phoneUnlocked=false;
	cout << R"(
							CASE FILE #001
							T H E   W E B

		============================================================

		STATUS       : ACTIVE INVESTIGATION
		LOCATION : VICTIM'S RESIDENCE
		VICTIM : 24 YEARS OLD
		CAUSE : UNDER INVESTIGATION

		============================================================

		"Every secret leaves a trace.
		Every trace tells a story.
		But some stories were never meant to be uncovered."

		------------------------------------------------------------

							[ CRIME SCENE ]

		You slowly push open the bedroom door. The room is unusually silent.

		A dim lamp flickers beside the bed.
		Thick spider webs cover the corners of the room.

		A lifeless body lies on the floor.

		The victim appears to be in his early twenties.
		His eyes are wide open, staring at the ceiling.

		There are no obvious signs of a struggle.

		Something about this scene feels deeply wrong.

		You take out your investigation notebook.

		Where would you like to begin?

		=============================================================
		PRESS ENTER TO START THE INVESTIGATION)";
	cin >> get();

	while (phoneUnlocked == false) {
		cout << "\n[ INVESTIGATION OPTIONS ]";
		cout << "\n 1. Examine the victim's body";
		cout << "\n 2. Search the room for evidence";
		cout << "\n 3. Attempt to unlock the phone";
		cout << "\n Enter your choice: ";
		cin >> choice;
		if (choice == 1) {
			cout << "\n[ FORENSIC EXAMINATION ]\n";
			cout << "You kneel beside the body.\n";
			cout << "The victim is a 24-year-old male.\n";
			cout << "His eyes show extreme light sensitivity.\n";
			cout << "\nThe forensic report reveals:\n";
			cout << "- Severe internal organ damage.\n";
			cout << "- Evidence of inhaled velvet spiders.\n";
			cout << "- High concentrations of PRISM-25.\n";
			cout << "\nYou record the findings in your notebook.\n";
		}
		else if (choice == 2) {
			cout << "\n[ ROOM INVESTIGATION ]\n";
			cout << "Thick webs cover the corners of the room.\n";
			cout << "Several velvet spiders are visible.\n";
			cout << "You find a mobile phone near the body.\n";
			cout << "The device is password protected.\n";

			phoneFound = true;
		}
		else if (choice == 3) {
			if (phoneFound == false)
				cout << "\n You must find the phone first.\n";
			else {
				cout << "\n[ PHONE LOCK ]\n";
				cout << "Ecrypted Message: VSLGHU LQ WKH GDUN";
				cout << "\nCaeser cipher shift: 3";
				cout << "\nEnter the decrypted message without spaces: ";
				cin >> answer;
				if (answer == "SPIDERINTHEDARK" || answer == "spiderinthedark") {
					cout << "\nPhone unlocked!";
					phoneUnlocked = true;
					cout << R"(
While scrolling through the phone, you discover a group called "THE HOLLOW".
It is full of vulnerable and depressed individuals. A user named "The Lumos" 
is offering members "help" through free dosages of a substance called PRISM-25. )";
					cout << "\n LEVEL 1 COMPLETE!";
				}
				else {
					cout << "\n Incorrect password. Try Again!";
					incorrect++;
					cout << "\n Do you want a hint? (y/n)";
					cin >> hint;
					if (hint == 'y'||hint=='Y') {
						if (hintsUsed < 3) {
							hintsUsed++;
							if (hintsUsed == 1) cout << "\n Hint 1: You notice a broken clock, running three hours behind.";
							else if (hintsUsed == 2) cout << "\n Hint 2: You find a note. It says, \"every letter has moved three places forward.\"";
							else if (hintsUsed == 3) cout << "\n Hint 3: A diary reveals, move each letter three steps backward. V becomes S.";
						}
						else cout << "\n You have used all the hints available.";
					}

				}
			}
		}
		else
			cout << "\n INVALID! Enter a number from 1 to 3.";
	}
		score_level1 = max(0, 100 - (10 * incorrect) - (20 * hintsUsed));
		totalscore += score_level1;

}

void Level_2() {
	// Level 2 code here
	
}

void Level_3() {
	// Level 3 code here
}

int timer() {
	int time;

	auto start = chrono::steady_clock::now(); // Record the start time

	// Simulate some user input
	// cin >> answer;

	auto end = chrono::steady_clock::now();// Record the end time

	chrono::duration<double> duration = end - start; // Calculate the duration in seconds

	time = duration.count();// Convert duration to seconds

	return time;
}


