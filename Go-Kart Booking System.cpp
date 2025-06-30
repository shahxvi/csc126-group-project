#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <cctype>

void displayMenu();
void displayRaceFormat();
void displayTrackList();
void displayRacingGear();
void displayEngineCapacities();
std::string setBooking();

int driver(std::string &bookingType, std::string driverName[], int driverAge[], char license[]);
std::string setRaceFormat(std::string &bookingType);
std::string setTrack(std::string &bookingType, std::string &raceFormat);
void setEngineCapacity(int driverCount, std::string driverName[], int driverAge[], char license[], int engineCapacity[]);
int setLaps(int driverCount, std::string &raceFormat);
float racingGear(int driverCount, std::string driverName[], std::string helmetSize[], std::string suitSize[], int shoeSize[], float helmetPrice[], float suitPrice[], float shoePrice[], float gearPrice[]);
float setMembershipDiscount();
float calcPrice(int engineCapacity[], int laps, int driverCount, float gearPrice, float membershipDiscount);	

int main() {
	int menu;
	
	do {
		displayMenu();
		std::cout << "\n\t\tChoose your option: ";
		std::cin >> menu;
	
		while (std::cin.fail() || menu < 0 || menu > 5) {
			std::cout << "\n\t\tPlease enter the valid option (0 - 5): ";
			std::cin >> menu;
		}

		if (menu == 0)
			return 0;
		if (menu == 2) 
			displayRaceFormat();
		if (menu == 3)
			displayTrackList();
		if (menu == 4)
			displayRacingGear();
		if (menu == 5)	
			displayEngineCapacities();

	} while (menu != 1);

	char continueChoice;
	int customer = 0;

	do {
		std::string raceFormat, track;

		std::string bookingType = setBooking(); //Type 1 Function

		std::string driverName[5];
		int driverAge[5];
		char license[5];
		int driverCount;

		driverCount = driver(bookingType, driverName, driverAge, license);

		raceFormat = setRaceFormat(bookingType);

		track = setTrack(bookingType, raceFormat);

		int engineCapacity[5];

		setEngineCapacity(driverCount, driverName, driverAge, license, engineCapacity);

		int laps = setLaps(driverCount, raceFormat);

		std::string helmetSize[5], suitSize[5]; int shoeSize[5];
		float helmetPrice[5], suitPrice[5], shoePrice[5];
		float gearPrice[5];

		float totalGearPrice = racingGear(driverCount, driverName, helmetSize, suitSize, shoeSize, helmetPrice, suitPrice, shoePrice, gearPrice); 

		float membershipDiscount = setMembershipDiscount();

		float totalPrice = calcPrice(engineCapacity, laps, driverCount, totalGearPrice, membershipDiscount);

		customer++;

		std::cout << "Continue for another customer? (Y/N): ";
		std::cin >> continueChoice;

			while (std::cin.fail() || std::toupper(continueChoice) != 'Y' && std::toupper(continueChoice) != 'N') {
            			std::cout << "\n\t\tPlease enter Y or N: ";
            			std::cin >> continueChoice;
    			}

	} while (std::toupper(continueChoice) == 'Y');

	std::cout << "Total Income: RM _";
	
	system("pause");

	return 0;
}

void displayMenu() {
	std::cout << "\n\t   _____         __ __         __    ___            __    _             ____         __          "
		  << "\n\t  / ___/__  ____/ //_/__ _____/ /_  / _ )___  ___  / /__ (_)__  ___ _  / __/_ _____ / /____ __ _ "
		  << "\n\t / (_ / _ \\/___/ ,< / _ `/ __/ __/ / _  / _ \\/ _ \\/  '_// / _ \\/ _ `/ _\\ \\/ // (_-</ __/ -_)  ' \\"
		  << "\n\t \\___/\\___/   /_/|_|\\_,_/_/  \\__/ /____/\\___/\\___/_/\\_\\/_/_//_/\\_, / /___/\\_, /___/\\__/\\__/_/_/_/"
		  << "\n\t                                                              /___/      /___/                   "
    		  << "\n\t\t1 - Start Booking"
    		  << "\n\t\t2 - Race Formats"
    		  << "\n\t\t3 - Track Lists"
		  << "\n\t\t4 - Racing Gear Sizes & Prices"
    		  << "\n\t\t5 - Go-Kart Engine Capacities"
    		  << "\n\t\t0 - Exit\n";
}

void displayRaceFormat() {
	std::cout << "\n\t\tAvailable Race Formats:"
		  << "\n\t\t1 - Circuit Race"
		  << "\n\t\t2 - Sprint Race"
		  << "\n\t\t3 - Time Trial"
		  << "\n\t\t4 - Drag Race\n";
}

