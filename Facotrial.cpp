#include <iostream>
using namespace std;
#define size 20
int fact( int arr[size],int n){
	arr[19]=1;
	int carry=0;
	for(int i =1; i<=n;++i){
		for(int k=19; k>=0; --k)
		{
			int tmp = arr[k]*i+ carry;
			arr[k]=tmp%10;
			carry=tmp/10;
		}

		carry=0;
	}
		int a=0;
		for(int k=0; k<size; ++k)
		{
			if(a ==0 && arr[k]==0)	continue;
			else ++a;
			cout<<arr[k];
			
		}
}
int main() {
	int arr[20]={0};
	int n;
	cin>>n;
	int range=1;
	fact(arr,n);
	return 0;
}
