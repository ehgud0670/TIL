import java.io.IOException;
import java.net.InetSocketAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

public class ChatServer {

    public static void main(String[] args) {
        try {
            ServerSocket serverSocket = new ServerSocket();
            serverSocket.bind(new InetSocketAddress("localhost", 5000));

            List<Socket> socketList = new ArrayList<>();
            while (true) {
                Socket socket = serverSocket.accept();
                System.out.println("[클라이언트 접속]");
                SessionThread sessionThread = new SessionThread(socket, socketList);
                sessionThread.start();
            }


        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
