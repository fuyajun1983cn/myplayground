import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;

class BankAccount {
	public int balance;
}

public class ReflectionTest {

	public void listMethods(Class<?> cls) {
		for (Method m : cls.getMethods()) {
			System.out.println(m.getName());
		}
	}

	private String modifierInfo(Method m) {
		int perms = m.getModifiers();
		String result = "";
		if (Modifier.isPublic(perms)) {
			result += "PUBLIC ";
		} 
		
		if (Modifier.isProtected(perms)) {
			result += "PROTECTED ";
		} 
		
		if (Modifier.isPrivate(perms)) {
			result += "PRIVATE ";
		} 
		
		if (Modifier.isFinal(perms)) {
			result += "FINAL ";
		}
		return result;
	}

	public void listDeclaredMethods(Class<?> cls) {
		for (Method m : cls.getDeclaredMethods()) {
			System.out.println(m.getName() + " : " + modifierInfo(m));
		}
	}
	/**
	 * 通过反射机制访问一个类的成员变量
	 * 当成员变量为私有时，不能进行读写
	 */
	public void accessField() {
		BankAccount myBankAccount = new BankAccount();

	    try {
	        Field balanceField = BankAccount.class.getField("balance");
	        // read it
	        int mybalance = balanceField.getInt( myBankAccount );
	        System.out.println("before mybalance = " + mybalance);
	        
	        // change it
	        balanceField.setInt( myBankAccount, 42 );
	        
	        // read it
	        mybalance = balanceField.getInt( myBankAccount );
	        System.out.println("after mybalance = " + mybalance);
	    } catch ( NoSuchFieldException e ) {
	        
	    } catch ( IllegalAccessException e2) {
	        
	    }
	}

	public static void main(String[] args) {
		ReflectionTest test = new ReflectionTest();
		//test.listDeclaredMethods(java.util.Calendar.class);
		test.accessField();
	}

}

/*

public class ReflectionTest {

    public static void main(final String[] args) {

        System.out.println("Started by ReflectionTest");

    }

}
*/

