#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//max activity
int countAct(vector<pair<int,int> > vec){
	int cnt=1;
	pair<int,int>  temp=vec[0];
	for(int i=1;i<vec.size();++i)
	{
		if(temp.second <= vec[i].first){
			++cnt;
			temp=vec[i];
		}
	}
	return cnt;
}
// Compares two intervals according to seconds times. 
bool comparePair(pair<int,int> i1, pair<int,int> i2) 
{ 
	return (i1.second < i2.second); 
} 

int main (int argc, char *argv[]) {
	
	vector<pair<int,int> > act;
	vector<int> out;
	int T;
	cin>>T;
	while(T--){
		int ca;
		cin>>ca;
		while(ca--){
			int f,t;
			cin>>f>>t;
			act.push_back(make_pair(f,t));
		}
		sort(act.begin(),act.end(),comparePair);
		out.push_back(countAct(act));
		//cout<<"max act: "<<countAct(act)<<endl;
		act.clear();
		act.resize(0);
	}
	
	for(auto item:out)
		  cout<<item<<endl;
	
	return 0;
}

