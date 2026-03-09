#include <iostream>
#include <vector>

std::vector<int> VecParser (const std::string& inVec);
std::vector<int> InsertionSort(const std::vector<int>& unsortedVec);

int main(void)
{
    std::string inVec;
    std::cin >> inVec;

    std::vector unsortedVec = VecParser(inVec);
    std::vector sortedVec = InsertionSort(unsortedVec);
}

std::vector<int> VecParser (const std::string& inVec)
{
    std::vector<int> outVec;
    std::string element;

    for(int i = 1; i < inVec.size()-1; i++)
    {
        if(inVec[i] == ',')
        {
            outVec.push_back(std::stoi(element));
            element.clear();
        }
        else
        {
            element += inVec[i];
        }
    }
    return outVec;
}

// Insertion Sort
std::vector<int> InsertionSort(const std::vector<int>& unsortedVec)
{
    std::vector<int> sortedVec = unsortedVec;
    
    for(int i = 0; i < sortedVec.size(); i++)
    {
        int key = sortedVec[i];
        int j = i - 1;
        while(j > 0 && sortedVec[j] > key)
        {
            sortedVec[j+1] = sortedVec[j];
            j--;
            sortedVec[j+1] = key;
        }
    }
    return sortedVec;
}