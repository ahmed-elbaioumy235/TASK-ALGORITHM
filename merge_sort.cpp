// worst case nlog n
// best case nlog n


#include <iostream>
using namespace std;
void merge(int arr[],int l,int m, int r) //m = l+(r-1)/2
{
int i,j,k;
int n1 = m-l+1;
int n2 = r-m;
int *L = new int(n1) , *R = new int(n2);
for (int i=0;i<n1;i++)
{
    L[i] =arr[l+i];
}
for (int j=0;j<n2;j++)
{
    R[j] =arr[m+1+j];
}
i=j=0;
k=l; // l=0
while (i<n1 && j<n2)
{
    if (L[i]<=R[j])
    {
        arr[k]=L[i];
        i++;

    }
    else
    {
        arr[k] = R[j];
        j++;

    }
    k++;

}
while(i<n1)
{
    arr[k]=L[i];
    i++;
    k++;

}
while(j<n2)
{
    arr[k]=R[j];
    j++;
    k++;

}

}
void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
        
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}

}

void print(int arr[],int n)
{
    for (int i =0; i<n;i++)
    {
        cout<<arr[i]<<" ";

    }
    cout<<endl;

}
int main()
{
    int arr[] = {60, 90, 20, 40, 75, 69};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,n-1);
    print(arr,n);
    
return 0;


}

