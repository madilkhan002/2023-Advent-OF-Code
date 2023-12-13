#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define nl cout << "\n"

int solve(string & s, int i, vector<int> & query, int j)
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
    if(s[i] == '?')
    {
        int skip = solve(s, i + 1, query, j); 
        int take = 0;
        int end = i + query[j];
        bool ok = (end <= (int)s.length());
        for(int k = i;k < end && ok;k++)
        {
            if(s[k] == '.') ok = false;
        }
        if(ok && (end == (int)s.length() || s[end] != '#')) take = solve(s, end + 1, query, j + 1);
        return (take + skip);
    } 
    else if(s[i] == '.')
    {
        return solve(s, i + 1, query, j);
    }
    else
    {
        int end = i + query[j];
        bool ok = (end <= (int)s.length());
        for(int k = i;k < end && ok;k++)
        {
            if(s[k] == '.') ok = false;
        }
        if(ok && (end == (int)s.length() || s[end] != '#')) return solve(s, end + 1, query, j + 1);
    }
    return 0;
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
        // Read the numbers into the vector<int> query
        char comma;
        int num;
        while (iss >> num) {
            query.push_back(num);
            iss >> comma;
        }
        result+=solve(s, 0, query, 0);
    }

    ////////////////////////////////////////// CODE ////////////////////////////////////////
    cout << result << '\n';
    // Close the file
    inputFile.close();
    return 0;
}