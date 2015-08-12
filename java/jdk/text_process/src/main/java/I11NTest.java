
import java.util.Locale;
import java.util.ResourceBundle;
import java.util.Date;
import java.text.*;

public class I11NTest {

    public static void main (String[] args) {
        Locale l = Locale.ITALIAN;
        System.out.println(l.getCountry());        
        System.out.println(l.getDisplayCountry());
        System.out.println(l.getDisplayLanguage());

        //use Locales to determine how to format and parse dates and times
        System.out.printf(Locale.ITALIAN, "%f\n", 3.14);


        //ResourceBundle
        //You can provide ResourceBundle in two ways: either as compiled Java
        //classes(hard-coded Java) or as simple property files. 
        ResourceBundle bun;
        bun = ResourceBundle.getBundle("Message", Locale.ITALY);
        System.out.println(bun.getString("HelloMessage"));
//        bun = ResourceBundle.getBundle("Message", Locale.US);
//        System.out.println(bun.getString("HelloMessage"));

        double salary = 1234.56;
        String here = NumberFormat.getCurrencyInstance().format(salary);
        String italy = NumberFormat.getCurrencyInstance(Locale.ITALY).format(salary);
        System.out.println("here: " + here + " salary: " + italy);

        double progress = 0.44;
        NumberFormat pf = NumberFormat.getPercentInstance();
        System.out.println( pf.format(progress) );    // "44%"
        try {
            System.out.println( pf.parse("77.2%") );  // "0.772"
        }
        catch (ParseException e) {}

        double[] limits = new double [] {0, 20, 40};
        String[] labels = new String [] {"young", "less young", "old"};
        ChoiceFormat cf = new ChoiceFormat(limits, labels);
        System.out.println(cf.format(12)); //"young"
        System.out.println(cf.format(26)); // "less young"

        MessageFormat mf = new MessageFormat(
        "You have {0, number, integer} messages on {1, date, long}.");
        // "You have 93 messages on April 10, 2002."
        //System.out.println( mf.format( 93, new Date() ) );
    }
}
