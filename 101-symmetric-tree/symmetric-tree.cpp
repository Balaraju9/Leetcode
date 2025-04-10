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
    bool fun(TreeNode* r1,TreeNode* r2){
        if(r1==NULL && r2!=NULL || r1!=NULL && r2==NULL){
            return false;
        }
        else if(r1==NULL && r2==NULL){
            return true;
        }
        else if(r1->val !=r2->val){
            return false;
        }
        return fun(r1->left,r2->right) && fun(r1->right,r2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right!=NULL) || (root->left!=NULL && root->right==NULL)){
            return false;
        }
        return fun(root->left,root->right);
        
    }
};










---------------------------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <ctype.h>
shift
int main() {
    char text[500];
    int key;

    printf("Enter a message to decrypt: ");
    fgets(text, sizeof(text), stdin);  // Read full message with spaces

    printf("Enter the key: ");
    scanf("%d", &key);

    for (int i = 0; text[i] != '\0'; ++i) {
        char ch = text[i];

        if (islower(ch)) {
            ch = (ch - 'a' - key + 26) % 26 + 'a';
        } 
        else if (isupper(ch)) {
            ch = (ch - 'A' - key + 26) % 26 + 'A';
        } 
        else if (isdigit(ch)) {
            ch = (ch - '0' - key + 10) % 10 + '0';
        }
        text[i] = ch;  // Store modified character
    }

    printf("Decrypted message: %s", text);
    return 0;
}

-----------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>

// Mapping for Mono-Alphabetic Substitution Cipher
char alpha[26][2] = { 
    {'a', 'f'}, {'b', 'a'}, {'c', 'g'}, {'d', 'u'}, {'e', 'n'}, {'f', 'i'}, {'g', 'j'}, {'h', 'k'}, {'i', 'l'}, 
    {'j', 'm'}, {'k', 'o'}, {'l', 'p'}, {'m', 'q'}, {'n', 'r'}, {'o', 's'}, {'p', 't'}, {'q', 'v'}, {'r', 'w'}, 
    {'s', 'x'}, {'t', 'y'}, {'u', 'z'}, {'v', 'b'}, {'w', 'c'}, {'x', 'd'}, {'y', 'e'}, {'z', 'h'} 
};

// Encryption function
char encrypt_char(char a) {
    for (int i = 0; i < 26; i++) {
        if (a == alpha[i][0])
            return alpha[i][1];
    }
    return a;  // Return unchanged if not found
}

// Decryption function
char decrypt_char(char a) {
    for (int i = 0; i < 26; i++) {
        if (a == alpha[i][1])
            return alpha[i][0];
    }
    return a;
}

int main() {
    char str[100], encrypted[100], decrypted[100];

    printf("Enter a string to encrypt: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // Remove newline character

    // Encryption
    for (int i = 0; str[i]; i++) {
        encrypted[i] = encrypt_char(str[i]);
    }
    encrypted[strlen(str)] = '\0';

    // Decryption
    for (int i = 0; encrypted[i]; i++) {
        decrypted[i] = decrypt_char(encrypted[i]);
    }
    decrypted[strlen(encrypted)] = '\0';

    printf("Original Text  : %s\n", str);
    printf("Encrypted Text : %s\n", encrypted);
    printf("Decrypted Text : %s\n", decrypted);

    return 0;
}
------------------------------------------------------------------------------------


#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char plaintext[100], key[100], ciphertext[100], decrypted[100];
    int i, len;

    printf("Enter plaintext (UPPERCASE, no spaces): ");
    scanf("%s", plaintext);
    printf("Enter key (SAME length as plaintext): ");
    scanf("%s", key);

    len = strlen(plaintext);

    // Encryption
    for (i = 0; i < len; i++) {
        ciphertext[i] = ((plaintext[i] - 'A' + key[i] - 'A') % 26) + 'A';
    }
    ciphertext[len] = '\0';

    printf("Encrypted Text: %s\n", ciphertext);

    // Decryption
    for (i = 0; i < len; i++) {
        decrypted[i] = ((ciphertext[i] - 'A' - (key[i] - 'A') + 26) % 26) + 'A';
    }
    decrypted[len] = '\0';

    printf("Decrypted Text: %s\n", decrypted);

    return 0;
}
----------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>