void displayTrackList() {
	std::cout << "\n\t\tAvailable Tracks:"
    		  << "\n\t\t1 - Section 9 Circuit"
    		  << "\n\t\t2 - Chrono Pass"
    		  << "\n\t\t3 - Rushline Dash"
    		  << "\n\t\t4 - Blackrock Circuit"
    		  << "\n\t\t5 - Torque Strip\n";
}

void displayRacingGear() {
	std::cout << "\n\t\tRacing Gears:"
		  << "\n\t\t\t\tHelmets\t\tSuits\t\tShoes\n"
		  << "\n\t\tSize S:\t\tRM 2\t\tRM 5\t\tSize 20-25 cm: RM 3"
		  << "\n\t\tSize M:\t\tRM 4\t\tRM 10\t\tSize 25-35 cm: RM 6"
		  << "\n\t\tSize L:\t\tRM 6\t\tRM 15"
		  << "\n\t\tSize XL\t\tRM 8\t\tRM 20\n";
}

void displayEngineCapacities() {
	std::cout << "\n\t\tAvailable Engine Capacities:"
		  << "\n\t\t1 - 100cc"
		  << "\n\t\t2 - 200cc"
		  << "\n\t\t3 - 270cc (with license)\n";
}

std::string setBooking() { //Booking
	int bookingTypeID;
	std::string bookingType;

	std::cout << "\n\t\t1 - Solo\n"
		  << "\t\t2 - Group (Maximum 5)\n"
		  << "\t\tPlease choose your desired booking (1 - 2): ";
	std::cin >> bookingTypeID;

	while (std:: cin.fail() || (bookingTypeID != 1 && bookingTypeID != 2)){
		std::cout << "\n\t\tPlease enter valid booking type (1 - 2): ";
		std::cin >> bookingTypeID;
	}

	if (bookingTypeID == 1) {
		return "Solo";
	}

	else {
		return "Group";
	}
}

