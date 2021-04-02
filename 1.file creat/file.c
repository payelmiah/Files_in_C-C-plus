#include<stdio.h>
int main()
{
    FILE *file;
    file = fopen("text.txt","w");
    if(file==NULL)
        printf("file doesn't exits");
    else
        printf("File is created");
        fclose(file);
    getch();
}
