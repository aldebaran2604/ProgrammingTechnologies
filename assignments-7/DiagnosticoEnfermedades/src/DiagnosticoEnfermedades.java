/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import jess.*;

/**
 *
 * @author lpadilla
 */
public class DiagnosticoEnfermedades {
    
    private Rete rete = new Rete();
    
    DiagnosticoEnfermedades(String archivo) throws JessException {
        rete.batch(archivo);
    }
    
    DiagnosticoEnfermedades() throws JessException {
        rete.batch("diagnostico.clp");
    }
    
    public void addSintoma(String sintoma) throws JessException {
        rete.eval(sintoma);
    }
    
    public int runDiagnostico() throws JessException {
        return rete.run();
    }
    
    public void resetDiagnostico() throws JessException {
        rete.reset();
    }
    
    public void addArchivoCLP(String archivo) throws JessException {
        rete.batch(archivo);
    }
    
    
}
