#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <cctype>

void booking(int &bookingType);
std::string setRaceFormat(int);

int main() {
	int bookingType, raceFormatID;

	booking(bookingType);

	setRaceFormat(bookingType);

	system("pause");
	return 0;
}

void booking(int &bookingType) {
	std::cout << "\n\t\t1 - Solo\n"
		  << "\t\t2 - Group (Maximum 5)\n"
		  << "\t\tPlease Choose your desired booking (1 - 2): ";
	std::cin >> bookingType;

	while (bookingType != 1 && bookingType != 2) {
		std::cout << "\n\t\tPlease enter valid booking type: ";
		std::cin >> bookingType;
	}
}

std::string setRaceFormat(int bookingType) {
	int raceFormatID;	
	std::string raceFormat;

	if (bookingType == 1) {
		std::cout << "\n\t\t1 - Circuit Race\n"
			  << "\t\t2 - Sprint Race\n"
			  << "\t\t3 - Time Trial\n"
			  << "\t\t4 - Drag Race\n"
			  << "\n\t\tPlease choose the race format (1-4): ";
		std::cin >> raceFormatID;

		while (raceFormatID < 1 || raceFormatID > 4) {
			std::cout << "\n\t\tPlease enter valid race format (1-4): ";
			std::cin >> raceFormatID;
		}

		switch (raceFormatID) {
			case 1: return "Circuit race"; break;
			case 2: return "Sprint race"; break;
			case 3: return "Time trial"; break;
			default : return "Drag race"; break;
		}
	}

	else {
		std::cout << "\t5 - Elimination Race"
                	  << "\n\t\tPlease choose the race format (1-5): ";
		std::cin >> raceFormatID;
		
		while (raceFormatID < 1 || raceFormatID > 4) {
			std::cout << "\n\t\tPlease enter valid race format (1-4): ";
			std::cin >> raceFormatID;
		}

		switch (raceFormatID) {
			case 1: return "Circuit race"; break;
			case 2: return "Sprint race"; break;
			case 3: return "Time trial"; break;
			case 4: return "Drag race"; break;
			default: return "Eleminiation Race"; break;
		}
	}
	
	return "0"; //temporary
}