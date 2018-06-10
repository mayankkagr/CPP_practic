#include <iostream>
using namespace std;

void RotateByNumberRight(int** matrix,int size,int number=1){
    cout<<endl;
    while(number>0){
    for(int lyr=0;lyr<size/2;++lyr)
    {
        int first=lyr;
        int last=size-lyr-1;
        int r=lyr;
        int c=lyr;

            int top=matrix[r][c];
            while(r<last){ matrix[r][c]=matrix[r+1][c]; ++r;}
            while(c<last){ matrix[r][c]=matrix[r][c+1]; ++c;}
            while(r>first){ matrix[r][c]=matrix[r-1][c]; --r;}
            while(c>(first+1)){ matrix[r][c]=matrix[r][c-1]; --c;}
            matrix[r][c]=top;
    }
    --number;
    }
}

void RotateByNumberLeft(int** matrix,int size,int number=1){
    cout<<endl;
    while(number>0){
    for(int lyr=0;lyr<size/2;++lyr)
    {
        int first=lyr;
        int last=size-lyr-1;
        int r=lyr;
        int c=lyr;

            int top=matrix[r][c];
            while(c<last){ matrix[r][c]=matrix[r][c+1]; ++c;}
            while(r<last){ matrix[r][c]=matrix[r+1][c]; ++r;}
            while(c>first){ matrix[r][c]=matrix[r][c-1]; --c;}
            while(r>first+1){ matrix[r][c]=matrix[r-1][c]; --r;}

            matrix[r][c]=top;
    }
    --number;
    }
}

void RotateLeft(int** matrix,int size){
    for(int lyr=0;lyr<size/2;++lyr)
    {
        int first=lyr;
        int last=size-lyr-1;

            for(int i=first;i<last;++i)
            {
            int offset=i-first;
            int top=matrix[first][i];
            matrix[first][i]=matrix[i][last];
            matrix[i][last]=matrix[last][last-offset];
            matrix[last][last-offset]=matrix[last-offset][first];
            matrix[last-offset][first]=top;
            }

    }
}
void RotateRight(int** matrix,int size){
    for(int lyr=0;lyr<size/2;++lyr)
    {
        int first=lyr;
        int last=size-lyr-1;

            for(int i=first;i<last;++i)
            {
                int offset=i-first;
                int top=matrix[first][i];
                matrix[first][i]=matrix[last-offset][first];
                matrix[last-offset][first]=matrix[last][last-offset];
                matrix[last][last-offset]=matrix[i][last];
                matrix[i][last]=top;
            }

    }
}

void RotateMatrixByDegree(int** matrix,int size,int deg=90,char direction = 'R'){
    int noOfrot=0;
    if(deg == 90){noOfrot=1;}
    else if(deg == 180){noOfrot=2;}
    else if(deg == 270){noOfrot=3;}
    else{cout<<"enter correct degree from 90,180,270"<<endl; return;}
    if(direction=='L' || direction == 'l'){
        while(noOfrot!=0){RotateLeft(matrix,size); --noOfrot;}
    }
    else if(direction == 'R' || direction == 'r'){
        while(noOfrot!=0){RotateRight(matrix,size); --noOfrot;}
    }
    else{cout<<" enter correct rotation , choose R for clockwise and L for anticlockwise "<<endl; return;}
};

void displayMatrix(int** matrix,int size){
    for(int i=0;i<size;++i)
    {
        for(int j=0;j<size;++j){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
void fillMatrix(int** matrix,int size){
    int count=0;
    for(int i=0;i<size;++i)
    {
        for(int j=0;j<size;++j){
            matrix[i][j]=count++;
        }
    }
    cout<<"matrix filled successfully" <<endl;
}

int main()
{
    cout<<"hello World"<<endl;
    int r,c;
    cout<< "enter row : ";
    cin>>r;
    c=r;
    int** Mat=new int*[r];
    cout<<"size of Matrix : "<<sizeof(Mat)<<endl;
    for(int i=0;i<r;++i)
        Mat[i] = new int[c];

    fillMatrix(Mat,r);
    displayMatrix(Mat,r);

    int rotWise;
    cout<<" rotate by number or deg(0=numberwise, 1=degWise) : ";
    cin>>rotWise;
    if(rotWise){
        int rot=1,deg;
        char dir;
        do{
            cout<<"enter deg and direction";
            cin>>deg>>dir;
        RotateMatrixByDegree(Mat,r,deg,dir);
        cout<<endl;
        displayMatrix(Mat,r);

        cout<<"do you want to check again, if no press 0 else give any number: ";
        cin>>rot;
        }while(rot != 0);
    }
    else{char dir;
    cout<<"enter the direction(R=clockwise L=AntiClockWise) : ";
    cin>>dir;
    if(dir == 'L' || dir =='l')
    {
        int rot=1;
        do{

            cout<< " enter Rotation : ";
            cin>>rot;
            RotateByNumberLeft(Mat,r,rot);
            displayMatrix(Mat,r);
            cout<<"do you want to check again, if no press 0 else give any number: ";
            cin>>rot;
            }while(rot != 0);
    }
    else{
            int rot=1;
            do{
                cout<< " enter Rotation : ";
                cin>>rot;
                RotateByNumberRight(Mat,r,rot);
                displayMatrix(Mat,r);
                cout<<"do you want to check again, if no press 0 else give any number: ";
                cin>>rot;
            }while(rot != 0);
        }
    }
    return 0;

}
