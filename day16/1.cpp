#include <bits/stdc++.h>
using namespace std;
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
    string input;
    vector<string> graph;
    int result = 0;
    while (getline(inputFile, input)) {
        graph.emplace_back(input);
    }
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    map<pair<char, int>, int> change_direction_mirror = {
        make_pair(make_pair('\\', 3), 1),
        make_pair(make_pair('\\', 1), 3),
        make_pair(make_pair('\\', 0), 2),
        make_pair(make_pair('\\', 2), 0),
        make_pair(make_pair('/', 0), 3),
        make_pair(make_pair('/', 3), 0),
        make_pair(make_pair('/', 1), 2),
        make_pair(make_pair('/', 2), 1),
    };

    queue<vector<int>>q; // i, j, direction
    q.push({0, 0, 0});
    const int n = graph.size(), m = graph[0].size();
    vector<vector<vector<int>>> vis(n + 1, vector<vector<int>>(m + 1, vector<int>(4, 0)));

    auto isValid = [&](int i, int j, int direction)
    {
        if(i >= 0 && i < n && j >= 0 && j < m && !vis[i][j][direction]) return 1;
        return 0;
    };

    while(!q.empty())
    {
        auto curr = q.front();
        q.pop();
        int i = curr[0], j = curr[1], direction = curr[2];
        if(vis[i][j][direction]) continue;
        vis[i][j][direction] = 1;
        int di = i + directions[direction][0], dj = j + directions[direction][1];
        if(graph[i][j] == '.')
        {
            if(isValid(di, dj, direction))q.push({di, dj, direction});
            continue;
        }
        if(graph[i][j] == '\\' || graph[i][j] == '/')
        {
            int changer = change_direction_mirror[{graph[i][j], direction}];
            di = i + directions[changer][0];
            dj = j + directions[changer][1];
            if(isValid(di, dj, changer)) q.push({di, dj, changer});
        }
        else if(graph[i][j] == '-')
        {
            if(direction == 1 || direction == 0)
            {
                if(isValid(di, dj, direction)) q.push({di, dj, direction});
                continue;
            }
            if(isValid(i, j - 1, 1)) q.push({i, j - 1, 1});
            if(isValid(i, j + 1, 0)) q.push({i, j + 1, 0});
        }
        else if(graph[i][j] == '|')
        {
            if(direction == 2 || direction == 3)
            {
                if(isValid(di, dj, direction))q.push({di, dj, direction});
                continue;
            }
            if(isValid(i - 1, j, 3)) q.push({i - 1, j, 3});
            if(isValid(i + 1, j, 2)) q.push({i + 1, j, 2});
        }
    }

    for(int i = 0;i < n;i++)
    {
        for(int j = 0; j < m;j++)
        {
            result+=(vis[i][j][0]|vis[i][j][1]|vis[i][j][2]|vis[i][j][3]);
            if((vis[i][j][0]|vis[i][j][1]|vis[i][j][2]|vis[i][j][3])) cout << '#';
            else cout << '.';
        }
        nl;
    }



    cout << result << '\n';
    // Close the file
    inputFile.close();
    return 0;
}