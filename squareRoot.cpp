#include <iostream>
using namespace std;

float squareRoot(float n){
	
	float x=n;
	float y=1;
	float loadf=0.000001;
	
	while(x-y > loadf){
		x=(x+y)/2;
		y=n/x;
		cout<<x<<" "<<y<<endl;
	}
	return x;
}

int main() {
	// your code goes here
	cout<<squareRoot(50);
	return 0;
}
