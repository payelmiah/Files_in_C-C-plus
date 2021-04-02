#include<stdio.h>
int main()
{
    FILE *file;
    char s[50];
    file = fopen("text.txt","a");
    if(file==NULL)
    {
        printf("File does not exits\n");
    }
    else
    {
        printf("File is opened\n");
        printf("Enter your name: ");
        gets(s);
        fputs(s,file);
        fputs("\n",file);
        printf("File is written successfully\n");
        fclose(file);
    }
}
