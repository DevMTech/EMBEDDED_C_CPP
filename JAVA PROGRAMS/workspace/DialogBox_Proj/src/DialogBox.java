import javax.swing.JOptionPane;
public class DialogBox
{
	public static void main(String[] args)
	{	
		//JOptionPane.showMessageDialog(null, "First Java dialog");
		int creditDays = 30;
		JOptionPane.showMessageDialog(null, "" + creditDays);
		JOptionPane.showMessageDialog(null, "Every bill is due in " + creditDays + " days");
		
		String result;
		result = JOptionPane.showInputDialog(null, "What is your name?");
		JOptionPane.showMessageDialog(null, "Hello, " + result + "!");
	}
}

