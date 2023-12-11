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
    int row[140]  = {}, col[140] = {};
    int counter = 0;
    while (getline(inputFile, query)) {
        graph.emplace_back(query);
        bool onlyStar = true;
        for(char & ch : query)
        {
            if(ch != '.')
            {
                onlyStar = false;
                break;
            }
        }
        if(onlyStar) row[counter] = 1;
        if(counter) row[counter]+= row[counter - 1];
        counter++;
    }

    ////////////////////////////////////////// CODE ////////////////////////////////////////

    // update the graph
    for(int i = 0;i < (int)graph[0].size();i++)
    {
        bool onlyStar = true;
        for(int j = 0;j < (int)graph.size();j++)
        {
            if(graph[j][i] != '.')
            {
                onlyStar = false;
                break;
            } 
        }
        if(onlyStar) col[i] = 1;
        if(i) col[i]+=col[i - 1];
    }
    int n = graph.size(), m = graph[0].size();
    // find all galaxies
    vector<pair<int, int>> galaxies;
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
            int sx = galaxies[i].first, sy = galaxies[i].second;
            int dx = galaxies[j].first, dy = galaxies[j].second;
            if(sx > dx) swap(sx, dx);
            if(sy > dy) swap(sy, dy);
            result+=((dx - sx) + (dy - sy));
            result+=(row[dx] - (sx - 1 >= 0 ? row[sx - 1] : 0))*(1000000 - 1);
            result+=(col[dy] - (sy - 1 >=0 ? col[sy - 1] : 0))*(1000000 - 1);
        }
    }

    cout << result << '\n';
    // Close the file
    inputFile.close();
    return 0;
}