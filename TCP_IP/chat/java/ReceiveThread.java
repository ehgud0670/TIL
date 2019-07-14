import java.io.IOException;
import java.io.InputStream;
import java.net.Socket;

class ReceiveThread extends Thread {

    private Socket socket;

    ReceiveThread(Socket socket) {
        this.socket = socket;
    }

    @Override
    public void run() {

        try (InputStream is = socket.getInputStream()) {
            while (true) {
                byte[] buf = new byte[512];
                int len = is.read(buf);
                if (len == -1) {
                    System.out.println("[서버 연결 끊김]");
                    break;
                }
                String message = new String(buf, 0, len);
                System.out.println(message);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

