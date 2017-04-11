public class Casa
{
    // se declaran los atributos privados de la clase
    private String nomenclatura;
    private int kilovatios;
    private int costo;
    private double subtotal;
    
    public Casa()
    {
        // se le asignan valores por defecto en el constructor de la clase a los atributos
        nomenclatura = "";
        kilovatios = 0;
        costo = 0;
        subtotal = 0;
    }
    
    // métodos Setters y Getters de los atributos de la clase
    public void setNomenclatura(String val)
    {
        nomenclatura = val;
    }
    
    public String getNomenclatura()
    {
        return nomenclatura;
    }
    
    public void setKilovatios(int val)
    {
        kilovatios = val;
    }
    
    public int getKilovatios()
    {
        return kilovatios;
    }
    
    public void setCosto(int val)
    {
        costo = val;
    }
    
    public int getCosto()
    {
        return costo;
    }
    
    public void setSubtotal(double val)
    {
        subtotal = val;
    }
    
    public double getSubtotal()
    {
        return subtotal;
    }
}