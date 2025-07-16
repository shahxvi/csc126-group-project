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

#define PRICEPERCC 0.3
#define MEMBERSHIPDISCOUNT 0.1

using std::string;
using std::cout;
using std::endl;
using std::cin;

void menu();
void displayMenu();
void displayRaceFormat(string bookingType);
void displayTrackList();
void displayRacingGear();
void displayEngineCapacities(int age, char license);

int getValidIntegerInput (string inputType, int minValue, int maxValue);
char getValidCharacterInput();
string getBookingType();
int getDriverCount(string& bookingType);
void getDriverDetails(int& driverCount, string driverName[], int driverAge[], char license[]);
string setRaceFormat(string& bookingType);
string setTrack(string& bookingType, string& raceFormat);
void setEngineCapacity(int driverCount, string driverName[], int driverAge[], char license[], int engineCapacity[]);
int setLaps(int driverCount, string& raceFormat);
string getValidSizeInput(string inputType);
float selectHelmet(int i, string helmetSize[], float helmetPrice[]);
float selectSuit(int i, string suitSize[], float suitPrice[]);
float selectShoe(int i, int shoeSize[], float shoePrice[]);
float calculateTotalGearPrice(int& driverCount, float helmetPrice[], float suitPrice[], float shoePrice[], float gearPrice[]);
float setMembershipDiscount(int driverCount, string driverName[]);
float calculatePrice(int engineCapacity[], int laps, int driverCount, float gearPrice, float membershipDiscount);

struct Counters {
	int customer = 0;
	float totalIncome = 0;
	int solo = 0;
	int group = 0;	
	int membership = 0;
	int cc120 = 0;
	int cc200 = 0;	
	int cc270 = 0;
	int section9 = 0;
	int blackrock = 0;
	int rushlineDash = 0;
	int choroPass = 0;
	int torqueStrip = 0;
	float minTotalPrice = 99999;
	float maxTotalPrice = -99999;
};
Counters counter;

