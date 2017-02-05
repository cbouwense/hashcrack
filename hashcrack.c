#include <stdio.h>
#include <string.h>
//#include <sys/types.h>
#include <openssl/sha.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	
	unsigned char* cipher = "f6677d53fee627ac44f18faaff0821954d8a1b6a";//"f6677d53fee627ac44f18faaff0821954d8a1b6a";
	char attempt[] = "0000000000";
	unsigned char hash[SHA_DIGEST_LENGTH];
    unsigned char* attempt2 = (unsigned char*)attempt;

    int a, b, c, d, e, f, g, h, i, j;
    for(a = '0'; a < 'z'; a++) {
    	attempt[0] = a;
    	if (a == '9')
    		a = 'A' - 1;
    	if (a == 'Z')
    		a = 'a' - 1;
    	for(b = '0'; b < 'z'; b++) {
    		attempt[1] = b;
    		if (b == '9')
    			b = 'A' - 1;
    		if (b == 'Z')
    			b = 'a' - 1;
    		for(c = '0'; c < 'z'; c++) {
    			attempt[2] = c;
    			if (c == '9')
		    		c = 'A' - 1;
		    	if (c == 'Z')
		    		c = 'a' - 1;
    			for(d = '0'; d < 'z'; d++) {
    				attempt[3] = d;
    				if (d == '9')
			    		d = 'A' - 1;
			    	if (d == 'Z')
			    		d = 'a' - 1;
    				for(e = '0'; e < 'z'; e++) {
    					attempt[4] = e;
    					if (e == '9')
				    		e = 'A' - 1;
				    	if (e == 'Z')
				    		e = 'a' - 1;
    					for(f = '0'; f < 'z'; f++) {
    						attempt[5] = f;
    						if (f == '9')
					    		f = 'A' - 1;
					    	if (f == 'Z')
					    		f = 'a' - 1;
    						for(g = '0'; g < 'z'; g++) {
    							attempt[6] = g;
    							if (g == '9')
						    		g = 'A' - 1;
						    	if (g == 'Z')
						    		g = 'a' - 1;
    							for(h = '0'; h < 'z'; h++) {
    								attempt[7] = h;
    								if (h == '9')
							    		h = 'A' - 1;
							    	if (h == 'Z')
							    		h = 'a' - 1;
    								for(i = '0'; i < 'z'; i++) {
    									attempt[8] = i;
    									if (i == '9')
								    		i = 'A' - 1;
								    	if (i == 'Z')
								    		i = 'a' - 1;
    									for(j = '0'; j < 'z'; j++) {
    										attempt[9] = j;
    										if (j == '9')
									    		j = 'A' - 1;
									    	if (j == 'Z')
									    		j = 'a' - 1;
    										
    										SHA1(attempt2, 10, hash);

    										// MAKE THIS EFFICIENT
    										char temp[2];
    										char finalHash[41];
    										memset(finalHash, 0, 41);

    										for(int k = 0; k < SHA_DIGEST_LENGTH; k++) {
    											sprintf(temp, "%02x", hash[k]);
    											strcat(finalHash, temp);
    										}
    										printf("\n");
    										finalHash[40] = '\0';

    										printf("%s\n", attempt);

    										if(memcmp(cipher, finalHash, 40) == 0)
    											// yeah I know, shut the fuck up
    											goto done;    										
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
   
    done: printf("Plaintext: %s\n", attempt);

    return 0;

}
