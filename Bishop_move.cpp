#include <iostream>
#include <iomanip>
using namespace std;

const int D=8;
static int count =0;

void printBoard(int board[D][D],int n){ 
     for(int i=0;i<n;++i){ 
         for(int j=0;j<n;++j) 
             cout<<setw(3)<<board[i][j]<<" "; 
     cout<<endl; 
     } 
 } 


bool canPlace(int board[D][D],int n,int row , int col){
	return row>=0 && col>=0 && row <n && col<n && board[row][col] ==0;
}
bool Solve_Bishop_move(int board[D][D],int n, int move,int row , int col){
	if(move == 32){
	    
		return true;
	}
	for(int i=-(D-1); i<D;++i){
		for(int j =-(D-1); j<D;++j){
			if(abs(i)==abs(j) && i!=0 ){
			int nextRow=row+i;
			int nextCol=col+j;
			
			if(canPlace(board,n,nextRow,nextCol)){
				board[nextRow][nextCol]=move+1;
				bool isSuccessful=Solve_Bishop_move(board,n,move+1,nextRow,nextCol);
				if(isSuccessful) return true; 
			             board[nextRow][nextCol]=0; 
		
			}
			
			}
		}
	}
	return false;
	
}

int main() {

	cout << "Hello world!" << endl; 
    int board[D][D]={0}; 
    int n; 
    cin>>n; 
    board[0][0]=1; 
    cout<<endl; 

    if(Solve_Bishop_move(board,n,1,0,0)) 
		printBoard(board,n);

	return 0;
}
