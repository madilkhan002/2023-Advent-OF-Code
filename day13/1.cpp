#include <bits/stdc++.h>
using namespace std;
#define int long long
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
    int result = 0;

    auto compute_rows = [&](int l, int r, int n, int m)
    {
        int add = r;
        while(l >= 0 && r < n)
        {
            for(int i = 0;i < m;i++) if(graph[l][i] != graph[r][i]) return;
            l--;r++;
        }
        result+=(add*100);
    };
    auto compute_cols = [&](int l, int r, int n, int m)
    {
        int add = r;
        while(l >= 0  && r < m)
        {
            for(int i = 0;i < n;i++) if(graph[i][l] != graph[i][r]) return;
            l--;r++;
        }
        result+=add;
    };
    auto compute_result = [&]()
    {
        int n = graph.size(), m = graph[0].length();
        for(int i = 1;i < n;i++)
        {
            compute_rows(i - 1, i, n, m);
        }
        for(int i = 1;i < m;i++)
        {
            compute_cols(i - 1, i, n, m);
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