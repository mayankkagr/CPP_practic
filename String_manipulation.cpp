#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include<string.h>

using namespace std;
#define SIZE_STR 100

void Swap(string& str1,string& str2){
    string tmp_str=str1;
    str1=str2;
    str2=tmp_str;
}

void Swap2(char** str1,char** str2){
    char* tmp_str=*str1;
    *str1=*str2;
    *str2=tmp_str;
}

void sort_Names(string str[SIZE_STR],int n){
    sort(str,str+n);
    cout<<endl;
    for(int i=0;i<n;++i)
        cout<<str[i]<<" ";
    cout<<endl;
}
bool CheckPalindrom(string str){
    bool flag=true;
    for(unsigned int i=0; i<str.length()/2;++i){
            if(str[i] != str[str.length()-1-i])
               {flag=false; break;}
    }
    return flag;
}
 char MaxOccurence(string str){
    map<char,int> map_c_i;
    for(int i=0; i<str.length();++i)
        ++map_c_i[str[i]];

    int max = 0;
    char result;
    for (int i = 0; i < str.length(); i++) {
        if (max < map_c_i[str[i]]) {
            max = map_c_i[str[i]];
            result = str[i];
        }
    }
    return result;
}

 void RemoveDuplicat(string& str){
     string tmp="";
    map<char,int> map_c_i;
    for(int i=0; i<str.length();++i){
        if(++map_c_i[str[i]]<=1)
            tmp+=str[i];
    }
    str= tmp;
}
set<char> PrintAllDup(string str){
    set<char> dup;
    map<char,int> map_c_i;
    for(int i=0; i<str.length();++i){
        if(++map_c_i[str[i]]>1)
            dup.insert(str[i]);
    }
    return dup;
}
void RemoveChar(string& str1,string str2){
    vector<char> u_str1;
    set<char> s_str2;
    for(int i=0; i<str1.length();++i)
            u_str1.push_back(str1[i]);

    for(int i=0; i<str2.length();++i)
        u_str1.erase((remove(u_str1.begin(),u_str1.end(),str2[i])),u_str1.end());

    str1="";
    for(auto itr=u_str1.begin();itr!=u_str1.end();++itr)
        str1+=*itr;
}
void swapChar( char *x,  char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute( char *a, int l, int r)
{
   int i;
   if (l == r)
     cout<<a<<endl;
   else
   {
       for (i = l; i <= r; i++)
       {
          swapChar((a+l), (a+i));
          permute(a, l+1, r);
          swapChar((a+l), (a+i)); //backtrack
       }
   }
}
void reverse(char *str)
{
   if (*str)
   {
       reverse(str+1);
       cout<<*str<<endl;
   }
}
void Pattern_search(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        int j;

        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;

        if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
            cout<<"Pattern found at index %d \n"<<i;
    }
}
int noOfWord(string st_sen){
    int count=0;
    for(int i = 0;i<st_sen.length();++i)
    {
        if(i==0 && st_sen[i]==' '){
            while(st_sen[++i] != ' ');
                --i;
        }
        if((st_sen[i]==' ' && st_sen[i+1] != ' ') || (st_sen[i]=='\n' && st_sen[i+1] != ' ') ||(st_sen[i]=='\t' && st_sen[i+1] != ' ')){
            ++count;
        }
    }
    return count;
}
int main()
{
    cout << "Hello world!" << endl;
    string name[]={"GeeksforGeeks", "GeeksQuiz", "CLanguage"};
    string str1="mayank";
    string str2="agrawal";
    //char* str1="mayank";
    //char* str2="agrawal";
    cout<<"str1 : "<<str1<<" ,str2: "<<str2<<endl;
    swap(str1,str2);
    //Swap2(&str1,&str2);
    cout<<"str1 : "<<str1<<" ,str2: "<<str2<<endl;
    int size = sizeof(name)/sizeof(name[0]);
    sort_Names(name,size);
    cout<<CheckPalindrom("abcdba")<<endl;
    cout<<MaxOccurence("abcdbba")<<endl;
    string str_d="geeksforgeeks";
    cout<<str_d<<endl;
    RemoveDuplicat(str_d);
    cout<<str_d<<endl;
    set<char> dup=PrintAllDup("test string");
    for(auto itr=dup.begin();itr!=dup.end();++itr)
        cout<<*itr<<" ";
    cout<<endl;
    cout<<str1<<" "<<str2<<endl;
    RemoveChar(str1,str2);
    cout<<str1<<endl;

    char per[]="abc";
    int n = 3;
    permute(per, 0, n-1);

    char txt[] = "AABAACAADAABAAABAA";
    char pat[] = "AABA";
    Pattern_search(pat, txt);

    string sentense="One two         three\n    four\tfive  ";
    cout<<endl<<noOfWord(sentense)<<endl;
    return 0;
}
