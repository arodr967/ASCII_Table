/*
    File name: ASCIITable.c
    @author Alicia Rodriguez
    Description: Program which will print the ASCII table, formatted based on
                 user input which only accepts columns from 1 - 8. The ASCII 
                 table will consist of Dec, Char, Oct, and Hex values.
 */
#include <stdio.h>

/* Prototype: Function which will be called */
void printTable(int column, int row);
void printControlCharacters(int decimalNumbers[], int character);

/* Constant */
#define TABLE_SIZE 128

/* Main function which will ask for user input and determine when to create the ASCII table. 
   If user input value is valid then create table, otherwise, ask again.
   Main function default return type is int */
int main()
{
    printf("\nWelcome!\nIn this program you will be creating your own ASCII table.");
    
    int column, row;
    
    printf("\nPlease enter a number from 1 - 8 for the columns your ASCII table will include: ");
    
    /* User must only input a number from 1 through 8; The while loop
       gets a character, assigns it to column, and then tests whether the
       character meets the condition */
    while((column = getchar()) != EOF)
    {
        /* Test if number was assigned to column */
        printf("You've inputted number: ");
        putchar(column);
        
        column = column - 48; /* Since getchar() is getting a range of ASCII code
                                 numbers from 48 - 57, by subtracting the input by
                                 48, we can get the actual decimal value */
        
        if(column >= 1 && column <= 8)
        {
            /* An extra row must be added for column values of
               3, 5, 6, and 7 because it will not hold up when TABLE_SIZE is
               divided */
            row = (TABLE_SIZE/column) + 1;
            printTable(column, row);
            
            break; /* End of file */
            
        } else {
            printf("\nPlease try again \nEnter a number of columns from 1 - 8: ");
            column = getchar(); /* Read the character again */
        }
    } 
}

/* PrintTable function which will print the formatted table according to user input. 
   Displays control characters. */
void printTable(int column, int row)
{
    printf("\n\nArray of decimal numbers from 0 - 127: \n");
    int character = 0;
    
    int decimalNumbers[TABLE_SIZE];   /* Array which will store numbers 0 - 127 */
    
    /* Fill array with numbers from 0 - 127 */
    for(int fill = 0; fill < TABLE_SIZE; fill++)
    {
        decimalNumbers[fill] = fill;
        printf("%d ", decimalNumbers[fill]);  /* Print array of numbers from 0 - 127 to
                                                 make sure all of the numbers are in the array */
    }
    printf("\n");
    
    
    printf("\nYour ASCII table \n\n");
    
    printf("Number of columns: %d\n", column);
    printf("Number of rows: %d\n", row);
    
    printf("\n");
    
    /* Display a header for the table */
    for (int k = 0; k < column; k ++)
    {
        printf("|%3s %5s  %5s  %4s ", "Dec", "Char ", "Oct  ", "Hex ");
    }
    
    printf("\n");

    /* Start creating the table from rows and columns */
    for (int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            /* Check for control characters */
            if((character >= 0 && character <= 32) || character == 127)
            {
                /* Call function to begin displaying the special control characters */
                printControlCharacters(decimalNumbers, character);
            }
            else if (character > 32 && character < 127)
            {
                printf("|%3d:%5c :%05o :0x%2x ", decimalNumbers[character], character, character, character);
            }
            else
            {
                printf("%s", " ");   //Display nothing for the other characters
            }
            character++;  //Go to the next character values
        }
        printf("\n");
    }
}

/* Print Control Characters function, which will fill the table with the special
   control characters that are needed for numbers 0 - 32 and 127 */
