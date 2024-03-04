#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void get_plaintxt();
void encrypt(int);
void decrypt(int);
char plaintxt[1000];
char ciphertxt[1000];
char rciphertxt[1000];
// main function
int main()
{
    int i;
    get_plaintxt();
    encrypt(1);
    puts("\n\ncipher message: ");
    puts(ciphertxt);
    decrypt(1);
    puts("\n\nrecipher message: ");
    puts(rciphertxt);
}
//..read plain text from text file
void get_plaintxt()
{
    FILE *fptr;
    char ch;
    int i = 0;
    //..open "plaintxt.txt" file for reading mode
    fptr = fopen("plaintxt.txt", "r");
    if (fptr == NULL)
    {
        printf("Error Reading!");
        exit(1);
    }
    //.. read file content char by char into string
    while ((ch = fgetc(fptr)) != EOF)
    {
        plaintxt[i++] = ch;
    }
    plaintxt[i] = '\0';
    puts("plain message: ");
    puts(plaintxt);
    fclose(fptr);
}
void encrypt(int key)
{
    int i = 0;
    FILE *fptr;
    //..open a text file "ciphertxt.txt" for writing mode
    fptr = fopen("ciphertxt.txt", "w");
    if (fptr == NULL)
    {
        printf("Error writing!!");
        exit(1);
    }
    //.. encrypt "plaintxt" and write it into "ciphertxt.txt" file
    //.. char by char
    while (plaintxt[i] != '\0')
    {
        if ((plaintxt[i] >= 'A' && plaintxt[i] <= 'M') || (plaintxt[i] >= 'a' && plaintxt[i] <= 'm'))
            ciphertxt[i] = plaintxt[i] + 13;
        else if ((plaintxt[i] >= 'N' && plaintxt[i] <= 'Z') || (plaintxt[i] >= 'n' && plaintxt[i] <= 'z'))
            ciphertxt[i] = plaintxt[i] - 13;
        else
            ciphertxt[i] = plaintxt[i] + 1;

        fputc(ciphertxt[i], fptr);
        i++;
    }
    ciphertxt[i] = '\0';
    fclose(fptr);
}
void decrypt(int key)
{
    int i = 0;
    FILE *fptr;
    //..open a text file "rciphertxt.txt" for writing mode
    fptr = fopen("rciphertxt.txt", "w");
    if (fptr == NULL)
    {
        printf("Error writing!!");
        exit(1);
    }
    //.. decrypt "ciphertxt" and write it into "rciphertxt.txt" file
    //.. char by char
    while (ciphertxt[i] != '\0')
    {
        if ((ciphertxt[i] >= 'A' && ciphertxt[i] <= 'M') || (ciphertxt[i] >= 'a' && ciphertxt[i] <= 'm'))
            rciphertxt[i] = ciphertxt[i] + 13;
        else if ((ciphertxt[i] >= 'N' && ciphertxt[i] <= 'Z') || (ciphertxt[i] >= 'n' && ciphertxt[i] <= 'z'))
            rciphertxt[i] = ciphertxt[i] - 13;
        else
            rciphertxt[i] = ciphertxt[i] - 1;
        fputc(rciphertxt[i], fptr);
        i++;
    }
    rciphertxt[i] = '\0';
    fclose(fptr);
}
