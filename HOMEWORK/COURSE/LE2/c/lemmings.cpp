#include <bits/stdc++.h>

int main (void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, b, sg, sb, s;

    std::priority_queue <int> green; 
    std::priority_queue <int> blue; 
    std::vector<int> g_suvivors;
    std::vector<int> b_suvivors;
    std::pair           <int, int> battlefield;    


    std::cin >> n;
    while(n--)
    {
        green = {};
        blue  = {};

        std::cin >> b >> sg >> sb;  // number of battlefields, soldiers green and soldiers blue

        // GREEN ARMY
        while (sg--)
        {
            std::cin >> s;          // soldier
            green.push(s);
        }

        // BLUE ARMY
        while (sb--)
        {
            std::cin >> s;          // soldier
            blue.push(s);
        }


        while(!green.empty() && !blue.empty())
        {
            for (int i = 0; i < b; i++)
            {

                if(green.empty() || blue.empty())
                {
                    break;
                }

                battlefield = {green.top(), blue.top()};
                green.pop();
                blue.pop();

                if (battlefield.first > battlefield.second)
                {
                    g_suvivors.push_back(battlefield.first - battlefield.second);
                }
                
                else if (battlefield.first < battlefield.second)
                {
                    b_suvivors.push_back(battlefield.second - battlefield.first);
                }
                
                else
                {
                    continue;
                }
            }

            for(int i = 0; i < g_suvivors.size(); i++)
            {
                green.push(g_suvivors[i]);
            }

            for(int i = 0; i < b_suvivors.size(); i++)
            {
                blue.push(b_suvivors[i]);
            }

            g_suvivors = {};
            b_suvivors = {};
        }

        // PROBABLY FAST ENOUGH 
        if (green.empty() && blue.empty())
        {
            std::cout << "green and blue died\n";
        }
        else if (green.empty())
        {
            std::cout << "blue wins\n";
            while(!blue.empty())
            {
                std::cout << blue.top() << "\n";
                blue.pop();
            }
        }
        else
        {
            std::cout << "green wins\n";
            while(!green.empty())
            {
                std::cout << green.top() << "\n";
                green.pop();
            }
        }
        
        if (n > 0)
        {
            std::cout << "\n";
        }
    }
}