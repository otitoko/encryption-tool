#include "../wrapping-algorithm/wrapping-algorithm.h"



void caesar_encryption(char *unencryptedPhrase, int shift){
	for(int i = 0;i < strlen(unencryptedPhrase);i++){
		int ascii = unencryptedPhrase[i];
		//make into algorithm, maybe recursive
		wrap_algorithm(&ascii, shift,97,122);	
		unencryptedPhrase[i] = ascii;
	}
	printf("The encrypted phrase is = %s\n", unencryptedPhrase);


}

void caesar_decryption(char *unencryptedPhrase, int shift){
	for(int i = 0;i < strlen(unencryptedPhrase);i++){
		int ascii = unencryptedPhrase[i];
		wrap_algorithm_reverse(&ascii, shift,97,122);
		unencryptedPhrase[i] = ascii;
	}
	printf("The decrypted phrase is = %s\n", unencryptedPhrase);

}

