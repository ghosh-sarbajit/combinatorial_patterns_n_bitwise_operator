#include <stdio.h>
#include <string.h>
void swap(char *a,char *b)
{
    char temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int shouldswap(char *arr,int low,int runningindex)
{
    for(int i=low; i < runningindex; i++)
    {
        if(arr[i] == arr[runningindex])
            return 0;
    }
    return 1;
}
void permute(char *arr,int low,int high)
{
    int i;
    if(low == high)
        printf("%s\n",arr);
    for(i=low;i<=high;i++)
    {
        int flag;
        flag = shouldswap(arr,low,i);
        if(flag)
        {
            swap(arr+low,arr+i);
            permute(arr,low+1,high);
            swap(arr+low, arr+i);//backtrace
        }
    }
}
int main()
{
    char arr[10];
    int n,i;
    printf("Enter number of characters : ");
    scanf("%d",&n);
    getchar();
    printf("Enter characters :\n");
    for(i=0;i<n;i++)
    {
        scanf("%c",&arr[i]);
    }
    printf("All possible permutations are :\n");
    permute(arr,0,n-1);
    return 0;
}
