#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TASK 1

// macro for defining buffer size
#define BUFFER_SIZE 32


void task_selector();
void usage();
void task1();
void task2();





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
        printf("\n\n");
    }
}

void using_fgets(char buffer[], int n, int length, int min_length){
    while(1) {
        printf("Type in a sequence of symbols: ");
        fgets(buffer, n, stdin);
        length = strlen(buffer) - 1;
        if (length < min_length) {
            usage(length);
        }
        printf("Your input was: ");
        puts(buffer);
        }
}

void using_scanf(char buffer[], int n, int length, int min_length){
    while(1) {
        printf("Type in a sequence of symbols: ");
        scanf("%s", buffer);
        length = strlen(buffer);
        if (length < min_length) {
            usage(length);
        }
        printf("Your input was: %s\n\n", buffer);
    }
}

void using_fread(char buffer[], int n, int length, int min_length) {
    char line[BUFFER_SIZE];
    char c;
    while (1) {
        int bytes_read;
        while((fread(&c, 1, 1, stdin)) == 1) {
            if(c == '\n') {
                if(length >= 5) {
                    char output[] = "Your input was: ";
                    fwrite(output, 1, strlen(output), stdout);
                    fwrite(line, 1, length, stdout);
                    fwrite("\n\n", 1, 1, stdout);
                } else {
                    usage(length);
                }
                length = 0;
            } else {
                if(length < BUFFER_SIZE - 1) {
                    line[length++] = c;
                }
            }
        
        }
    }
}

void task_selector() {
    printf("Choose: \n"
        "[1] task1\n"
        "[2] task2\n"
        "[0] kill\n"
        "Enter number: ");

    int num;
    if(scanf("%d", &num) != 1) {
        fprintf(stderr, "Invalid input!\n");
        exit(EXIT_FAILURE);
    } 

    switch (num)
    {
    case 0: 
        exit(0);
    case 1:
        system("clear");
        task1();
        break;
    case 2:
        //task2();
        break;
    default:
        fprintf(stderr, "You choosed number %d which isn't within the scope!\n", num);
        exit(EXIT_FAILURE);
    }
    
}


void task1() {
    char buffer[BUFFER_SIZE]; 
    int n = sizeof(buffer) / sizeof(buffer[0]);
    int length = 0;
    int min_length = 5;

    printf("Choose which I/O functions you want to use:\n"
        "[1] getc() & putc()\n"
        "[2] fgets() & puts()\n"
        "[3] scanf() & printf()\n"
        "[4] fread() & fwrite()\n"
        "[0] go back to task selection\n"
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
    case 0:
        system("clear");
        task_selector();
    
    default:
        fprintf(stderr, "You choosed number %d which isn't within the scope!\n", num);
        exit(EXIT_FAILURE);
    }
}




int main(void) {
    
    task_selector();
    
    return 0;
}

