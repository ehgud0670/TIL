
import java.io.IOException;
import java.io.OutputStream;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.util.Scanner;

public class ChatClient2 {
    public static void main(String[] args) {
        try {
            Socket socket = new Socket();
            socket.connect(new InetSocketAddress("127.0.1.1",5000));

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

