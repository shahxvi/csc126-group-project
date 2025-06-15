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
int setEngineCapacity(int x);

int main() {
    	int ID = 0;

	std::cout << "Welcome to the Go-Kart Booking System!" << std::endl;

	std::cout << "Racing Formats\n"
		  << "1 - Circuit\n"
		  << "2 - Sprint\n"
		  << "3 - Time Trial\n"
		  << "4 - Drag\n"
		  << "5 - Elimination\n";
    	std::cout << "Please enter your desired racing format (1-5): ";
    	std::cin >> ID;
	
	while (ID < 1 || ID > 5) {
		std::cout << "Please choose correct racing format (1-5): ";
		std::cin >> ID;
	}

    	std::string raceFormat = setRaceFormat(ID);

        std::cout << "You have chosen: " << raceFormat << std::endl;

	std::cout << "\nGo-Kart Engine Capacities:\n"
		  << "120cc\n"
	          << "200cc\n"
		  << "270cc\n";
	
	std::cout << "Please enter your desired Go-Kart engine Capacity (120, 200, 270): ";
	std::cin >> ID;
	
	int engineCapacity = setEngineCapacity(ID);

	std::cout << "You have chosen: " << engineCapacity << "cc" << std::endl;

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
        	default:
            		return "Elimination Race";
    }
}

int setEngineCapacity(int x) {
	if (x == 120)
		return 120;
	if (x == 200)
		return 200;
	return 270;
}

