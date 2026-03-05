#include <iostream>

int CountElements(const std::string& list);



int main(void)
{
    int biggestListSize = 0;

    std::string biggestList;
    std::string inList;

    while(std::getline(std::cin, inList))
    {
        int currentListSize = CountElements(inList);
        
        if(currentListSize > biggestListSize)
        {
            biggestListSize = currentListSize;
            biggestList = inList;
        }
    } 

    std::cout << biggestList << "\n";
    return 0;
}



int CountElements(const std::string& list)
{
    int listSize = 0;
    
    for(int i = 0; i < list.size(); i++)
    {
        if(list[i] == ',')
            listSize++;
    }

    return listSize;
}