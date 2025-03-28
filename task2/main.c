#include <stdio.h>
#include <stdlib.h>


void usage() {
    fprintf(stderr, "type in five symbols max.!\n");
    exit(EXIT_FAILURE);
}


int main(void) {
    
    char buffer[5]; 
    char tmp = -1;
    int n = sizeof(buffer) / sizeof(buffer[0]);
    int free = sizeof(buffer) / sizeof(buffer[0]);

    printf("tipp was rein lmao: ");
    while (tmp = getc(stdin) != EOF || free == 0) {
        if (free == 0) {
            usage();    // fehler
        }
        buffer[n - free] = tmp;
        free--;
    }

    while (free != n){
        printf("%c ", buffer[free]);
        free++;
    }

    exit(EXIT_SUCCESS);

    return 0;
}