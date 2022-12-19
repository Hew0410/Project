#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("===============================\n");
    printf("MOI CALCULATOR\n");
    printf("-------------------------------\n");

    char input_file[100];
    char output_file[100];
    printf("Please enter input file name:");
    reenter:
    scanf("%s",input_file);

    //the function strcmp means "string compare, if string are equal, then the value will return to 0
    //the specification format of strcmp is strcmp(<var name>,"<string>')==0
    if(strcmp(input_file,"input.txt")==0)
    {
        printf("Please enter output file name:");
        scanf("%s",&output_file);
    }
    else
    {
        printf("ERROR:Input file not exist...\n");
        printf("Please re-enter input file name:");
        goto reenter;
    }

    FILE*input;
    input=fopen("input.txt","r");



}
