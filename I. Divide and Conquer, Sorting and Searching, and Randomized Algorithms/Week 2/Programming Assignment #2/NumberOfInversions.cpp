#include<iostream>
using namespace std;

long merge(int a[], int l, int m, int r){
	int b[m-l+1], c[r-m]; long cnt=0;
	for(int i=0; i<m-l+1; i++){
		b[i]=a[l+i];
	}
	for(int i=0; i<r-m; i++){
		c[i]=a[m+1+i];
	}
	int i=0,j=0,k=l;
	while((i<m-l+1)&&(j<r-m)){
		if(b[i]<c[j]){
			a[k++]=b[i++];
		}
		else{
			a[k++]=c[j++];
			cnt+=(m-l+1-i);
		}
	}
	while(i<m-l+1){
		a[k++]=b[i++];
	}
	while(j<r-m){
		a[k++]=c[j++];
	}
	/*for(int i=0; i<8; i++){
		cout<<a[i]<<" ";
	}
	cout<<cnt<<endl;*/
	return cnt;
}

long mergesort(int a[], int l, int r){
	long cnt=0;
	if(l<r){
		int m = l + (r-l)/2;
		cnt+=mergesort(a,l,m);
		cnt+=mergesort(a,m+1,r);
		cnt+=merge(a,l,m,r);
	}
	return cnt;
}

int main(){
	long n=100000;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<mergesort(arr,0,n-1)<<endl;
	/*for(int i=0; i<8; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;*/
	return 0;
}