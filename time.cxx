/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdio.h>
#include<string>

int find(int arr[], int len, int seek)
{
    for (int i = 0; i < len; ++i)
    {
        if (arr[i] == seek) return i;
    }
    return -1;
}

std::string generate(int A, int B, int C, int D) {
    int i,j,mustStartWith2,numbersAvailableForMinute,startsWith2;
    int vals[4] = { A, B, C, D };
    int counts[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    for (i = 0; i < 4; i++) 
    {
        for (j = vals[i]; j < 10; j++) 
		counts[j]++;
    }


    // counts is now populated with the number of values less than or equal to the index it belongs to
    // so counts[2] is the total number of 0's, 1's and 2's
    if (counts[2] == 0) return "NOT POSSIBLE";
    // if there are no 0's and 1's, then it must start with 2
    mustStartWith2 = counts[1] == 0;
    if (mustStartWith2 && counts[3] == 1) return "NOT POSSIBLE";
    // We want a count of the number of free digits that are 5 or less (for the minute digit)
    numbersAvailableForMinute = counts[5] - (mustStartWith2 ? 2 : 1); 
    if (numbersAvailableForMinute == 0) return "NOT POSSIBLE";
    // we now know that it is a valid time
    int time[4] = { 0, 0, 0, 0 };
    // we also know if it starts with 2
    startsWith2 = mustStartWith2 || (numbersAvailableForMinute >= 2 && counts[2] > counts[1]);
    // knowing the starting digit, we know the maximum value for each digit
    int maxs[4] = {2, 3, 5, 9}; // = startsWith2 ? {2, 3, 5, 9} : {1, 9, 5, 9};
    //if(startsWith2)
    //  maxs[4] = {2, 3, 5, 9};
    //else
    //  maxs[4] = {1, 9, 5, 9};
    for (i = 0; i < 4; i++) {
        // find the first occurrence in counts that has the same count as the maximum
        //time[i] = counts.indexOf(counts[maxs[i]]);
        time[i] = find(counts,10, counts[maxs[i]]);
        // update counts after the value was removed
        for (j = time[i]; j < 10; j++) counts[j]--;
    }
    
    // create the time
    printf("%d %d : %d %d\n\n",time[0],time[1],time[2],time[3]);
    return " ";
}


main()
{
	int a[100],i,HMS[6];
	//printf("enter:");
	for(i=0;i<4;i++)	
	{
	scanf("%1d,",&a[i]);
	}
	printf("%s", generate(a[0],a[1],a[2],a[3]));

}
