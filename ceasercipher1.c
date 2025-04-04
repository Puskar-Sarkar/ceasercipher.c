#include <stdio.h>
#include <string.h>
void encrypt(char message[], int key) {
 for (int i = 0; message[i] != '\0'; ++i) {
 char ch = message[i];
 if (ch >= 'A' && ch <= 'Z') {
 ch = (ch - 'A' + key) % 26 + 'A';
 }
 else if (ch >= 'a' && ch <= 'z') {
 ch = (ch - 'a' + key) % 26 + 'a';
 }
 message[i] = ch;
 }
}
void decrypt(char message[], int key) {
 for (int i = 0; message[i] != '\0'; ++i) {
 char ch = message[i];
 if (ch >= 'A' && ch <= 'Z') {
 ch = (ch - 'A' - key + 26) % 26 + 'A';
 }
 else if (ch >= 'a' && ch <= 'z') {
 ch = (ch - 'a' - key + 26) % 26 + 'a';
 }
 message[i] = ch;
 }
}
int main() {
 char message[100];
 int key;
 printf("Enter a message to encrypt: ");
 fgets(message, sizeof(message), stdin);
 message[strcspn(message, "\n")] = 0; //Remove newline character
  printf("Enter key: ");
 scanf("%d", &key);
 encrypt(message, key);
 printf("Encrypted message: %s\n", message);
 decrypt(message, key);
 printf("Decrypted message: %s\n", message);
 return 0;
}