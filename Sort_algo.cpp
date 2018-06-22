#include <iostream>

using namespace std;
void merge_all(int* a,int start,int e){
    int mid = (start+e)/2;

    int first=start;
    int second = mid+1;
    int tmp=start;

    int tmp_arr[100];

    while(first<=mid && second<=e){
        if(a[first] < a[second])
            tmp_arr[tmp++]=a[first++];
        else
            tmp_arr[tmp++]=a[second++];
    }
    while(first<=mid){tmp_arr[tmp++]=a[first++];}
    while(second<=e){tmp_arr[tmp++]=a[second++];}

    //copy all element in regular array
    for(int k=start;k<=e;++k)
        a[k]=tmp_arr[k];

}
void merge_sort(int a[],int start,int e){
    if(start>=e){return;}
    //divide in two part
    int mid = (start+e)/2;
    //explore(start to mid, mid+1 to end)
    merge_sort(a,start,mid);
    merge_sort(a,mid+1,e);

    //mearge two part
    merge_all(a,start,e);

}


int partition(int *a,int s,int e){
    int i=s-1;
    int j=s;
    int pivot = a[e];

    for(; j<e;j++){
        if(a[j]<=pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[e]);
    return i+1;
}
void quick_sort(int a[],int s,int e){

    if(s>=e) return;

    int p=partition(a,s,e);
    quick_sort(a,s,p-1);
    quick_sort(a,p+1,e);

}

void BubbleSort(int* arr,int n){
	for(int j=0;j<n;++j){
		int flag =0;
		for(int i=0;i<n-j-1; ++i){
			if(arr[i] > arr[i+1]){
				arr[i]=arr[i]^arr[i+1];
				arr[i+1]=arr[i]^arr[i+1];
				arr[i]=arr[i]^arr[i+1];

				flag=1;
			}
		}
		if (flag==0)
			break;
	}

}
void SelectionSort(int * arr,int n){
    int iMin;
    for(int i=0;i<n;++i){
            iMin =i;
        for(int j=i+1;j<n;++j){
            if(arr[iMin]< arr[j] )
                iMin =j;
        }
        int tmp=arr[i];
        arr[i]=arr[iMin];
        arr[iMin]=tmp;

    }
}

void printSorted(int *arr,int n){
	for(int i =0 ;i<n ;++i){
		cout<<arr[i]<<" ";
	}
}

int main()
{
    cout << "Hello world!" << endl;
  /*  int a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];

    quick_sort(a,0,n-1);
    for(int i=0;i<n;++i)
        cout<<a[i]<<" ";
*/
    int n;
    cin>>n;
    int * arr=new int[n];
	for(int i =0 ;i<n ;++i){
		cin>>arr[i];
	}
	BubbleSort(arr,n);
	printSorted(arr,n);
	SelectionSort(arr,n);
	printSorted(arr,n);
    return 0;
}
