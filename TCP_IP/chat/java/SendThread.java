
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.util.ArrayList;


public class SendThread extends Thread {

    private Socket socket;
    private ArrayList<SendThread> sendThreadList;

    SendThread(Socket socket, ArrayList<SendThread> sendThreadList){
        this.socket = socket;
        this.sendThreadList = sendThreadList;
        this.sendThreadList.add(this);
    }

    private void sendAllClients(byte[] buf, int len){
        for(SendThread sendThread: sendThreadList){
            OutputStream os;
            try {
                os = sendThread.socket.getOutputStream();
                os.write(buf,0,len);
            } catch (IOException e) {
                e.printStackTrace();
            }

        }
    }

    @Override
    public void run() {
        try {

            while (true) {
                byte[] buf = new byte[512];
                InputStream is = socket.getInputStream();

                int len = is.read(buf);
                if(len == -1 ){
                    break;
                }
                sendAllClients(buf, len);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

