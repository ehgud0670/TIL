import java.io.IOException;
import java.io.OutputStream;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.util.Scanner;

public class ChatClient {
    public static void main(String[] args) {
        try {
            Socket socket = new Socket();
            socket.connect(new InetSocketAddress("localhost", 5000));
            System.out.println("[서버에 연결 성공]");

            ReceiveThread receiveThread = new ReceiveThread(socket);
            receiveThread.start();

            try (OutputStream os = socket.getOutputStream()) {

                Scanner sc = new Scanner(System.in);
                while (true) {
                    String str = sc.nextLine();
                    os.write(str.getBytes());
                }
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

