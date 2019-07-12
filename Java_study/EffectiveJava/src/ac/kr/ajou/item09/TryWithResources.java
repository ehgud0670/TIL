package ac.kr.ajou.item09;

import java.io.*;

public class TryWithResources {
    private static final int BUFFER_SIZE = 1024;

    static String firstLineOfFile(String path) throws IOException {
        try (BufferedReader br = new BufferedReader(new FileReader(path))) {
            return br.readLine();
        }
    }
    static String firstLineOfFile(String path, String defaultVal){
        try (BufferedReader br = new BufferedReader(new FileReader(path))) {
            return br.readLine();
        } catch(IOException e){
            return defaultVal;
        }
    }  // => 해당 메소드는 파일을 열지 못하거나 데이터를 읽지 못했을 때 예외를 던지는 대신 defaultVal 이라는 기본값을 반환하는 메소드이다.


    // try-with-resources 을 사용하면 자동으로 자원을 닫아 준다.
    // 또한 어디서 먼저 에러가 났는지 알 수 있고(close()메소드의 에러는 숨겨지기(suppressed) 때문이다.),
    // 가독성을 매우 높여준다는 큰 장점이 있다. => 자원 닫기를 해야 할 경우에 반드시 try-with-resources 문을 사용하자!
    static void copy(String src, String dst) throws IOException {
        try (InputStream in = new FileInputStream(src);
             OutputStream out = new FileOutputStream(dst)) {

            byte[] buf = new byte[BUFFER_SIZE];
            int n;
            while ((n = in.read(buf)) >= 0) {
                out.write(buf, 0, n);
            }

        }

    }
}