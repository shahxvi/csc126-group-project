// CSC126 Group Project
// Go-Kart Booking System

// IRFAN SHAH BIN MAIZUL HISHAM		(2025171523) (shahxvi)
// SHAHRIN AREFF SHAH BIN SHAH RIZAL	(2025151503) (rinnnnnn17)
// MUHAMMAD BIN ABDUL AZIZ		(2025507823) (Kundoo)

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <cctype>
#include <algorithm>

void displayMenu();
void displayRaceFormat(std::string bookingType);
void displayTrackList();
void displayRacingGear();
void displayEngineCapacities(int age, char license);

std::string setBooking();
int driver(std::string& bookingType, std::string driverName[], int driverAge[], char license[]);
std::string setRaceFormat(std::string& bookingType);
std::string setTrack(std::string& bookingType, std::string& raceFormat);
void setEngineCapacity(int driverCount, std::string driverName[], int driverAge[], char license[], int engineCapacity[]);
int setLaps(int driverCount, std::string& raceFormat);
float selectHelmet(int i, std::string helmetSize[], float helmetPrice[]);
float selectSuit(int i, std::string suitSize[], float suitPrice[]);
float selectShoe(int i, int shoeSize[], float shoePrice[]);
float racingGear(int driverCount, std::string driverName[], std::string helmetSize[], std::string suitSize[], int shoeSize[], float helmetPrice[], float suitPrice[], float shoePrice[], float gearPrice[]);
float setMembershipDiscount();
float calcPrice(int engineCapacity[], int laps, int driverCount, float gearPrice, float membershipDiscount);	

int main()
{
	// Main Selection Menu
	int menu;
	
	do {
		displayMenu();
		std::cout << "\n\t\t\tChoose your option: ";
		std::cin >> menu;

		while (std::cin.fail() || (menu < 0 || menu > 5)) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "\n\t\t\tPlease enter the valid option (0 - 5): ";
			std::cin >> menu;
		}

		if (menu == 0)
			return 0;
		if (menu == 2) {
			system("cls");
			displayRaceFormat("Group");	// Parameters to allow the menu to show every option
		}
		if (menu == 3) {
			system("cls");
			displayTrackList();
		}
		if (menu == 4) {
			system("cls");
			displayRacingGear();
		}
		if (menu == 5) {
			system("cls");
			displayEngineCapacities(18, 'Y');	// Parameters to allow the menu to show every option
		}

	} while (menu != 1);

	// Go-Kart Booking System Crux
	char continueChoice;
	int customer = 0;
	float totalIncome = 0;

	do {

		std::string bookingType = setBooking(); //Type 1 Function

		std::string driverName[5];
		int driverAge[5];
		char license[5];
		int driverCount;

		driverCount = driver(bookingType, driverName, driverAge, license);

		std::string raceFormat = setRaceFormat(bookingType);

		std::string track = setTrack(bookingType, raceFormat);

		int engineCapacity[5];

		setEngineCapacity(driverCount, driverName, driverAge, license, engineCapacity);

		int laps = setLaps(driverCount, raceFormat);

		std::string helmetSize[5], suitSize[5]; int shoeSize[5];
		float helmetPrice[5], suitPrice[5], shoePrice[5];
		float gearPrice[5];

		float totalGearPrice = racingGear(driverCount, driverName, helmetSize, suitSize, shoeSize, helmetPrice, suitPrice, shoePrice, gearPrice); 

		float membershipDiscount = setMembershipDiscount();

		float totalPrice = calcPrice(engineCapacity, laps, driverCount, totalGearPrice, membershipDiscount);

		std::cout << "\n\t\t\tRace Format: " << raceFormat
			  << "\n\t\t\tTrack: " << track << "\n";


		for (int i = 0; i < driverCount; i++) {
			std::cout << "\n\t\t\tDriver: " << driverName[i]
				  << "\n\t\t\tAge: " << driverAge[i]
				  << "\n\t\t\tHas License: " << license[i]
				  << "\n\t\t\tEngine Capacity :" << engineCapacity[i] << "cc"
				  << "\n\t\t\tHelmet Size: " << helmetSize[i]
				  << "\n\t\t\tHelmet Price: RM" << helmetPrice[i]
				  << "\n\t\t\tSuit Size: " << suitSize[i]
				  << "\n\t\t\tSuitPrice: RM" << suitPrice[i]
				  << "\n\t\t\tShoe Size : " << shoeSize[i] << "cm"
				  << "\n\t\t\tShoe Price: RM" << shoePrice[i]
				  << "\n\t\t\tTotal Gear Price: RM" << totalGearPrice;
		}
		
		std::cout << "\n\t\t\tTotal : RM" << totalPrice;

		totalIncome += totalPrice;
		customer++;

		std::cout << "\n\t\t\tContinue for another customer? (Y/N): ";
		std::cin >> continueChoice;

			while (std::cin.fail() || std::toupper(continueChoice) != 'Y' && std::toupper(continueChoice) != 'N') {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
            			std::cout << "\n\t\t\tPlease enter Y or N: ";
            			std::cin >> continueChoice;
    			}

	} while (std::toupper(continueChoice) == 'Y');

	std::cout << "\n\t\t\tTotal Income: RM " << totalIncome << "\n";
	
	system("pause");

	return 0;
}

