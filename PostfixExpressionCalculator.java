import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Stack;

public class PostfixExpressionCalculator {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        Stack<Double> operand = new Stack<Double>();
        try {
            scan = new Scanner(new File("in.dat"));

        }
        catch(FileNotFoundException e) {
            System.out.print("File not found");
        }
    while(scan.hasNextLine()) {
        String line = scan.nextLine();
        Scanner scan2 = new Scanner(line);

        while (scan2.hasNext()) {
            String next = scan2.next();
            if(next.charAt(0) == '0' || next.charAt(0) == '1' || next.charAt(0) == '2' || next.charAt(0) == '3' || next.charAt(0) == '4' || next.charAt(0) == '5'
                    || next.charAt(0) == '6' || next.charAt(0) == '7' || next.charAt(0) == '8' || next.charAt(0) == '9') {
                operand.push(Double.parseDouble(next));
            }
            else {  if(next.equals("+") || next.equals("-") || next.equals("*") || next.equals("/") || next.equals("^") ) {
                Double n1 = operand.pop();
                Double n2 = operand.pop();

                if (next.equals("+")) {
                    operand.push(n1 + n2);
                } else if (next.equals("-")) {
                    operand.push(n2 - n1);
                } else if (next.equals("*")) {
                    operand.push(n2 * n1);

                } else if (next.equals("/")) {
                    operand.push(n2 / n1);
                } else if (next.equals("^")) {
                    operand.push(Math.pow(n2, n1));
                }
            }

                     else if (next.equals("_")) {
                        Double n1 = -operand.pop();
                        operand.push(n1);
                    } else if (next.equals("#")) {
                        Double n1 = operand.pop();
                        operand.push(Math.sqrt(n1));
                    }

                }
            }
        System.out.println("The value of \"" + line + "\" is " + operand.pop());
        }




    }






    }

