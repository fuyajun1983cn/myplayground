

public StringTest {

    public static void main (String[] args) {
        String quote = "To be or not to be";
        int length = quote.length();
        boolean empty = quote.isEmpty();

        //String name = "John " + "Smith";
        String name = "John ".concat("Smith");

        String poem =
        "'Twas brillig, and the slithy toves\n" +
        "   Did gyre and gimble in the wabe:\n" +
        "All mimsy were the borogoves,\n" +
        "   And the mome raths outgrabe.\n";

        //construct from char array
        char [] data = new char [] { 'L', 'e', 'm', 'm', 'i', 'n', 'g' };
        String lemming = new String( data );

        //construct from utf-8 array
        //
        byte [] data = new byte [] { (byte)97, (byte)98, (byte)99 };
        String abc = new String(data, "ISO8859_1");

       //access the characters of a String
       //
        String s = "Newton";
        for ( int i = 0; i < s.length(); i++ )
            System.out.println( s.charAt( i ) );

        //get the characters all at once
        //
        char [] abcs = "abcdefghijklmnopqrstuvwxyz".toCharArray();

        //get strings from other things
        String one = String.valueOf( 1 ); // integer, "1"
        String two = String.valueOf( 2.384f );  // float, "2.384"
        String notTrue = String.valueOf( false ); // boolean, "false"

        Date date = new Date();
        // Equivalent, e.g., "Fri Dec 19 05:45:34 CST 1969"
        String d1 = String.valueOf( date );
        String d2 = date.toString();

        date = null;
        d1 = String.valueOf( date );  // "null"
        d2 = date.toString();  // NullPointerException!

        //+
        String today = "Today's date is :" + date;

        String two = "" + 2.384f;
        String today = "" + new Date();


        //StringBuilder is used to build a complex string from components.
        //is an unsynchronized relacement for StringBuffer.
        tringBuilder sb = new StringBuilder("Hello");
        sb.append(" there.");
        sb.append(" How are you?");

        StringBuilder text = new StringBuilder();
        while( (line = readline()) != EOF )
            text.append( line );
         String message = sb.toString();

    }
