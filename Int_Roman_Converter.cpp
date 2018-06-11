#include <iostream>
#include <map>
#include <string>
#include <cmath>

using namespace std;


string Integer_to_Roman(unsigned int value){

    struct romandata_t { unsigned int value; char const* numeral; };
    const struct romandata_t romandata[] =
    {
        {1000, "M"}, {900, "CM"},
        {500, "D"}, {400, "CD"},
        {100, "C"}, { 90, "XC"},
        { 50, "L"}, { 40, "XL"},
        { 10, "X"}, { 9, "IX"},
        { 5, "V"}, { 4, "IV"},
        { 1, "I"},
        { 0, NULL} // end marker
    };

    string result;
    for (const romandata_t* current = romandata; current->value > 0; ++current)
    {
        while (value >= current->value)
        {
            result += current->numeral;
            value -= current->value;
        }
    }
    return result;
}

int Roman_to_Integer(string str){
    if(str.length() ==0 )
        return 0;
    map<char,int> std_Rom_to_int;
    std_Rom_to_int.insert(make_pair('I',1));
    std_Rom_to_int.insert(make_pair('V',5));
    std_Rom_to_int.insert(make_pair('X',10));
    std_Rom_to_int.insert(make_pair('L',50));
    std_Rom_to_int.insert(make_pair('C',100));
    std_Rom_to_int.insert(make_pair('D',500));
    std_Rom_to_int.insert(make_pair('M',1000));

    std::map<char, int>::const_iterator it = std_Rom_to_int.find(str[str.length()-1]);
    int result = it->second;
    cout<<str.length()<<endl;
//    cout<<value;
    for(int i=str.length()-2 ; i>=0; i--){
            cout<< (std_Rom_to_int.find(str[i]))->second<<endl;
            int val1 = (std_Rom_to_int.find(str[i]))->second;
            int val2 = (std_Rom_to_int.find(str[i+1]))->second;
            if(val1>=val2)
                result= result+val1;
            else
                result=result-val1;
    }
   return result;

}

int main()
{
    cout << "Hello world!" << endl;
    cout<<Roman_to_Integer("XIX")<<endl;
    cout<<Integer_to_Roman(449);
    return 0;
}