void displayMenu()
{
	std::cout << "\t_________            ______ __             _____  ________            ______ _____                 ________              _____                 "
		  << "\n\t__  ____/_____       ___  //_/_____ _________  /_ ___  __ )______________  /____(_)_____________ _ __  ___/____  __________  /____________ ___ "
		  << "\n\t_  / __ _  __ \\________  ,<  _  __ `/_  ___/  __/ __  __  |  __ \\  __ \\_  //_/_  /__  __ \\_  __ `/ _____ \\__  / / /_  ___/  __/  _ \\_  __ `__ \\"
		  << "\n\t/ /_/ / / /_/ //_____/  /| | / /_/ /_  /   / /_   _  /_/ // /_/ / /_/ /  ,<  _  / _  / / /  /_/ /  ____/ /_  /_/ /_(__  )/ /_ /  __/  / / / / /"
		  << "\n\t\\____/  \\____/       /_/ |_| \\__,_/ /_/    \\__/   /_____/ \\____/\\____//_/|_| /_/  /_/ /_/_\\__, /   /____/ _\\__, / /____/ \\__/ \\___//_/ /_/ /_/ "
		  << "\n\t                                                                                         /____/           /____/                               "
    		  << "\n\t\t\t1 - Start Booking"
    		  << "\n\t\t\t2 - Race Formats"
    		  << "\n\t\t\t3 - Track Lists"
		  << "\n\t\t\t4 - Racing Gear Sizes & Prices"
    		  << "\n\t\t\t5 - Go-Kart Engine Capacities"
    		  << "\n\t\t\t0 - Exit\n";
}

void displayRaceFormat(std::string bookingType)
{
	std::cout << "\n\t\t\tAvailable Race Formats:"
		  << "\n\t\t\t1 - Circuit Race"
		  << "\n\t\t\t2 - Sprint Race"
		  << "\n\t\t\t3 - Time Trial"
		  << "\n\t\t\t4 - Drag Race";
	if (bookingType == "Group") {
		std::cout << "\n\t\t\t5 - Eliminationn Race (Group)\n";
	}
}

void displayTrackList()
{
	std::cout << "\n\t\t\tAvailable Tracks:"
    		  << "\n\t\t\t1 - Section 9 Circuit"
    		  << "\n\t\t\t2 - Chrono Pass"
    		  << "\n\t\t\t3 - Rushline Dash"
    		  << "\n\t\t\t4 - Blackrock Circuit"
    		  << "\n\t\t\t5 - Torque Strip\n";
}

void displayRacingGear()
{
	std::cout << "\n\t\t\tRacing Gears:"
		  << "\n\t\t\t\t\t\tHelmets\t\t\tSuits\t\t\tShoes\n"
		  << "\n\t\t\tSize S:\t\t\tRM 2\t\t\tRM 5\t\t\tSize 20-25 cm: RM 3"
		  << "\n\t\t\tSize M:\t\t\tRM 4\t\t\tRM 10\t\t\tSize 25-35 cm: RM 6"
		  << "\n\t\t\tSize L:\t\t\tRM 6\t\t\tRM 15"
		  << "\n\t\t\tSize XL\t\t\tRM 8\t\t\tRM 20\n";
}

void displayEngineCapacities(int age, char license)
{ 
	std::cout << "\n\t\t\tAvailable Engine Capacities:";
	std::cout << "\n\t\t\t1 - 100cc (Under 13)";
	if (age >= 18) {
		std::cout << "\n\t\t\t2 - 200cc";
		if (license == 'Y')
			std::cout << "\n\t\t\t3 - 270cc (Requires License)\n";
	}
}

