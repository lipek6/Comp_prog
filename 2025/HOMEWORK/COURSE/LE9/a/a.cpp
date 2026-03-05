#include<bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    
    vector<string> words(n); 
    for(int i = 0; i < n; i++) cin >> words[i];
    
    string target_text; cin >> target_text;
    int text_length = target_text.size();

    vector<int> dp(text_length + 1, 0); dp[0] = 1;
    for(int i = 0; i < text_length; i++)   
    {
        if(dp[i] == 0) continue;
        for(auto word : words)
        {
            int word_length = word.size();
            if(i + word_length > text_length) continue;

            bool found = true;
            for(int j = 0; j < word_length; j++)
            {
                if(target_text[i+j] != '?' && target_text[i+j] != word[j])
                {
                    found = false;
                    break;
                }
            }
            if(found) dp[i + word_length] = (dp[i + word_length] + dp[i]) % (int)mod;  
        }
    }
    cout << dp[text_length] << "\n";
}