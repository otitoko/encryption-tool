#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LIMIT 1024
int operation;
int shift;
char *unencryptedPhrase;

void configureCipher(){
	do{
		printf("\n\nWould you like to encrypt or decrypt?\n");
		printf("1. Encrypt\n");
		printf("2. Decrypt\n");
		printf("3. Exit\n");
	
		scanf("%d",&operation);

	}
	while(operation > 3 || operation < 1);



	if(operation == 3){
		exit(0);
	}

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

void encryption(char *unencryptedPhrase, int shift){
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

int main(){
	while(1){
		configureCipher();
		if(operation == 1){
			encryption(unencryptedPhrase,shift);
			free(unencryptedPhrase);
		}
		else if(operation == 2){
			decryption(unencryptedPhrase,shift);
			free(unencryptedPhrase);
		}
	}
	return 0;
}
