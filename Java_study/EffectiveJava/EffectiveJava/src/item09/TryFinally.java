package item09;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.FileInputStream;
import java.io.OutputStream;
import java.io.FileOutputStream;

public class TryFinally {
    private static final int BUFFER_SIZE = 1024;

    static String firstLineOfFile(String path) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(path));
        try {
            return br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                br.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return "";
    }
     /// 이와 같은 방식으로 CATCH 문을 싸줘야 어디서 에러가 처음에 났는지 알수가 있다. => 매우 번거롭고 코드가 너무 지저분하다.
    static void copy(String src, String dst) throws IOException {

        InputStream in = new FileInputStream(src);
        try {
            OutputStream out = new FileOutputStream(dst);
            try {
                byte[] buf = new byte[BUFFER_SIZE];
                int n;
                    try {
                        while ((n = in.read(buf)) >= 0) {
                            out.write(buf, 0, n);
                        }
                    } catch(IOException e){
                        e.printStackTrace();
                    }

            } finally {
                try {
                    out.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        } finally {
            try {
                in.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

}