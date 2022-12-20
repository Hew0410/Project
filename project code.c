#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//function prototype
float shape_A(float b,float h);
float shape_B(float b,float h);
//declare the buffer area outside of functions
//so that this buffer area can be shared with all functions
//this is because the outputs from each function are going to be displayed in a same file
FILE*output;

int main()
{
    //describe main functionality
    printf("===============================\n");
    printf("MOI CALCULATOR\n");
    printf("-------------------------------\n");

    //ask users for the name of input file
    char input_file[100];
    char output_file[100];
    printf("Please enter input file name:");
    reenter:
    scanf("%s",&input_file);

    //the function strcmp means "string compare", if string are equal, then the value will return to 0
    //the specification format of strcmp is strcmp(<var name>,"<string>")==0
    //if the file exists,users are going to create an output file named by themselves
    //users can put any file name they want
    if(strcmp(input_file,"input.txt")==0)
    {
        printf("Please enter output file name:");
        scanf("%s",&output_file);
    }
    //if the file does not exist, users are required to reenter the file name, until they enter the correct file name
    else
    {
        printf("ERROR:Input file not exist...\n");
        printf("Please re-enter input file name:");
        goto reenter;
    }

    printf("-------------------------------\n");
    printf("OUTPUT:\n\n");

    //declare a buffer area to read the input file that are already existed
    FILE*input;
    input=fopen("input.txt","r");
    output=fopen(output_file,"w");

    //variables declaration
    char column_title[100];
    int current_line;
    char type;
    float length,height;

    //this is a loop to read the first line of input file but it will not be displayed on the screen and also in the output file
    for(current_line=1;current_line<2;current_line++)
    {
        fscanf(input,"%[^\n]",&column_title);
        fscanf(input,"%c %f %f",&type,&length,&height);
    }

    //to display the column title on the screen and in the output file
    printf("Type\tb\t\th\t\tMOIcx\t\tMOIcy\t\tMOIx\t\tMOIy\n");
    fprintf(output,"%s","Type\tb\t\th\t\tMOIcx\t\tMOIcy\t\tMOIx\t\tMOIy\n");

    //this is a loop to read the input file start from second line as the required data for calculation start from second line
    //these data and its computation results will be displayed on the screen and in the output file
    while((current_line=2)&&(!feof(input)))
    {
        fscanf(input,"%c %f %f\n",&type,&length,&height);
        //this is branching in which the different function will be executed based on the type of shape
        //if there is a shape other than type A or B, an error message will be displayed
        //if the length and height are 0 or negative, an error message will also be displayed
        if((type=='A')&&(length>0)&&(height>0))
        {
            shape_A(length,height);
        }
        else if((type=='B')&&(length>0)&&(height>0))
        {
            shape_B(length,height);
        }
        else
        {
            printf("%c\t%.3e\t%.3e\t\"INPUT_ERROR\"\n",type,length,height);
            fprintf(output,"%c\t%.3e\t%.3e\t\"INPUT_ERROR\"\n",type,length,height);
        }
    }

    //the end of buffer area
    fclose(input);
    fclose(output);
}

//a function to calculate moments about axis origin and moments about shape's centroid based on shape A
float shape_A(float b,float h)
{
    float cx,cy,x,y;
    cx=(1./12.)*b*h*h*h;
    cy=(1./12.)*b*b*b*h;
    x=(1./3.)*b*h*h*h;
    y=(1./3.)*b*b*b*h;
    printf("A\t%.3e\t%.3e\t%.3e\t%.3e\t%.3e\t%.3e\n",b,h,cx,cy,x,y);
    fprintf(output,"A\t%.3e\t%.3e\t%.3e\t%.3e\t%.3e\t%.3e\n",b,h,cx,cy,x,y);
}

//a function to calculate moments about axis origin and moments about shape's centroid based on shape B
float shape_B(float b,float h)
{
    float cx,cy,x,y;
    cx=(1./36.)*b*h*h*h;
    cy=(1./36.)*b*b*b*h;
    x=(1./12.)*b*h*h*h;
    y=(1./12.)*b*b*b*h;
    printf("B\t%.3e\t%.3e\t%.3e\t%.3e\t%.3e\t%.3e\n",b,h,cx,cy,x,y);
    fprintf(output,"B\t%.3e\t%.3e\t%.3e\t%.3e\t%.3e\t%.3e\n",b,h,cx,cy,x,y);
}
