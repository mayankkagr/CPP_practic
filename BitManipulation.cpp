#include <iostream>
#include <cstring>

using namespace std;
int CountBits(int n){
  int count=0;
  while(n>0){
    count += n&1;
    n=n>>1;
  }
  return count;
}
int CountBits2(int n){
  int count=0;
  while(n>0){
    ++count;

    n=n&(n-1);
  }
  return count;
}
int Xor_Swaping(int &a, int &b)
{
    a= a^b;
    b= b^a;
    a=a^b;
}
int getithBit(int n, int i){
    return (n & (1<<i))!=0?1:0;
}
int setithBit(int n, int i){
    n= (n | (1<<i));
    return n;
}
int clearithBit(int n, int i){
    n= (n & ~(1<<i));
    return n;
}

void filterchar(char* a, int no)
{
    int i =0;
    while(no>0){
       (no&1) ? cout<< a[i]:cout<< "";
       i++;
       no=no>>1;
    }
    cout<<endl;
}
void generateSubsets(char *a){
    int n = strlen(a);
    int range =(1<<n) -1;
        for(int i=0;i<=range; i++)
            filterchar(a,i);

}
int main()
{
    cout << "Hello world!" << endl;
    cout<<CountBits(11)<<endl;
    cout<<CountBits2(11);
    int a=5,b=7;
    Xor_Swaping(a,b);
    cout<<a<<" "<<b<<endl;

    cout<<getithBit(17,2)<<endl;
    cout<<setithBit(13,1)<<endl;
    cout<<clearithBit(13,2)<<endl;
    char c[100];
    cin>>c;
    generateSubsets(c);

    return 0;
}
