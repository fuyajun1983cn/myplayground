
public class AnnotationTest {


	public static void main(String[] args) {

	}

}

@Deprecated
class OldClass {}

class AgingClass 
{
    @Deprecated 
    public void someMethod() {  }

}

class TestingClass {
	
	@Author( first="Pat",
            last="Niemeyer" )
    @TestValues( { "one",
              "two" } )
	public void someMethod() {}
}
