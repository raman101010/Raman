#include<iostream>
using namespace std;

void merge(int arr[],int l,int mid,int h)
{
    int n1=mid-l+1;
    int  n2=h-mid;

    int a[n1];    
    int b[n2];     //temporary array

    for(int i=0;i<n1;i++)
    {
         a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        b[i]=arr[mid+1+i];
    }

    int i=0;
    int j=0;
    int k=l;

    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
        {
           arr[k]=a[i];
           k++; i++;
        }
        else
        {
           arr[k]=b[j];
           k++; j++;    
        }
    }

    while(i<n1)             //When element of a or b is not reach in last position then we apply this code
    {
         arr[k]=a[i];
         k++; i++;
    }
     
    while(j<n2)
    {
        arr[k]=b[j];
        k++; j++;
    }


}
void mergesort(int arr[],int l,int h)
{
     if(l<h)
     {
        int mid=(l+h)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,h);

        merge(arr,l,mid,h);
     }
}
int main()
{   

    int n;
    cout<<"\n\nEnter the size of array : ";
    cin>>n;

    int arr[n];
    cout<<"\nEnter the unsorted array element : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    mergesort(arr,0,n);

    cout<<"\nAfter sorted array element is : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }


    return 0;
}

