#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
bool balanceHelper(string str,unsigned int &noOf_rep){
    stack<char> sign;
    stack<char> rep_sign;
    if(str[str.length()-1]=='<')
        return false;
    for(unsigned int i =0;i<str.length();++i){
        if(str[i] == '<'){sign.push(str[i]);}
        else if(!sign.empty() && str[i]== '>' && sign.top()=='<'){sign.pop();}
        else{rep_sign.push(str[i]);}
    }
    if(sign.empty() && rep_sign.size()<= noOf_rep)
    return true;
    else
        return false;

}

// Complete balancedOrNot function
// DO NOT MODIFY anything outside the below function
vector<bool> balancedOrNot(const vector<string>& expressions, const vector<unsigned int>& maxReplacements) {
    unsigned int count = expressions.size();
    vector<bool> res;
    for(unsigned int i =0;i<count;++i){
        string str = expressions[i];
        unsigned int noOf_rep=maxReplacements[i];
        if(balanceHelper(str,noOf_rep))
            res.push_back(1);
        else
            res.push_back(0);
    }

   //res.reserve(count);
    return res;
}
// DO NOT MODIFY anything outside the above function

int main() {

    /* Read input from STDIN. Print output to STDOUT */
    int n = 0, m = 0;

    cin >> n;

    vector<string> expressions;
    expressions.reserve(n);
    for (int i = 0; i < n; ++i) {
        string expression;
        cin >> expression;
        expressions.push_back(expression);
    }

    cin >> m;

    vector<unsigned int> maxReplacements;
    maxReplacements.reserve(m);
    for (int i = 0; i < m; ++i) {
        unsigned int maxReplacement;
        cin >> maxReplacement;
        maxReplacements.push_back(maxReplacement);
    }

    // call balancedOrNot function
    vector<bool> results = balancedOrNot(expressions, maxReplacements);

    for (int i = 0; i < n; ++i) {
        cout << results[i] << endl;
    }

    return 0;
}
