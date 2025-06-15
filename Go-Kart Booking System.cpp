// CSC126 Group Project
// Go-Kart Booking System

// IRFAN SHAH BIN MAIZUL HISHAM       (2025171523)  (RCDCS1101A) (shahxvi)
// SHAHRIN AREFF SHAH BIN SHAH RIZAL  (2025151503)  (RCDCS1101A) (rinnnnnnn17)
// MUHAMMAD BIN ABDUL AZIZ            (2025507823)  (RCDCS1101B) (Kundoo)

// SUPERVISED BY MADAM NORA YANTI BINTI CHE JAN

#include <iostream>
#include <string>
#include <iomanip>

std::string setRaceFormat(int x);

int main() {
    int ID = 0;

    std::cout << "Welcome to the Go-Kart Booking System!" << std::endl;
    std::cout << "Please enter your desired racing format (1-5): ";
    std::cin >> ID;

    std::string chosenFormat = setRaceFormat(ID);

    if (chosenFormat.empty()) {
        std::cout << "Invalid racing format selected." << std::endl;
    } else {
        std::cout << "You have chosen: " << chosenFormat << std::endl;
    }

    return 0;
}

std::string setRaceFormat(int x) {
    switch (x) {
        case 1:
            return "Circuit Race";
        case 2:
            return "Sprint Race";
        case 3:
            return "Time Trial";
        case 4:
            return "Drag Race";
        case 5:
            return "Elimination Race";
        default:
            return "";
    }
}