int main()
{
	char continueChoice;
	do {
		menu();

		//Initializations (in order)
		string bookingType;

		int driverCount;
		string driverName[5];
		int driverAge[5];
		char license[5];

		string raceFormat;
		string track;
		
		int engineCapacity[5];

		int laps;

		string helmetSize[5], suitSize[5]; int shoeSize[5];
		float helmetPrice[5], suitPrice[5], shoePrice[5];
		float gearPrice[5];

		// The Crux of the Go-Kart Booking System
		bookingType = getBookingType();
		
		driverCount = getDriverCount(bookingType);

		getDriverDetails(driverCount, driverName, driverAge, license);

		system("cls");

		raceFormat = setRaceFormat(bookingType);

		track = setTrack(bookingType, raceFormat);

		setEngineCapacity(driverCount, driverName, driverAge, license, engineCapacity);

		laps = setLaps(driverCount, raceFormat);
		cout << "\n\t\t\t" << system("pause");
		
		for (int i = 0; i < driverCount; i++) {
			system("cls");
			displayRacingGear();
			cout << "\n\t\t\tDriver: " << driverName[i];
			selectHelmet(i,helmetSize, helmetPrice);
			selectSuit(i,suitSize, suitPrice);
			selectShoe(i, shoeSize, shoePrice);
		}

		float totalGearPrice = calculateTotalGearPrice(driverCount, helmetPrice, suitPrice, shoePrice, gearPrice);

		float membershipDiscount = setMembershipDiscount(driverCount, driverName);

		float totalPrice = calculatePrice(engineCapacity, laps, driverCount, totalGearPrice, membershipDiscount);

		system("cls");

		// Summary for each customers
		cout << "\n\t\t\tRace Format: " << raceFormat
		     << "\n\t\t\tTrack: " << track << "\n";

		std::cout << std::fixed << std::showpoint << std::setprecision(2);
		for (int i = 0; i < driverCount; i++) {
			cout << "\n\t\t\tDriver\t\t\t: "	<< driverName[i]
			     << "\n\t\t\tAge\t\t\t: "		<< driverAge[i]
			     << "\n\t\t\tHas License\t\t: "	<< license[i]
			     << "\n\t\t\tEngine Capacity\t\t: " << engineCapacity[i] << "cc"
			     << "\n\t\t\tPrice per CC\t\t: " 	<< "RM " << PRICEPERCC << "/cc"
			     << "\n\t\t\tGo-Kart Price\t\t: RM " << PRICEPERCC * engineCapacity[i]
			     << "\n\t\t\tHelmet Size\t\t: "	<< helmetSize[i]
			     << "\n\t\t\tHelmet Price\t\t: RM "	<< helmetPrice[i]
			     << "\n\t\t\tSuit Size\t\t: "	<< suitSize[i]
			     << "\n\t\t\tSuit Price\t\t: RM "	<< suitPrice[i]
			     << "\n\t\t\tShoe Size\t\t: "	<< shoeSize[i] << "cm"
			     << "\n\t\t\tShoe Price\t\t: RM "	<< shoePrice[i]
			     << "\n\t\t\tGear Price\t\t: RM "	<< gearPrice[i] << endl;
		}

		cout << "\n\t\t\tTotal Gear Price\t: RM " << totalGearPrice
		     << "\n\t\t\tSubtotal before discount: RM " << totalPrice / (1 - membershipDiscount)
		     << "\n\t\t\tMembership Discount\t: " << membershipDiscount * 100 << "%"
		     << "\n\t\t\tTotal\t\t\t: RM " << totalPrice;

		counter.totalIncome += totalPrice;
		counter.customer += driverCount;

		if (totalPrice < counter.minTotalPrice)
			counter.minTotalPrice = totalPrice;
		if (totalPrice > counter.maxTotalPrice)
			counter.maxTotalPrice = totalPrice;

		cout << "\n\t\t\tContinue for another customer? (Y/N): ";
		continueChoice = getValidCharacterInput();

		system("cls");

	} while (std::toupper(continueChoice) == 'Y');

	// Overall Summary
	cout << "\n\t\t\tTotal Number Drivers: " << counter.customer;
	cout << "\n\t\t\tTotal Income: RM " << counter.totalIncome << endl;

	cout << "\n\t\t\tTotal Number of 120cc Go-Kart Booked: " << counter.cc120;
	cout << "\n\t\t\tTotal Number of 200cc Go-Kart Booked: " << counter.cc200;
	cout << "\n\t\t\tTotal Number of 270cc Go-Kart Booked: " << counter.cc270 << endl;

	cout << "\n\t\t\tTotal Number of members: " << counter.membership <<  endl;

	cout << "\n\t\t\tTotal Number of Section 9 Circuit booking: " << counter.section9;
	cout << "\n\t\t\tTotal Number of Blackrock Circuit booking: " << counter.blackrock;
	cout << "\n\t\t\tTotal Number of Rushline Dash booking: " << counter.rushlineDash;
	cout << "\n\t\t\tTotal Number of Chrono Pass booking: " << counter.choroPass;
	cout << "\n\t\t\tTotal Number of Torque Strip booking: " << counter.torqueStrip << endl;

	cout << "\n\t\t\tMinumum amount of payment: RM" << counter.minTotalPrice;
	cout << "\n\t\t\tMaximum amount of payment: RM" << counter.maxTotalPrice << endl;

	cout << endl;
	cout << "\n\t\t\t" << system("pause");

	return 0;
}

void menu()
{
	enum menu {start = 1, format = 2, track = 3, gear = 4, engine = 5};
	menu menuOption;

	do {
		displayMenu();
		cout << "\n\t\t\tChoose your option: ";
		menuOption = static_cast<menu>(getValidIntegerInput("option", 1, 5)); // Converts integers into menu enums

		if (menuOption == format) {
			system("cls");
			displayRaceFormat("Group");		// Parameters to allow the menu to show every option
			system("pause");
			system("cls");
		}
		if (menuOption == track) {
			system("cls");
			displayTrackList();
			system("pause");
			system("cls");
		}
		if (menuOption == gear) {
			system("cls");
			displayRacingGear();
			system("pause");
			system("cls");
		}
		if (menuOption == engine) {
			system("cls");
			displayEngineCapacities(18, 'Y');	// Parameters to allow the menu to show every option
			system("pause");
			system("cls");
		}

	} while (menuOption != start);
}

