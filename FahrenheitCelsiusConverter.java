import javax.swing.JFrame;
import javax.swing.JTextField;
import javax.swing.JPanel;
import javax.swing.JButton;
import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class FahrenheitCelsiusConverter extends JFrame implements ActionListener{
    private JTextField eq;
    private JTextField ans;
    private JTextField f;
    private JTextField c;



    public static void main(String[] args) {
        FahrenheitCelsiusConverter calc = new FahrenheitCelsiusConverter();
        calc.setVisible(true);
    }

    public FahrenheitCelsiusConverter() {
        setTitle("Temperature Converter");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(800, 300);
        setLayout(new BorderLayout());

        JPanel textPanel = new JPanel();
        textPanel.setLayout(new GridLayout(2, 2));
        eq = new JTextField("enter temperature F", 30);
        eq.setEditable(false);
        eq.setBackground(Color.YELLOW);
        eq.setFont(new Font("Arial", Font.ITALIC, 40));
        textPanel.add(eq);
        f = new JTextField("Fahrenheit");
        f.setBackground(Color.ORANGE);
        f.setFont(new Font("Arial", Font.ITALIC, 40));
        textPanel.add(f);
        ans = new JTextField("enter temperature C");
        ans.setEditable(false);
        ans.setBackground(Color.ORANGE);
        ans.setFont(new Font("Arial", Font.ITALIC, 40));
        textPanel.add(ans);
        c = new JTextField("Celsius");
        c.setBackground(Color.YELLOW);
        c.setFont(new Font("Arial", Font.ITALIC, 40));
        textPanel.add(c);



        JPanel buttonPanel = new JPanel();
        buttonPanel.setBackground(Color.GREEN);
        buttonPanel.setLayout(new FlowLayout());

        JButton calculateFtoC = new JButton("Convert F to C");
        calculateFtoC.addActionListener(this);
        buttonPanel.add(calculateFtoC);

        JButton calculateCtoF = new JButton("Convert C to F");
        calculateCtoF.addActionListener(this);
        buttonPanel.add(calculateCtoF);

        JButton clear = new JButton("Clear");
        clear.addActionListener(this);
        buttonPanel.add(clear);

        add(textPanel, BorderLayout.NORTH);
        add(buttonPanel, BorderLayout.CENTER);


    }
    public void actionPerformed(ActionEvent e) {
        try {
            assumingCorrectNumberFormats(e);
        }
        catch(NumberFormatException e2) {
            f.setText("Error: reenter value");
        }

    }
    public void assumingCorrectNumberFormats(ActionEvent e) {

        String actionCommand = e.getActionCommand();
        if(actionCommand.equals("Convert F to C")) {

            try {
                c.setText("" + ((stringToDouble(f.getText()) - 32.0) * 5.0/9.0));
            } catch (ArrayIndexOutOfBoundsException a) {
                ans.setText("Error: invalid expression");
            }
        }
        else if (actionCommand.equals("Convert C to F")){
            try {
                f.setText("" + ((stringToDouble(c.getText()) * (9.0/5.0)) + 32.0));
            } catch (ArrayIndexOutOfBoundsException a) {
                ans.setText("Error: invalid expression");
            }
        }
        else if(actionCommand.equals("Clear")) {
            f.setText("Fahrenheit");
            c.setText("Celsius");
        }

    }
    private static double stringToDouble(String stringObject) {
        return Double.parseDouble(stringObject.trim());
    }
}
