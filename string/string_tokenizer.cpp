#include<iostream>
#include<string>
#include<cstring>
using namespace std;
char *mystrtok(char *ptr,char deli)
{
    static char*input=NULL;
    if(ptr!=NULL)
    {
        input=ptr;
    }
    //start extracting tokens
    if(input==NULL)
    {
        return NULL;
    }
    else
    {
        char *output=new char[strlen(input)];
        int i=0;
        while(input[i]!='\0')
        {
            if(input[i]!=deli)
            {
                output[i]=input[i];
            }
            else
            {
                output[i]='\0';
                input=input+i+1;
                return output;
            }
            i++;
        }
        //corner case
        output[i]='\0';
        input = NULL;
        return output;
    }
}
int main()
{
    char s[100]="I love apple juice";
    char *ptr=mystrtok(s,' ');
    cout<<ptr<<endl;
    while(ptr!=NULL)
    {
        ptr=mystrtok(NULL,' ');
        cout<<ptr<<endl;
    }
}