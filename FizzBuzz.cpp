/******************************************************************************
FizzBuzz Problem. C/C++ Solution
github.com/akshaykrjain
*******************************************************************************/
#include <stdio.h>
void CheckAndShowFizzBuzz(int);

int main()
{
    printf("\n ################### #\n");
    printf("\n # Fizz Buzz Printer #\n");
    printf("\n #####################\n");
    int i;
    
    for (i=1;i<=100;i++)
    {
    
        CheckAndShowFizzBuzz(i);
        printf("\n");
            
    }
    return 0;
}


void CheckAndShowFizzBuzz(int i)
{
    
    if(i%3==0 && i%5==0)
        printf("FizzBuzz");
    else
        if(i%3==0)
		  printf("Fizz");
		else
		    if(i%5==0)
		        printf("Buzz");
		    else
		       printf("%d",i);
}
		

