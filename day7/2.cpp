#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()

int card_rank(string s)
{
    unordered_map<char, int> counter;
    // replace J with appropriate character
    int mx_cnt = 0, mx_char = 'L';
    for(char & ch : s)
    {
        counter[ch]++;
        if(ch != 'L' && counter[ch] > mx_cnt)
        {
            mx_cnt = counter[ch];
            mx_char = ch;
        }
    }
    for(int i = 0;i < 5;i++)
    {
        if(s[i] == 'L')
        {
            s[i] = mx_char;
        }
    }
    sort(s.begin(), s.end());
    if(s[0] == s[4]) return 0;
    if(s[0] == s[3] || s[1] == s[4]) return 1;
    if((s[0] == s[2] && s[3] == s[4]) || (s[2] == s[4] && s[0] == s[1])) return 2;
    if(s[0] == s[2] || s[2] == s[4] || s[1] == s[3]) return 3;
    unordered_set<char> count(all(s));
    if(count.size() == 3) return 4;
    if(count.size() == 4) return 5;
    return 6;
}

signed main()
{
	// Open the input file
    ifstream inputFile("input.txt");

    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
        return 1;
    }
    // Read and print each line from the file
    string query;
    multiset<pair<string, int>> cards_order[7];
    unordered_map<char, char> converter = {
        {'J','L'},{'2','M'},{'3','N'}, {'4','O'}, {'5','P'},
        {'6','Q'},{'7','R'},{'8','S'}, {'9','T'}, {'T','U'},
        {'Q','W'},{'K','X'}, {'A','Y'}
    };
    while (getline(inputFile, query))
    {
        stringstream iss(query);
        string cards, bid;
        iss >> cards >> bid;
        for(int i = 0;i < 5;i++)
        {
            cards[i] = converter[cards[i]];
        }
        cards_order[card_rank(cards)].insert({cards, stoll(bid)});
    }
    int result = 0;
    int _rank = 1;
    for(int i = 6;i >= 0;i--)
    {
        while(!cards_order[i].empty())
        {
            result+=((*cards_order[i].begin()).second * _rank);
            cards_order[i].erase(cards_order[i].begin());
            _rank+=1;
        }
    }
    cout << result << '\n';
    // TC = O(N*LogN), SC = O(N)
    
    // Close the file
    inputFile.close();

	return 0;
}