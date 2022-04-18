#include <stdio.h>
#include <stdlib.h>

#define LINE_SIZE 50

int getArray(char *str_arr);
int isAlphaNumeric(char ch);
int countAlphaNumeric(char *str_arr );
void printString(char *str_arr);
void printMetadata(char *str_arr, int alphaNumeric, int length );

int main()
{
    /**
     * this function get a char array from user in a dynamic way (can be any size)
     * and counts how many alphanumeric characters in array
     */
    /*define*/
    int current_size = 0;
    int alphanum_count = 0;
    char *str_arr;
    str_arr = malloc(sizeof( char ));

    /*do*/
    current_size = getArray(str_arr);
    alphanum_count = countAlphaNumeric(str_arr);


    printMetadata(str_arr, alphanum_count, current_size );


    /*cleanup*/
    free(str_arr);
    str_arr = NULL;

    return 0;
}

int getArray(char *str_arr)
{
    /**
     * function that get a char array from user, dynamic memory
     * @param str_arr - char pointer that will store our array
     * @return - int, array size after input
     */
    int end = EOF;
    int i = 0;
    int current_size = 1;

    printf("\nEnter a very very very long String value:");

    if(str_arr != NULL)
    {

        /*accept user input until hit enter or end of file*/
        while ((end = getchar()) != '\n' && end != EOF)
        {
            str_arr[i++] = (char) end;

            /*if i reached maximize size then realloc size*/
            if (i == current_size)
            {
                current_size = i + 1;
                str_arr = realloc(str_arr, current_size);
            }
        }
        str_arr[i] = '\0';

    }
    return current_size;
}

void printString(char *str_arr)
{
    /**
     * function that prints string nicely.
     * @param str_arr - char pointer, our array
     */
    int i = 0;
    printf("\nLong String value: \n");
    while (str_arr[i] != '\0')
    {
        printf("%c",str_arr[i]);
        i++;
        if (i%LINE_SIZE == 0)
            printf("\n");
    }
    printf("\n");
}

int isAlphaNumeric(char ch)
{
    /**
     * return 1 if char is alphanumeric , 0 if not
     * @param ch - char
     * @return - int, 1 = True, 0 = False
     */
    if (((ch >= '0') & (ch <= '9')) || ((ch >= 'a') && (ch <= 'z')) || ((ch >= 'A') &&( ch <= 'Z')))
        return 1;

    return 0;
}
int countAlphaNumeric(char *str_arr )
{
    /**
     * function that counts how many alphaNumeric chars there are in our char array
     * @param str_arr - char pointer, our array
     * @return - int,  how many alphanumeric characters in array
     */
    int counter = 0;
    int i =0;
    while (str_arr[i] != '\0')
    {
        counter = counter + isAlphaNumeric(str_arr[i]);
        i++;
    }
    return counter;
}

void printMetadata(char *str_arr, int alphaNumeric, int length )
{
    /**
     * function prints some metadata given
     * @param str_arr - char pointer, our array
     * @param alphaNumeric - int, how many alphanumeric characters in array
     * @param length- int, length of the array
     *
     */
    printString(str_arr);
    printf("Total number of characters:\n%d\n",length );
    printf("Number of alphaNumeric characters:\n%d\n",alphaNumeric );
}