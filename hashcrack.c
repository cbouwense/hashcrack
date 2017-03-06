#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int threadID = 0;

void checkHash(int* t) {
    printf("%d\n", *t);
    free(t);
}

int main() {
	
    pthread_t threads[100];

	unsigned char* cipher = "f6677d53fee627ac44f18faaff0821954d8a1b6a";//"f6677d53fee627ac44f18faaff0821954d8a1b6a";
	unsigned char attempt[] = "0000000000"; // dummy string to allocate space
	unsigned char hash[SHA_DIGEST_LENGTH]; // string that the hashed attempt will be dumped into

    // Create Threads

    for (int i = 0; i < 100; i++) {
        int *num = malloc(sizeof(int));
        *num = i;
        pthread_create(&threads[i], NULL, (void *)checkHash, num);
    }

    for (int i = 0; i < 100; ++i) {
       pthread_join(threads[i], NULL);
    }

    return 0;

}
