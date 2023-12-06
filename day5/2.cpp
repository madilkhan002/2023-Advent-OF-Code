#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
signed main()
{
	// Open the input file
    ifstream inputFile("input.txt");

    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
        return 1;
    }
    string query;
    vector<vector<int>> convertors[7];
    vector<int>seeds;
    int i = -1;
    while (getline(inputFile, query))
    {
        if(query.length() == 2)
        {
            i++;
            continue;
        }
        istringstream iss(query);
        vector<int>numbers;
        int number;
        while (iss >> number)
        {
            numbers.emplace_back(number);
        }
        if(i == -1)
        {
            for(int & seed : numbers) seeds.emplace_back(seed);
        }
        else
        {
            convertors[i].emplace_back(numbers);
        }
    }
    vector<pair<int,int>> seeds_curr_state;
    for(int i = 0;i < (int)seeds.size();i+=2)
    {
        seeds_curr_state.push_back({seeds[i], seeds[i] + seeds[i + 1]});
    }
    for(int i = 0;i < 7;i++)
    {
        vector<pair<int,int>> seeds_next_state;
        while(!seeds_curr_state.empty())
        {
            auto [s, e] = seeds_curr_state.back();
            seeds_curr_state.pop_back();
            bool isRangeMatched = false;
            for(int j = 0;j < (int)convertors[i].size();j++)
            {
                int dest = convertors[i][j][0];
                int src = convertors[i][j][1];
                int gap = convertors[i][j][2];
                int interval_start = max(s, src);
                int interval_end = min(e, src + gap);
                if(interval_start < interval_end)
                {
                    seeds_next_state.push_back({interval_start + (dest - src), interval_end + (dest - src)});
                    if(interval_start > s)
                    {
                        seeds_curr_state.push_back({s, interval_start});
                    }
                    if(interval_end < e)
                    {
                        seeds_curr_state.push_back({interval_end, e});
                    }
                    isRangeMatched = true;
                    break;
                }
            }
            if(!isRangeMatched)seeds_next_state.push_back({s, e});
        }
        seeds_curr_state = seeds_next_state;     
    }
    
    int result = 1e18;
    for(auto &[s,_] : seeds_curr_state) result = min(result, s);
    cout << result << '\n';
    // Close the file
    inputFile.close();

	return 0;
}