#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

    char column_title[100];
    int current_line;
    char type;
    float length,height;

    for(current_line=1;current_line<2;current_line++)
    {
        fscanf(input,"%[^\n]",&column_title);
        fscanf(input,"%c %f %f",&type,&length,&height);
    }

    printf("Type\t\tb\t\th\t\tMOIcx\t\tMOIcy\t\tMOIx\t\tMOIy\n");

    while((current_line=2)&&(!feof(input)))
    {
        fscanf(input,"%c %f %f\n",&type,&length,&height);
        if((type=='A')&&(length>0)&&(height>0))
        {
            A(length,height);
        }
        else if((type=='B')&&(length>0)&&(height>0))
        {
            B(length,height);
        }
        else
        {
            printf("ERROR!(to be deleted)\n\n");//to be modified
        }
    }

}

void A(float b,float h)
{
    float MOIcx,MOIcy,MOIx,MOIy;
    MOIcx=(1/12)*b*h*h*h;
    MOIcy=(1/12)*b*b*b*h;
    MOIx=(1/3)*b*h*h*h;
    MOIy=(1/3)*b*b*b*h;
    printf("A\t%.3e\t%.3e\t%.3e\t%.3e\t%.3e\t%.3e\n",b,h,MOIcx,MOIcy,MOIx,MOIy);
}

void B(float b,float h)
{
    float MOIcx,MOIcy,MOIx,MOIy;
    MOIcx=(1/36)*b*h*h*h;
    MOIcy=(1/36)*b*b*b*h;
    MOIx=(1/12)*b*h*h*h;
    MOIy=(1/12)*b*b*b*h;
    printf("B\t%.3e\t%.3e\t%.3e\t%.3e\t%.3e\t%.3e\n",b,h,MOIcx,MOIcy,MOIx,MOIy);
}


