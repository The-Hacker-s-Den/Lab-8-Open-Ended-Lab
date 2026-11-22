#include <iostream>
#include <string>
#include<chrono>
#include<algorithm>
#include<cctype>
#include <windows.h>

using namespace std;
int welcome();
void Level_1();
void Level_2(string clues[]);
void Level_3();
void Level_4(string clues[]);
void timer(string*, int&);
int main_menu();
int totalscore = 0, score_level1 = 0, score_level2 = 0, score_level3 = 0, score_level4 = 0;


int ciphers_help();
int lore();
int credits();
int how_to_play();
int fullscreen();
void ending();


int fullscreen(){


	HWND hwnd = GetConsoleWindow();// Get the handle to the console window

	ShowWindow(hwnd, SW_MAXIMIZE); // Maximize the console window


	keybd_event(VK_MENU, 0, 0, 0);        // Press Alt
	keybd_event(VK_RETURN, 0, 0, 0);      // Press Enter

	keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0); // Release Enter
	keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0);   // Release Alt

	return 0;

}

int lore() {
		system("cls");
	cout << R"(
				
				 _         ____     _____     ______ 
				| |       / __ \   |  __ \   |  ____|
				| |      | |  | |  | |__) |  | |__   
				| |      | |  | |  |  _  /   |  __|  
				| |____  | |__| |  | | \ \   | |____ 
				|______|  \____/   |_|  \_\  |______|

		===========================================================================

			The inspiration is fron the cdrama The Truth Within.
		)";
		system("pause");
		return 0;
}

int ciphers_help(){
	int  ciphers_help = 0;
	system("cls");

	do {

		cout << R"(

                  ____ ___ ____  _   _ _____ ____  ____  
                 / ___|_ _|  _ \| | | | ____|  _ \/ ___| 
                | |    | || |_) | |_| |  _| | |_) \___ \ 
                | |___ | ||  __/|  _  | |___|  _ < ___) |
                 \____|___|_|   |_| |_|_____|_| \_\____/

		The Ciplers used in the game are:
			1. Caesar Cipher
			2. Atbash (Reverse Alphabet)
			3. Single-character XOR Cipher

		Enter the number of the cipher to learn more about it, or enter 0 to return to the help menu: )";
		cin >> ciphers_help;
		if (ciphers_help == 1) {
			system("cls");
			cout << R"(
			
					  ____      _      _____   ____      _      ____  
					 / ___|    / \    | ____| / ___|    / \    |  _ \ 
					| |       / _ \   |  _|   \___ \   / _ \   | |_) |
					| |___   / ___ \  | |___   ___) | / ___ \  |  _ < 
					 \____| /_/   \_\ |_____| |____/ /_/   \_\ |_| \_\
                                                  
					  ____   ___   ____    _   _   _____   ____  
					 / ___| |_ _| |  _ \  | | | | | ____| |  _ \ 
					| |      | |  | |_) | | |_| | |  _|   | |_) |
					| |___   | |  |  __/  |  _  | | |___  |  _ < 
					 \____| |___| |_|     |_| |_| |_____| |_| \_\

		The Caesar cipher is a substitution cipher where each letter in the plaintext is shifted a certain number of places
		down or up the alphabet.
		For example, with a shift of 3, A becomes D, B becomes E, and so on. To decrypt, you simply shift in the
		opposite direction.)";
		}
		else if (ciphers_help == 2) {
			system("cls");
			cout << R"(


				    _      _____    ____       _      ____     _   _ 
				   / \    |_   _|  | __ )     / \    / ___|   | | | |
				  / _ \     | |    |  _ \    / _ \   \___ \   | |_| |
				 / ___ \    | |    | |_) |  / ___ \   ___) |  |  _  |
				/_/   \_\   |_|    |____/  /_/   \_\ |____/   |_| |_|

				  ____     ___     ____     _   _    _____    ____  
				 / ___|   |_ _|   |  _ \   | | | |  | ____|  |  _ \ 
				| |        | |    | |_) |  | |_| |  |  _|    | |_) |
				| |___     | |    |  __/   |  _  |  | |___   |  _ < 
				 \____|   |___|   |_|      |_| |_|  |_____|  |_| \_\

		The Atbash cipher is a simple substitution cipher that replaces each letter with its corresponding letter
		from the reverse of the alphabet.
		For example, A becomes Z, B becomes Y, C becomes X, and so on. To decrypt, you apply the same substitution
		in reverse.)";
		}
		else if (ciphers_help == 3) {
			system("cls");
			cout << R"(


						 ____    ___   _   _    ____   _       _____  
						/ ___|  |_ _| | \ | |  / ___| | |     | ____|  
						\___ \   | |  |  \| | | |  _  | |     |  _|   
						 ___) |  | |  | |\  | | |_| | | |___  | |___  
						|____/  |___| |_| \_|  \____| |_____| |_____|

				  ____    _   _      _      ____        _      ____   _____   _____   ____  
				 / ___|  | | | |    / \    |  _ \      / \    / ___| |_   _| | ____| |  _ \ 
				| |      | |_| |   / _ \   | |_) |    / _ \  | |       | |   |  _|   | |_) |
				| |___   |  _  |  / ___ \  |  _ <    / ___ \ | |___    | |   | |___  |  _ < 
				 \____|  |_| |_| /_/   \_\ |_| \_\  /_/   \_\ \____|   |_|   |_____| |_| \_\

					__  __   ___    ____          ____    ___   ____    _   _   _____   ____  
					\ \/ /  / _ \  |  _ \        / ___|  |_ _| |  _ \  | | | | | ____| |  _ \ 
					 \  /  | | | | | |_) |      | |       | |  | |_) | | |_| | |  _|   | |_) |
					 /  \  | |_| | |  _ <       | |___    | |  |  __/  |  _  | | |___  |  _ < 
					/_/\_\  \___/  |_| \_\       \____|  |___| |_|     |_| |_| |_____| |_| \_\


		The single-character XOR cipher is a symmetric encryption method where each byte of the plaintext is
		XORed with a single character key.
		This means that the same key is used for both encryption and decryption. To decrypt, you simply
		XOR the ciphertext with the same key.)";
		}
		else if (ciphers_help == 0) {
			system("cls");
			return 0;
		}
		else {
			cout << "Invalid choice. Please enter a number between 0 and 3.";
		}
	} while (ciphers_help != 0);
}

