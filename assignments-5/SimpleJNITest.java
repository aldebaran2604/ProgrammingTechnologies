import java.util.List;
import java.util.ArrayList;
 
public class SimpleJNITest {
  ArrayList <String> values;
 
  public SimpleJNITest() {
    values = new ArrayList <> ();
  }
 
  public void addValue(String v) {
    values.add(v);
  }
 
  public int getSize() {
    return values.size();
  }
 
  public void printValues() {
    for (String v: values) {
      System.out.println("Value: " + v);
    }
  }
}  
