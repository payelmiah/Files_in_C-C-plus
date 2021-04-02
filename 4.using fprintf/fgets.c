#include<stdio.h>
int main()
{
    FILE *file;
    char ch[50];
    file = fopen("text.txt","r");
    if(file==NULL)
    {
        printf("File does not exits\n");

    }
    else
    {
        printf("File is opened\n");

        while(!feof(file))
        {
            fgets(ch,30,file);
            printf("%s",ch);
        }
        fclose(file);

    }
}


