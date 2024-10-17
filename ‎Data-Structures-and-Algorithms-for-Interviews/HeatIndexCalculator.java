import java.util.Scanner;

public class HeatIndexCalculator {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter temperature in Fahrenheit: ");
        double temperature = scanner.nextDouble();

        System.out.print("Enter relative humidity (percentage): ");
        double humidity = scanner.nextDouble();

        double heatIndex = calculateHeatIndex(temperature, humidity);

        System.out.printf("The heat index is: %.2f°F%n", heatIndex);
    }

    public static double calculateHeatIndex(double temperature, double humidity) {
        // Constants for the heat index formula
        final double c1 = -42.379;
        final double c2 = 2.04901523;
        final double c3 = 10.14333127;
        final double c4 = -0.22475541;
        final double c5 = -6.83783e-3;
        final double c6 = -5.481717e-2;
        final double c7 = 1.22874e-3;
        final double c8 = 8.5282e-4;
        final double c9 = -1.99e-6;

        // Calculate heat index using the formula
        double heatIndex = c1 + (c2 * temperature) + (c3 * humidity) + (c4 * temperature * humidity)
                + (c5 * Math.pow(temperature, 2)) + (c6 * Math.pow(humidity, 2))
                + (c7 * Math.pow(temperature, 2) * humidity) + (c8 * temperature * Math.pow(humidity, 2))
                + (c9 * Math.pow(temperature, 2) * Math.pow(humidity, 2));

        return heatIndex;
    }
}