int how_to_play() {
	int how_to_play_choice;
	do {
		system("cls");

		cout << R"(

		==========================================================================
			 _   _   _____   _       ____        __  __   _____   _   _   _   _ 
			| | | | | ____| | |     |  _ \      |  \/  | | ____| | \ | | | | | |
			| |_| | |  _|   | |     | |_) |     | |\/| | |  _|   |  \| | | | | |
			|  _  | | |___  | |___  |  __/      | |  | | | |___  | |\  | | |_| |
			|_| |_| |_____| |_____| |_|         |_|  |_| |_____| |_| \_|  \___/


		==========================================================================
		Welcome to PRISM-25! In this interactive experience, you will take on the role of a detective
		investigating a series of mysterious events. Your goal is to uncover the truth behind the
		cases presented in each level.
		[ How to Play ]
		1. Navigate through the investigation by choosing from the available options.
		2. Examine evidence, interview witnesses, and solve puzzles to progress in the story.
		3. Pay attention to details and clues provided in the narrative.
		4. Use your problem-solving skills to decrypt messages and unlock secrets.
		5. Keep track of your score based on your performance in each level.
		[ Controls ]
		- Use the keyboard to input your choices and answers.
		- Follow on-screen prompts for hints and guidance.
		[ Objective ]
		Solve all levels, uncover the truth, and achieve the highest score possible!
		============================================================)";
	

		cout << R"(

		What would you like to do now?
			1. Go to Ciphers Guide
			2. Read the Lore
			3. Return to Main Menu
	
		Your choice: )";
		cin >> how_to_play_choice;

		if (how_to_play_choice == 3) {
			return 0;
		}
		else if (how_to_play_choice == 1) {
			ciphers_help();
		}
		else if (how_to_play_choice == 2) {
			lore();
		}
	}while (how_to_play_choice != 3);
	



	

	return 0;
}


int main() {

	fullscreen();
	

	string clues[4] = { "", "", "", "" };

	int main_menu_choice = 0;
	
		while (main_menu_choice != 4) {
			welcome();

			main_menu_choice = main_menu();
			if (main_menu_choice == 1)
			{
				Level_1();
				Level_2(clues);
				Level_3();
				Level_4(clues);
			}
			else if (main_menu_choice == 2)
			{
				how_to_play();
			}
			else if (main_menu_choice == 3)
			{
				credits();
			}
			else if (main_menu_choice == 4)
			{
				cout << "Exiting the game. Goodbye!" << endl;
				return 0;
			}
			else
			{
				cout << "Invalid choice. Please restart the game and select a valid option." << endl;
				return 0;
			}
		}
	return 0;
}
	

