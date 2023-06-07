import javax.swing.JFrame;
import javax.swing.JTextField;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JButton;
import javax.swing.JTextArea;
import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;


public class Calculator2 extends JFrame implements ActionListener {
    private JTextField eq;
    private JTextField ans;
    private JTextArea area;



    private double answer = 0.0;

    public static void main(String[] args) {
        Calculator2 calc = new Calculator2();
        calc.setVisible(true);
    }

    public Calculator2() {
        setTitle("Calculator");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(800, 300);
        setLayout(new BorderLayout());

        JPanel textPanel = new JPanel();
        textPanel.setLayout(new GridLayout(3, 1));
        eq = new JTextField("Enter an expression", 30);
        eq.setBackground(Color.YELLOW);
        eq.setFont(new Font("Arial", Font.ITALIC, 40));
        textPanel.add(eq);
        ans = new JTextField("Answer");
        ans.setEditable(false);
        ans.setBackground(Color.ORANGE);
        ans.setFont(new Font("Arial", Font.ITALIC, 40));
        textPanel.add(ans);
        area = new JTextArea("Enter a mathematical expression, which allows for the four basic operations and " +
                "exponentiation\n (represented by the \"^\" symbol). Any negative number must be enclosed in parenthesis.");
        area.setEditable(false);
        area.setBackground(Color.RED);
        area.setFont(new Font("Times New Roman", Font.ITALIC, 16));
        textPanel.add(area);


        JPanel buttonPanel = new JPanel();
        buttonPanel.setBackground(Color.GREEN);
        buttonPanel.setLayout(new FlowLayout());

       JButton calculate = new JButton("Calculate");
       calculate.addActionListener(this);
       buttonPanel.add(calculate);

        JButton reset = new JButton("Reset");
        reset.addActionListener(this);
        buttonPanel.add(reset);
        add(textPanel, BorderLayout.NORTH);
        add(buttonPanel, BorderLayout.CENTER);

       // add(buttonPanel, BorderLayout.CENTER);
    }
    public void actionPerformed(ActionEvent e) {
        try {
            assumingCorrectNumberFormats(e);
        }
        catch(NumberFormatException e2) {
            eq.setText("Error: reenter value");
        }

    }
    public void assumingCorrectNumberFormats(ActionEvent e) {

      String actionCommand = e.getActionCommand();
        if(actionCommand.equals("Calculate")) {
            LR eval = new LR(eq.getText());
            try {
                answer = eval.evaluator();
                if (answer == (int)Math.round(answer)){
                    ans.setText("" + (int)answer);
                }
                else{
                    ans.setText(Double.toString(answer));
                }
            } catch (ArrayIndexOutOfBoundsException a) {
                ans.setText("Error: invalid expression");
            }
        }
        else if(actionCommand.equals("Reset")) {
            answer = 0.0;
            eq.setText("0.0");
            ans.setText("Answer");
        }

    }
    private static double stringToDouble(String stringObject) {
        return Double.parseDouble(stringObject.trim());
    }
}

