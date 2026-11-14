#include <iostream>
#include <vector>
#include <string>

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

int main() {
	welcome();
	return 0;
}