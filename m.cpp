#include<iostream>
#include<omp.h>
#include<stdio.h>

using namespace std;


void merge(int arr[],int i1,int j1,int i2,int j2){
    int temp[1000];
    int t = 0;
    int i = i1;
    int j = i2;
    
    while (i <= j1 && j <= j2){

        if(arr[i] < arr[j]){
            temp[t] = arr[i];
            i++;
            t++;
        }
        else{
            temp[t] = arr[j];
            j++;
            t++;
        }

    }

    while (i<= j1)
    {
        temp[t] = arr[i];
        i++;
        t++;
    }

    while (j <= j2)
    {
        temp[t] = arr[j];
            j++;
            t++;
    }

    int t2 = 0;
    for(int i = i1;i <= j2;i++){
        arr[i] = temp[t2++];
    } 
}

 
// void merge(int a[],int i1,int j1,int i2,int j2)
// {
// 	int temp[1000];    
// 	int i,j,k;

// 	i=i1;    
// 	j=i2;    
// 	k=0;
    
// 	while(i<=j1 && j<=j2)    
// 	{
//     	if(a[i]<a[j])
//     	{
//         	temp[k++]=a[i++];
//     	}
//     	else
//     	{
//         	temp[k++]=a[j++];
//         }    
// 	}
    
// 	while(i<=j1)    
// 	{
//     	temp[k++]=a[i++];
// 	}
   	 
// 	while(j<=j2)    
// 	{
//     	temp[k++]=a[j++];
// 	}

//     int l = 0;
   	 
// 	for(i=i1;i<=j2;i++)
// 	{
//     	a[i]=temp[l++];
// 	}    
// }


void mergeSort(int *arr,int i,int j){
    int mid;
    if(i<j){
        mid = (i+j)/2;
        #pragma omp parallel sections
        {
            #pragma omp section
            {
                mergeSort(arr,i,mid);
            }
            #pragma omp section
            {
                mergeSort(arr,mid+1,j);
            }
        }
        merge(arr,i,mid,mid+1,j);
    }
}


int main(){
    int *arr,n;
    cout<<"Enter Number of Element : ";
    cin>>n;

    arr = new int[n];

    for(int i = 0;i < n;i++){
        cout<<"Enter Element : ";
        cin>>arr[i];
    }
    cout<<endl;

    for(int i = 0;i < n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl<<" M S ";

    mergeSort(arr,0,n-1);

    cout<<endl;

    for(int i = 0;i < n;i++){
        cout<<arr[i]<<" ";
    }
    
}