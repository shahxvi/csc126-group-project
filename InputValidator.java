import java.util.Scanner;

public class InputValidator {

  public static int getValidIntegerInput(String inputName, int minValue, int maxValue) {
    Scanner keyboard = new Scanner(System.in);
    int input = keyboard.nextInt();

    while (input < minValue || input > maxValue) {
      System.out.printf("Please enter a valid %s (%d - %d)", inputName, minValue, maxValue);
      input = keyboard.nextInt();
    }

    return input;
  }

}
