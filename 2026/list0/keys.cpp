#include<iostream>

int main(void)
{
    std::string inString;
    std::getline(std::cin, inString);

    int toClose = 0;
    for(int i = 0; i < inString.size(); i++)
    {
        if(inString[i] == '{')
            toClose++;
        else if(inString[i] == '}')
            toClose--;
        
        if(toClose < 0)
            break;
    }

    if(toClose != 0)
        std::cout << "N\n";
    else
        std::cout << "S\n";
    return 0;
}


