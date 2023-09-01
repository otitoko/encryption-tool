#include "../wrapping-algorithm/wrapping-algorithm.h"


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

void ext_caesar_decryption(char *unencryptedPhrase, int shift){
	for(int i = 0; i < strlen(unencryptedPhrase); i++){
		int ascii = unencryptedPhrase[i];
		ascii-=shift;
		unencryptedPhrase[i] = ascii;
	}
	printf("The decrypted phrase is = %s\n", unencryptedPhrase);
}


