#include "DiceRoll.h"
#include <algorithm>

int DiceRoll::count1=0;
void DiceRoll::DiceRollsHelper(int dice, vector<int>& chosen)
{
    if(dice==0 ){
        for(unsigned int i=0;i<chosen.size();++i)
            cout<<chosen[i]<<" ";
        cout<<endl;
    }
    else{
        for(int i =1;i<=6;i++){
            chosen.push_back(i);

            DiceRollsHelper(dice-1,chosen);
            if(chosen.size() >0)
                chosen.pop_back();
        }
    }
}

void DiceRoll::DiceRolls(int dice)
{
    vector<int> chosen;
    DiceRollsHelper(dice,chosen);
}
void DiceRoll::DiceSumHelper(int dice, int& desire_sum,int sum_till, vector<int>& chosen)
{
    if(dice==0 ){
            ++count1;
        for(unsigned int i=0;i<chosen.size();++i)
            cout<<chosen[i]<<" ";
        cout<<endl;
    }
    else{
        for(int i =1;i<=6;i++){
            if(sum_till+i+1*(dice-1) <= desire_sum && sum_till+i+6*(dice-1) >= desire_sum){
            chosen.push_back(i);
            DiceSumHelper(dice-1,desire_sum,sum_till+i,chosen);
            if(chosen.size() >0)
                chosen.pop_back();
            }
        }
    }
}

void DiceRoll::DiceSum(int dice, int& desire_sum )
{
    vector<int> chosen;
    DiceSumHelper(dice,desire_sum,0,chosen);
}
