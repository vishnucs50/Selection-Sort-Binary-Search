#include <stdio.h>
#include <cs50.h>
#include <string.h>

void ssort(int len, int num[], int y);
int bsearch (int n, int num[], int x);
int main (void)
{
    int n = get_int("How many numbers? ");
    int dig[n];
    for(int i=0; i<n;i++)
    {
        dig[i]= get_int("%i number: ", i+1);
    }
    int x = get_int("what number you want to find? ");
    ssort(n,dig,x); // Selection Sorting function

}

void ssort(int len, int arr[],int y)
{
    for (int i =0; i<len; i++)
    {
        int temp, hold,c =0;
        hold = arr[i];
        for (int j=i; j<len-1;j++)
        {
            if (hold > arr[j+1])
            {
                hold = arr[j+1];
                temp = j+1;
                c++;
            }
        }
        if (c!=0) // if smallest element is found, then swap.
        {
            hold = arr[i];
            arr[i] = arr[temp];
            arr[temp] = hold;
        }
    }
    printf("\nSorted Array: ");
    for (int k=0; k<len; k++)
    {
        printf("%i ", arr[k]);
    }
    printf("\n");

    bsearch (y,arr,len); // pass the sorted array to the binary search finction.
}

int bsearch (int n, int num[], int x)
{
    int l =0, r =x-1, mid = (l+r)/2, c=1; // left, right, and mid values are declared.
    // Counter c is used to represnt number of steps taken to achieve the search function.
    bool f = true;
    while (f)
    {
        if (num[mid] == n)
        {
            printf("Found\n");
            f=false;
        }
        else if(l==r && r==mid)
        {
            printf("Not Found :( \n");
            f=false;
        }
        else if (n < num[mid])
        {
            r = mid -1;
            if ( (l+r) %2 != 0)
                mid = 1+(l+r)/2;
            else
                mid = (l+r)/2;
        }
        else if (n > num[mid])
        {
            l = mid + 1;
            if ( !(l+r) %2)
                mid = 1+(l+r)/2;
            else
                mid = (l+r)/2;
        }
        c++; // Steps
    }
    printf("steps: %i\n", c);
    return 0;

}