std::string setBooking()
{
	int bookingTypeID;
	std::string bookingType;

	std::cout << "\n\t\t\t1 - Solo\n"
		  << "\t\t\t2 - Group (Maximum 5)\n"
		  << "\t\t\tPlease choose your desired booking (1 - 2): ";
	std::cin >> bookingTypeID;

	while (std:: cin.fail() || (bookingTypeID != 1 && bookingTypeID != 2)){
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "\n\t\t\tPlease enter valid booking type (1 - 2): ";
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
int driver(std::string& bookingType, std::string driverName[], int driverAge[], char license[])
{
	int driverCount;
	
	if (bookingType == "Solo") {
		driverCount = 1;
	}
	else {
		std::cout << "\t\t\tPlease enter the number of drivers (2 - 5): ";
		std::cin >> driverCount;

		while (std::cin.fail() || (driverCount < 2 || driverCount > 5)) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "\t\t\tPlease enter a valid number of drivers: ";
			std::cin >> driverCount;
		}

		std::cin.ignore();
	}

	for (int i = 0; i < driverCount; i++) {
		std::cout << "\n\t\t\tDriver #" << (i+1) << " Name: ";
		std::getline(std::cin, driverName[i]);

		std::cout << "\t\t\tDriver #" << (i+1) << " Age: ";
		std::cin >> driverAge[i];

		std::cout << "\t\t\tDoes Driver #" << (i+1) << " has a license? (Y/N): ";
		std::cin >> license[i];
		
		while(!isalpha(license[i]) || isdigit(license[i])) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "\t\t\tPlease enter a valid input (Y/N): ";
			std::cin >> license[i];
		}
	}
	return driverCount;
}

std::string setRaceFormat(std::string& bookingType)
{
	int raceFormatID;	
	std::string raceFormat;

	displayRaceFormat(bookingType);

	if (bookingType == "Solo") {
		std::cout << "\n\t\t\tPlease choose the race format (1 - 4): ";
		std::cin >> raceFormatID;

		while (std :: cin.fail() || (raceFormatID < 1 || raceFormatID > 4)) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "\n\t\t\tPlease enter valid race format (1 - 4): ";
			std::cin >> raceFormatID;
		}
	}
	else {
                std::cout << "\n\t\t\tPlease choose the race format (1 - 5): ";
		std::cin >> raceFormatID;
		
		while (std:: cin.fail() || (raceFormatID < 1 || raceFormatID > 5)){
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "\n\t\t\tPlease enter valid race format (1 - 5): ";
			std::cin >> raceFormatID;
		}
	}
	
	switch (raceFormatID) {
		case 1: return "Circuit Race"; break;
		case 2: return "Sprint Race"; break;
		case 3: return "Time Trial"; break;
		case 4: return "Drag Race"; break;
		case 5: return "Elimination Race"; break;
		default: return "Invalid Race Format"; break;
	}
}