int welcome() {
	system("cls");
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
	cout << "3. Credits" << endl;
	cout << "4. Exit" << endl;

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
	system("cls");
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

		You slowly push open the bedroom door. 
		The room is unusually silent.

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
				//string cypher1 = "VSLGHU LQ WKH GDUN"
				//answer1 = "SPIDER IN THE DARK"
				cout << "Encrypted Message: " << cypher1;
				cout << "\nCaesar cipher shift: 3";
				cout << "\n_____________________________________\n";
				cout << "\nEnter the decrypted message with spaces: ";

				timer(&answer1, time1);
				cout << "\nTime taken: " << time1 << " seconds";

				//Make it uppercase for comparison

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


void Level_2(string clues[]) {
	int choice = 0, choice2 = 0, hintsUsed = 0, incorrect = 0, time2 = 0;

	string answer2;
	char hint;
	bool notebookFound = false, notebookDeciphered = false;

	system("cls");


	cout << R"(

		  ____    _    ____  _____   _____ ___ _     _____
		 / ___|  / \  / ___|| ____| |  ___|_ _| |   | ____|
		| |     / _ \ \___ \|  _|   | |_   | || |   |  _|
		| |___ / ___ \ ___) | |___  |  _|  | || |___| |___
		 \____/_/   \_\____/|_____| |_|   |___|_____|_____|

					# 0 0 2

)";
	cout << R"(

	           	T H E   U N D E R C O V E R   D R O P 

		============================================================

		STATUS       : UNDERCOVER MEMBER OF "THE HOLLOW"
		LOCATION     : THE WAREHOUSE
		CAUSE        : MEET "THE LUMOS"

		============================================================

		"Every mask hides a motive.
                 Every motive demands a price.
                 And tonight, you have to wear the face of the prey to catch the predator."

		------------------------------------------------------------
		Press Enter to go inside the warehouse...
)";

	cin.ignore(10000, '\n');
	cin.get();

	cout << R"(
		[INSIDE THE WAREHOUSE]

		Using the victim's phone,
                you see "THE LUMOS" has sent a message in "THE HOLLOW" group chat.

		The message read:
		            "Abandoned Textile Warehouse.
                 5am sharp.
                 Free your mind, free your soul."
 
	 	You disguise yourself as a reckoned individual,
                memeber of "THE HOLLOW" group. 
                You open the rusted warehouse door.
                The building is pitch black.

		"THE LUMOS" had suspected your arrival and is gone,
                fled before your arrival in a hurry,
                leaving behind scattered supplies.
                Inside the warehouse, a single bulb swings overhead,
                casting long shadows across the floor.
		 Heavy crates and chemical glassware sit abandoned on a wooden workbench.

		Fresh boot prints lead toward the back exit.
		Something about this setup feels like a trap.

		You take out your investigation notebook.

		Where would you like to begin?

		=============================================================

		PRESS ENTER TO START THE INVESTIGATION)";


	std::cin.get();

	while (notebookDeciphered == false) {
		cout << "\n[ INVESTIGATION OPTIONS ]";
		cout << "\n 1. Examine the chemical glassware";
		cout << "\n 2. Search the warehouse for clues";
		cout << "\n 3. Decipher the message in the book";
		cout << "\n\n Enter your choice: ";
		cin >> choice;
		if (choice == 1) {
			cout << "\n_________________________________________________\n";
			cout << "\n[ CHEMICAL TRACE EXAMINATION ]\n";
			cout << "You examine the chemical glassware.\n";
			cout << "The glassware contains traces of an LSD, PRISM-25.\n";
			cout << "\nThe Examination report reveals:\n";
			cout << "PRISM-25 was stored here not manufactured here.\n";
			cout << "\n_________________________________________________\n";
		}
		else if (choice == 2) {
			cout << "\n__________________________________________________\n";
			cout << "\n[ WAREHOUSE INVESTIGATION ]\n";
			cout << "The warehouse has tiny holes in its structure,\n";
			cout << "allowing little morning rays of light pass through.\n";
			cout << "It has 2 doors, \n";
			cout << "a wider one for entry and and a little one at the back for exit.\n";
			cout << "Muddy boot prints lead toward the back exit.\n";
			cout << "You find a Notebook near the workbench.\n";
			cout << "That seemed to belong to 'The Lumos'.\n";
			cout << "The notebook contains a scrambled supplier entry.\n";
			cout << "The message is written in a reverse alphabet cipher.\n";
			cout << "\n__________________________________________________\n";
			notebookFound = true;
		}
		else if (choice == 3) {
			if (notebookFound == false)
				cout << "\n\n  You must find the notebook first.\n";
			else {
				cout << "\n________________________________________________\n";
				cout << "\n[ NOTEBOOK ENTRY ]\n";
				string cipher2 = "XSVNRHG ZORZH EVHKVI XLWV 8492";

				//answer = "CHEMIST ALIAS VESPER CODE 8492"

				cout << "Encrypted Message: " << cipher2;
				cout << "\nCipher Type: Atbash (Reverse Alphabet)";
				cout << "\n________________________________________________\n";
				cout << "\nEnter the decrypted message without spaces in UPPER/LOWERCASE: ";
				timer(&answer2, time2);

				int size_cipher2 = cipher2.length();

				int size_answer2 = answer2.length();

				for (int i = 0; i < size_answer2; i++) {
					answer2[i] = toupper(answer2[i]);
				}


				for (int i = 0; i < size_answer2; i++) {
					if ((answer2[i] != ' ') && (answer2[i] >= 'A' && answer2[i] <= 'Z')) {
						answer2[i] = 'Z' - (answer2[i] - 'A');
					}
				}

				int answer_accuracy = 0;

				bool answer_true = false;

				if (size_answer2 == size_cipher2) {
					for (int i = 0; i < size_answer2; i++) {
						if (answer2[i] == cipher2[i]) {
							answer_accuracy++;
						}
					}
					if (answer_accuracy == size_answer2) {
						answer_true = true;
					}

				}


				//if (answer2 == "CHEMISTALIASVESPERCODE8492" || answer2 == "chemistaliasvespercode8492")
				if (answer_true){
					cout << "\nNotebook deciphered!";
					notebookDeciphered = true;
					cout << R"(
______________________________________________________________________________
You dont know what to do with the information you have just found. 
Do you wish to:
1) Store the information in your notebook,
2) Or do you wish to follow the boot prints to the back exit?
______________________________________________________________________________
 )";
					cout << "Enter a choice (1 or 2): ";
					cin >> choice2;
					if (choice2 == 1) {
						cout << "\nYou have stored the information in your notebook.";
						cout << "\nYou decoded: CHEMIST ALIAS VESPER CODE 8492";
								clues[1] = "8492";
								cout << "[SAVED] Code 8492 recorded in notebook.\n";
					}
					else if (choice2 == 2) {
								cout << "[WARNING] Code not saved. Lumos is gone there are tire tracks outside, you leave the matter of arrest to another police team\n";
					}
					else {
								cout << "Invalid input. Please enter 1 to save or 2 to not save: ";
					}
				}
				else {
					cout << "\n Incorrect. Try Again!";
					incorrect++;
					cout << "\n Do you want a hint? (y/n)";
					cin >> hint;
					if (hint == 'y' || hint == 'Y') {
						if (hintsUsed < 3) {
							hintsUsed++;
							if (hintsUsed == 1) {
								cout << "\n Hint 1: You notice a message on the cover of the notebook.\n";
								cout << "\n         Your fate will mirror you.\n";
							}
							else if (hintsUsed == 2) cout << "\n Hint 2: The alphabet is reversed: A becomes Z, B becomes Y, C becomes X.\n";
							else if (hintsUsed == 3) cout << "\n Hint 3: X = C, S = H, V = E. The first word is CHEMIST, and numbers stay the same.\n";
						}
						else cout << "\n You have used all the hints available.";
					}

				}
			}
		}
		else
			cout << "\n INVALID! Enter a number from 1 to 3.";
		if (notebookFound == true && notebookDeciphered == true) {
			score_level2 = max(0, 100 - (10 * incorrect) - (20 * hintsUsed));
			totalscore += score_level2;
			cout << "\n================================\n";
			cout << "       LEVEL 2 COMPLETE\n";
			cout << "================================\n";
			cout << "       SCORE: " << score_level2 << " / 100\n";
			cout << "================================\n";
		}
	}
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

				//cipher = 0x18, 0x1F, 0x6B, 0x01, 0x1E, 0x0F, 0x0E, 0x6B, 0x1B, 0x18, 0x12, 0x08, 0x03, 0x02, 0x0A, 0x1F, 0x19, 0x02, 0x08, 0x6B, 0x08, 0x07, 0x02, 0x05, 0x02, 0x08
				//answer string = "ST JUDE PSYCHIATRIC CLINIC"


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

				//Make it uppercase for comparison

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
				answer3_accuracy = 0;


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

