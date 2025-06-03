// CSC126 Group Project
// Motorsport Booking System

// IRFAN SHAH BIN MAIZUL HISHAM       (2025171523)  (RCDCS1101A)
// MUHAMMAD HANIF BIN AMIR HAMZAH     (2025155097)  (RCDCS1101A)
// SHAHRIN AREFF SHAH BIN SHAH RIZAL  (2025151503)  (RCDCS1101A)
// MUHAMMAD BIN ABDUL AZIZ            (2025507823)  (RCDCS1101B)

// SUPERVISED BY MADAM NORA YANTI BINTI CHE JAN

#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

int main() {
    
    /* Initialization */

    // Driver information
    char driverName[50], driverNationality[50];         // Driver name & nationality
    int driverAge = 0;                                  // Driver age
    char driverLicense = 'N';                           // Driver license

    // Formula 1 information
    char f1Team[50], f1Car[50];                             // Team and Car
    char f1CircuitMY[50] = "Sepang International Circuit";  // Circuit name
    char f1CircuitSG[50] = "Marina Bay Street Circuit";     // Circuit name

    // Go-Kart information
    int kartCC = 0;     // Kart engine capacity in CC

    // MotoGP information
    char motoGPTeam[50], motoGPBike[50];                        // Team and Bike
    char motoGPCircuitMY[50] = "Sepang International Circuit";  // Circuit name
    char motoGPCircuitSG[50] = "Marina Bay Street Circuit";     // Circuit name


    // Greeting message
    cout << " __  __       _                                  _     ____              _    _               ____            _                               " << endl;
    cout << "|  \\/  | ___ | |_ ___  _ __ ___ _ __   ___  _ __| |_  | __ )  ___   ___ | | _(_)_ __   __ _  / ___| _   _ ___| |_ ___ _ __ ___               " << endl;
    cout << "| |\\/| |/ _ \\| __/ _ \\| '__/ __| '_ \\ / _ \\| '__| __| |  _ \\ / _ \\ / _ \\| |/ / | '_ \\ / _` | \\___ \\| | | / __| __/ _ \\ '_ ` _ \\  " << endl;
    cout << "| |  | | (_) | || (_) | |  \\__ \\ |_) | (_) | |  | |_  | |_) | (_) | (_) |   <| | | | | (_| |  ___) | |_| \\__ \\ ||  __/ | | | | |          " << endl;
    cout << "|_|  |_|\\___/ \\__\\___/|_|  |___/ .__/ \\___/|_|   \\__| |____/ \\___/ \\___/|_|\\_\\_|_| |_|\\__, | |____/ \\__, |___/\\__\\___|_| |_| |_| " << endl;
    cout << "                               |_|                                                    |___/         |___/                                     " << endl;
    cout << " _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ " << endl;
    cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;

    cout << endl;

    cout << " ____  _                        ____ _                           __   __                        " << endl;
    cout << "|  _ \\| | ___  __ _ ___  ___   / ___| |__   ___   ___  ___  ___  \\ \\ / /__  _   _ _ __       " << endl;
    cout << "| |_) | |/ _ \\/ _` / __|/ _ \\ | |   | '_ \\ / _ \\ / _ \\/ __|/ _ \\  \\ V / _ \\| | | | '__| " << endl;
    cout << "|  __/| |  __/ (_| \\__ \\  __/ | |___| | | | (_) | (_) \\__ \\  __/   | | (_) | |_| | |        " << endl;
    cout << "|_|__ |_|\\___|\\__,_|___/\\___|  \\____|_| |_|\\___/ \\___/|___/\\___|   |_|\\___/ \\__,_|_|   " << endl;
    cout << "|  _ \\ __ _  ___ ___  |_   _|   _ _ __   ___   _                                               " << endl;
    cout << "| |_) / _` |/ __/ _ \\   | || | | | '_ \\ / _ \\ (_)                                            " << endl;
    cout << "|  _ < (_| | (_|  __/   | || |_| | |_) |  __/  _                                                " << endl;
    cout << "|_| \\_\\__,_|\\___\\___|   |_| \\__, | .__/ \\___| (_)                                         " << endl;
    cout << "                            |___/|_|                                                            " << endl;

    cout << endl;
    system("pause");
    return 0;
}