std::string setTrack(std::string& bookingType, std::string& raceFormat)
{
	int trackID;

	if (bookingType == "Solo" || raceFormat == "Circuit Race") {
		std::cout << "\n\t\t\tAvailable Track: Section 9 Circuit"
			  << "\n\t\t\tDefaulting to said track\n";
		return "Section 9 Circuit";
	}
	else if (bookingType == "Solo" || raceFormat == "Sprint Race") {
		std::cout << "\n\t\t\tAvailable Track: Rushline Dash"
			  << "\n\t\t\tDefaulting to said track\n";
		return "Rushline Dash";
	}
	else if (bookingType == "Solo" || raceFormat == "Time Trial") {
		std::cout << "\n\t\t\tAvailable Track:"
			  << "\n\t\t\t1 - Section 9 Circuit"
			  << "\n\t\t\t2 - Chrono Pass"
			  << "\n\t\t\t3 - Rushline Dash"
			  << "\n\t\t\t4 - Blackrock Circuit"
			  << "\n\t\t\tPlease choose your track (1 - 4): ";
		std::cin >> trackID;

		while (std::cin.fail()|| trackID < 1 || trackID > 4){
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "\t\t\tPlease choose a valid track (1 - 4): ";
			std::cin >> trackID;
		}

		switch (trackID) {
			case 1: return "Section 9 Circuit";
			case 2: return "Chrono Pass";
			case 3: return "Rushline Dash";
			default: return "Blackrock Circuit";
		}
	}
	else if (bookingType == "Solo" || raceFormat == "Drag Race") {
		std::cout << "\n\t\t\tAvailable Track: Torque Strip"
				  << "\n\t\t\tDefaulting to said track\n";
		return "Torque Strip";
	}

	else if (bookingType == "Group" || raceFormat == "Circuit Race") {
		std::cout << "\n\t\t\tAvailable Track:"
			  << "\n\t\t\t1 - Section 9 Circuit"
			  << "\n\t\t\t2 - Blackrock Circuit"
			  << "\n\t\t\tPlease choose your track (1 - 2): ";
		std::cin >> trackID;
		
		while (std::cin.fail() || trackID < 1 || trackID > 2){
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "\t\t\tPlease choose a valid track (1-2): ";
			std::cin >> trackID;
		}

		switch (trackID) {
			case 1: return "Section 9 Circuit";
			default: return "Blackrock Circuit";
		}
	}
	
	else if (bookingType == "Group" || raceFormat == "Sprint Race") {
		std::cout << "\n\t\t\tAvailable Track: Rushline Dash"
				  << "\n\t\t\tDefaulting to said track\n";
		return "Rushline Dash";
	}

	else if (bookingType == "Group" || raceFormat == "Time Trial") {
		std::cout << "\n\t\t\tAvailable Track:"
			  << "\n\t\t\t1 - Section 9 Circuit"
			  << "\n\t\t\t2 - Chrono Pass"
			  << "\n\t\t\t3 - Rushline Dash"
			  << "\n\t\t\t4 - Blackrock Circuit"
			  << "\n\t\t\tPlease choose your track: ";
		std::cin >> trackID;

		while (std::cin.fail() || trackID < 1 || trackID > 4) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "\t\t\tPlease choose a valid track (1 - 4): ";
			std::cin >> trackID;
		}

		switch (trackID) {
			case 1: return "Section 9 Circuit";
			case 2: return "Chrono Pass";
			case 3: return "Rushline Dash";
			default: return "Blackrock Circuit";
		}
	}

	else if (bookingType == "Group" || raceFormat == "Drag Race") {
		std::cout << "\n\t\t\tAvailable Track: Torque Strip"
			  << "\n\t\t\tDefaulting to said track\n";
		return "Torque Strip";
	}

	else if (bookingType == "Group" || raceFormat == "Elimination Race") {
		std::cout << "\n\t\t\tAvailable Track: Blackrock Circuit"
			  << "\n\t\t\tDefaulting to said track\n";
		return "Blackrock Circuit";
	}
	return "Track"; // Should never get to this point
}

void setEngineCapacity(int driverCount, std::string driverName[], int driverAge[], char license[], int engineCapacity[])
{
	for (int i = 0; i < driverCount; i++) {
		std::cout << "\n\t\t\tDriver : " << driverName[i];

		displayEngineCapacities(driverAge[i], license[i]);

		if (driverAge[i] < 13) {
			std::cout << "\n\t\t\tDriver under 13: Go-Kart must be under 200cc"
				  << "\n\t\t\tDefaulting to 120cc\n";
			engineCapacity[i] = 1;
		}

		// Over 13 with License
		else if (driverAge[i] > 13 && license[i] == 'Y') {
			std::cout << "\n\t\t\tChoose your desired engine capacity (1 - 3): ";
			std::cin >> engineCapacity[i];
				
			while (std::cin.fail() || engineCapacity[i] < 1 || engineCapacity[i] > 3) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "\t\t\tPlease enter a valid engine capacity (1 - 3): ";
				std::cin >> engineCapacity[i];
			}
		}

		// Over 13 without License
		else if (driverAge[i] > 13 && license[i] != 'Y') {
			std::cout << "\n\t\t\tChoose your desired engine capacity (1 - 2): ";
			std::cin >> engineCapacity[i];
	 
			while (std::cin.fail() || engineCapacity[i] < 1 || engineCapacity[i] > 2) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "\t\t\tPlease enter a valid engine capacity (1 - 2): ";
				std::cin >> engineCapacity[i];
			}
		}

		switch (engineCapacity[i]) {
			case 1: engineCapacity[i] = 120; break;
			case 2: engineCapacity[i] = 200; break;
			default: engineCapacity[i] = 270; break;
		}
	}
}

int setLaps(int driverCount, std::string& raceFormat) {
	int laps;
	if (raceFormat == "Circuit Race") {
		std::cout << "\n\t\t\tAvailable number of laps: 2, 3, 4"
			  << "\n\t\t\tHow many laps do you want? : ";
		std::cin >> laps;
	}
	
	else if (raceFormat == "Sprint Race" || raceFormat == "Drag Race") {
		std::cout << "\n\t\t\tSprint Races and Drag Races only have 1 lap\n";
		laps = 1;
	}
	
	else if (raceFormat == "Time Trial") {
		std::cout << "\n\t\t\tAvailable number of laps: Unlimited"
			  << "\n\t\t\tHow many laps do you want? : ";
		std::cin >> laps;
	}
	
	else { // Elimination Race
		std::cout << "\n\t\t\tNumber of laps corresponds with the number of drivers";
		laps = driverCount - 1;
		std::cout << "\n\t\t\tLaps = Driver Count - 1"
			  << "\n\t\t\tLaps = " << driverCount << " - 1"
			  << "\n\t\t\tLaps = " << laps;
	}
	
	return laps;
}

