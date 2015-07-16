import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationHandler;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.lang.reflect.ParameterizedType;
import java.lang.reflect.Proxy;
import java.lang.reflect.Type;
import java.lang.reflect.TypeVariable;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

/**
 * 通过反射机制访问一个类的方法
 * @author Yajun Fu
 *
 */

interface MyInterface {
	void anyMethod();
}


public class Invoke {


	public static void main(String[] args) {
		try {
	          Class<?> clas = Class.forName( args[0] );
	          Method method = clas.getMethod( args[1] ); // Named method, 
	                                                     // no arguments
	          Object ret =  method.invoke( null );  // Invoke a static method

	          System.out.println(
	              "Invoked static method: " + args[1]
	              + " of class: " + args[0]
	              + " with no args\nResults: " + ret );
	        } catch ( ClassNotFoundException e ) {
	          // Class.forName() can't find the class
	        } catch ( NoSuchMethodException e2 ) {
	          // that method doesn't exist
	        } catch ( IllegalAccessException e3 ) {
	          // we don't have permission to invoke that method
	        } catch ( InvocationTargetException e4 ) {
	          // an exception occurred while invoking that method
	          System.out.println(
	              "Method threw an: " + e4.getTargetException() );
	        }
	        
	        /**
	         * 通过反射机制访问一个类的构造函数 
	         */
	        try {
	            Constructor<Date> cons =
	                Date.class.getConstructor( String.class );
	            Date date = cons.newInstance( "Jan 1, 2006" );
	            System.out.println( date );
	        } catch ( NoSuchMethodException e ) {
	            // getConstructor() couldn't find the constructor we described
	        } catch ( InstantiationException e2 ) {
	            // the class is abstract
	        } catch ( IllegalAccessException e3 ) {
	            // we don't have permission to create an instance
	        } catch ( InvocationTargetException e4 ) {
	            // the construct threw an exception
	        }

	        /**
	         * 通过反射机制访问模板类
	         */
	     // public interface List<E> extends Collection<E> { ... }
	        TypeVariable [] tv = List.class.getTypeParameters();
	        System.out.println( tv[0].getName() ); // "E"
	        
	        class StringList extends ArrayList<String> { }

	        Type type = StringList.class.getGenericSuperclass();

	        System.out.println( type );  //
	        // "java.util.ArrayList<java.lang.String>"

	        ParameterizedType pt = (ParameterizedType)type;
	        System.out.println( pt.getActualTypeArguments()[0] ); //
	        // "class java.lang.String"
	        
	}

}
