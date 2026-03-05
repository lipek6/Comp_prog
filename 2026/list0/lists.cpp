#include <iostream>

long long CountElements(const std::string& list);



int main(void)
{
    long long biggestListSize = -1;

    std::string biggestList;
    std::string inList;

    while(std::getline(std::cin, inList))
    {
        long long currentListSize = CountElements(inList);
        
        if(currentListSize > biggestListSize)
        {
            biggestListSize = currentListSize;
            biggestList = inList;
        }
    } 

    std::cout << biggestList << "\n";
    return 0;
}



long long CountElements(const std::string& list)
{
    if(list.size() <= 2)
        return 0;
    
    long long listSize = 1;
    
    for(size_t i = 0; i < list.size(); i++)
    {
        if(list[i] == ',')
            listSize++;
    }

    return listSize;
}