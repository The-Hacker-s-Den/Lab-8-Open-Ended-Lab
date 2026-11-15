#include <iostream>
#include <vector>
#include <string>
#include<chrono>

using namespace std;

int welcome() {
    const std::vector<std::string> banner = {
        R"(  _____   _____   _____   _____  __  __          ___   _____ )",
        R"( |  __ \ |  __ \ |_   _| / ____||  \/  |        |__ \ | ____|)",
        R"( | |__) || |__) |  | |  | (___  | \  / |  ______   ) || |__  )",
        R"( |  ___/ |  _  /   | |   \___ \ | |\/| | |______| / / |___ \ )",
        R"( | |     | | \ \  _| |_  ____) || |  | |         / /_  ___) |)",
        R"( |_|     |_|  \_\|_____||_____/ |_|  |_|        |____||____/ )"
    };

    for (const auto& line : banner) {
        std::cout << line << '\n';
    }

    return 0;
}
void Level_1() {
	// Level 1 code here

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

int main() {
	welcome();
	int main_menu_choice = main_menu();
	return 0;
}