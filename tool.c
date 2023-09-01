#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "encryption-methods/caesar-method.h"
#include "encryption-methods/ext-caesar-method.h"
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

		scanf("%d", &operation);
	
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



void operation_decider(int operation, int encryption_type){
	if(operation == 1){
		if(encryption_type == 1){
			caesar_encryption(unencryptedPhrase,shift);
		}
		else if(encryption_type == 2){
			ext_caesar_encryption(unencryptedPhrase,shift);
		}
	}
	else if(operation == 2){
		if (encryption_type == 1){
			caesar_decryption(unencryptedPhrase, shift);
		}
		else if(encryption_type == 2){
			ext_caesar_decryption(unencryptedPhrase,shift);}
	}
}

int main(){
	while(1){
		configureCipher();
		operation_decider(operation, encryption_type);}
	return 0;
}
