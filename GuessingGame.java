import java.util.Scanner;


public class GuessingGame {
    //This program prompts the user to think of a number
    //between 1 and 1,000,000.
    //The program then tries to guess the user's number.
    //The user then tells the program whether the number
    //was higher, lower, or if the program guessed the number
    //The program will keep running until it guesses the users number.

    public static void main(String[] args) {
        guess(1, 1000000);
    }
    public static void guess(int low, int high) {
        Scanner scan = new Scanner(System.in);
        int n = (low + high) / 2;
        System.out.println("Think of a number between 1 and 1,000,000, and I'll try to guess it!\n");
        System.out.println("Is " + n + " your number? If so type \"Y\". If not, type \"H\" for higher or \"L\" for lower.");
        String answer = scan.next();
        while(!answer.equalsIgnoreCase("Y") && !answer.equalsIgnoreCase("L") && !answer.equalsIgnoreCase("H" )){
            System.out.println("Your answer was invalid. Please type \"Y\" if " + n + " is your number, or type \"H\" for higher, or \"L\" for lower.");
            answer = scan.next();
        }
        if(answer.equalsIgnoreCase("Y")) {
            System.out.println("I guessed your number!");
        }
        else if(answer.equalsIgnoreCase("H")) {
                guess(n + 1, high);
            }
            else {
                guess(low, n - 1);
            }
        }

    }

