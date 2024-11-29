import java.util.Scanner;

class Stack {
    private int maxSize;
    private int[] stackArray;
    private int top;

    // Constructor to initialize the stack
    public Stack(int size) {
        maxSize = size;
        stackArray = new int[maxSize];
        top = -1;
    }

    // Push method to add an element to the stack
    public void push(int value) {
        if (isFull()) {
            System.out.println("Stack is full. Cannot push " + value);
        } else {
            stackArray[++top] = value;
            System.out.println("Pushed " + value + " to the stack.");
        }
    }

    // Pop method to remove the top element from the stack
    public int pop() {
        if (isEmpty()) {
            System.out.println("Stack is empty. Cannot pop.");
            return -1;
        } else {
            System.out.println("Popped " + stackArray[top] + " from the stack.");
            return stackArray[top--];
        }
    }

    // Peek method to view the top element without removing it
    public int peek() {
        if (isEmpty()) {
            System.out.println("Stack is empty.");
            return -1;
        } else {
            return stackArray[top];
        }
    }

    // Method to check if the stack is empty
    public boolean isEmpty() {
        return (top == -1);
    }

    // Method to check if the stack is full
    public boolean isFull() {
        return (top == maxSize - 1);
    }
}

public class StackDemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Create a stack with a size of 5
        Stack stack = new Stack(5);

        boolean exit = false;

        while (!exit) {
            System.out.println("\nChoose an operation: ");
            System.out.println("1. Push");
            System.out.println("2. Pop");
            System.out.println("3. Peek");
            System.out.println("4. Exit");

            int choice = scanner.nextInt();
            switch (choice) {
                case 1:
                    System.out.print("Enter a value to push: ");
                    int value = scanner.nextInt();
                    stack.push(value);
                    break;

                case 2:
                    stack.pop();
                    break;

                case 3:
                    int topValue = stack.peek();
                    if (topValue != -1) {
                        System.out.println("Top element is: " + topValue);
                    }
                    break;

                case 4:
                    exit = true;
                    System.out.println("Exiting...");
                    break;

                default:
                    System.out.println("Invalid choice! Please select again.");
            }
        }
        scanner.close();
    }
}
