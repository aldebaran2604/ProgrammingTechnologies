/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import jess.JessException;
import jess.Rete;

/**
 *
 * @author lpadilla
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws JessException {
        // TODO code application logic here
        DiagnosticoEnfermedades de = new DiagnosticoEnfermedades();
        for(int cont=0 ; cont<args.length; cont++) {
            de.addSintoma("(assert ("+args[cont]+"))");
        }
        int contEnfermedades = de.runDiagnostico();
        if (contEnfermedades>0) {
            System.out.println("Esta dando las últimas");
            System.out.println("Tiene "+(contEnfermedades)+" enfermedad(es)");
        } else {
            System.out.println("Usted no tiene alguna enfermedad registrada puede que muera pronto");
        }
    }
}
