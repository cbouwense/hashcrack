#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int threadID = 0;

void checkHash(int* t) {

    unsigned char* cipher = "f6677d53fee627ac44f18faaff0821954d8a1b6a";//"f6677d53fee627ac44f18faaff0821954d8a1b6a";
    unsigned char attempt[] = "000000000"; // dummy string to allocate space
    unsigned char hash[SHA_DIGEST_LENGTH]; // string that the hashed attempt will be dumped into

    attempt[0] = *t;
    // Counters
    char a, b, c, d, e, f, g, h;

    /* I don't check if the characters are alphanumeric because that would
     * most likely just make the runtime less efficient in the long run
     */
    for (a = '0'; a <= 'z'; a++) {
        attempt[1] = a;
        for (b = '0'; b <= 'z'; b++) {
            attempt[2] = b;
            for (c = '0'; c <= 'z'; c++) {
                attempt[3] = c;
                for (d = '0'; d <= 'z'; d++) {
                    attempt[4] = d;
                    for (e = '0'; e <= 'z'; e++) {
                        attempt[5] = e;
                        for (f = '0'; f <= 'z'; f++) {
                            attempt[6] = f;
                            for (g = '0'; g <= 'z'; g++) {
                                attempt[7] = g;
                                for (h = '0'; h <= 'z'; h++) {
                                    attempt[8] = h;

                                    SHA1(attempt, 9, hash);

                                    char temp[2]; // Buffer to hold translated hex chunks
                                    char finalHash[41]; // Fully translated output

                                    // Clear finalHash of any garbage data
                                    memset(finalHash, 0, 41);

                                    /* This was the only way I could find to translate 
                                     * the hex output from SHA into readable ASCII.
                                     * I am almost positive this can be done better.
                                     */
                                    for(int k = 0; k < SHA_DIGEST_LENGTH; k++) {
                                        // Store the interpreted hash into temp
                                        sprintf(temp, "%02x", hash[k]);
                                        // Concat that onto the final hash output
                                        strcat(finalHash, temp);
                                    }
                                    // Null terminate the final hash
                                    finalHash[40] = '\0';

                                    // Compare the final hash to the actual cipher
                                    if(memcmp(cipher, finalHash, 40) == 0) {
                                        printf("Thread %c is the Winrar!\nPlaintext: %s\n", *t, attempt);
                                        exit(1);
                                    }
                                }
                            }
                        }
                    }
                }
            }         
        }
    }

    free(t);
}

int main() {
	
    // Make a thread for each possible character in the most significant slot
    pthread_t threads[62];

    // Create Threads
    int j = 0; // index of thread in threads array
    for (int i = '0'; i <= 'z'; i++) {
        if (i == ':') // if we are one over the ASCII value for '9'
            i = 'A';
        else if (i == '[')
            i = 'a';
        int *first = malloc(sizeof(int));
        *first = i;
        pthread_create(&threads[j], NULL, (void *)checkHash, first);
        j++;
    }

    // Wait for all the threads to finish execution
    for (int i = 0; i < 62; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;

}
/*

    */