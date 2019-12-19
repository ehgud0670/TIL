import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.util.List;

class SessionThread extends Thread {

	private Socket socket;
	private List<Socket> socketList;
	private static final Object MUTEX = new Object();

	SessionThread(Socket socket, List<Socket> socketList) {
		this.socket = socket;
		this.socketList = socketList;
		synchronized(MUTEX){
			this.socketList.add(socket);
		}
	}

	private void broadcast(String message) throws IOException {
		synchronized(MUTEX){
			for (Socket socket : socketList) {
				OutputStream os = socket.getOutputStream();
				os.write(message.getBytes());
			}
		}
	}

	@Override
		public void run() {
			try (InputStream is = socket.getInputStream()) {
				while (true) {
					byte[] buf = new byte[512];
					int len = is.read(buf);
					if (len == -1) {
						System.out.println("[클라이언트 연결 끊김]");
						break;
					}

					String message = new String(buf, 0, len);
					broadcast(message);

				}
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
}

