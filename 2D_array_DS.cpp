#include <iostream>
#include <iomanip>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
const int D = 9;

void printBoard(int board[D][D], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(3) << board[i][j] << " ";
        }
        cout << endl;
    }
}
int hourglassSum(vector<vector<int>> board){
    int tmp=0;
    int max_sum=INT_MIN;
    for(int i=0;i< board.size()-2;++i){
        for(int k=0 ; k<board.size()-2; ++k){
            tmp=board[i][k]+board[i][k+1]+board[i][k+2]
                +board[i+1][k+1]
                +board[i+2][k]+board[i+2][k+1]+board[i+2][k+2];

            max_sum=max(max_sum,tmp);
        }
    }
    return max_sum;
}
int main()
{
    cout << "Hello world!" << endl;
     int board[D][D] =
    {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    int tmp=0;
    int max_sum=INT_MIN;
    for(int i=0;i< D-2;++i){
        for(int k=0 ; k<D-2; ++k){
            tmp=board[i][k]+board[i][k+1]+board[i][k+2]
                +board[i+1][k+1]
                +board[i+2][k]+board[i+2][k+1]+board[i+2][k+2];

            max_sum=max(max_sum,tmp);
        }
    }
    cout<<max_sum;

    //ofstream fout(getenv("OUTPUT_PATH"));
    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);
        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }
       // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    int result = hourglassSum(arr);
    cout << result << "\n";

    return 0;
}
