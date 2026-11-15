#include <iostream>
#include <string>
#include<chrono>
#include<algorithm>
#include<cctype>
using namespace std;
int welcome();
void Level_1();
void Level_2();
void Level_3();
void timer(string*, int&);
int main_menu();
int totalscore = 0, score_level1 = 0, score_level3=0;


int main() {
	welcome();
	int main_menu_choice = main_menu();
	if (main_menu_choice == 1)
	{
		Level_1();
		Level_3();
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
	string answer1;
	int time1 = 0;

	char hint;
	bool phoneFound = false, phoneUnlocked=false;
	cout << R"(

		  ____    _    ____  _____   _____ ___ _     _____
		 / ___|  / \  / ___|| ____| |  ___|_ _| |   | ____|
		| |     / _ \ \___ \|  _|   | |_   | || |   |  _|
		| |___ / ___ \ ___) | |___  |  _|  | || |___| |___
		 \____/_/   \_\____/|_____| |_|   |___|_____|_____|

					# 0 0 1

				     T H E   W E B
)";
	cout << R"(		
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
		Press Enter to view the crime scene...
)";

	cin.ignore(10000, '\n');
	cin.get(); 

		cout<<R"(
		[CRIME SCENE]

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

	std::cin.get();

	while (phoneUnlocked == false) {
		cout << "\n_____________________________________\n";
		cout << "\n[ INVESTIGATION OPTIONS ]";
		cout << "\n 1. Examine the victim's body";
		cout << "\n 2. Search the room for evidence";
		cout << "\n 3. Attempt to unlock the phone";
		cout << "\n\n Enter your choice: ";
		cin >> choice;
		if (choice == 1) {
			cout << "\n_____________________________________\n";
			cout << "\n[ FORENSIC EXAMINATION ]\n";
			cout << "You kneel beside the body.\n";
			cout << "The victim is a 24-year-old male.\n";
			cout << "His eyes show extreme light sensitivity.\n";
			cout << "\nThe forensic report reveals:\n";
			cout << "- Severe internal organ damage.\n";
			cout << "- Evidence of inhaled velvet spiders.\n";
			cout << "- High concentrations of PRISM-25.\n";
			cout << "\nYou record the findings in your notebook.\n";
			cout << "\n_____________________________________\n";
		}
		else if (choice == 2) {
			cout << "\n_____________________________________\n";
			cout << "\n[ ROOM INVESTIGATION ]\n";
			cout << "Thick webs cover the corners of the room.\n";
			cout << "Several velvet spiders are visible.\n";
			cout << "You find a mobile phone near the body.\n";
			cout << "The device is password protected.\n";
			cout << "\n_____________________________________\n";

			phoneFound = true;
		}
		else if (choice == 3) {
			if (phoneFound == false)
				cout << "\n\n  You must find the phone first.\n";
			else {
				cout << "\n_____________________________________\n";
				cout << "\n[ PHONE LOCK ]\n";
				string cypher1 = "VSLGHU LQ WKH GDUN";
				cout << "Encrypted Message: " << cypher1;
				cout << "\nCaesar cipher shift: 3";
				cout << "\n_____________________________________\n";
				cout << "\nEnter the decrypted message with spaces: ";

				timer(&answer1, time1);
				cout << "\nTime taken: " << time1 << " seconds";

				//Make it lowercase for comparison

				for (int i = 0; i < answer1.length(); i++) {
					answer1[i] = toupper(answer1[i]);
					if (answer1[i] != ' ') {
						answer1[i] += 3;
					}
				}

				if (answer1 == cypher1) {
					cout << "\nPhone unlocked!";
					phoneUnlocked = true;
					cout << R"(
______________________________________________________________________________
While scrolling through the phone, you discover a group called "THE HOLLOW".
It is full of vulnerable and depressed individuals. A user named "The Lumos" 
is offering members "help" through free dosages of a substance called PRISM-25.
______________________________________________________________________________
 )";
				}
				else {
					cout << "\n Incorrect password. Try Again!";
					incorrect++;
					cout << "\n Do you want a hint? (y/n)";
					cin >> hint;
					if (hint == 'y'||hint=='Y') {
						choice = 3;
						if (hintsUsed < 3) {
							hintsUsed++;
							if (hintsUsed == 1) cout << "\n Hint 1: You notice a broken clock, running three hours behind.\n";
							else if (hintsUsed == 2) cout << "\n Hint 2: You find a note. It says, \"every letter has moved three places forward.\"\n";
							else if (hintsUsed == 3) cout << "\n Hint 3: A diary reveals, move each letter three steps backward. V becomes S.\n";
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
		cout << "\n================================\n";
		cout << "       LEVEL 1 COMPLETE\n";
		cout << "================================\n";
		cout << "       SCORE: " << score_level1 << " / 100\n";
		cout << "       Puzzle time: " << time1 << " seconds\n";
		cout << "================================\n";
		
}

void Level_2() {
	// Level 2 code here
	
}

void Level_3() {
	bool tagDecoded = false, packFound=false;
	int choice = 0, time3 = 0, hintsUsed = 0,incorrect=0;
	char hint;
	string answer3;
	cout << R"(

		  ____    _    ____  _____   _____ ___ _     _____
		 / ___|  / \  / ___|| ____| |  ___|_ _| |   | ____|
		| |     / _ \ \___ \|  _|   | |_   | || |   |  _|
		| |___ / ___ \ ___) | |___  |  _|  | || |___| |___
		 \____/_/   \_\____/|_____| |_|   |___|_____|_____|

					# 0 0 3

				     T H E   M O T H
)";
	cout << R"(
		============================================================

		LOCATION : THEATRE
		STATUS   : ACTIVE INVESTIGATION

		============================================================

		You cross-reference usernames from The Hollow and arrange
		to meet a theatre lighting technician.

		But when you reach the theatre, you are too late.

		The technician lies motionless beneath the studio lamps.
		A harsh white light floods the silent stage.

		Another victim. Another connection to PRISM-25.
		)";
	while (tagDecoded == false) {
		cout << "\n_____________________________________\n";
		cout << "\n[ INVESTIGATION OPTIONS ]";
		cout << "\n1. Examine the victim";
		cout << "\n2. Inspect the studio lamps";
		cout << "\n3. Search near the body";
		cout << "\n4. Decode the pharmacy batch tag";
		cout << "\n\nEnter your choice: ";
		cin >> choice;

		if (choice == 1) {
			cout << "\n_____________________________________\n";
			cout << "\n[ FORENSIC EXAMINATION ]\n";
			cout << "The victim worked as a lighting technician.\n";
			cout << "The report records severe eye damage.\n";
			cout << "PRISM-25 is linked to the victim's symptoms.\n";
			cout << "You record the similarities to the first case.\n";
			cout << "\n_____________________________________\n";
		}
		else if (choice == 2) {
			cout << "\n_____________________________________\n";
			cout << "\n[ STUDIO LAMPS ]\n";
			cout << "You notice high-wattage lamps facing the stage.\n";
			cout << "Upon examining them, you discover evidence\n";
			cout << "suggesting the victim stared directly into\n";
			cout << "the intense lights for a prolonged period.\n";
			cout << "You recall an unusual symptom of PRISM-25:\n";
			cout << "an uncontrollable attraction to light.\n";
			cout << "\n_____________________________________\n";
		}
		else if (choice == 3) {
			cout << "\n_____________________________________\n";
			cout << "\n[ EVIDENCE COLLECTED ]\n";
			cout << "A silver foil blister pack lies beside the body.\n";
			cout << "An encrypted pharmacy batch tag is stamped on it.\n";
			cout << "The packaging suggests a medical facility.\n";
			cout << "\n_____________________________________\n";

			packFound = true;
		}
		else if (choice == 4) {
			if (packFound == false) {
				cout << "\n\nFind the blister pack first.\n";
			}
			else {
				cout << "\n_____________________________________\n";
				cout << "\n[ ENCRYPTED BATCH TAG ]\n";
				//cout << "18 1F 01 1E 0F 0E 1B 18 12 08 03 02\n";
				//cout << "0A 1F 19 02 08 08 07 02 05 02 08\n";
				int hex_values[] = { 0x18, 0x1F, 0x6B, 0x01, 0x1E, 0x0F, 0x0E, 0x6B, 0x1B,
					0x18, 0x12, 0x08, 0x03, 0x02, 0x0A, 0x1F, 0x19, 0x02, 0x08, 0x6B,
					0x08, 0x07, 0x02, 0x05, 0x02, 0x08 };

				cout << "The encrypted batch tag in hex is: \n "<<hex;

				const int size_hex_cypher = sizeof(hex_values) / sizeof(hex_values[0]);

				int cypher3_solved[size_hex_cypher];

				for (int i = 0; i < size_hex_cypher; i++) {
					cout << hex_values[i] << " ";
				}

				cout << dec;

				for (int i = 0; i < size_hex_cypher; i++) {
					
					//Commented out the if statement to allow for spaces in the decrypted text

					/*if (hex_values[i] != 0x20) {
						cypher3_solved[i] = hex_values[i] ^ 75; // XOR with 75
					}
					else 
					{
						cypher3_solved[i] = 32; // Space character
					}
					*/ 
					cypher3_solved[i] = hex_values[i] ^ 75; //
				}

				//cout << "\nThe decrypted batch tag in decimal is: \n";

				/*for (int i = 0; i < size_hex_cypher; i++) {
					cout << cypher3_solved[i] << " ";
				}
				*/


				cout << "\nCipher: Single-character XOR";
				cout << "\nKey: K (ASCII decimal 75, hexadecimal 4B)";
				cout << "\nConvert each hex value to a number, XOR";
				cout << "\nwith 75, then read the resulting ASCII letter.";
				cout << "\n_____________________________________\n";
				cout << "\n\nEnter the decrypted text with spaces: ";
				timer(&answer3, time3);

				//Make it lowercase for comparison

				for (int i = 0; i < answer3.length(); i++) {
					answer3[i] = toupper(answer3[i]);
				}
				bool answer3_true = false;

				int answer3_accuracy = 0;

				for (int i = 0; i < size_hex_cypher; i++) {
					if (answer3[i] == cypher3_solved[i]) {
						answer3_accuracy++;
					}
				}

				if (answer3_accuracy == size_hex_cypher) {
					answer3_true = true;
				}


				if (answer3_true == true) {
					tagDecoded = true;
					cout << "\n[ BATCH TAG DECODED ]\n";
					cout << "ST JUDE PSYCHIATRIC CLINIC\n";
					cout << R"(
___________________________________________________________________________________
The message leads you to a clinic where every victim associated with The Hollow 
had visited to receive therapy. This establishes a connection between the victims, 
their psychological treatment, and PRISM-25. You cross-reference the clinic's 
patient records with the victims associated with The Hollow.

You discover that every victim had previously visited this clinic for therapy.

Could PRISM-25 be connected to their treatment?

Your next destination: ST JUDE PSYCHIATRIC CLINIC
___________________________________________________________________________________
 )";
				}
				else {
					incorrect++;
					cout << "\nIncorrect answer. Try again.\n";
					cout << "Do you want a hint? (y/n): ";
					cin >> hint;
					if (hint == 'y' || hint == 'Y') {
						if (hintsUsed < 3) {
							hintsUsed++;

							if (hintsUsed == 1) {
								cout << "\n[ HINT 1: HEXADECIMAL ]\n";
								cout << "Hexadecimal is a base-16 number system.\n";
								cout << "Convert each hex value into decimal first.\n";
								cout << "Example: 18 (hex) = 1 * 16 + 8 = 24.\n";
							}
							else if (hintsUsed == 2) {
								cout << "\n[ HINT 2: XOR OPERATION ]\n";
								cout << "XOR compares two binary bits.\n";
								cout << "Same bits give 0, different bits give 1.\n";
								cout << "Use the XOR operator (^) with key 75.\n";
								cout << "Example: 24 ^ 75 = 83.\n";
							}
							else if (hintsUsed == 3) {
								cout << "\n[ HINT 3: ASCII DECRYPTION ]\n";
								cout << "Convert your XOR result into an ASCII letter.\n";
								cout << "83 = S, 84 = T.\n";
							}
						}
						else {
							cout << "\n You have used all available hints.\n";
						}
					}
				}
			}


		}
		else
			cout << "\n INVALID! Enter a number from 1 to 4. \n";
	}
	score_level3 = max(0, 100 - (10 * incorrect) - (20 * hintsUsed));
	totalscore += score_level3;
	cout << "\n================================\n";
	cout << "       LEVEL 3 COMPLETE\n";
	cout << "================================\n";
	cout << "       SCORE: " << score_level3 << " / 100\n";
	cout << "       Puzzle time: " << time3 << " seconds\n";
	cout << "================================\n";


}

void Level_4() {
	int choice = 0, hintsUsed = 0, incorrect = 0;
	string answer4;
	int time4 = 0;

	char hint;


}

void timer(string* timed_answer, int& time) {

	auto start = chrono::steady_clock::now(); // Record the start time

	getline(cin >> ws, *timed_answer); // Wait for user input

	auto end = chrono::steady_clock::now();// Record the end time

	chrono::duration<double> duration = end - start; // Calculate the duration in seconds

	time += (int)duration.count();// Convert duration to seconds

}