// This was originally intended as a void function but for the setEngineCapacity function to work it needs the driverCount parameter
// and this function just so happens to be perfect for that 
int driver(std::string &bookingType, std::string driverName[], int driverAge[], char license[]) { //Driver Data
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

		while (std::cin.fail() || (driverCount < 2 || driverCount > 5)) {
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
	return driverCount;
}

std::string setRaceFormat(std::string &bookingType) { //Race Format
	int raceFormatID;	
	std::string raceFormat;

	std::cout << "\n\t\t1 - Circuit Race"
			  << "\n\t\t2 - Sprint Race"
			  << "\n\t\t3 - Time Trial"
			  << "\n\t\t4 - Drag Race";

	if (bookingType == "Solo") {
		std::cout << "\n\t\tPlease choose the race format (1 - 4): ";
		std::cin >> raceFormatID;

		while (std :: cin.fail() || (raceFormatID < 1 || raceFormatID > 4)) {
			std::cout << "\n\t\tPlease enter valid race format (1 - 4): ";
			std::cin >> raceFormatID;
		}
	}

	else {
		std::cout << "\n\t\t5 - Elimination Race"
                  << "\n\t\tPlease choose the race format (1 - 5): ";
		std::cin >> raceFormatID;
		
		while (std :: cin.fail() || (raceFormatID < 1 || raceFormatID > 5)){
			std::cout << "\n\t\tPlease enter valid race format (1 - 5): ";
			std::cin >> raceFormatID;
		}
	}
	
	switch (raceFormatID) {
		case 1: return "Circuit Race";
		case 2: return "Sprint Race";
		case 3: return "Time Trial";
		case 4: return "Drag Race";
		case 5: return "Elimination Race";
		default: return "Invalid Race Format";
	}
}

std::string setTrack(std::string &bookingType, std::string &raceFormat) { //Track
	std::string track;
	int trackID;

	if (bookingType == "Solo") {
		if (raceFormat == "Circuit Race") {
			std::cout << "\n\t\tAvailable Track: Section 9 Circuit"
					  << "\n\t\tDefaulting to said track\n";
			track = "Section 9 Circuit";
		}
		
		else if (raceFormat == "Sprint Race") {
			std::cout << "\n\t\tAvailable Track: Rushline Dash"
				  	  << "\n\t\tDefaulting to said track\n";
			track = "Rushline Dash";
		}

		else if (raceFormat == "Time Trial") {
			std::cout << "\n\t\tAvailable Track:"
				  	  << "\n\t\t1 - Section 9 Circuit"
				  	  << "\n\t\t2 - Chrono Pass"
				  	  << "\n\t\t3 - Rushline Dash"
				  	  << "\n\t\t4 - Blackrock Circuit"
				  	  << "\n\t\tPlease choose your track (1 - 4): ";
			std::cin >> trackID;

			while (std::cin.fail()|| trackID < 1 || trackID > 4){
				std::cout << "\t\tPlease choose a valid track (1 - 4): ";
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
			std::cout << "\n\t\tAvailable Track: Torque Strip"
					  << "\n\t\tDefaulting to said track\n";
			track = "Torque Strip";
		}
	}

	else { //Group
		if (raceFormat == "Circuit Race") {
			std::cout << "\n\t\tAvailable Track:"
				  	  << "\n\t\t1 - Section 9 Circuit"
				  	  << "\n\t\t2 - Blackrock Circuit"
				 	  << "\n\t\tPlease choose your track (1 - 2): ";
			std::cin >> trackID;
			
			while (std::cin.fail() || trackID < 1 || trackID > 2){
				std::cout << "\t\tPlease choose a valid track (1-2): ";
				std::cin >> trackID;
			}

			switch (trackID) {
				case 1: track = "Section 9 Circuit";
				default: track = "Blackrock Circuit";
			}
		}
		
		else if (raceFormat == "Sprint Race") {
			std::cout << "\n\t\tAvailable Track: Rushline Dash"
				  	  << "\n\t\tDefaulting to said track\n";
			track = "Rushline Dash";
		}

		else if (raceFormat == "Time Trial") {
			std::cout << "\n\t\tAvailable Track:"
					  << "\n\t\t1 - Section 9 Circuit"
				 	  << "\n\t\t2 - Chrono Pass"
					  << "\n\t\t3 - Rushline Dash"
					  << "\n\t\t4 - Blackrock Circuit"
					  << "\n\t\tPlease choose your track: ";
			std::cin >> trackID;

			while (std::cin.fail() || trackID < 1 || trackID > 4) {
				std::cout << "\t\tPlease choose a valid track (1 - 4): ";
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
			std::cout << "\n\t\tAvailable Track: Torque Strip"
					  << "\n\t\tDefaulting to said track\n";
			track = "Torque Strip";
		}

		else { // Elimination Race
			std::cout << "\n\t\tAvailable Track: Blackrock Circuit"
					  << "\n\t\tDefaulting to said track\n";
			track = "Blackrock Circuit";
		}
	}

	return track;
}

void setEngineCapacity(int driverCount, std::string driverName[], int driverAge[], char license[], int engineCapacity[]) { //Engine
	for (int i = 0; i < driverCount; i++) {
		std::cout << "\n\t\tDriver : " << driverName[i]
			  	  << "\n\t\tGo-Kart Engine Capacities Available:";

		if (driverAge[i] < 13) {
			std::cout << "\n\t\tUnder 13: Go-Kart must be under 120cc"
				 	  << "\n\t\tDefaulting to 120cc\n";
			engineCapacity[i] = 120;
		}

		else { // DriverAge > 13
			std::cout << "\n\t\t1 - 120cc"
				  	  << "\n\t\t2 - 200cc";

			if (license[i] == 'Y') {
				std::cout << "\n\t\t3 - 270cc";
				std::cout << "\n\t\tChoose your desired engine capacity (1 - 3): ";
				std::cin >> engineCapacity[i];
					
				while (std::cin.fail() || engineCapacity[i] < 1 || engineCapacity[i] > 3){
					std::cout << "\t\tPlease enter a valid engine capacity (1 - 3): ";
					std::cin >> engineCapacity[i];
				}
			}
			
			else {
				std::cout << "\n\t\tChoose your desired engine capacity (1 - 2): ";
				std::cin >> engineCapacity[i];
		 
				while (std::cin.fail() || engineCapacity[i] < 1 || engineCapacity[i] > 2){
					std::cout << "\t\tPlease enter a valid engine capacity (1 - 2): ";
					std::cin >> engineCapacity[i];
				}
			}

			switch (engineCapacity[i]) {
				case 1: engineCapacity[i] = 120;
				case 2: engineCapacity[i] = 200;
				default: engineCapacity[i] = 270;
			}
		}
	}
}

int setLaps(int driverCount, std::string &raceFormat) { //Laps
	int laps;
	if (raceFormat == "Circuit Race") {
		std::cout << "\n\t\tAvailable number of laps: 2, 3, 4"
				  << "\n\t\tHow many laps do you want?";
		std::cin >> laps;
	}
	
	else if (raceFormat == "Sprint Race" || raceFormat == "Drag Race") {
		std::cout << "\n\t\tSprint Races and Drag Races only have 1 lap\n";
		laps = 1;
	}
	
	else if (raceFormat == "Time Trial") {
		std::cout << "\n\t\tAvailable number of laps: Unlimited"
				  << "\n\t\tHow many laps do you want?";
		std::cin >> laps;
	}
	
	else {
		if (raceFormat == "Elimination Race") {
			std::cout << "\n\t\tNumber of laps corresponds with the number of drivers"
				  	  << "\n\t\tHow many laps do you want?";
			std::cin >> laps;
		}
	}
	
	return laps;
}

float racingGear(int driverCount, std::string driverName[], std::string helmetSize[], std::string suitSize[], int shoeSize[], float helmetPrice[], float suitPrice[], float shoePrice[], float gearPrice[]) { //Racing Gearh
	float totalGearPrice = 0;

	std::cout << "\n\t\tRacing Gears:"
		 	  << "\n\t\t\t\tHelmets\t\tSuits\t\tShoes\n"
			  << "\n\t\tSize S:\t\tRM 2\t\tRM 5\t\tSize 20-25 cm: RM 3"
			  << "\n\t\tSize M:\t\tRM 4\t\tRM 10\t\tSize 25-35 cm: RM 6"
			  << "\n\t\tSize L:\t\tRM 6\t\tRM 15"
			  << "\n\t\tSize XL\t\tRM 8\t\tRM 20\n";

	for (int i = 0; i < driverCount; i++) {
		std::cout << "\n\t\tDriver: " << driverName[i]
			  	  << "\n\t\tPlease choose your helmet size (S/M/L/XL): ";
		std::cin >> helmetSize[i];
		
		while (std::cin.fail() || helmetSize[i] != "S" && helmetSize[i] != "M" && helmetSize[i] != "L" && helmetSize[i] != "XL") {
			std::cout << "\n\t\tPlease choose a valid helmet size (S/M/L/XL): ";
			std::cin >> helmetSize[i];
		}
		
		if (helmetSize[i] == "S")
			helmetPrice[i] = 2;

		else if (helmetSize[i] == "M")
			helmetPrice[i] = 4;

		else if (helmetSize[i] == "L")
			helmetPrice[i] = 6;
		
		else if (helmetSize[i] == "XL")
			helmetPrice[i] = 8;
			
		std::cout << "\n\t\tPlease choose your suit size (S/M/L/XL): ";
		std::cin >> suitSize[i];

		while (std::cin.fail() || suitSize[i] != "S" && suitSize[i] != "M" && suitSize[i] != "L" && suitSize[i] != "XL"){
			std::cout << "\n\t\tPlease choose a valid suit size (S/M/L/XL): ";
			std::cin >> suitSize[i];
		}
		
		if (suitSize[i] == "S")
			suitPrice[i] = 5;
	
		else if (suitSize[i] == "M")
			suitPrice[i] = 10;
		
		else if (suitSize[i] == "L")
			suitPrice[i] = 15;
		
		else if (suitSize[i] == "XL")
			suitPrice[i] = 20;

		std::cout << "\n\t\tPlease choose your shoe size (20 - 35): ";
		std::cin >> shoeSize[i];
		
		while (std::cin.fail() || shoeSize[i] < 20 || shoeSize[i] > 35){
			std::cout << "\n\t\tPlease choose a valid shoe size (20 - 35): ";
			std::cin >> shoeSize[i];
		}
		
		if (shoeSize[i] <= 25)
			shoePrice[i] = 3;
	
		else 
			shoePrice[i] = 6;

		gearPrice[i] = helmetPrice[i] + suitPrice[i] + shoePrice[i];

		totalGearPrice += gearPrice[i];
	}
	return totalGearPrice;
}

float setMembershipDiscount() { //Membership
	char membership;	

	std::cout << "\n\t\tDo you have a membership? (Y/N): ";
	std::cin >> membership;

	if(std::toupper(membership) == 'Y')
		return 0.1;
	else
		return 0.0;
}

float calcPrice(int engineCapacity[], int laps, int driverCount, float totalGearPrice, float membershipDiscount) { //Price
	const float pricePerCC = 0.3;
	float totalKartPrice = 0;
	
	for (int i = 0; i < driverCount; i++)
		totalKartPrice += engineCapacity[i] * pricePerCC * laps;
	
	float finalPrice = (totalKartPrice + totalGearPrice) * (1 - membershipDiscount);
	return finalPrice;
}