void Level_4(string clues[]) {
	int choice = 0, hintsUsed = 0, incorrect = 0;
	int password;
	int passwordAttempts = 0;
	int passwordLimit = 3;
	string answer4;
	int time4 = 0;
	char checkNotebook, storeClues, hint;
	bool computerLocked = true, computerDeciphered = false;

	system("cls");

	cout << R"(

		  ____    _    ____  _____   _____ ___ _     _____
		 / ___|  / \  / ___|| ____| |  ___|_ _| |   | ____|
		| |     / _ \ \___ \|  _|   | |_   | || |   |  _|
		| |___ / ___ \ ___) | |___  |  _|  | || |___| |___
		 \____/_/   \_\____/|_____| |_|   |___|_____|_____|

					# 0 0 4

				     T H E   F I N A L E
                 T H E   C H E M I S T ' S   F O R M U L A 
)";
	cout << R"(		
		============================================================

		STATUS       : RAID ST JUDE PSYCHIATRIC CLINIC
		LOCATION : ST JUDE PSYCHIATRIC CLINIC 
		CAUSE : FIND SOLID EVIDENCE TO ROOT OUT PRISM-25
		AND ARREST THE CHEMIST AND ALL RELEVANT PEOPLE

		============================================================

		"Every grief demands a price.
			Every formula hides a sin."

		------------------------------------------------------------
		Press Enter to raid the clinic...
)";

	cin.get();

	cout << R"(
	        ============================================================
		[INDIDE CLINIC]

		You break into the clinic, 
                searching for evidence of PRISM-25 distribution.

		The chat log (level 1), LUMOS' notebook (level 2), 
                and finally the pharmacy batch tag (level 3), 
                are enough evidences to issue a search varrant.

		The staff and patienyts are escorted out.
                You enter the clinic's main office,
                where you find a desk with a computer,
                and Dr. Vance sitting infront of the computer.

		 Dr. Vance is placed in handcuffs and detained on-site .

		You take out your investigation notebook.

		Where would you like to begin?

		=============================================================

		PRESS ENTER TO START THE INVESTIGATION)";

	std::cin.get();

	while (computerDeciphered == false) {
		cout << "\n_____________________________________\n";
		cout << "\n[ INVESTIGATION OPTIONS ]";
		cout << "\n 1. Interrogate Dr. Vance";
		cout << "\n 2. Unlock the computer";
		cout << "\n 3. Decipher the evidence on the computer";
		cout << "\n\n Enter your choice: ";
		cin >> choice;

		if (choice == 1) {
			cout << "\n_____________________________________\n";
			cout << "\n[ INTERROGATION ]\n";
			cout << "You approach Dr. Vance, who is visibly relaxed.\n";
			cout << "He keeps smiling as if he knows you won't find evidence.\n";
			cout << "The computer is locked.\n";
			cout << "By Law: protection against self-incrimination,\n";
			cout << "you cannot force Dr. Vance to say the password legally.\n";
			cout << "Forceful interrogation is illegal without solid evidence.\n";
			cout << "\nSo you attempt to crack it yourself.\n";
			cout << "\n_____________________________________\n";
		}
		else if (choice == 2) {
			if (computerLocked == false) {
				cout << "\n[!] The computer is already unlocked.\n";
			}
			else {
				cout << "\n_____________________________________\n";
				cout << "\n[ UNLOCK COMPUTER ]\n";
				cout << "The password is a 4-digit code.\n";
				cout << "You find a note on the desk saying CHEMIST VESPER CODE.\n";

				while (computerLocked == true && passwordAttempts < passwordLimit) {
					cout << "\nEnter the 4-digit code: ";
					cin >> password;
					cout << "\n_____________________________________\n";

					if (password == 8492) {
						cout << "\n[ACCESS GRANTED] Computer unlocked!\n";
						computerLocked = false;
					}
					else {
						passwordAttempts++;
						cout << "\nIncorrect password. Attempts remaining: " << (passwordLimit - passwordAttempts) << "\n";

						if (passwordAttempts >= passwordLimit) {
							cout << "\nToo many failed attempts. The computer remains locked.\n";
							break;
						}

						cout << "Do you wish to check your notebook for the clues? (y/n): ";
						cin >> checkNotebook;

						if (checkNotebook == 'y' || checkNotebook == 'Y') {
							if (clues[1] == "8492") {
								cout << "\n[NOTEBOOK VERIFIED] Stored Override Code: " << clues[1] << "\n";
							}
							else {
								cout << "\n[ACCESS DENIED] Your notebook is empty. You never saved the code in Level 2.\n";
							}
						}
							else if (checkNotebook == 'n' || checkNotebook == 'N') {
							cout << "\nYou chose not to check your notebook. Try to recall the code from memory.\n";
							}
					  else {
								cout << "\nInvalid input. Please enter 'y' or 'n'.\n";
						}
					}
				}
			}
			cout << R"(

After cracking the computer,
you find encrypted evidence files.

 )";
		}
		else if (choice == 3) {
			if (computerLocked == true) {
				cout << "\n\n  You must unlock the computer first.\n";
			}
			else {
				cout << "\n_____________________________________\n";
				cout << "\n[ ENCRYPTED EVIDENCE FILE ]\n";
				string cypher4 = "QEFRI WPRVTH KCI LGMRGW LD WVZ LWG EXVMF X QLNX XAIV";
				//string solution4 = "VANCE FUNDED THE TRIALS TO SEE HER AGAIN I MUST FLEE";

				string key = "VESPER";

				int key_length = key.length();

				cout << "Encrypted Message: " << cypher4;
				cout << "\nVigenere Cipher (Key: Chemist's Alias)";

				cout << "\n_____________________________________\n";
				cout << "\nEnter the decrypted message with spaces: ";

				cin.ignore(); 
				timer(&answer4, time4);
				cout << "\nTime taken: " << time4 << " seconds\n";

				// Convert player's input to uppercase for comparison
				for (int i = 0; i < answer4.length(); i++) {
					answer4[i] = toupper(answer4[i]);
				}

				int cipher4_length = cypher4.length();

				int answer4_length = answer4.length();

				int answer4_accuracy = 0;

				bool answer4_true = false;

				int key_index = 0;

				if (answer4_length == cipher4_length) {
					for (int i = 0; i < answer4_length; i++) {

						if (answer4[i] == ' ') {
							continue;
						}

						if (answer4[i] != ' ' && (answer4[i] >= 'A' && answer4[i] <= 'Z')) {
							answer4[i] = char((answer4[i] - 'A' + 26 + (key[key_index] - 'A')) % 26 + 'A');
						}
						key_index = (key_index + 1) % key_length;

						while (answer4[i] < 'A') {
							answer4[i] += 26;
						}

						while (answer4[i] > 'Z') {
							answer4[i] -= 26;
						}
					}
				}

				for (int i = 0; i < answer4_length; i++) {
					if (answer4[i] == cypher4[i]) {
						answer4_accuracy++;
					}
				}
				if (answer4_accuracy == cipher4_length) {
					answer4_true = true;
				}

				if (answer4_true) {
					cout << "\n[FILES DECRYPTED] Evidence secured! Dr. Vance placed under arrest.\n";
					cout << R"(
______________________________________________________________________________________
The solid evidence you have gathered leads the immediate arrest of Dr. Vance
and his accomplices, including THE LUMOS and some other supplierstemporary detention
becomes a formal arrest for drug trafficking, unlawful human experimentation, 
and accessory to manslaughter.State medical authorities immediately revoke
St. Jude Clinic's license and seal the facility as a crime scene. However the chemist 
behind PRISM-25 boarded the international plane 20 min before the raid.
______________________________________________________________________________________
 )";
					computerDeciphered = true;
					system("pause");
				}
				else {
					cout << "\n Incorrect password. Try Again!";
					incorrect++;
					cout << "\n Do you want a hint? (y/n)";
					cin >> hint;
					if (hint == 'y' || hint == 'Y') {
						choice = 3;
						if (hintsUsed < 3) {
							hintsUsed++;
							if (hintsUsed == 1) cout << "\n Hint 1: Repeat the keyword VESPER beneath the encrypted message \"use a polyalphabetic Vigenere lock.\n";
							else if (hintsUsed == 2) cout << "\nSubtract the keyword letter's position from each cipher letter: Q minus V (21) shifts back to V.\"\n";
							else if (hintsUsed == 3) cout << "\n Hint 3: First word is VANCE..\n";
						}
						else cout << "\n You have used all the hints available.";
					}
				}
			}
		}
		else
			cout << "\n INVALID! Enter a number from 1 to 3.";
	}
	score_level4 = max(0, 100 - (10 * incorrect) - (20 * hintsUsed));
	totalscore += score_level4;
	cout << "\n================================\n";
	cout << "       LEVEL 4 COMPLETE\n";
	cout << "================================\n";
	cout << "       SCORE: " << score_level4 << " / 100\n";
	cout << "       Puzzle time: " << time4 << " seconds\n";
	cout << "================================\n";

}


