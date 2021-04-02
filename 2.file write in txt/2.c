#include<stdio.h>
int main()
{
    FILE *file;
    char s[]={"i am your dad"};
    file = fopen("text.txt","w");
    if(file==NULL)
        printf("file doesn't exits");
    else
        printf("File is open\n");
        for(int i=0;s[i]!=0;i++)
        {
            fputc(s[i],file);
        }
        printf("file is written sucessfully\n");
        fclose(file);
    getch();
}

