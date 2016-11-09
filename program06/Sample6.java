import jess.*;
public class Sample6 {
  public static void main(String[] unused) throws JessException {
        Rete r = new Rete();
        r.eval("(reset)");
        r.eval("(defrule r1 (sintoma a) => (printout t \":)\"))");
	r.eval("(assert (sintoma a))");
        r.eval("(facts)");
        r.eval("(run)");
  }
}
