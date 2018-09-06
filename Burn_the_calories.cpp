#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculate_cal(vector<int> vec){

	int lst_cl=0;
	int total_cl=0;

	for( int i =0;i< vec.size();++i){
			total_cl=total_cl + (2*lst_cl+vec[i]);
			lst_cl+=vec[i];
	}
	cout<<total_cl<<endl;
	return total_cl;
}

bool myfunction (int i,int j) { return (i>j); }

int main() {
	// your code goes here
	int t;
	cin >> t;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	for(int i =0; i<t;++i){
		vector<int> vec;
		int number_day,line_data;
		cin>> number_day;
		while(number_day){
			int data;
			cin>>data;
			vec.push_back(data);
			--number_day;
		}
		std::sort(vec.begin(),vec.end(),myfunction);
		calculate_cal(vec);
		vec.clear();
	}

	return 0;
}
