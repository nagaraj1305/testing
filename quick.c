#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//nt n=0;

int partition(int a[],int low,int high)
{
    int i,j,k,key,temp;
    key=a[low];
    i=low+1;
    j=high;
    while(i<=j)
    {
        while(i<=j && key >=a[i])
        {
            i++;
        }
        while(key <a[j])
        {
            j--;
        }
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        else
        {
            k=a[j];
            a[j]=a[low];
            a[low]=key;
        }
    }
    return j;
}

void quicksort(int a[],int low,int high)
{
    int pos;
    if(low<high)
    {
        pos=partition(a,low,high);
        quicksort(a,low,pos-1);
        quicksort(a,pos+1,high);
    }
}
void main()
{
    int n,i;
    clock_t start,end;
    double totaltime;
    printf("\n enter the number of elements \n");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        a[i]=rand();
    }
    start=clock();
    quicksort(a,0,n-1);
    end=clock();
    printf("sorted array:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    totaltime=(double)(end-start)/CLOCKS_PER_SEC;

printf("\n time taken %f ",totaltime);
}