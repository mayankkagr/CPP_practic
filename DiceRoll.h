#include <iostream>
#include <vector>

using namespace std;
#ifndef DICEROLL_H_INCLUDED
#define DICEROLL_H_INCLUDED

class DiceRoll{
public:
    static int count1;

    void DiceRollsHelper(int dice,vector<int>& chosen);
    void DiceRolls(int dice);

    void DiceSumHelper(int dice,int& desire_sum,int sum_till,vector<int>& chosen);
    void DiceSum(int dice,int& desire_sum);

};

#endif // DICEROLL_H_INCLUDED
