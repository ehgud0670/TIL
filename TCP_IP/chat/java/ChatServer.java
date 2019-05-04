import java.io.IOException;
import java.net.InetSocketAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;

public class ChatServer{
    public static void main(String[] args) {
        try {
            ServerSocket serverSocket = new ServerSocket();
            serverSocket.bind(new InetSocketAddress("127.0.1.1", 5002));
            ArrayList<SendThread> sendThreads = new ArrayList<>();

            while (true) {
                Socket socket = serverSocket.accept();
                SendThread sendThread = new SendThread(socket, sendThreads);
                sendThread.start();
            }


        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
