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
// Please update the comment line of the prototype function.

#include <iostream>
#include <string>
#include <iomanip>

void booking(int &bookingType, int &driverCount, int driverAge[], std::string driverName[], char license[]); //line 86
std::string setRaceFormat(int x);		// Line 136
// Insert Track Selection Function Prototype
// Intert Environment Function Prototype
int setEngineCapacity(int x);			// Line 153
int setMembershipDiscount(char &membership);	// Line 162
// Insert Price Calculation Prototype	

int main() {
    	int bookingType, driverCount = 0, driverAge[5];
	std::string driverName[5];
	char license[5];
	int racingFormatID;
	int engineCapacityID;
	char membership;

	std::cout << "Welcome to the Go-Kart Booking System!" << std::endl;

	std::cout << "\nBooking Type:\n"
		  << "1. Solo\n"
		  << "2. Group (Max 5)\n";
	std::cout << "Please choose your booking type: ";
	std::cin >> bookingType;

	booking(bookingType, driverCount, driverAge, driverName, license);
	
	std::cout << "\nRacing Formats\n"
		  << "1 - Circuit\n"
		  << "2 - Sprint\n"
		  << "3 - Time Trial\n"
		  << "4 - Drag\n"
		  << "5 - Elimination\n";
    	std::cout << "Please enter your desired racing format (1-5): ";
    	std::cin >> racingFormatID;
	
	while (racingFormatID < 1 || racingFormatID > 5) {
		std::cout << "Please choose correct racing format (1-5): ";
		std::cin >> racingFormatID;
	}

    	std::string raceFormat = setRaceFormat(racingFormatID);

        std::cout << "You have chosen: " << raceFormat << std::endl;

	std::cout << "\nGo-Kart Engine Capacities:\n"
		  << "120cc\n"
		  << "200cc\n"
		  << "270cc\n";

	std::cout << "Please enter your desired Go-Kart engine Capacity (120, 200, 270): ";
	std::cin >> engineCapacityID;
	
	int engineCapacity = setEngineCapacity(engineCapacityID);

	std::cout << "You have chosen: " << engineCapacity << "cc" << std::endl;
	
	int membershipDicount = setMembershipDiscount(membership);

	if (driverCount == 1) { 
		std::cout << "\nDriver Name: " << driverName[0] << std::endl;
		std::cout << "Driver Age: " << driverAge[0] << std::endl;
		std::cout << "Driver's License: " << license[0] << std::endl;	

	}	
	system("pause"); // To prevent the console from closing immediately
    	return 0;
}

// 1 - Booking Type Function
void booking(int &bookingType, int &driverCount, int driverAge[], std::string driverName[], char license[]) {
	
	while (bookingType < 1 || bookingType > 2) {
		std::cout << "Please choose a valid booking type (1 or 2): ";
		std::cin >> bookingType;
	}

	if(bookingType == 1) {	// Solo Booking
		driverCount = 1;
		std::cout << "\nPlease enter your name: ";
		std::cin >> driverName[0];
		
		std::cout << "Please enter your age: ";
		std::cin >> driverAge[0];
		
		// Will check driver age at the set engine capacity function
		
		std::cout << "Do you have a driving license? (Y/N): ";
		std::cin >> license;
		license[0] = toupper(license[0]);
	}
	
	else {	// Group Booking
		std::cout << "Please enter the total number of drivers: ";
		std::cin >> driverCount;
		
		while (driverCount < 1 || driverCount > 5) {
			std::cout << "Please enter a valid number of drivers (1-5): ";
			std::cin >> driverCount;
		}

		for (int i = 0; i < driverCount; i++) {
			std::cout << "Please enter the name of driver " << (i + 1) << ": ";
			std::cin >> driverName[i];
			
			std::cout << "Please enter the age of driver " << (i + 1) << ": ";
			std::cin >> driverAge[i];
			
			// Will check driver age at the set engine capacity function
			
			std::cout << "Does driver " << (i + 1) << " have a driving license? (Y/N): ";
			std::cin >> license[i];
			license[i] = toupper(license[i]);
		}
	}
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
int setMembershipDiscount(char &membership) {
	std::cout << "Do you have a membership? (Y/N): ";
	std::cin >> membership;
	membership = toupper(membership);
	
	if(membership == 'Y')
		return 0.1;
	
	else
		return 0;
}
