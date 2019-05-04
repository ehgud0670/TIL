import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.util.Scanner;

public class ChatClient1 {

    public static void main(String[] args) {
        try {
            Socket socket = new Socket();
            socket.connect(new InetSocketAddress("192.168.11.20",5000));

            OutputStream os = socket.getOutputStream();
            ReceiveThread receiveThread = new ReceiveThread(socket);
            receiveThread.start();

            Scanner sc = new Scanner(System.in);
            while(true){
                String str = sc.nextLine();
                os.write(str.getBytes());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}

