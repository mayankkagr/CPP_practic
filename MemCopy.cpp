#include <iostream>
#include<cstring>

using namespace std;

void MemCopy(void* src,void* dest,int size){
	char* src1=static_cast<char*>(src);
	char* dest1=static_cast<char*>(dest);
//	char* src1=(char*)src;
//	char* dest1=(char*)dest;
	for(int i=0;i<size;++i){
		cout<<src1[i]<<" ";
		dest1[i]=src1[i];
	}
	cout<<endl;
}

int main() {
	int str[] ={1,2,3,4,5,6,7};
	int n =sizeof(str)/sizeof(str[0]);
	int str2[n];
	MemCopy(&str,&str2,sizeof(str));
	for(int i=0;i<n;++i)
		cout<<str2[i]<<endl;
		
  char str3[]="mayank";
	int nn=strlen(str3);
	char str4[nn];
	MemCopy(&str3,&str4,nn);
	cout<<str4<<endl;

	return 0;


}
