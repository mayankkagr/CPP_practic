#include <iostream>
#include <vector>

using namespace std;

#define SIZE 5

vector<pair<int,int> > island_point;

int get_size_of_islands(int **area,int r,int c){
	if(r<0 || c<0 ||r>SIZE-1 ||c >SIZE-1)
		return 0;
	if(area[r][c]==0)
		return 0;
	if(area[r][c]==1)
		island_point.push_back(make_pair(r,c));
	int size =1;
	area[r][c]=0;
	for(int i=r-1;i<=r+1;++i){
		for(int j=c-1;j<=c+1;++j)
		size+=get_size_of_islands(area,i,j);
	}
	return size;
}

int get_No_of_islands(int **area){
	int count=0;
	for(int i =0; i<SIZE;++i){
		for(int j =0; j<SIZE;++j){
			if(area[i][j]==1){
			int size=0;
			size=get_size_of_islands(area,i,j);
			++count;
			cout<<"Island No: "<<count<<" size: "<<size<<endl;
			cout<<"Island Path :";
			for(int k=0;k<island_point.size();++k)
				cout<<"-->"<<island_point[k].first<<":"<<island_point[k].second;
			cout<<endl;
			island_point.clear();
			}
		}
	}
	return count;
	
}

void Display(int **area){
	for(int i =0; i<SIZE;++i){
		for(int j =0; j<SIZE;++j){
		cout<<area[i][j]<<" ";
		}
	cout<<endl;
	}
}

int main() {
	// your code goes here
	int **area=new int*[SIZE];
	for(int i =0; i<SIZE;++i){
		area[i]=new int[SIZE];
	}
	
	int a[5][5]  = {{1, 1, 0, 0, 0},
                         {0, 1, 0, 0, 1},
                         {1, 0, 0, 1, 1},
                         {0, 0, 0, 0, 0},
                         {1, 0, 1, 0, 1}};
           for(int i =0; i<SIZE;++i){
		for(int j =0; j<SIZE;++j){
		area[i][j]=a[i][j];
		}
	}
	Display(area);
	cout<<"Total no of island: " <<get_No_of_islands(area)<<endl;
	
	return 0;
}
