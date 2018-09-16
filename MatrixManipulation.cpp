#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int r1=2, c1=3, r2=3, c2=2;
    
    int **a2d=new int*[r1];
    for(int i =0;i<r1;++i){
        a2d[i]=new int[c1];
    }
    for(int i=0;i<r1;++i)
        for(int j=0;j<c1;++j)
            a2d[i][j]= i+j;

    for(int i=0;i<r1;++i){
        for(int j=0;j<c1;++j)
            cout<<a2d[i][j]<<" ";
        cout<<endl;
    }
    
    int **a2d_2=new int*[r2];
    for(int i =0;i<r2;++i){
        a2d_2[i]=new int[c2];
    }
    for(int i=0;i<r2;++i)
        for(int j=0;j<c2;++j)
            a2d_2[i][j]= i*10+j;


    cout<<endl;
    for(int i=0;i<r2;++i){
        for(int j=0;j<c2;++j)
            cout<<a2d_2[i][j]<<" ";
        cout<<endl;
    }

    if(c1 != r2){
        cout<< "matrix manipulation not possible"<<endl;
        return 0;
    }
    int **a2d_3=new int*[r1];
    for(int i=0;i<r1;++i)
        a2d_3[i]=new int[c2];

    for( int i =0;i<r1;++i){
        for(int j=0;j<c2;++j){
            int sum=0;
            for(int k =0; k<r2;++k)
                sum=sum+a2d[i][k]*a2d_2[k][j];
            a2d_3[i][j]=sum;
        }
    }

    cout<<endl;
    for(int i=0;i<r1;++i){
        for(int j=0;j<c2;++j)
            cout<<a2d_3[i][j]<<" ";
        cout<<endl;
    }

    for(int i=0;i<r1;++i)
        delete[] a2d[i];
        
    delete[] a2d;
    
    for(int i=0;i<r2;++i)
        delete[] a2d_2[i];

    delete[] a2d_2;
    
     for(int i=0;i<r1;++i)
        delete[] a2d_2[i];

    delete[] a2d_2;
    

    return 0;
}
