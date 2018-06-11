#include <iostream>
using namespace std;

int main() {
	// your code goes here

	int start,end;
	cin>>start>>end;
	
	int s=(start-1)/7 , e=end/7;
	
	int sum = 7*((e*(e+1)/2) - (s*(s+1)/2));
	cout<<sum<<endl;
	
	return 0;
}
