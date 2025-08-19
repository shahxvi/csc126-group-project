import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
	
		menu();

	}

	public static int getValidIntegerInput(String inputType, int minValue, int maxValue) {
		Scanner keyboard = new Scanner(System.in);
		int input = keyboard.nextInt();

		while (input < minValue || input > maxValue) {
			System.out.printf("Please enter a valid %s (%d - %d)", inputType, minValue, maxValue);
			input = keyboard.nextInt();
		}

		return input;
	}

	public static void menu() {
		
		Menu menu = new Menu();

		int choice;
		do {
			menu.display();
			System.out.print("Choose your option: ");

			choice = getValidIntegerInput("menu option", 1, 5);

			switch (choice) {
			    case 1:
				// Start Booking Logic
				break;
			    case 2:
				menu.displayRaceFormats("Group");
				break;
			    case 3:
				menu.displayTrackList();
				break;
			    case 4:
				menu.displayRacingGear();
				break;
			    default:
				menu.displayKartCapacities(18, true);
				break;
			}

		} while (choice != 1);
	}
}