void displayMenu()
{
	cout << "\t_________            ______ __             _____  ________            ______ _____                 ________              _____                 "
	     << "\n\t__  ____/_____       ___  //_/_____ _________  /_ ___  __ )______________  /____(_)_____________ _ __  ___/____  __________  /____________ ___ "
	     << "\n\t_  / __ _  __ \\________  ,<  _  __ `/_  ___/  __/ __  __  |  __ \\  __ \\_  //_/_  /__  __ \\_  __ `/ _____ \\__  / / /_  ___/  __/  _ \\_  __ `__ \\"
	     << "\n\t/ /_/ / / /_/ //_____/  /| | / /_/ /_  /   / /_   _  /_/ // /_/ / /_/ /  ,<  _  / _  / / /  /_/ /  ____/ /_  /_/ /_(__  )/ /_ /  __/  / / / / /"
	     << "\n\t\\____/  \\____/       /_/ |_| \\__,_/ /_/    \\__/   /_____/ \\____/\\____//_/|_| /_/  /_/ /_/_\\__, /   /____/ _\\__, / /____/ \\__/ \\___//_/ /_/ /_/ "
	     << "\n\t                                                                                         /____/           /____/                               "
	     << "\n\t\t\t1 - Start Booking"
    	     << "\n\t\t\t2 - Race Formats"
    	     << "\n\t\t\t3 - Track Lists"
	     << "\n\t\t\t4 - Racing Gear Sizes & Prices"
    	     << "\n\t\t\t5 - Go-Kart Engine Capacities\n";
}

void displayRaceFormat(string bookingType)
{
	cout << "\n\t\t\tAvailable Race Formats:"
	     << "\n\t\t\t1 - Circuit Race"
	     << "\n\t\t\t2 - Sprint Race"
	     << "\n\t\t\t3 - Time Trial"
	     << "\n\t\t\t4 - Drag Race";
	if (bookingType == "Group") {
		cout << "\n\t\t\t5 - Eliminationn Race (Group)\n";
	}
}

void displayTrackList()
{
	cout << "\n\t\t\tAvailable Tracks:"
    		  << "\n\t\t\t1 - Section 9 Circuit"
    		  << "\n\t\t\t2 - Chrono Pass"
    		  << "\n\t\t\t3 - Rushline Dash"
    		  << "\n\t\t\t4 - Blackrock Circuit"
    		  << "\n\t\t\t5 - Torque Strip\n";
}

void displayRacingGear()
{
	cout << "\n\t\t\tRacing Gears:"
		  	  << "\n\t\t\t\t\t\tHelmets\t\t\tSuits\t\t\tShoes\n"
			  << "\n\t\t\tSize S:\t\t\tRM 2\t\t\tRM 5\t\t\tSize 20-25 cm: RM 3"
			  << "\n\t\t\tSize M:\t\t\tRM 4\t\t\tRM 10\t\t\tSize 26-35 cm: RM 6"
			  << "\n\t\t\tSize L:\t\t\tRM 6\t\t\tRM 15"
			  << "\n\t\t\tSize XL\t\t\tRM 8\t\t\tRM 20\n";
}

void displayEngineCapacities(int age, char license)
{ 
	cout << "\n\t\t\tAvailable Engine Capacities:";
	cout << "\n\t\t\t1 - 100cc (Under 13)";
	if (age >= 18)
		cout << "\n\t\t\t2 - 200cc";
	if (license == 'Y')
		cout << "\n\t\t\t3 - 270cc (Requires License)\n";
}

int getValidIntegerInput(string inputType, int minValue, int maxValue)
{
	int input;
	cin >> input;
	while (cin.fail() || (input < minValue || input > maxValue)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "\t\t\tPlease enter a valid " << inputType << " (" << minValue << " - " << maxValue << "): ";
		cin >> input;
	}
	return input;
}

char getValidCharacterInput()
{
	string input;
	cin >> input;

	while (input.length() != 1 || !std::isalpha(input[0])) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "\t\t\tPlease enter a valid input (Y/N): ";
		cin >> input;
	}
	return std::toupper(input[0]);
}

string getBookingType()
{
	int bookingTypeID;

	cout << "\n\t\t\t1 - Solo\n"
	     << "\t\t\t2 - Group (Maximum 5)\n"
	     << "\t\t\tPlease choose your desired booking (1 - 2): ";
	bookingTypeID = getValidIntegerInput("booking type", 1, 2);

	if (bookingTypeID == 1) {
		counter.solo++;
		return "Solo";
	}
	else {
		counter.group++;
		return "Group";
	}
}

int getDriverCount(string& bookingType)
{
	if (bookingType == "Solo")
		return 1;
	cout << "\t\t\tPlease enter the number of drivers (2 - 5): ";
	return getValidIntegerInput("number of drivers", 2, 5);
}