void printControlCharacters(int decimalNumbers[], int character)
{
    switch (character) {
        case 0:
            printf("|%3d:<NUL> :%05o :0x%02x ", decimalNumbers[character], character, character);
            break;
        case 1:
            printf("|%3d:<SOH> :%05o :0x%02x ", decimalNumbers[character], character, character);
            break;
        case 2:
            printf("|%3d:<STX> :%05o :0x%02x ", decimalNumbers[character], character, character);
            break;
        case 3:
            printf("|%3d:<ETX> :%05o :0x%02x ", decimalNumbers[character], character, character);
            break;
        case 4:
            printf("|%3d:<EOT> :%05o :0x%02x ", decimalNumbers[character], character, character);
            break;
        case 5:
            printf("|%3d:<ENQ> :%05o :0x%02x ", decimalNumbers[character], character, character);
            break;
        case 6:
            printf("|%3d:<ACK> :%05o :0x%02x ", decimalNumbers[character], character, character);
            break;
        case 7:
            printf("|%3d:<BEL> :%05o :0x%02x ", decimalNumbers[character], character, character);
            break;
        case 8:
            printf("|%3d:<0BS> :%05o :0x%02x ", decimalNumbers[character], character, character);
            break;
        case 9:
            printf("|%3d:<0HT> :%05o :0x%02x ", decimalNumbers[character], character, character);
            break;
        case 10:
            printf("|%3d:<0NL> :%05o :0x%02x ", decimalNumbers[character], character, character);
            break;
        case 11:
            printf("|%3d:<0VT> :%05o :0x%02x ", decimalNumbers[character], character, character);
            break;
        case 12:
            printf("|%3d:<0NP> :%05o :0x%02x ", decimalNumbers[character], character, character);
            break;
        case 13:
            printf("|%3d:<0CR> :%05o :0x%02x ", decimalNumbers[character], character, character);
            break;
        case 14:
            printf("|%3d:<0SO> :%05o :0x%02x ", decimalNumbers[character], character, character);
            break;
        case 15:
            printf("|%3d:<0SI> :%05o :0x%02x ", decimalNumbers[character], character, character);
            break;
        case 16:
            printf("|%3d:<DLE> :%05o :0x%2x ", decimalNumbers[character], character, character);
            break;
        case 17:
            printf("|%3d:<DC1> :%05o :0x%2x ", decimalNumbers[character], character, character);
            break;
        case 18:
            printf("|%3d:<DC2> :%05o :0x%2x ", decimalNumbers[character], character, character);
            break;
        case 19:
            printf("|%3d:<DC3> :%05o :0x%2x ", decimalNumbers[character], character, character);
            break;
        case 20:
            printf("|%3d:<DC4> :%05o :0x%2x ", decimalNumbers[character], character, character);
            break;
        case 21:
            printf("|%3d:<NAK> :%05o :0x%2x ", decimalNumbers[character], character, character);
            break;
        case 22:
            printf("|%3d:<SYN> :%05o :0x%2x ", decimalNumbers[character], character, character);
            break;
        case 23:
            printf("|%3d:<ETB> :%05o :0x%2x ", decimalNumbers[character], character, character);
            break;
        case 24:
            printf("|%3d:<CAN> :%05o :0x%2x ", decimalNumbers[character], character, character);
            break;
        case 25:
            printf("|%3d:<0EM> :%05o :0x%2x ", decimalNumbers[character], character, character);
            break;
        case 26:
            printf("|%3d:<SUB> :%05o :0x%2x ", decimalNumbers[character], character, character);
            break;
        case 27:
            printf("|%3d:<ESC> :%05o :0x%2x ", decimalNumbers[character], character, character);
            break;
        case 28:
            printf("|%3d:<0FS> :%05o :0x%2x ", decimalNumbers[character], character, character);
            break;
        case 29:
            printf("|%3d:<0GS> :%05o :0x%2x ", decimalNumbers[character], character, character);
            break;
        case 30:
            printf("|%3d:<0RS> :%05o :0x%2x ", decimalNumbers[character], character, character);
            break;
        case 31:
            printf("|%3d:<0US> :%05o :0x%2x ", decimalNumbers[character], character, character);
            break;
        case 32:
            printf("|%3d:<SPC> :%05o :0x%2x ", decimalNumbers[character], character, character);
            break;
        case 127:
            printf("|%3d:<DEL> :%05o :0x%2x ", decimalNumbers[character], character, character);
            break;
        default:
            printf("|%3d:<000> :%05o :0x%2x ", decimalNumbers[character], character, character);
            break;
    }
}
