#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define all(x) x.begin(),x.end()
#define nl cout << "\n"

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
    string query;
    vector<string> graph;
    long long result = 0;

    auto compute_rows = [&](int l, int r, int n, int m, int & fix)
    {
        int add = r;
        int diff = 0;
        while(l >= 0 && r < n)
        {
            for(int i = 0;i < m;i++) 
            {
                if(graph[l][i] != graph[r][i])
                {
                    diff++;
                }
            } 
            if(diff > 1) return 0;
            l--;r++;
        }
        if(!fix || !diff)
        {
            return 0;
        }
        fix--;
        return (add*100);
    };
    auto compute_cols = [&](int l, int r, int n, int m, int & fix)
    {
        int add = r;
        int diff = 0;
        while(l >= 0  && r < m)
        {
            for(int i = 0;i < n;i++)
            {
                if(graph[i][l] != graph[i][r])
                {
                    diff++;
                }
            } 
            if(diff > 1) return 0;
            l--;r++;
        }
        if(!fix || !diff)
        {
            return 0;
        }
        fix--;
        return add;
    };
    auto compute_result = [&]()
    {
        int n = graph.size(), m = graph[0].length();
        int fix = 1;
        for(int i = 1;i < n;i++)
        {
            int value = compute_rows(i - 1, i, n, m, fix);
            if(value)
            {
                result+= value;return;
            }
        }
        for(int i = 1;i < m;i++)
        {
            int value = compute_cols(i - 1, i, n, m, fix);
            if(value)
            {
                result+= value;return;
            }
        }
    };
    while (getline(inputFile, query)) {
        if(query.size())graph.emplace_back(query);
        if(!query.size())
        {
            compute_result();
            graph.clear();
        }
    }
    compute_result();

    cout << result << '\n';
    // Close the file
    inputFile.close();
    return 0;
}