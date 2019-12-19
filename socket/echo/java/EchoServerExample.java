
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.InetSocketAddress;
import java.net.ServerSocket;
import java.net.Socket;

public class EchoServerExample {
	public static void main(String[] args) {
		try {
			ServerSocket serverSocket = new ServerSocket();
			serverSocket.bind(new InetSocketAddress("localhost", 5001));

			Socket socket = serverSocket.accept();
			try(InputStream is = socket.getInputStream();
					OutputStream os = socket.getOutputStream()){

				byte[] buf = new byte[512];
				while (true) {

					int len = is.read(buf);
					if (len == -1) {
						break;
					}
					String message = new String(buf,0,len);
					System.out.println(message);

					os.write(buf, 0, len);
				}
			} 



		} catch (IOException e) {
			e.printStackTrace();
		}

	}
}

