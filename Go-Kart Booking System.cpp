// CSC126 Group Project
// Go-Kart Booking System

// IRFAN SHAH BIN MAIZUL HISHAM       (2025171523)  (RCDCS1101A) (shahxvi)
// SHAHRIN AREFF SHAH BIN SHAH RIZAL  (2025151503)  (RCDCS1101A) (rinnnnnnn17)
// MUHAMMAD BIN ABDUL AZIZ            (2025507823)  (RCDCS1101B) (Kundoo)

// SUPERVISED BY MADAM NORA YANTI BINTI CHE JAN

// READ THIS BEFORE MAKING ANY CHANGES:
// Function Prototypes are defined at the top of the code after the headings.
// Each function should be defined below the main function.
// This ensures readability and maintainability of the code.
// Please update the comment line of the prototype function.

#include <iostream>
#include <string>
#include <iomanip>

void booking(int &bookingType, int &driverCount, int driverAge[], std::string driverName[], char license[]);	//line 88
std::string setRaceFormat(int x);						// Line 138
// Insert Track Selection Function Prototype
// Intert Environment Function Prototype
int setEngineCapacity(int x);							// Line 154
float setMembershipDiscount(char &membership);					// Line 172
float calcPrice(int engineCapacity, int laps, float membershipDiscount,float gearPrice);	// Line 176

