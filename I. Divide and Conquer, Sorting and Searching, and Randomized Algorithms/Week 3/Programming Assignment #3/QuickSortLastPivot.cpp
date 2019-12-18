#include<iostream>
using namespace std;

//int cnt=0;

int partition(int a[], int l, int r, int *ptr){
	int pivot=a[r], temp;
	int i=l+1;
	temp=a[r];
	a[r]=a[l];
	a[l]=temp;
	*ptr+=r-l;
	for(int j=l+1;j<=r;j++){
		if(a[j]<pivot){
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i++;
		}
	}
	temp=a[l];
	a[l]=a[i-1];
	a[i-1]=temp;
	return i-1;
}

void quicksort(int a[], int l, int r, int *ptr){
	if(l<r){
		int p = partition(a,l,r,ptr);
		//cout<<"PI= "<<p<<endl;
		quicksort(a,l,p-1,ptr);
		quicksort(a,p+1,r,ptr);
	}
}

int main(){
	int n=10000;
	int a[n], cnt=0, *cntptr=&cnt;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"File Loaded! "<<endl;
	quicksort(a,0,n-1,cntptr);
	cout<<cnt<<endl;
	return 0;
}