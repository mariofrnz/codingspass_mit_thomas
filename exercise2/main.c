#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// macro for defining buffer size
#define BUFFER_SIZE 32

// function declarations
void task_selector();
void usage();
void task1();
void task2();
void task2_logic();
void using_getc();
void using_fgets();
void using_scanf();
void using_fread();

// TASK 1

// helper-function for wrong inputs
void usage(size_t length) {
    fprintf(stderr, "You typed in %d symbols.\nType in at least five symbols!\n", length);
    exit(EXIT_FAILURE);
}

void using_getc(char buffer[], int n, size_t length, int min_length){
    while(1) {
        char tmp;
        int ix = 0;

        printf("Type in a sequence of symbols: ");

        // reading symbols and writing them to buffer-array
        while((tmp = getc(stdin)) != '\n' && tmp != EOF) {
            buffer[ix++] = (char) tmp;
        }

        // manually adding nullterminator for indicating end of string-sequence
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

void using_fgets(char buffer[], int n, size_t length, int min_length){
    while(1) {
        printf("Type in a sequence of symbols: ");

        // since fgets does already appends '\0' at the end of a sequence, we do not have
        // to manually append it at the end
        fgets(buffer, n, stdin);

        // check length
        length = strlen(buffer) - 1;
        if (length < min_length) {
            usage(length);
        }

        // output - puts() already adds a new line (\n), so we dont have to worry about it
        printf("Your input was: ");
        puts(buffer);
        }
}

void using_scanf(char buffer[], int n, size_t length, int min_length){
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

void using_fread(char buffer[], int n, size_t length, int min_length) {
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


void task1() {
    char buffer[BUFFER_SIZE];
    const int n = sizeof(buffer) / sizeof(buffer[0]);
    size_t length = 0;
    int min_length = 5;

    printf("************ task 1 ************\n"
        "Choose which I/O functions you want to use:\n"
        "[1] getc() & putc()\n"
        "[2] fgets() & puts()\n"
        "[3] scanf() & printf()\n"
        "[4] fread() & fwrite()\n"
        "[0] back to task selection\n"
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
    switch (num) {
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

void task2() {
    int num;

    printf("************ task 2 ************\n"
        "[1]: begin task2\n"
        "[0]: back to task-selection\n"
        "Enter number: ");
    
    if(scanf("%d", &num) != 1) {
        fprintf(stderr, "Invalid input!\n");
        exit(EXIT_FAILURE);
    }

    switch (num) {
        case 1:
            task2_logic();
            break;
        case 0:
            system("clear");
            task_selector();
            break;
        default:
            fprintf(stderr, "You choosed number %d which isn't within the scope!\n", num);
            exit(EXIT_FAILURE);
    }

}

void task2_logic() {
    int n = 0;
    int year, mileage, height;
    float weight;
    char brand[16], model[16], name[12];
    char license_type;

    system("clear");
    printf("Type in the data of your car.\n"
        "The order must be: brand, model, year of construction, mileage in km - seperated by a blank\n"
        "example: Volkswagen Golf 2015 124000\n"
        "Your input: ");
        
    n = scanf("%16s %16s %d %d", &brand[0], &model[0], &year, &mileage);

    if(n != 4) {
        printf("your input was wrong. Try it again!\n");
        exit(EXIT_FAILURE);
    }

    printf("Now type in your first name, the type of driving license you have (A or B), your height in cm and your weigth in kg\n"
        "example: Rainer B 190 230.5\n"
        "Your input: ");

    
    
    n = scanf("%11s %c %d %f", &name[0], &license_type, &height, &weight);

    if (n != 4) {
        printf("Your input was invalid. Try it again!\n");
        exit(EXIT_FAILURE);
    }
    float bmi = (weight / (height / 10.0));
    bmi *= bmi;
    system("clear");
    printf("You are %s, you own a driving license of type: %c, your BMI is: %f and you are driving the following car:\n"
        "Brand: %s, Model: %s, Year of construction: %d, Mileage: %d\n", name, license_type, bmi, brand, model, year, mileage);
}

void task_selector() {
    printf("**** task-selection **** \n"
        "[1] task1\n"
        "[2] task2\n"
        "[0] kill\n"
        "Enter number: ");

    int num;
    if(scanf("%d", &num) != 1) {
        fprintf(stderr, "Invalid input!\n");
        exit(EXIT_FAILURE);
    } 

    switch (num) {
        case 0: 
            system("clear");
            exit(0);
        case 1:
            system("clear");
            task1();
            break;
        case 2:
            system("clear");
            task2();
            break;
        default:
            fprintf(stderr, "You choosed number %d which isn't within the scope!\n", num);
            exit(EXIT_FAILURE);
    }
    
}

int main(void) {
    
    task_selector();
    
    return 0;
}

