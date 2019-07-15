## Gson

Packet.java
```java
// Protocol - Calculation
// => Json(Gson) 
//   [op: char ][lhs: int][rhs: int ]
//   '+', '-' , '*'
public class Packet {
	private char op;
	private int lhs;
	private int rhs;

	Packet(char op, int lhs, int rhs) {
		this.op = op;
		this.lhs = lhs;
		this.rhs = rhs;
	}

	public char getOp() {
		return op;
	}

	public int getLhs() {
		return lhs;
	}

	public int getRhs() {
		return rhs;
	}
}
```


Server.java
```java
import com.google.gson.Gson;
import gson.Packet;

import java.io.DataInputStream;
import java.io.EOFException;
import java.io.IOException;
import java.io.InputStream;
import java.net.ServerSocket;
import java.net.Socket;

// Protocol - Calculation
// => Json(Gson)
//   [op: char ][lhs: int][rhs: int ]
//   '+', '-' , '*'
public class Server {
	public static void main(String[] args) {
		try {
			ServerSocket serverSocket = new ServerSocket(5000);
			Socket socket = serverSocket.accept();
			try (InputStream is = socket.getInputStream();
					DataInputStream dis = new DataInputStream(is)) {

				int count = 0;
				while (true) {
					byte[] data = new byte[1024];
					int packetLen;
					try {
						packetLen = dis.readInt();
					} catch (EOFException e) {
						break;
					}

					int ret = is.read(data, 0, packetLen);
					if (ret == -1) {
						break;
					}

					String json = new String(data, 0, packetLen);
					Gson gson = new Gson();
					Packet packet = gson.fromJson(json, Packet.class);
					System.out.printf("[%5d] %d %c %d\n", count++, packet.getLhs(), packet.getOp(), packet.getRhs());

				}
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
```

Client.java
```java
import com.google.gson.Gson;
import gson.Packet;

import java.io.DataOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.Socket;

public class Client {

    public static void main(String[] args) {

        Packet packet = new Packet('+', 10, 20);
        Gson gson = new Gson();
        String json = gson.toJson(packet);

        try {
            Socket socket = new Socket("127.0.0.1", 5000);

            try (OutputStream os = socket.getOutputStream();
                 DataOutputStream dos = new DataOutputStream(os)) {
                for (int i = 0; i < 100000; i++) {
                    byte[] data = json.getBytes();
                    int len = data.length;
                    dos.writeInt(len);
                    os.write(data, 0, len);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```
