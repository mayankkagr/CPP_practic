#include <iostream>
using namespace std;

bool isprime(int n){
	if (n == 2)
    	return true; 
	if (n == 3) 
	    return true; 
	if (n % 2 == 0) 
	    return false; 
	if (n % 3 == 0) 
	    return false; 
	int i = 5; 
	int w = 2; 
	int counter=0;
	while (i * i <= n){
	     if (n % i == 0)
	         return false; 
	     i += w; 
	     w = 6 - w; 
		++counter;
	}
	cout<<"counter="<<counter<<endl;
	return true;
}
int main() {
	// your code goes here
	for(int i=0;i<10000;++i)
		cout<<i<<" "<<isprime(i)<<endl;
		
	cout<<" "<<isprime(5113)<<endl;
	
	return 0;
}
