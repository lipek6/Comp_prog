#include<bits/stdc++.h>
using namespace std;

const long long modular = 1e9 + 7;

long long sum(long long&operand1, long long& operand2);
long long sub(long long&operand1, long long& operand2);
long long mul(long long&operand1, long long& operand2);
long long exp(long long&operand1, long long& operand2);
long long fast_exp(long long base, long long exponent);
long long str_to_ll(string str_number, long long modu);


int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    string str_operand1;  cin >> str_operand1;
    char   str_operator0; cin >> str_operator0;
    string str_operand2;  cin >> str_operand2;    


    long long operand1;
    long long operand2;
    long long result;
    
    if(str_operator0 == '^')
    {
        operand1 = str_to_ll(str_operand1, modular);
        operand2 = str_to_ll(str_operand2, modular-1);    
    
        result = exp(operand1, operand2);
        cout << result << "\n";
        
        return 0;     
    }

    operand1 = str_to_ll(str_operand1, modular);
    operand2 = str_to_ll(str_operand2, modular);

    if     (str_operator0 == '+') result = sum(operand1, operand2);
    else if(str_operator0 == '-') result = sub(operand1, operand2);     
    else if(str_operator0 == '*') result = mul(operand1, operand2);

    cout << result << "\n";
    return 0;
}

long long sum(long long& operand1, long long& operand2)
{
    return ((operand1 % modular) + (operand2 % modular)) % modular;
}



long long sub(long long& operand1, long long& operand2)
{
    return ((operand1 % modular) - (operand2 % modular) + modular) % modular;
}



long long mul(long long& operand1, long long& operand2)
{
    return ((operand1 % modular) * (operand2 % modular)) % modular;
}



long long exp(long long& operand1, long long& operand2)
{
    return fast_exp(operand1, operand2);
}





long long fast_exp(long long base, long long exponent)
{
    if(exponent == 0) return 1;

    long long half = fast_exp(base, exponent / 2);

    long long result = ((half % modular) * (half % modular)) % modular;

    if(exponent % 2 == 0)
        return result;
    else
        return ((base % modular) * (result % modular)) % modular;
}



long long str_to_ll(string str_number, long long modu)
{
    long long result = 0;
    
    for(char number : str_number)
    {
        result = (result * 10 + (number - '0')) % modu;
    }

    return result;
}