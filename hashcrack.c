#include <stdio.h>
#include <string.h>
//#include <sys/types.h>
#include <openssl/sha.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	
	unsigned char* cipher = "8104ba1dc0409b259f487ed07db477c38f205a30";//"f6677d53fee627ac44f18faaff0821954d8a1b6a";
	char attempt[] = "0000000000";
	unsigned char hash[SHA_DIGEST_LENGTH];
    unsigned char* attempt2 = (unsigned char*)attempt;

    int a, b, c, d, e, f, g, h, i, j;
    for(a = '0'; a < 'z'; a++) {
    	attempt[0] = a;
    	for(b = '0'; b < 'z'; b++) {
    		attempt[1] = b;
    		for(c = '0'; c < 'z'; c++) {
    			attempt[2] = c;
    			for(d = '0'; d < 'z'; d++) {
    				attempt[3] = d;
    				for(e = '0'; e < 'z'; e++) {
    					attempt[4] = e;
    					for(f = '0'; f < 'z'; f++) {
    						attempt[5] = f;
    						for(g = '0'; g < 'z'; g++) {
    							attempt[6] = g;
    							for(h = '0'; h < 'z'; h++) {
    								attempt[7] = h;
    								for(i = '0'; i < 'z'; i++) {
    									attempt[8] = i;
    									for(j = '0'; j < 'z'; j++) {
    										attempt[9] = j;
    										
    										SHA1(attempt2, 10, hash);
    										if(!strcmp(cipher, (char*)hash))
    											break;
    										char temp[2];
    										char finalHash[41];
    										memset(finalHash, 0, 41);
    										printf("%s\n", finalHash);

    										for(int k = 0; k < SHA_DIGEST_LENGTH; k++) {
    											sprintf(temp, "%02x", hash[k]);
    											strcat(finalHash, temp);
    										}
    										printf("\n");
    										finalHash[40] = '\0';

											printf("attempt: %s\n", attempt);
    										printf("attempt2: %s\n", attempt2);
    										printf("cipher: %s\n", cipher);
    										printf("hash: %s\n", hash);
    										printf("finalHash: %s\n", finalHash);
    										printf("strlen(cipher): %d\n", (int)strlen(cipher));
    										printf("memcmp: %d\n", memcmp(cipher, finalHash, 40));

    										for (i = 0; i < SHA_DIGEST_LENGTH; i++)
        										printf("%02x", hash[i]);
    										printf("\n");

    										if(memcmp(cipher, finalHash, 40) == 0)
    											printf("We did it Reddit!\n");

    										read(1, attempt, 10);
    										
    									} 
    								}
    							}
    						}
    					}
    				}
    			}
    		}
    	}
    }

    
    printf("Plaintext: %s\n", attempt);

    return 0;

}
