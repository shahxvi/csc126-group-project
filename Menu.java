public class Menu {

	public void display() {
		System.out.println("Go-Kart Booking System");
		System.out.println("1 - Start Booking");
		System.out.println("2 - Race Formats");
		System.out.println("3 - Track Lists");
		System.out.println("4 - Racing Gear Sizes @ Prices");
		System.out.println("5 - Go-Kart Engine Capacities");
	}

	public void displayRaceFormats(String bookingType) {
		System.out.println("Available Race Formats:");
		System.out.println("1 - Circuit Race");
		System.out.println("2 - Sprint Race");
		System.out.println("3 - Time Trail");
		System.out.println("4 - Drag Race");
		System.out.println(bookingType == "Group" ? "Elimination Race (Group)" : "");
	}

	public void displayTrackList() {
		System.out.println("Available Tracks:");
		System.out.println("1 - Section 9 Circuit");
		System.out.println("2 - Chrono Pass");
		System.out.println("3 - Rushline Dash");
		System.out.println("4 - Blackrock Circuit");
		System.out.println("5 - Torque Strip");
	}

	public void displayRacingGear() {
		System.out.println("Helmets\t\t\tSuits\t\t\tShoes");
		System.out.println("Size S:\t\t\tRM 2\t\t\tRM 5\t\t\tSize 20-25 cm: RM 3");
		System.out.println("Size M:\t\t\tRM 4\t\t\tRM 10\t\t\tSize 26-35 cm: RM 6");
		System.out.println("Size L:\t\t\tRM 6\t\t\tRM 15");
		System.out.println("Size XL\t\t\tRM 8\t\t\tRM 20");
	}

	public void displayKartCapacities(int age, boolean isLicensed) {
		System.out.println("Available Engine Capacities:");
		System.out.println("1 - 120cc (Under 13)");
		if (age >= 18)
			System.out.println("2 - 200cc");
		if (isLicensed)
			System.out.println("3 - 270cc (Requires License)");
	}

}
