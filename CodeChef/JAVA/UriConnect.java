import java.net.URI;
import java.awt.Desktop;

class UriConnect {
    public static void main(String args[]) throws Exception{
        // Create Desktop object
        Desktop d=Desktop.getDesktop();

        // Browse a URL, say google.com
        d.browse(new URI("http://facebook.com"));

        }
    }
