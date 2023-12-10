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
    vector<string>graph;
    while (getline(inputFile, query)) {
        graph.emplace_back(query);
    }

    ///////////////////////////////////// CODE /////////////////////////////////////////////
    int result = 0;
    int si = 0, sj = 0;
    const int n = graph.size(), m = graph[0].size();
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            if(graph[i][j] == 'S')
            {
                si = i, sj = j;
                break;
            }
        }
    }
    //

    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    unordered_map<char, int> pipe_movement = {
        {'|', 12}, {'-',3}, {'L',9}, {'J',10}, {'7',6},{'F',5}
    };
    int visited[150][150];
    memset(visited, 0, sizeof(visited));

    // check is i, j is valid point
    auto isValidPosition = [&](int i, int j)
    {
        if(i >= 0 && j >= 0 && i < n && j < m && graph[i][j] != '.' && visited[i][j] == 0) return 1;
        return 0;
    };
    // get the valid neighbours of (i, j) point
    auto get_neighbour = [&](int i, int j)
    {
        char curr = graph[i][j];
        int movement = pipe_movement[curr];
        vector<pair<int, int>> neighbours;
        for(int k = 0;k < 4;k++)
        {
            if(movement&(1<<k))
            {
                int di = i + directions[k][0], dj = j + directions[k][1];
                if(isValidPosition(di, dj))
                {
                    neighbours.push_back({di, dj});
                }
            }
        }
        return neighbours;
    };

    // get starting neighbours of S
    queue<pair<int, int>> q;
    map<pair<int, int>, bool> isStart;
    for(auto & dir : directions)
    {
        int di = si + dir[0], dj = sj + dir[1];
        if(isValidPosition(di, dj))
        {
            auto neighbours = get_neighbour(di, dj);
            for(auto [i, j] : neighbours)
            {
                if(si == i && sj == j)
                {
                    q.push({di, dj});
                    isStart[{di, dj}] = 1;
                    break;
                }
            }
        }
    }    

    // change the S to appropriate Pipe
    for (auto [key, value] : pipe_movement)
    {
        bool isOkay = 1;
        for(int i = 0;i < 4;i++)
        {
            if(value&(1<<i))
            {
                int di = si + directions[i][0], dj = sj + directions[i][1];
                if(di >= 0 && di < n && dj >= 0 && dj < m && isStart[{di, dj}]) continue;
                isOkay = false;
            }
        }
        if(isOkay) 
        {
            graph[si][sj] = key;
            break;
        }
    }

    // bfs to get the polygon
    visited[si][sj] = 1;
    while(!q.empty())
    {
        int size = q.size();
        while(size--)
        {
            auto [i, j] = q.front();
            visited[i][j] = 1;
            q.pop();
            auto neighbours = get_neighbour(i, j);
            for(auto [di, dj] : neighbours) q.push({di, dj});
        }
    }

    auto point_in_polygon = [&](int i, int j)
    {
        int count = 0;
        for(int k = j - 1; k >= 0;k--)
        {
            if(visited[i][k])
            {
                if(graph[i][k] == '|' or graph[i][k] == 'J' || graph[i][k] == 'L')count++;
            }
        }
        return (count%2 ? 1 : 0);
    };

    for(int i = 0; i < n;i++)
    {
        for(int j = 0; j < m;j++)
        {
            if(!visited[i][j])
            {
                if(point_in_polygon(i, j))
                {
                    result++;
                    cout << '?';
                }
                else
                {
                    cout << " ";
                }
            }
            else
            {
                cout << graph[i][j];
            }
        }
        nl;
    }
    cout << result << endl;
    // Close the file
    inputFile.close();

    return 0;
}