#include <iostream>
#include <iomanip>

using namespace std;
const int D=8;

void IncrPrint(int n){
    if(n==0)
        return;
    IncrPrint(n-1);
    cout<<n<<" ";
}
void DcrPrint(int n){
    if(n==0)
        return;
    cout<<n<<" ";
    DcrPrint(n-1);
    //cout<<n<<" ";
}
void printBoard(int board[D][D],int n){
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)
            cout<<setw(3)<<board[i][j]<<" ";
    cout<<endl;
    }

}
bool canPlace(int board[D][D],int n,int Row,int Col){
    return Row >= 0 && Col>=0 && Row<n && Col<n && board[Row][Col]==0;
}
bool Solve_Knight_move(int board[D][D],int n,int move_no,int curRow,int curCol){
    if(move_no == n*n){
        printBoard(board,n);
        return true;
    }
    int rowDir[]={2,1,-1,-2,-2,-1,1,2};
    int colDir[]={1,2,2,1,-1,-2,-2,-1};

    for(int curDir =0 ; curDir< 8; ++curDir){
        int nextRow=curRow + rowDir[curDir];
        int nextCol=curCol + colDir[curDir];

        if(canPlace(board,n,nextRow,nextCol)){
            board[nextRow][nextCol]=move_no+1;
            bool isSuccessful = Solve_Knight_move(board,n,move_no+1,nextRow,nextCol);
            if(isSuccessful) return true;
            board[nextRow][nextCol]=0;
        }

    }
    return false;
}


bool Solve_Knight_move_All_Possible_combination(int board[D][D],int n,int move_no,int curRow,int curCol){
    if(move_no == n*n){
        printBoard(board,n);
        cout<<"+++++++++++++++++++++++++++++"<<endl;
        return true;
    }
    int rowDir[]={2,1,-1,-2,-2,-1,1,2};
    int colDir[]={1,2,2,1,-1,-2,-2,-1};

    for(int curDir =0 ; curDir< 8; ++curDir){
        int nextRow=curRow + rowDir[curDir];
        int nextCol=curCol + colDir[curDir];

        if(canPlace(board,n,nextRow,nextCol)){
            board[nextRow][nextCol]=move_no+1;
            bool isSuccessful = Solve_Knight_move_All_Possible_combination(board,n,move_no+1,nextRow,nextCol);
            //if(isSuccessful) return true;
            board[nextRow][nextCol]=0;
        }

    }
    return false;
}


int main()
{
    cout << "Hello world!" << endl;
    /*int n;
    cin>>n;
    DcrPrint(n);*/
    int board[D][D]={0};
    int diamantion;
    cin>>diamantion;
    board[0][0]=1;
    cout<<endl;
   // Solve_Knight_move(board,diamantion,1,0,0);
    Solve_Knight_move_All_Possible_combination(board,diamantion,1,0,0);;
 /*   if(ans){
        printBoard(board,diamantion);
    }
    else{
        cout<<"cant visit all board";
    }*/

    return 0;
}
