#include <iostream>
#include <vector>
#include <deque>
#include<algorithm>
#include<iterator>
#include<set>

using namespace std;
static int count1 =0;
void subsetHelper(deque<string>& v,vector<string>& v_choosen){
   if(v.size() == 0){
        ++count1;
        cout<<"{ ";
        for(unsigned int i=0;i<v_choosen.size();++i)
            cout<<v_choosen[i]<<" ";
        cout<<"}"<<endl;

    }
    else{
    string first=v[0];
    v_choosen.push_back(v[0]);
    v.erase(std::remove(v.begin(), v.end(), v[0]), v.end());

    subsetHelper(v,v_choosen);
    v_choosen.erase(std::remove(v_choosen.begin(), v_choosen.end(), v_choosen[v_choosen.size()-1]), v_choosen.end());

    subsetHelper(v,v_choosen);
    v.push_front(first);
    }
}
void subset(deque<string> v){
    vector<string> ch;
        subsetHelper(v,ch);
}

void permuteHelper(string str,string chosen,set<string>& s_str){
    if(str.size() == 0){

            if(s_str.find(chosen)== s_str.end()){
                 s_str.insert(chosen);
                 cout<<chosen<<endl;
                    ++count1;
            }
    }
    else{
            for(unsigned int i=0;i<str.length();++i){
                char ch = str[i];
                chosen += ch;
                str.erase(i,1);
                permuteHelper(str,chosen,s_str);
                str.insert(i,1,ch);
                chosen.erase(chosen.length()-1, 1);
            }
    }
}


void permute(string v){
    string chosen;
    set<string> str;
    permuteHelper(v,chosen,str);
}


int main()
{
    cout << "Hello world!" << endl;
    deque<string> vec={"may","ank","agr","wal"};

    subset(vec);
    permute("mayank");
    cout<<count1;
    return 0;
}
