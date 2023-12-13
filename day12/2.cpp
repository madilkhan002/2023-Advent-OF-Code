#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define nl cout << "\n"

int solve(string & s, int i, vector<int> & query, int j, vector<vector<int>> & dp)
{
    if(i >= (int)s.length())
    {
        return (j == (int)query.size());
    }
    if(j == (int)query.size())
    {
        while(i < (int)s.length())
        {
            if(s[i++] == '#') return 0;
        }
        return 1;
    }
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == '?')
    {
        int skip = solve(s, i + 1, query, j, dp); 
        int take = 0;
        int end = i + query[j];
        bool ok = (end <= (int)s.length());
        for(int k = i;k < end && ok;k++)
        {
            if(s[k] == '.') ok = false;
        }
        if(ok && (end == (int)s.length() || s[end] != '#')) take = solve(s, end + 1, query, j + 1, dp);
        return dp[i][j] = (take + skip);
    } 
    else if(s[i] == '.')
    {
        return dp[i][j] = solve(s, i + 1, query, j, dp);
    }
    else
    {
        int end = i + query[j];
        bool ok = (end <= (int)s.length());
        for(int k = i;k < end && ok;k++)
        {
            if(s[k] == '.') ok = false;
        }
        if(ok && (end == (int)s.length() || s[end] != '#')) return dp[i][j] = solve(s, end + 1, query, j + 1, dp);
    }
    return 0;
}

signed main()
{
    // Open the input file
    ifstream inputFile("sample_input.txt");

    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
        return 1;
    }
    // Read input from file
    int result = 0;
    string input;
    while (getline(inputFile, input)) {

        vector<int> query;
        // Assuming the input is in the format "?###???????? 3,2,1"
        istringstream iss(input);
        // Read the string into s
        string s;
        iss >> s;
        string new_s = s;
        for(int i = 0;i < 4;i++)
        {
            new_s.push_back('?');
            new_s+=s;
        }
        // Read the numbers into the vector<int> query
        char comma;
        int num;
        while (iss >> num) {
            query.push_back(num);
            iss >> comma;
        }
        int query_size = query.size();
        for(int i = 0;i < 4;i++)
        {
            for(int j = 0;j < query_size;j++)
            {
                query.emplace_back(query[j]);
            }
        }
        vector<vector<int>> dp((int)new_s.length(), vector<int>((int)query.size(), -1));
        result+=solve(new_s, 0, query, 0, dp);
    }

    ////////////////////////////////////////// CODE ////////////////////////////////////////
    cout << result << '\n';
    // Close the file
    inputFile.close();
    return 0;
}