float selectHelmet(int i, std::string helmetSize[], float helmetPrice[])
{
	std::cout << "\n\t\t\tPlease choose your helmet size (S/M/L/XL): ";
	std::cin >> helmetSize[i];
	
	std::transform(helmetSize[i].begin(), helmetSize[i].end(), helmetSize[i].begin(), ::toupper);

	while (std::cin.fail() || (helmetSize[i] != "S" && helmetSize[i] != "M" && helmetSize[i] != "L" && helmetSize[i] != "XL")) {
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "\n\t\t\tPlease choose a valid helmet size (S/M/L/XL): ";
		std::cin >> helmetSize[i];
		std::transform(helmetSize[i].begin(), helmetSize[i].end(), helmetSize[i].begin(), ::toupper);
	}
	
	if (helmetSize[i] == "S")
		helmetPrice[i] = 2;
	if (helmetSize[i] == "M")
		helmetPrice[i] = 4;
	if (helmetSize[i] == "L")
		helmetPrice[i] = 6;
	if (helmetSize[i] == "XL")
		helmetPrice[i] = 8;

	return helmetPrice[i];
}

float selectSuit (int i, std::string suitSize[], float suitPrice[])
{
	std::cout << "\n\t\t\tPlease choose your suit size (S/M/L/XL): ";
	std::cin >> suitSize[i];

	std::transform(suitSize[i].begin(), suitSize[i].end(), suitSize[i].begin(), ::toupper);

	while (std::cin.fail() || (suitSize[i] != "S" && suitSize[i] != "M" && suitSize[i] != "L" && suitSize[i] != "XL")){
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "\n\t\t\tPlease choose a valid suit size (S/M/L/XL): ";
		std::cin >> suitSize[i];
		std::transform(suitSize[i].begin(), suitSize[i].end(), suitSize[i].begin(), ::toupper);
	}
	
	if (suitSize[i] == "S")
		suitPrice[i] = 5;
	if (suitSize[i] == "M")
		suitPrice[i] = 10;
	if (suitSize[i] == "L")
		suitPrice[i] = 15;
	if (suitSize[i] == "XL")
		suitPrice[i] = 20;
	
	return suitPrice[i];
}

float selectShoe (int i, int shoeSize[], float shoePrice[])
{
	std::cout << "\n\t\t\tPlease choose your shoe size (20 - 35): ";
	std::cin >> shoeSize[i];
	
	while (std::cin.fail() || (shoeSize[i] < 20 || shoeSize[i] > 35)){
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "\n\t\t\tPlease choose a valid shoe size (20 - 35): ";
		std::cin >> shoeSize[i];
	}
	
	if (shoeSize[i] <= 25)
		shoePrice[i] = 3;
	else 
		shoePrice[i] = 6;

	return shoePrice[i];
}

float racingGear(int driverCount, std::string driverName[], std::string helmetSize[], std::string suitSize[], int shoeSize[], float helmetPrice[], float suitPrice[], float shoePrice[], float gearPrice[])
{
	float totalGearPrice = 0;

	displayRacingGear();

	for (int i = 0; i < driverCount; i++) {
		std::cout << "\n\t\t\tDriver: " << driverName[i];

		helmetPrice[i] = selectHelmet(i, helmetSize, helmetPrice);

		suitPrice[i] = selectSuit (i, suitSize, suitPrice);

		shoePrice[i] = selectShoe (i, shoeSize, shoePrice);

		gearPrice[i] = helmetPrice[i] + suitPrice[i] + shoePrice[i];

		totalGearPrice += gearPrice[i];
	}
	return totalGearPrice;
}

float setMembershipDiscount()
{
	char membership;	

	std::cout << "\n\t\t\tDo you have a membership? (Y/N): ";
	std::cin >> membership;

	if(std::toupper(membership) == 'Y')
		return 0.1;
	else
		return 0.0;
}

float calcPrice(int engineCapacity[], int laps, int driverCount, float totalGearPrice, float membershipDiscount)
{
	const float pricePerCC = 0.3;
	float totalKartPrice = 0;
	
	for (int i = 0; i < driverCount; i++)
		totalKartPrice += (engineCapacity[i] * pricePerCC) * laps;
	
	float finalPrice = (totalKartPrice + totalGearPrice) * (1 - membershipDiscount);
	return finalPrice;
}
