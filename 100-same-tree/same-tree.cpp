/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
vector<int> v1,v2;
void fun(TreeNode *p,vector<int> &v1){
    if(p==NULL){
        return;
    }
    v1.push_back(p->val*9);
    fun(p->left,v1);
    v1.push_back(p->val*10);
    fun(p->right,v1);

}
void fun1(TreeNode *q,vector<int> &v2){
      if(q==NULL){
        return;
    }
    v2.push_back(q->val*9);
    fun(q->left,v2);
    v2.push_back(q->val*10);
    fun(q->right,v2);

    
}
    bool isSameTree(TreeNode* p, TreeNode* q) {
        fun(p,v1);
        fun1(q,v2);
        return v1==v2;
        
    }
};















server
import java.io.*;
import java.net.*;

public class FileServer {
    public static void main(String[] args) {
        int port = 5000; 
        String filePath = "attendance.docx";

        try (ServerSocket serverSocket = new ServerSocket(port)) {
            System.out.println("Server is running and waiting for a connection...");

            Socket clientSocket = serverSocket.accept();
            System.out.println("Client connected: " + clientSocket.getInetAddress());

           
            File file = new File(filePath);
            if (!file.exists()) {
                System.out.println("Error: File not found!");
                clientSocket.close();
                return;
            }

            try (FileInputStream fileInputStream = new FileInputStream(file);
                 BufferedInputStream bufferedInputStream = new BufferedInputStream(fileInputStream);
                 OutputStream outputStream = clientSocket.getOutputStream()) {

                byte[] buffer = new byte[8192]; 
                int bytesRead;

                System.out.println("Sending file...");
                while ((bytesRead = bufferedInputStream.read(buffer)) != -1) {
                    outputStream.write(buffer, 0, bytesRead);
                }
                outputStream.flush(); 
                System.out.println("File sent successfully.");
            }

            clientSocket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}


client
import java.io.*;
import java.net.*;

public class FileClient {
    public static void main(String[] args) {
        String serverAddress = "127.0.0.1"; 
        int port = 5000; 
        String saveFilePath = "received_file.docx"; 

        try (Socket socket = new Socket(serverAddress, port);
             InputStream inputStream = socket.getInputStream();
             FileOutputStream fileOutputStream = new FileOutputStream(saveFilePath);
             BufferedOutputStream bufferedOutputStream = new BufferedOutputStream(fileOutputStream)) {

            byte[] buffer = new byte[8192]; 
            int bytesRead;

            System.out.println("Connected to Server! Receiving file...");
            while ((bytesRead = inputStream.read(buffer)) != -1) {
                bufferedOutputStream.write(buffer, 0, bytesRead);
            }
            bufferedOutputStream.flush(); 
            System.out.println("File received and saved to: " + saveFilePath);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}



javac FileServer.java FileClient.java
java -cp . FileServer
java -cp . FileClient







----------------------------------------------------------------------------------->
#include <stdio.h>
#include <string.h>
#include <openssl/hmac.h>

void print_hex(unsigned char *data, int len) {
    for (int i = 0; i < len; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

int main() {
    const char *key = "secretkey";
    const char *message = "Hello, HMAC!";
    unsigned char hmac_result[EVP_MAX_MD_SIZE]; 
    unsigned int len;

    HMAC(EVP_sha256(), key, strlen(key), (unsigned char*)message, strlen(message), hmac_result, &len);

    printf("HMAC (SHA-256) of the message: ");
    print_hex(hmac_result, len);

    return 0;
}
