#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <cctype>

std::string setBooking();
void driver(std::string &bookingType, std::string driverName[], int driverAge[], char license[]); 
std::string setRaceFormat(std::string &bookingType);
std::string setTrack(std::string bookingType, std::string raceFormat);

int main() {
	std::string raceFormat, track;

	std::string bookingType = setBooking(); //Type 1 Function

	std::string driverName[5];
	int driverAge[5];
	char license[5];
	int driverCount;
	
	driver(bookingType, driverName, driverAge, license);

	raceFormat = setRaceFormat(bookingType);

	track = setTrack(bookingType, raceFormat);

	system("pause");
	return 0;
}

std::string setBooking() {
	int bookingTypeID;
	std::string bookingType;

	std::cout << "\n\t\t1 - Solo\n"
		  << "\t\t2 - Group (Maximum 5)\n"
		  << "\t\tPlease Choose your desired booking (1 - 2): ";
	std::cin >> bookingTypeID;

	while (bookingTypeID != 1 && bookingTypeID != 2) {
		std::cout << "\n\t\tPlease enter valid booking type: ";
		std::cin >> bookingTypeID;
	}

	if (bookingTypeID == 1) {
		return "Solo";
	}

	else {
		return "Group";
	}
}

void driver(std::string &bookingType, std::string driverName[], int driverAge[], char license[]) {
	int driverCount;
	
	if (bookingType == "Solo") {
		driverCount = 1;
		
		std::cout << "\n\t\tDriver Name: ";
		std::cin >> driverName[0];

		std::cout << "\t\tDriver Age: ";
		std::cin >> driverAge[0];

		std::cout << "\t\tDo you have a driver's license? (Y/N): ";
		std::cin >> license[0];
	}
	
	else {
		std::cout << "\t\tPlease enter the number of drivers (2 - 5): ";
		std::cin >> driverCount;

		while (driverCount < 2 || driverCount > 5) {
			std::cout << "\t\tPlease enter a valid number of drivers: ";
			std::cin >> driverCount;
		}
	
		for (int i = 0; i < driverCount; i++) {
		
		std::cout << "\n\t\tDriver #" << (i+1) << " Name: ";
		std::cin >> driverName[i];

		std::cout << "\t\tDriver #" << (i+1) << " Age: ";
		std::cin >> driverAge[i];

		std::cout << "\t\tDoes Driver #" << (i+1) << " has a license? (Y/N): ";
		std::cin >> license[i];
		}
	}
}

