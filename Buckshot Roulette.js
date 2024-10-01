import java.util.Random;
import java.util.Scanner;

class Player {
    String username;
    int health;

    public Player(String name, int health) {
        this.username = name;
        this.health = health;
    }

    public void shoot(Player target) {
        Random rand = new Random();
        int ammo = rand.nextInt(2) + 1; // 1 for blank, 2 for full round

        System.out.println("Do you want to shoot yourself (Y/N)?");
        Scanner scanner = new Scanner(System.in);
        String choice = scanner.next();

        if (choice.equalsIgnoreCase("Y")) {
            System.out.println(this.username + " chose to shoot themselves.");
            if (ammo == 1) {
                shoot(this); // player shoots themselves
            } else {
                target.health -= 1;
            }
        } else {
            System.out.println(this.username + " chose to shoot the enemy.");
            if (ammo == 1) {
                target.shoot(this); // enemy shoots self
            } else {
                target.health -= 1;
            }
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Welcome to BuckShot Roullette, Care to state your name?");
        String playerName = scanner.nextLine();
        System.out.println("Your name has been recorded.");
        System.out.println("----------------------");

        Player player = new Player(playerName, 3);
        Player enemy = new Player("Enemy", 3);

        System.out.println(player.username + " " + player.health);
        System.out.println(enemy.username + " " + enemy.health);

        while (player.health > 0 && enemy.health > 0) {
            player.shoot(enemy);

            if (enemy.health <= 0) {
                System.out.println("Player wins!");
            } else {
                System.out.println("Enemy chose to Shoot The Player");
                enemy.shoot(player);
            }

            if (player.health <= 0) {
                System.out.println("Enemy wins!");
            }
        }
    }
}