void getDriverDetails(int& driverCount, string driverName[], int driverAge[], char license[])
{
	for (int i = 0; i < driverCount; i++) {
		system("cls");

		cin.ignore();
		cout << "\n\t\t\tDriver #" << (i+1) << " Name: ";
		std::getline(cin, driverName[i]);

		cout << "\t\t\tDriver #" << (i+1) << " Age: ";
		driverAge[i] = getValidIntegerInput("age", 1, 100);

		cout << "\t\t\tDoes Driver #" << (i+1) << " has a license? (Y/N): ";
		license[i] = getValidCharacterInput();
	}
}

string setRaceFormat(string& bookingType)
{
	int raceFormatID;
	string raceFormat;

	displayRaceFormat(bookingType);

	if (bookingType == "Solo") {
		cout << "\n\t\t\tPlease choose the race format (1 - 4): ";
		raceFormatID = getValidIntegerInput("race format", 1, 4);
	}
	else if (bookingType == "Group") {
		cout << "\n\t\t\tPlease choose the race format (1 - 5): ";
		raceFormatID = getValidIntegerInput("race format", 1, 5);
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

string setTrack(string& bookingType, string& raceFormat)
{
	int trackID;

	if (bookingType == "Group" && raceFormat == "Circuit Race") {
		cout << "\n\t\t\tAvailable Track:"
			  << "\n\t\t\t1 - Section 9 Circuit"
			  << "\n\t\t\t2 - Blackrock Circuit"
			  << "\n\t\t\tPlease choose your track (1 - 2): ";
		trackID = getValidIntegerInput("track", 1, 2);
	}
	else if (raceFormat == "Time Trial") {
		cout << "\n\t\t\tAvailable Track:"
			  << "\n\t\t\t1 - Section 9 Circuit"
			  << "\n\t\t\t2 - Blackrock Circuit"
			  << "\n\t\t\t3 - Rushline Dash"
			  << "\n\t\t\t4 - Chrono Pass"
			  << "\n\t\t\tPlease choose your track (1 - 4): ";
		trackID = getValidIntegerInput("track", 1, 4);
	}
	switch (trackID) {
		case 1: counter.section9++; return "Section 9 Circuit";
		case 2: counter.blackrock++; return "Blackrock Circuit";
		case 3: counter.rushlineDash++; return "Rushline Dash";
		default: counter.choroPass++; return "Chrono Pass";
	}
	if (bookingType == "Solo" && raceFormat == "Circuit Race") {
		cout << "\n\t\t\tAvailable Track: Section 9 Circuit"
		     << "\n\t\t\tDefaulting to said track\n";
		counter.section9++;
		return "Section 9 Circuit";
	}
	else if (raceFormat == "Elimination Race") {
		cout << "\n\t\t\tAvailable Track: Blackrock Circuit"
		     << "\n\t\t\tDefaulting to said track\n";
		counter.blackrock++;
		return "Blackrock Circuit";
	}
	else if (raceFormat == "Sprint Race") {
		cout << "\n\t\t\tAvailable Track: Rushline Dash"
			  << "\n\t\t\tDefaulting to said track\n";
		counter.rushlineDash++;
		return "Rushline Dash";
	}
	else if (raceFormat == "Drag Race") {
		cout << "\n\t\t\tAvailable Track: Torque Strip"
			  << "\n\t\t\tDefaulting to said track\n";
		counter.torqueStrip++;
		return "Torque Strip";
	}
	return "Track"; // Should never get to this point
}

void setEngineCapacity(int driverCount, string driverName[], int driverAge[], char license[], int engineCapacity[])
{
	for (int i = 0; i < driverCount; i++) {
		cout << "\n\t\t\tDriver : " << driverName[i];

		displayEngineCapacities(driverAge[i], license[i]);

		if (driverAge[i] < 13) {
			cout << "\n\t\t\tDriver under 13: Go-Kart must be under 200cc"
				  << "\n\t\t\tDefaulting to 120cc\n";
			engineCapacity[i] = 120;
			counter.cc120++;
			continue;
		}
		// Over 13 without License
		if (license[i] != 'Y') {
			cout << "\n\t\t\tChoose your desired engine capacity (1 - 2): ";
			engineCapacity[i] = getValidIntegerInput("engine capacity", 1 , 2);
		}
		// Over 13 with License
		if (license[i] == 'Y') {
		cout << "\n\t\t\tChoose your desired engine capacity (1 - 3): ";
		engineCapacity[i] = getValidIntegerInput("engine capacity", 1 , 3);
		}

		switch (engineCapacity[i]) {
			case 1: engineCapacity[i] = 120; counter.cc120++; break;
			case 2: engineCapacity[i] = 200; counter.cc200++; break;
			default: engineCapacity[i] = 270; counter.cc270++; break;
		}
	}
}

int setLaps(int driverCount, string& raceFormat) {
	int laps;
	if (raceFormat == "Circuit Race") {
		cout << "\n\t\t\tAvailable number of laps: 2, 3, 4"
			  << "\n\t\t\tHow many laps would you like? (2/3/4): ";
		cin >> laps;
	}
	else if (raceFormat == "Sprint Race" || raceFormat == "Drag Race") {
		cout << "\n\t\t\tSprint Races and Drag Races only have 1 lap\n";
		laps = 1;
	}
	else if (raceFormat == "Time Trial") {
		cout << "\n\t\t\tAvailable number of laps: Unlimited"
			  << "\n\t\t\tHow many laps would you like?: ";
		cin >> laps;
	}
	else { // Elimination Race
		cout << "\n\t\t\tNumber of laps corresponds with the number of drivers";
		laps = driverCount - 1;
		cout << "\n\t\t\tLaps = Driver Count - 1"
			  << "\n\t\t\tLaps = " << driverCount << " - 1"
			  << "\n\t\t\tLaps = " << laps << "\n";
	}
	return laps;
}

string getValidSizeInput(string inputType)
{
	string sizeInput;
	cin >> sizeInput;
	std::transform(sizeInput.begin(), sizeInput.end(), sizeInput.begin(), ::toupper);

	while (cin.fail() || (sizeInput != "S" && sizeInput != "M" && sizeInput != "L" && sizeInput != "XL")) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "\n\t\t\tPlease choose a valid " << inputType << " (S/M/L/XL): ";
		cin >> sizeInput;
		std::transform(sizeInput.begin(), sizeInput.end(), sizeInput.begin(), ::toupper);
	}
	
	return sizeInput;
}
float selectHelmet(int i, string helmetSize[], float helmetPrice[])
{
	cout << "\n\t\t\tPlease choose your helmet size (S/M/L/XL): ";
	helmetSize[i] = getValidSizeInput("helmet size");

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

float selectSuit(int i, string suitSize[], float suitPrice[])
{
	cout << "\n\t\t\tPlease choose your suit size (S/M/L/XL): ";
	suitSize[i] = getValidSizeInput("suit size");
	
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

float selectShoe(int i, int shoeSize[], float shoePrice[])
{
	cout << "\n\t\t\tPlease choose your shoe size (20 - 35) cm: ";
	cin >> shoeSize[i];
	
	while (cin.fail() || (shoeSize[i] < 20 || shoeSize[i] > 35)){
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "\n\t\t\tPlease choose a valid shoe size (20 - 35): ";
		cin >> shoeSize[i];
	}
	
	if (shoeSize[i] <= 25)
		shoePrice[i] = 3;
	else 
		shoePrice[i] = 6;

	return shoePrice[i];
}


float calculateTotalGearPrice(int& driverCount, float helmetPrice[], float suitPrice[], float shoePrice[], float gearPrice[])
{
	float totalGearPrice = 0;
	
	for (int i = 0; i < driverCount; i++) {
		gearPrice[i] = helmetPrice[i] + suitPrice[i] + shoePrice[i];
		totalGearPrice += gearPrice[i];
	}
	return totalGearPrice;
}

float setMembershipDiscount(int driverCount, string driverName[])
{
	char membership[5];
	float membershipDiscount = 0.1;

	for (int i = 0; i < driverCount; i++) {
		cout << "\n\t\t\tDoes " << driverName[i] << " have a membership? (Y/N): ";
		membership[i] = getValidCharacterInput();

		if(membership[i] == 'Y') {
			counter.membership++;
		}
	}
	if (counter.membership > 0) {
		return MEMBERSHIPDISCOUNT;
	}
	return 0;
}

float calculatePrice(int engineCapacity[], int laps, int driverCount, float totalGearPrice, float membershipDiscount)
{
	float totalKartPrice = 0;
	
	for (int i = 0; i < driverCount; i++)
		totalKartPrice += (engineCapacity[i] * PRICEPERCC) * laps;
	
	float finalPrice = (totalKartPrice + totalGearPrice) * (1 - membershipDiscount);
	return finalPrice;
}
