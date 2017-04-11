
import javax.swing.JOptionPane;

public class Main
{
    // método para mostrar el vector
    public static void mostrarVector(Facturacion obj)
    {
        // inicializamos una variable de tipo string llamada datosVector en vacio
        String datosVector = "";
        // recorremos el vector con el ciclo for
        for (int i = 0; i < obj.getTamaño(); i++)
        {
            // acumulamos en la variable datosVector los datos que haya en cada posicion del vector
            datosVector +=  "Nomenclatura: " + obj.getVector(i).getNomenclatura() + "\n" +
                            "Kilovatios consumidos: " + obj.getVector(i).getKilovatios() + "\n" +
                            "Costo basico: $" + obj.getVector(i).getCosto()+ "\n" +
                            validar(obj, i) + "\n" +
                            "Subtotal: " + obj.getVector(i).getSubtotal() + "\n\n";
        }
        JOptionPane.showMessageDialog(null, datosVector);
    }
    
    // método para validar el costo
    public static String validar(Facturacion obj, int pos)
    {
        // si los kilovatios de la casa de la posicion pos es superior a 350 kilovatios
        if (obj.getVector(pos).getKilovatios() > 350)
        {
            // entonces se le cobrara el triple al costo
            return "Se le cobrara el triple al costo por kilovatios" + "\n" +
                   "Nuevo costo: $" + (obj.getVector(pos).getKilovatios() * 3);
        }
        else
        {
            // sino el municipio le dara un subsidio
            return "El municipio le ha subsidiado un 0.8% al subtotal" + "\n" +
                   "Descuento: $" + (obj.getVector(pos).getKilovatios() * obj.getVector(pos).getCosto()) * 0.08;
        }
    }
    
    // método para llenar los datos de la casa
    public static void llenar(Casa cas)
    {
        String nom = JOptionPane.showInputDialog("Digite nomenclatura de la casa:");
        cas.setNomenclatura(nom);
        int kil = Integer.parseInt(JOptionPane.showInputDialog("Digite kilovatios consumidos de la casa:"));
        cas.setKilovatios(kil);
        int cos = Integer.parseInt(JOptionPane.showInputDialog("Digite costo basico por kilovatio:"));
        cas.setCosto(cos);
    }
    
    public static void main(String[] args)
    {
        // se crea un objeto de la clase Facturacion (Instanciación)
        Facturacion obj = new Facturacion();
        // se declara un objeto de tipo Casa
        Casa cas;
        // pedimos el tamaño del vector
        int numeroElementos = Integer.parseInt(JOptionPane.showInputDialog(null, "Digite tamaño del Vector:"));
        // encapsumalos la variable numeroElementos
        obj.setTamaño(numeroElementos);
        // creamos el vector
        obj.crearVector();
        // recorremos el vector con ciclo for
        for (int i = 0; i < obj.getTamaño(); i++)
        {
            // creamos una nueva instancia de tipo Casa
            cas = new Casa();
            JOptionPane.showMessageDialog(null, "Llene la informacion de la casa " + i);
            // se llena la informacion del objeto cas
            llenar(cas);
            // guardamos en la posicion i el objeto cas
            obj.setVector(i, cas);
        }
        // calculamos el subtotal
        obj.calcularSubtotal();
        // mostramos el vector
        mostrarVector(obj);
    }
}
