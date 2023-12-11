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
    vector<string>old_graph;
    while (getline(inputFile, query)) {
        old_graph.emplace_back(query);
        bool onlyStar = true;
        for(char & ch : query)
        {
            if(ch != '.')
            {
                onlyStar = false;
                break;
            }
        }
        if(onlyStar) old_graph.emplace_back(query);
    }

    ////////////////////////////////////////// CODE ////////////////////////////////////////

    // update the graph
    unordered_set<int> additional_columns;
    for(int i = 0;i < (int)old_graph[0].size();i++)
    {
        bool onlyStar = true;
        for(int j = 0;j < (int)old_graph.size();j++)
        {
            if(old_graph[j][i] != '.')
            {
                onlyStar = false;
                break;
            } 
        }
        if(onlyStar) additional_columns.insert(i);
    }
    vector<string> graph((int)old_graph.size());    
    for(int i = 0;i < (int)old_graph.size();i++)
    {
        string row;
        for(int j = 0;j < (int)old_graph[0].size();j++)
        {
            row.push_back(old_graph[i][j]);
            if(additional_columns.find(j) != additional_columns.end()) row.push_back('.');
        }
        graph[i] = row;
    }

    // find all galaxies
    vector<pair<int, int>> galaxies;
    int n = graph.size(), m = graph[0].size();
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            if(graph[i][j] == '#') galaxies.push_back({i, j});
        }
    }

    int result = 0;
    for(int i = 0;i < (int)galaxies.size();i++)
    {
        for(int j = i + 1;j < (int)galaxies.size();j++)
        {
            result+=(abs(galaxies[i].first - galaxies[j].first) + abs(galaxies[i].second - galaxies[j].second));
        }
    }

    cout << result << '\n';
    // Close the file
    inputFile.close();
    return 0;
}