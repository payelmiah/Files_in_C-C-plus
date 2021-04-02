#include<stdio.h>
int main()
{
    FILE *file;
    char ch[50],l[20];
    int a;
    file = fopen("text.txt","r");
    if(file==NULL)
    {
        printf("File does not exits\n");

    }
    else
    {
        printf("File is opened\n");


        fscanf(file,"%s %s %d",&ch,&l,&a);
        printf("%s %s %d",ch,l,a);

        fclose(file);

    }
}



