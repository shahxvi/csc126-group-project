// CSC126 Group Project
// Go-Kart Booking System

// IRFAN SHAH BIN MAIZUL HISHAM       (2025171523)  (RCDCS1101A) (shahxvi)
// SHAHRIN AREFF SHAH BIN SHAH RIZAL  (2025151503)  (RCDCS1101A) (rinnnnnnn17)
// MUHAMMAD BIN ABDUL AZIZ            (2025507823)  (RCDCS1101B) (Kundoo)

// SUPERVISED BY MADAM NORA YANTI BINTI CHE JAN

// READ THIS BEFORE MAKING ANY CHANGES:
// Function Prototypes are defined at the top of the code.
// Each function should be defined below the main function.
// This ensures readability and maintainability of the code.

#include <iostream>
#include <string>
#include <iomanip>

void booking(int &bookingType, int &driverCount, int &driverAge, std::string &driverName, char &license);
std::string setRaceFormat(int x);
// Insert Track Selection Function Prototype
// Intert Environment Function Prototype
int setEngineCapacity(int x);
int membershipDiscount(char &membership);
// Insert Price Calculation Prototype

int main() {
    	int ID = 0;
    	int bookingType, driverCount = 0, driverAge = 0;
	std::string driverName;
	char license, membership;

	std::cout << "Welcome to the Go-Kart Booking System!" << std::endl;

	std::cout << "Booking Type:\n"
		  << "1. Solo\n"
		  << "2. Group (max 5)\n";
	std::cout << "Please choose your booking type: ";
	std::cin >> bookingType;

	booking(bookingType, driverCount, driverAge, driverName, license);
	
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
	
	int membershipFunc = membershipDiscount(membership);
	
	system("pause"); // To prevent the console from closing immediately
    	return 0;
}

// 1 - Booking Type Function
void booking(int &bookingType, int &driverCount, int &driverAge, std::string &driverName, char &license) {
	
	if(bookingType == 1) {
		driverCount = 1;
		std::cout << "Please enter your name: ";
		std::cin >> driverName;
		
		std::cout << "Please enter your age: ";
		std::cin >> driverAge;
		
		if(driverAge < 13)
			int engineCapacity = 120;
		
		std::cout << "Do you have a driving license? (Y/N): ";
		std::cin >> license;
		license = toupper(license);
	}
	
	else if(bookingType == 2) {
		std::cout << "Please enter the total number of drivers: ";
		std::cin >> driverCount;
		
		if(driverCount < 2 || driverCount > 5)
			std::cout << "Exceeded the maximum number of drivers.\n";
		
		else
			std::cout << "Arrayy";
	}
	
	else
		std::cout << "Please choose a correct booking type (1 or 2).\n";
}


// 2 - Set Race Format Function
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

// 5 - Set Go-Kart Engine Capacity Function
int setEngineCapacity(int x) {
	if (x == 120)
		return 120;
	if (x == 200)
		return 200;
	return 270;
}

// 6 - Membership Discount Function
int membershipDiscount(char &membership) {
	std::cout << "Do you have a membership? (Y/N): ";
	std::cin >> membership;
	membership = toupper(membership);
	
	if(membership == 'Y')
		return 0.1;
	
	else
		return 0;
}