void timer(string* timed_answer, int& time) {

	auto start = chrono::steady_clock::now(); // Record the start time

	getline(cin >> ws, *timed_answer); // Wait for user input

	auto end = chrono::steady_clock::now();// Record the end time

	chrono::duration<double> duration = end - start; // Calculate the duration in seconds

	time += (int)duration.count();// Convert duration to seconds

}


int credits() {
	system("cls");
	cout << R"(

			  ____    ____    _____   ____    ___   _____   ____  
			 / ___|  |  _ \  | ____| |  _ \  |_ _| |_   _| / ___| 
			| |      | |_) | |  _|   | | | |  | |    | |   \___ \ 
			| |___   |  _ <  | |___  | |_| |  | |    | |    ___) |
			 \____|  |_| \_\ |_____| |____/  |___|   |_|   |____/
		============================================================

		Hania Nauman
		Rameen Arjmand
		Shaheer

		============================================================

)";
	system("pause");
	return 0;
}
void ending() {
	system("cls");
	cout << R"(
		============================================================
		                    C A S E   C L O S E D
		============================================================

		Three weeks later.

		The headlines read the same everywhere:

		   "ST JUDE CLINIC SEALED. DR. VANCE CHARGED."

		Dr. Julian Vance, THE LUMOS, and every supplier tied to
		PRISM-25 now wait for trial. The victims' families finally
		have names to put to what happened to them.

		The Hollow's group chat has been taken offline.
		Its members have been contacted by counselors, this time
		with real help.

		------------------------------------------------------------
)";
	system("pause");
	cout << R"(
		But one file never made it into evidence.

		The pharmacy batch tag. The notebook. The override code.
		Every trail pointed to one alias:

		                      V E S P E R

		No name. No face. Only a seat on an international flight
		that took off twenty minutes before the raid.

		You close your notebook.

		Somewhere, a chemist is still working.

		"Every grief demands a price.
		 Every formula hides a sin."

		------------------------------------------------------------
)";
	system("pause");
	string rank;
	if (totalscore >= 350) rank = "MASTER DETECTIVE";
	else if (totalscore >= 250 && totalscore < 350) rank = "SENIOR INVESTIGATOR";
	else if (totalscore >= 150 && totalscore < 250) rank = "JUNIOR INVESTIGATOR";
	else if (totalscore >= 0 && totalscore < 150) rank = "ROOKIE INVESTIGATOR";
	system("cls");
	cout << endl << endl;
	cout << "		============================================\n";
	cout << "		              FINAL REPORT\n";
	cout << "		============================================\n";
	cout << "       Level 1 - The Web ............." << score_level1 << "/100" << endl;
	cout << "       Level 2 - The Undercover Drop.." << score_level2 << "/100" << endl;
	cout << "       Level 3 - The Moth............." << score_level3 << "/100" << endl;
	cout << "       Level 4 - The Finale..........." << score_level4 << "/100" << endl;
	cout << "       --------------------------------------------\n";
	cout << "       TOTAL SCORE : " << totalscore << "/400" << endl;
	cout << "       RANK : " << rank << endl;
	cout << R"(
		        PRISM-25 will return... will you?

		 _____ _   _ _____   _____ _   _ ____  
		|_   _| | | | ____| | ____| \ | |  _ \ 
		  | | | |_| |  _|   |  _| |  \| | | | |
		  | | |  _  | |___  | |___| |\  | |_| |
		  |_| |_| |_|_____| |_____|_| \_|____/ 

)";
	system("pause");
}