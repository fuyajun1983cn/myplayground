
public class Test {

    /**
     * 最大公约数
     * 辗转相除法：
     * 先用小的数，除了大的数，然后取余数，若余数为0,则得到正解，
     * 否则，继续使用小数除以刚才得到的余数，得到下一个余数，
     * 依此类推。
     */
    private static int  gcd(int a, int b) {
        int max = a > b ? a : b;
        int min = a < b ? a : b;
        int result = max%min;

        while (result != 0) {
            max = min;
            min = result;

            result = max%min;
        }
        
        return min;
    }

    private static int gcd2(int a, int b) {
        int max = a > b ? a : b;
        int min = a < b ? a : b;
        if (max%min == 0)
            return min;
        else
            return gcd2(min, max%min);
    }

    /**
     * 最小公倍数
     */
    private static int lcd(int a, int b) {

        return a * b / gcd(a, b);
    }

    private static int lcd2(int a, int b) {
        int axb = a * b;

        int ret = axb;
        while ( axb % a == 0 && axb % b == 0) {
            ret = axb;
            axb = axb / 2;
        }
        return ret;
    }

    public static void main(String args[]) {
   
        System.out.println(gcd(4, 5));
        System.out.println(gcd2(4, 5));

        System.out.println(lcd(4, 20));
        System.out.println(lcd2(4, 20));
    }

}
