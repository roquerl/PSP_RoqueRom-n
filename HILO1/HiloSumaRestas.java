public class HiloSumaRestas implements Runnable {


    private static int numero = 1000;
    
    public HiloSumaRestas (){

    }

    public HiloSumaRestas(int numveces, String operacion){
            this.numveces = numveces;
            this.operacion = operacion;
            
    }

    



    public int incrementar( int numveces){
        
        numero = numero + numveces;
        
        return numero;


    }

    public int decrementar( int numveces){
        
        numero = numero - numveces;
        
        return numero;


    }

    @Override
    public void run() {
        
        HiloSumaRestas h = new HiloSumaRestas();
        if(h.))
        
    }
    
}
