import java.util.Scanner;

public class TipCalculator {

    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Input total bill amount from the user
        System.out.print("Enter the total bill amount: $");
        double totalBill = scanner.nextDouble();

        // Input the tip percentage from the user
        System.out.print("Enter the tip percentage (e.g., 15 for 15%): ");
        double tipPercentage = scanner.nextDouble();

        // Input the number of people sharing the bill
        System.out.print("Enter the number of people sharing the bill: ");
        int numberOfPeople = scanner.nextInt();

        // Calculate the tip amount
        double tipAmount = (tipPercentage / 100) * totalBill;

        // Calculate the total amount including the tip
        double totalAmount = totalBill + tipAmount;

        // Calculate the amount each person needs to pay
        double amountPerPerson = totalAmount / numberOfPeople;

        // Output the results
        System.out.println("\n--- Bill Summary ---");
        System.out.printf("Total Bill Amount: $%.2f%n", totalBill);
        System.out.printf("Tip Amount: $%.2f%n", tipAmount);
        System.out.printf("Total Amount (including tip): $%.2f%n", totalAmount);
        System.out.printf("Amount per person: $%.2f%n", amountPerPerson);

        // Close the scanner
        scanner.close();
    }
}