void vernamCipher(char *input, char *key, char *output) {
    for (int i = 0; input[i] != '\0'; i++) {
        output[i] = input[i] ^ key[i];  // XOR operation
    }
    output[strlen(input)] = '\0';  // Null terminate
}

int main() {
    char plaintext[100], key[100], ciphertext[100], decrypted[100];

    printf("Enter Plaintext: ");
    scanf("%s", plaintext);
    
    printf("Enter Key (same length as plaintext): ");
    scanf("%s", key);

    if (strlen(plaintext) != strlen(key)) {
        printf("Error: Key length must match plaintext length.\n");
        return 1;
    }

    // Encrypt
    vernamCipher(plaintext, key, ciphertext);
    printf("Ciphertext: ");
    for (int i = 0; i < strlen(ciphertext); i++) {
        printf("%02X ", (unsigned char)ciphertext[i]);  // Print as hex
    }
    printf("\n");

    // Decrypt
    vernamCipher(ciphertext, key, decrypted);
    printf("Decrypted Text: %s\n", decrypted);

    return 0;
}

---------------------------------------------------------------------------------------
#include <stdio.h>
#include <math.h>
RSA Algorithm in C
// Function to compute GCD
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function t	o compute (base^exp) % mod
long long power_mod(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {  // If exp is odd, multiply base
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    // Choose two prime numbers
    int p = 3, q = 7;
    int n = p * q;  // Compute n
    int totient = (p - 1) * (q - 1);  // Compute totient

    // Choose public key exponent e (must be coprime with totient)
    int e = 2;
    while (gcd(e, totient) != 1) {
        e++;
    }

    // Compute private key d (modular inverse of e)
    int d = 1;
    while ((d * e) % totient != 1) {
        d++;
    }

    // Message to encrypt
    int msg = 12;
    
    // Encryption: c = (msg^e) % n
    int c = power_mod(msg, e, n);

    // Decryption: m = (c^d) % n
    int m = power_mod(c, d, n);

    // Print results
    printf("Message: %d\n", msg);
    printf("p = %d, q = %d\n", p, q);
    printf("n = %d\n", n);
    printf("Totient = %d\n", totient);
    printf("Public Key (e) = %d\n", e);
    printf("Private Key (d) = %d\n", d);
    printf("Encrypted Data (Ciphertext) = %d\n", c);
    printf("Decrypted Message = %d\n", m);

    return 0;
}
-------------------------------------------------------------------------------------
 Diffie-Hellman Key Exchange in C
#include <stdio.h>

// Function to compute (base^exp) % mod efficiently
long long power_mod(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {  // If exp is odd, multiply base
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    long long P = 23, G = 9; // Public keys (Prime number & Primitive root)
    long long a = 4, b = 3;  // Private keys chosen by Alice & Bob

    printf("Public keys: P = %lld, G = %lld\n", P, G);
    printf("Alice's private key: %lld\n", a);
    printf("Bob's private key: %lld\n\n", b);

    // Compute public keys to exchange
    long long A = power_mod(G, a, P); // Alice's public key
    long long B = power_mod(G, b, P); // Bob's public key

    printf("Alice's public key (A) = %lld\n", A);
    printf("Bob's public key (B) = %lld\n\n", B);

    // Compute shared secret key
    long long secret_Alice = power_mod(B, a, P); // Secret key for Alice
    long long secret_Bob = power_mod(A, b, P);   // Secret key for Bob

    printf("Secret key for Alice: %lld\n", secret_Alice);
    printf("Secret key for Bob: %lld\n", secret_Bob);

    return 0;
}


--------------------------------------------------
Simple ElGamal Cryptosystem in C
#include <stdio.h>

// Function to compute (base^exp) % mod efficiently
long long power_mod(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {  // If exp is odd, multiply base
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    long long p = 23, g = 5; // Public prime and generator
    long long x = 6;  // Private key (chosen by receiver)
    
    // Compute public key
    long long y = power_mod(g, x, p);
    
    printf("Public key: (p = %lld, g = %lld, y = %lld)\n", p, g, y);
    printf("Private key (x): %lld\n\n", x);
    
    // Encryption
    long long msg = 10; // Original message
    long long k = 3;  // Random secret integer
    long long c1 = power_mod(g, k, p);
    long long c2 = (msg * power_mod(y, k, p)) % p;
    
    printf("Original Message: %lld\n", msg);
    printf("Encrypted values: (c1 = %lld, c2 = %lld)\n\n", c1, c2);
    
    // Decryption
    long long key = power_mod(c1, x, p);
    long long decrypted_msg = (c2 * power_mod(key, p - 2, p)) % p; // Modular inverse
    
    printf("Decrypted Message: %lld\n", decrypted_msg);

    return 0;
}


-------------------------------------------
------------------------------------------
sentence reversal
import java.io.*;  
import java.net.*;  

public class ReverseServer {  
    public static void main(String[] args) throws IOException {  
        ServerSocket server = new ServerSocket(1234);  
        System.out.println("Server running... Waiting for clients.");  

        while (true) {  
            Socket client = server.accept();  
            BufferedReader in = new BufferedReader(new InputStreamReader(client.getInputStream()));  
            PrintWriter out = new PrintWriter(client.getOutputStream(), true);  

            String input = in.readLine();  
            System.out.println("Client: " + input);  

            String reversed = new StringBuilder(input).reverse().toString();  
            out.println(reversed);  

            client.close();  
        }  
    }  
}

import java.io.*;  
import java.net.*;  

public class ReverseClient {  
    public static void main(String[] args) throws IOException {  
        Socket socket = new Socket("localhost", 1234);  
        BufferedReader userIn = new BufferedReader(new InputStreamReader(System.in));  
        PrintWriter out = new PrintWriter(socket.getOutputStream(), true);  
        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));  

        System.out.print("Enter sentence: ");  
        String sentence = userIn.readLine();  
        out.println(sentence);  

        System.out.println("Reversed: " + in.readLine());  
        socket.close();  
    }  
}
----------------------------------------------------------------

transfer file
import java.io.*;  
import java.net.*;  

public class FileServer {  
    public static void main(String[] args) throws IOException {  
        ServerSocket server = new ServerSocket(5000);  
        System.out.println("Waiting for connection...");  

        Socket client = server.accept();  
        System.out.println("Client connected.");  

        // Create a sample file dynamically
        String fileName = "sample.txt";
        FileWriter writer = new FileWriter(fileName);
        writer.write("This is a test file sent from server.");
        writer.close();

        // Send the file
        FileInputStream fileIn = new FileInputStream(fileName);  
        OutputStream out = client.getOutputStream();  
        byte[] buffer = new byte[4096];  
        int bytesRead;  
        while ((bytesRead = fileIn.read(buffer)) != -1) {  
            out.write(buffer, 0, bytesRead);  
        }  

        System.out.println("File sent.");  
        fileIn.close();  
        client.close();  
        server.close();  
    }  
}


import java.io.*;  
import java.net.*;  

public class FileClient {  
    public static void main(String[] args) throws IOException {  
        Socket socket = new Socket("127.0.0.1", 5000);  
        InputStream in = socket.getInputStream();  
        FileOutputStream fileOut = new FileOutputStream("received.txt");  

        byte[] buffer = new byte[4096];  
        int bytesRead;  
        while ((bytesRead = in.read(buffer)) != -1) {  
            fileOut.write(buffer, 0, bytesRead);  
        }  

        System.out.println("File received.");  
        fileOut.close();  
        socket.close();  
    }  
}


--------------------------------------------------------------
select
import java.io.*;
import java.net.*;
import java.nio.*;
import java.nio.channels.*;
import java.util.*;

public class TCPConcurrentServerUpper {
    public static void main(String[] args) throws IOException {
        Selector selector = Selector.open();
        ServerSocketChannel server = ServerSocketChannel.open();
        server.bind(new InetSocketAddress(5000));
        server.configureBlocking(false);
        server.register(selector, SelectionKey.OP_ACCEPT);
        System.out.println("Server running...");

        while (true) {
            selector.select();
            Iterator<SelectionKey> keys = selector.selectedKeys().iterator();
            while (keys.hasNext()) {
                SelectionKey key = keys.next();
                keys.remove();

                if (key.isAcceptable()) {
                    SocketChannel client = server.accept();
                    client.configureBlocking(false);
                    client.register(selector, SelectionKey.OP_READ);
                } 
                else if (key.isReadable()) {
                    SocketChannel client = (SocketChannel) key.channel();
                    ByteBuffer buffer = ByteBuffer.allocate(1024);
                    if (client.read(buffer) == -1) { client.close(); continue; }
                    buffer.flip();
                    String msg = new String(buffer.array(), 0, buffer.limit()).toUpperCase();
                    client.write(ByteBuffer.wrap(msg.getBytes()));
                }
            }
        }
    }
}


import java.io.*;
import java.net.*;
import java.nio.*;
import java.nio.channels.*;
import java.util.Scanner;

public class TCPClientUpper {
    public static void main(String[] args) throws IOException {
        SocketChannel client = SocketChannel.open(new InetSocketAddress("localhost", 5000));
        ByteBuffer buffer = ByteBuffer.allocate(1024);
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.print("Enter text (or 'exit' to quit): ");
            String msg = scanner.nextLine();
            if (msg.equalsIgnoreCase("exit")) break;

            buffer.clear();
            buffer.put(msg.getBytes());
            buffer.flip();
            client.write(buffer);

            buffer.clear();
            client.read(buffer);
            buffer.flip();
            System.out.println("Server: " + new String(buffer.array(), 0, buffer.limit()));
        }
        
        client.close();
        scanner.close();
    }
}

