#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// helper-function for wrong inputs
void usage(int length) {
    fprintf(stderr, "You typed in %d symbols.\nType in at least five symbols!\n", length);
    exit(EXIT_FAILURE);
}

void using_getc(char buffer[], int n, int length, int min_length){
    while(1) {
        char tmp;
        int ix = 0;

        printf("Type in a sequence of symbols: ");
        // reading symbols and writing them to buffer-array
        while((tmp = getc(stdin)) != '\n' && tmp != EOF) {
            buffer[ix++] = (char) tmp;
        }

        // nullterminator for indicating end of string-sequence
        buffer[ix] = '\0';

        // check length
        length = strlen(buffer);
        if(length < min_length) {
            usage(length);
        }

        // writing to stdout
        printf("Your input was: ");
        ix = 0;
        while (buffer[ix] != '\0') {
            putc(buffer[ix++], stdout);
        }
        printf("\n");
    }
}


void using_scanf(char buffer[], int n, int length, int min_length){

}

void using_fread(char buffer[], int n, int length, int min_length){

}

void using_fgets(char buffer[], int n, int length, int min_length){
    while(1) {
        printf("Type in a sequence of symbols: ");
        fgets(buffer, n, stdin);
        length = strlen(buffer) - 1;
        if (length < min_length) {
            usage(length);
        }
        fprintf(stdout, "Your input was: ");
        puts(buffer);
        }
}


int main(void) {
    
    char buffer[32]; 
    int n = sizeof(buffer) / sizeof(buffer[0]);
    int length;
    int min_length = 5;

    printf("Choose which I/O functions you want to test:\n"
        "1: getc() & putc()\n"
        "2: fgets() & puts()\n"
        "3: scanf() & printf()\n"
        "4: fread() & fwrite()\n"
        "Enter number: ");

    int num;
    if (scanf("%d", &num) != 1) {
        fprintf(stderr, "Invalid input!\n");
        exit(EXIT_FAILURE);
    }

    // empty buffer
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    // switch statement for determining which functions to be used
    switch (num)
    {
    case 1:
        using_getc(buffer, n, length, min_length);
        break;
    case 2:
        using_fgets(buffer, n, length, min_length);
        break;
    case 3:
        using_scanf(buffer, n, length, min_length);
        break;
    case 4:
        using_fread(buffer, n, length, min_length);
        break;
    
    default:
        fprintf(stderr, "You choosed number %d which isn't within the scope!\n", num);
        exit(EXIT_FAILURE);
    }
    
    return 0;
}

