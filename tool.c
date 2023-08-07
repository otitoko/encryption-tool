#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LIMIT 1024
int operation;
int shift;

void configureCipher(){
	printf("Would you like to encrypt or decrypt?\n");
	printf("1. Encrypt\n");
	printf("2. Decrypt\n");

	scanf("%d",&operation);

	printf("How much shift?\n");
	scanf("%d",&shift);
}

int encryption(int shift){
	printf("Enter the phrase you wish to encrypt: \n");
	char unencryptedPhrase[MAX_LIMIT]
	fgets(unencryptedPhrase, MAX_LIMIT, stdin);
	unencryptedPhrase[strcspn(unencryptedPhrase, "\n")] = 0;
}

int main(){
	configureCipher();
}
