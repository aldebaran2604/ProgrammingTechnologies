import jess.*;

class MainClass {
	private Rete rete = new Rete();
	public MainClass(String archivo) throws JessException {
		rete.reset();
		rete.batch(archivo);
	}

	public MainClass() throws JessException {
		rete.reset();
	}

	public void addAssert(String nameAssert) throws JessException {
		rete.eval("(assert ("+nameAssert+"))");
	}

	public String getFetch(String nameFetch) throws JessException {
		return rete.fetch(nameFetch).stringValue(rete.getGlobalContext());
	}

	public int runJess() throws JessException {
        return rete.run();
    }

    public void addArchivoCLP(String archivo) throws JessException {
        rete.batch(archivo);
    }

	public static void main(String[] args) throws JessException {
        MainClass mainClass = new MainClass("diagnostico.clp");
        for(int cont=0 ; cont<args.length; cont++) {
            mainClass.addAssert(args[cont]);
        }
        int contEnfermedades = mainClass.runJess();
        if (contEnfermedades>0) {
            System.out.println("Esta dando las últimas");
            System.out.println("Tiene "+mainClass.getFetch("enfermedad"));
        } else {
            System.out.println("Usted no tiene alguna enfermedad registrada puede que muera pronto");
        }
	}
}