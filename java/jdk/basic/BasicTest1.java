

public class BasicTest1 {

    public static void main(String args[]) {

        //Basic Primitive 
        int RICHARD_NIXONS_SSN = 567_68_0515;
        int for_no_reason = 1___2___3;
        int JAVA_ID = 0xCAFE_BABE;

        System.out.println("RICHARD_NIXONS_SSN: " + RICHARD_NIXONS_SSN);
        System.out.println("for_no_reason: " + for_no_reason);
        System.out.println("JAVA_ID: " + JAVA_ID);

        //floating-point literals
        double d = 8.31;
        double e = 3.00e+8;
        float f = 8.31F;
        float g = 3.00e+8F;
        float pi = 3.14_159_265_358f;

        //Binary Literals
        byte one =     (byte)0b00000001;
        byte two =     (byte)0b00000010;
        byte four =    (byte)0b00000100;
        byte sixteen = (byte)0b00001000;
        int cafebabe = 0b11001010111111101011101010111110;
        long lots_o_ones = (long)0b11111111111111111111111111111111111111111111111L;

        //character literals
        char a = 'a';
        char newline = '\n';
        char smiley = '\u263a';

        System.out.println("smiley: " + smiley);

    }

}
