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

    // Booking information
    char bookingID[2];

    // Driver information
    char driverName[50];                                // Driver name & nationality
    int driverAge = 0;                                  // Driver age
    char driverLicense = 'N';                           // Driver license


    // Greeting message
    cout << "  ____             _  __          _     ____              _    _               ____            _                 " << endl;
    cout << " / ___| ___       | |/ /__ _ _ __| |_  | __ )  ___   ___ | | _(_)_ __   __ _  / ___| _   _ ___| |_ ___ _ __ ___  " << endl;
    cout << "| |  _ / _ \\ _____| ' // _` | '__| __| |  _ \\ / _ \\ / _ \\| |/ / | '_ \\ / _` | \\___ \\| | | / __| __/ _ \\ '_ ` _ \\ " << endl;
    cout << "| |_| | (_) |_____| . \\ (_| | |  | |_  | |_) | (_) | (_) |   <| | | | | (_| |  ___) | |_| \\__ \\ ||  __/ | | | | |" << endl;
    cout << " \\____|\\___/      |_|\\_\\__,_|_|   \\__| |____/ \\___/ \\___/|_|\\_\\_|_| |_|\\__, | |____/ \\__, |___/\\__\\___|_| |_| |_|" << endl;
    cout << "                                                                       |___/         |___/                       " << endl;
    cout << " _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ " << endl;
    cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;

    cout << endl;

    cout << "    _                                   _                                               ___           " << endl;
    cout << "   / \\   _ __ ___   _   _  ___  _   _  (_)_ __     __ _    __ _ _ __ ___  _   _ _ __   |__ \"        " << endl;
    cout << "  / _ \\ | '__/ _ \\ | | | |/ _ \\| | | | | | '_ \\   / _` |  / _` | '__/ _ \\| | | | '_ \\    / /    " << endl;
    cout << " / ___ \\| | |  __/ | |_| | (_) | |_| | | | | | | | (_| | | (_| | | | (_) | |_| | |_) |  |_|          " << endl;
    cout << "/_/   \\_\\_|  \\___|  \\__, |\\___/ \\__,_| |_|_| |_|  \\__,_|  \\__, |_|  \\___/ \\__,_| .__/   (_) " << endl;
    cout << "  __ __   __     __ |___/_  __                            |___/                |_|                    " << endl;
    cout << " / / \\ \\ / /    / / | \\ | | \\ \\                                                                  " << endl;
    cout << "| |   \\ V /    / /  |  \\| |  | |                                                                    " << endl;
    cout << "| |    | |    / /   | |\\  |  | |                                                                     " << endl;
    cout << "| |    |_|   /_/    |_| \\_|  | |                                                                     " << endl;
    cout << " \\_\\                        /_/   															       " << endl;


    cin >> bookingID; // Input booking ID
    cin.ignore(); // Clear the newline character from the input buffer

    
    cout << endl;
    system("pause");
    return 0;
}