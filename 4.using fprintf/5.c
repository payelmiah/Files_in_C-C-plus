#include<stdio.h>
int main()
{
    FILE *file;
    char name[50];
    int age;
    file = fopen("text.txt","a");
    if(file==NULL)
    {
        printf("File does not exits\n");

    }
    else
    {
        printf("File is opened\n");
        printf("Enter your name: ");
        gets(name);
        printf("Enter your age: ");
        scanf("%d",&age);

        fprintf(file,"Name = %s , Age = %d\n",name,age);
        printf("File is written successfully\n");
        fclose(file);

    }
}