std::string setRaceFormat(std::string &bookingType) {
	int raceFormatID;	
	std::string raceFormat;

	std::cout << "\n\t\t1 - Circuit Race\n"
		  << "\t\t2 - Sprint Race\n"
		  << "\t\t3 - Time Trial\n"
		  << "\t\t4 - Drag Race\n";

	if (bookingType == "Solo") {
		std::cout << "\n\t\tplease choose the race format (1-4): ";
		std::cin >> raceFormatID;

		while (raceFormatID < 1 || raceFormatID > 4) {
			std::cout << "\n\t\tPlease enter valid race format (1-4): ";
			std::cin >> raceFormatID;
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
	}
	
	switch (raceFormatID) {
		case 1: return "Circuit Race"; break;
		case 2: return "Sprint Race"; break;
		case 3: return "Time Trial"; break;
		case 4: return "Drag Race"; break;
		case 5: return "Elimination Race"; break;
	}

	return "\n\t\tInvalid Race Format";
}


std::string setTrack(std::string bookingType, std::string raceFormat) {
	std::string track;
	int trackID;

	if (bookingType == "Solo") {
		if (raceFormat == "Circuit Race") {
			std::cout << "\n\t\tAvailable Track: Section 9 Circuit\n"
				  << "\t\tDefaulting to said track";
			track = "Section 9 Circuit";
		}
		
		else if (raceFormat == "Sprint Race") {
			std::cout << "\n\t\tAvailable Track: Rushline Dash\n"
				  << "\t\tDefaulting to said track";
			track = "Rushline Dash";
		}

		else if (raceFormat == "Time Trial") {
			std::cout << "\n\t\tAvailable Track:\n"
				  << "\t\t1 - Section 9 Circuit\n"
				  << "\t\t2 - Chrono Pass\n"
				  << "\t\t3 - Rushline Dash\n"
				  << "\t\t4 - Blackrock Circuit\n"
				  << "\t\tPlease choose your track";
			std::cin >> trackID;

			while (trackID < 1 || trackID > 4) {
				std::cout << "\t\tPlease choose a valid track (1-4): ";
				std::cin >> trackID;
			}

			switch (trackID) {
				case 1: track = "Section 9 Circuit";
				case 2: track = "Chrono Pass";
				case 3: track = "Rushline Dash";
				default: track = "Blackrock Circuit";
			}
		}

		else {
			std::cout << "\n\t\tAvailable Track: Torque Strip\n"
					<< "\t\tDefaulting to said track";
			track = "Torque Strip";
		}
	}

	else { //Group
		if (raceFormat == "Circuit Race") {
			std::cout << "\n\t\tAvailable Track:\n"
				  << "\t\t1 - Section 9 Circuit\n"
				  << "\t\t2 - Blackrock Circuit\n"
				  << "\t\tPlease choose your track";
			std::cin >> trackID;
			
			while (trackID < 1 || trackID > 2) {
				std::cout << "\t\tPlease choose a valid track (1-2)";
				std::cin >> trackID;
			}

			switch (trackID) {
				case 1: track = "Section 9 Circuit";
				default: track = "Blackrock Circuit";
			}
		}
		
		else if (raceFormat == "Sprint Race") {
			std::cout << "\n\t\tAvailable Track: Rushline Dash\n"
				  << "\t\tDefaulting to said track";
			track = "Rushline Dash";
		}

		else if (raceFormat == "Time Trial") {
			std::cout << "\n\t\tAvailable Track:\n"
				  << "\t\t1 - Section 9 Circuit\n"
				  << "\t\t2 - Chrono Pass\n"
				  << "\t\t3 - Rushline Dash\n"
				  << "\t\t4 - Blackrock Circuit\n"
				  << "\t\tPlease choose your track";
			std::cin >> trackID;

			while (trackID < 1 || trackID > 4) {
				std::cout << "\t\tPlease choose a valid track (1-4): ";
				std::cin >> trackID;
			}

			switch (trackID) {
				case 1: track = "Section 9 Circuit";
				case 2: track = "Chrono Pass";
				case 3: track = "Rushline Dash";
				default: track = "Blackrock Circuit";
			}
		}

		else if (raceFormat == "Drag Race") {
			std::cout << "\n\t\tAvailable Track: Torque Strip\n"
					<< "\t\tDefaulting to said track";
			track = "Torque Strip";
		}

		else { // Elimination Race
			std::cout << "\n\t\tAvailable Track: Blackrock Circuit\n"
				  << "\t\tDefaulting to said track";
			track = "Blackrock Circuit";
	
		}
	}

	return track;
}

float setMembershipDiscount(char membership) {
	if(toupper(membership) == 'Y')
		return 0.1;
	else
		return 0;
}

int setEngineCapacity(int cc) {
	while (cc != 120 && cc != 200 && cc != 200) {
		std::cout << "Please input valid engine capacity: ";
		std::cin >> cc;
	}	
	return cc;
}

float calcPrice(int engineCapacity, int laps, float gearPrice, float membershipDiscount) {
	const float PRICEPERCC = 0.3;
	float kartPrice = engineCapacity * PRICEPERCC;
	float totalKartPrice = kartPrice * laps;
	float finalPrice = (totalKartPrice + gearPrice) * (1 - membershipDiscount);
	return finalPrice;
}
