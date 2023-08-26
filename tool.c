#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LIMIT 1024

int operation;
int encryption_type;
int shift;
char *unencryptedPhrase;

void shutdown(int exit_number){
	if (exit_number == 3){
		exit(0);
	}
}

void configureCipher(){
	do{
		printf("\n\nWould you like to encrypt or decrypt?\n");
		printf("1. Encrypt\n");
		printf("2. Decrypt\n");
		printf("3. Exit\n");
	
		scanf("%d",&operation);

	}
	while(operation > 3 || operation < 1);
	
	shutdown(operation);
	


	do{
		printf("Which type algorithm would you like to use?\n");
		printf("1. Caesar Cipher\n");
		printf("2. Extended Caesar Cipher\n");
		printf("3. Exit\n");

		scanf("%d", &encryption_type);
	}
	while(encryption_type > 3 || encryption_type < 1);

	shutdown(encryption_type);

	printf("How much shift?\n");
	scanf("%d",&shift);

	unencryptedPhrase = (char *)malloc(MAX_LIMIT * sizeof(char));
	if (unencryptedPhrase == NULL){
		printf("Mem Alloc failed.\n");
		exit(1);
	}

	
	printf("Enter the phrase you wish to encrypt/decrypt: \n");
	getchar();
	fgets(unencryptedPhrase, MAX_LIMIT, stdin);
	unencryptedPhrase[strcspn(unencryptedPhrase, "\n")] = 0;
}
void caesar_encryption(char *unencryptedPhrase, int shift){
	for(int i = 0;i < strlen(unencryptedPhrase);i++){
		int ascii = unencryptedPhrase[i];
		//make into algorithm, maybe recursive
		if(ascii + shift >= 122){
			int temp = 122 - ascii;
			ascii += temp;
			shift-=temp;
			ascii+=shift;
		}
		else{
			ascii+=shift;
		}
		unencryptedPhrase[i] = ascii;
	}
	printf("The encrypted phrase is = %s\n", unencryptedPhrase);


}

void caesar_decryption(char *unencryptedPhrase, int shift){
	for(int i = 0;i < strlen(unencryptedPhrase);i++){
		int ascii = unencryptedPhrase[i];
		if(ascii == 97){
			ascii = 122;
		}
		else{
			ascii-=shift;
		}
		unencryptedPhrase[i] = ascii;
	}
	printf("The decrypted phrase is = %s\n", unencryptedPhrase);

}

void ext_caesar_encryption(char *unencryptedPhrase, int shift){
	//how to do this??
	//at a char level: loop through each char and put it forward by shift amount of spaces
	//if too far forward where it is no longer a character, loop it back.
	for(int i = 0;i < strlen(unencryptedPhrase);i++){
		int ascii = unencryptedPhrase[i];
		ascii+=shift;
		unencryptedPhrase[i] = ascii;
	}
	printf("The encrypted phrase is = %s\n", unencryptedPhrase);
}

void decryption(char *unencryptedPhrase, int shift){
	for(int i = 0; i < strlen(unencryptedPhrase); i++){
		int ascii = unencryptedPhrase[i];
		ascii-=shift;
		unencryptedPhrase[i] = ascii;
	}
	printf("The decrypted phrase is = %s\n", unencryptedPhrase);
}
/**
void operation_decider(operation, encryption_type){
	if(operation == 1){
		if(encryption_type == 1){
			ext_caesar_encryption(unencryptedPhrase,shift);
		}
	}
}
**/
int main(){
	while(1){
		configureCipher();
		caesar_encryption(unencryptedPhrase,shift);
	
		caesar_decryption(unencryptedPhrase, shift);
		}
	return 0;
}
