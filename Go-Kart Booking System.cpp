#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <cctype>

void booking(int &bookingType);
std::string setRaceFormat(int);
std::string setEnvironment();

int main() {
	int bookingType;
	std::string raceFormat, environment, track;

	booking(bookingType);

	raceFormat = setRaceFormat(bookingType);

	environment = setEnvironment();

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

	std::cout << "\n\t\t1 - Circuit Race\n"
		  << "\t\t2 - Sprint Race\n"
		  << "\t\t3 - Time Trial\n"
		  << "\t\t4 - Drag Race\n";

	if (bookingType == 1) {
		std::cout << "\n\t\tPlease choose the race format (1-4): ";
		std::cin >> raceFormatID;

		while (raceFormatID < 1 || raceFormatID > 4) {
			std::cout << "\n\t\tPlease enter valid race format (1-4): ";
			std::cin >> raceFormatID;
		}

		switch (raceFormatID) {
			case 1: return "Circuit Race"; break;
			case 2: return "Sprint Race"; break;
			case 3: return "Time Trial"; break;
			default : return "Drag Race"; break;
		}
	}

	else {
		std::cout << "\t\t5 - Elimination Race"
                	  << "\n\t\tPlease choose the race format (1-5): ";
		std::cin >> raceFormatID;
		
		while (raceFormatID < 1 || raceFormatID > 5) {
			std::cout << "\n\t\tPlease enter valid race format (1-5): ";
			std::cin >> raceFormatID;
		}

		switch (raceFormatID) {
			case 1: return "Circuit Race"; break;
			case 2: return "Sprint Race"; break;
			case 3: return "Time Trial"; break;
			case 4: return "Drag Race"; break;
			default: return "Elimination Race"; break;
		}
	}
	
	return "\n\t\tInvalid Race Format";
}

std::string setEnvironment() {
	int environmentID;

	std::cout << "\n\t\t1 - Indoor\n"
		  << "\t\t2 - Outdoor\n"
		  << "\t\tPlease enter your desired racing environment (1/2): ";
	std::cin >> environmentID;

	while (environmentID < 1 || environmentID > 2) {
		std::cout << "\n\t\tPlease enter valid racing environment (1/2): ";
		std::cin >> environmentID;
	}

	switch (environmentID) {
		case 1: return "Indoor";
		default: return "Outdoor";
	}

	return "Invalid Environment";
}