----------------------------------------------------------------------------------------
poll
import java.io.*;
import java.net.*;
import java.nio.*;
import java.nio.channels.*;
import java.util.*;

public class TCPConcurrentPollServer {
    public static void main(String[] args) throws IOException {
        ServerSocketChannel server = ServerSocketChannel.open();
        server.bind(new InetSocketAddress(12345));
        server.configureBlocking(false);
        
        Selector selector = Selector.open();
        server.register(selector, SelectionKey.OP_ACCEPT);
        System.out.println("Server running...");

        while (true) {
            selector.select();
            Iterator<SelectionKey> keys = selector.selectedKeys().iterator();
            while (keys.hasNext()) {
                SelectionKey key = keys.next();
                keys.remove();

                if (key.isAcceptable()) {
                    SocketChannel client = server.accept();
                    client.configureBlocking(false);
                    client.register(selector, SelectionKey.OP_READ);
                    System.out.println("Client connected: " + client.getRemoteAddress());
                } 
                else if (key.isReadable()) {
                    SocketChannel client = (SocketChannel) key.channel();
                    ByteBuffer buffer = ByteBuffer.allocate(1024);
                    int bytesRead = client.read(buffer);
                    if (bytesRead == -1) {
                        client.close();
                        System.out.println("Client disconnected");
                    } else {
                        buffer.flip();
                        client.write(buffer); // Echoing back
                        buffer.clear();
                    }
                }
            }
        }
    }
}


import java.io.*;
import java.net.*;
import java.nio.*;
import java.nio.channels.*;
import java.util.Scanner;

public class TCPClientPoll {
    public static void main(String[] args) throws IOException {
        SocketChannel client = SocketChannel.open(new InetSocketAddress("localhost", 12345));
        ByteBuffer buffer = ByteBuffer.allocate(1024);
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.print("Enter message (or 'exit' to quit): ");
            String msg = scanner.nextLine();
            if (msg.equalsIgnoreCase("exit")) break;

            buffer.clear();
            buffer.put(msg.getBytes());
            buffer.flip();
            client.write(buffer);

            buffer.clear();
            client.read(buffer);
            buffer.flip();
            System.out.println("Echo from server: " + new String(buffer.array(), 0, buffer.limit()));
        }
        
        client.close();
        scanner.close();
    }
}