int main() {
	int bookingType, driverCount, driverAge[5];
	std::string driverName[5];
	char license[5];
	int racingFormatID;
	int engineCapacityID;
	char membership;
	int laps = 1;

	std:: string setTrack(int trackID);
	std:: string setEnvironment(const std::string & trackName);
	float getHelmetPrice(const std::string & size);
	float getShoePrice(int size);
	int trackID;
    
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
		  << "4 - Drag\n";

	if (bookingType == 1) {	
		std::cout << "Please enter your desired racing format (1-4): ";
	}
	
	else {
		std::cout << "5 - Elimination\n";
		std::cout << "Please enter your desired racing format (1-5): ";
	}

	std::cin >> racingFormatID;
	
	while (std::cin.fail() || racingFormatID < 1 || racingFormatID > 5) {
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
	
	std:: string helmetSize[5],suitSize[5];
	int shoeSize[5];
	float helmetPrice[5],shoePrice[5],totalGearPrice = 0;
	for(int i=0; i< driverCount;i++){
		std::cout<<"\nDriver "<<(i+1)<<" Gear Rental :\n";
		
		std::cout<<"Helmet size(S/M/L/XL): ";
		std::cin>> helmetSize[i];
		
		std::cout<<"Suit Size (any text): ";
		std::cin>>suitSize[i];
		
		std::cout<<" Shoe size (20-35): ";
		std::cin>> shoeSize[i];
		
		helmetPrice[i]=getHelmetPrice(helmetSize[i]);
		shoePrice[i]=getShoePrice(shoeSize[i]);
		
		if (helmetPrice[i] == 0){
			std::cout<<"Invalid helmet size,defaulting to RM0.\n";
		}
		if(shoePrice[i]==0){
			std::cout<<"Invalid shoe size,defaulting to RM0.\n";
		}
		totalGearPrice += helmetPrice[i] + shoePrice[i];
	}
	
	float membershipDiscount = setMembershipDiscount(membership);

	if (driverCount == 1) { 
		std::cout << "==================================";
		std::cout << "\nDriver's Name: " << driverName[0] << std::endl;
		std::cout << "Driver's Age: " << driverAge[0] << std::endl;
		std::cout << "Driver's License: " << license[0] << std::endl;	
	}

	else {
	
	}
	
	float price = calcPrice(engineCapacity, laps, membershipDiscount,totalGearPrice);
	
	std::cout << "\nTotal price: RM " << price << std::endl;
	
	std::cout<<"\nAvailable Tracks :\n"
	         <<"1. Section 9 Circuit\n"
	         <<"2. Chrono Pass\n"
	         <<"3. Rushline Dash\n"
	         <<"4.Torque Strip\n"
	         <<"5. Blackrock Circuit\n";
	std::cout<<"Please choose a track (1-5): ";
	std::cin>>trackID; 
	
	std:: string trackName = setTrack(trackID);
	std:: string environment = setEnvironment(trackName);
	
	std:: cout<<"You have chose track: "<<trackName<<std::endl;
	std::cout<<"Environment: "<<environment<<std::endl;       
	
	system("pause"); // To prevent the console from closing immediately
	return 0;
}

// 1 - Booking Type Function
void booking(int &bookingType, int &driverCount, int driverAge[], std::string driverName[], char license[]) {
	
	while (bookingType < 1 || bookingType > 2) {
		std::cout << "Please choose a valid booking type (1 or 2): ";
		std::cin >> bookingType;
	}

	// Solo Booking
	if(bookingType == 1) {
		driverCount = 1;
		std::cout << "\nPlease enter your name: ";
		std::cin >> driverName[0];
		
		std::cout << "Please enter your age: ";
		std::cin >> driverAge[0];
		
		// Will check driver age at the set engine capacity function
		
		std::cout << "Do you have a driving license? (Y/N): ";
		std::cin >> license[0];
		license[0] = toupper(license[0]);
	}
	
	else {	// Group Booking
		std::cout << "Please enter the total number of drivers: ";
		std::cin >> driverCount;
		
		while (driverCount < 2 || driverCount > 5) {
			std::cout << "Please enter a valid number of drivers (1-5): ";
			std::cin >> driverCount;
		}

		for (int i = 0; i < driverCount; i++) {
			std::cout << "Please enter the name of driver " << (i + 1) << ": ";
			std::cin >> driverName[i];
			
			std::cout << "Please enter the age of driver " << (i + 1) << ": ";
			std::cin >> driverAge[i];
			
			// Will check driver age at the set engine capacity function
			
			std::cout << "Does driver " << (i + 1) << " has a driving license? (Y/N): ";
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
int setEngineCapacity(int cc) {
	while (cc != 120 && cc != 200 && cc != 200) {
		std::cout << "Please input valid engine capacity: ";
		std::cin >> cc;
	}	
	return cc;
}

// 6 - Membership Discount Function
float setMembershipDiscount(char &membership) {
	if(toupper(membership) == 'Y')
		return 0.1;
	else
		return 0;
}

// 7 - Price Calculation Function
float calcPrice(int engineCapacity, int laps, float membershipDiscount,float gearPrice) {
	const float PRICEPERCC = 0.3;
	float kartPrice = engineCapacity * PRICEPERCC;
	float totalKartPrice = kartPrice * laps;
	float finalPrice = (totalKartPrice + gearPrice) * (1 - membershipDiscount);
	return finalPrice;
}

//8-Track Selectin Function
std::string setTrack(int trackID){
	switch(trackID){
	case 1: return "Section 9 Circuit";
	case 2: return "Chrono Pass";
	case 3: return "Rushline Dash";
	case 4: return "Torque Strip";
	case 5: return"Blackrock Circuit";
	default:return "Unkwon Track";
    }
}

//9-Enviroment Funtion
std:: string setEnvironment(const std:: string & trackName){
	if(trackName == "Section 9 circuit" || trackName == "Chrono Pass"){
		return "Indoor";
	}
	else {
		return"Outdoor";
	}
}

//10-Racing Gear Rental Fuction
float getHelmetPrice(const std:: string & size){
	if(size== "S")
	return 2;
	else if (size=="M")
	return 4;
	else if (size=="L")
	return 6;
	else if (size=="XL")
	return 8;
	else 
	return 0;
}

float getShoePrice(int size){
	if(size >=20 && size <= 25)
	return 3;
	else if(size > 25 && size<=35)
	return 6;
	else
	return 0;
}
