#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define nl cout << "\n"
const int INF = 1e9;
vector<vector<int>> directions = {{0, 1}, {1, 0},{0, -1}, {-1, 0}};

signed main()
{
    // Open the input file
    // ifstream inputFile("sample_input.txt");
    ifstream inputFile("input.txt");

    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
        return 1;
    }
    // Read input from file
    string input;
    vector<vector<int>> grid;
    while (getline(inputFile, input)) {
        vector<int>mapper;
        for(auto & num : input) mapper.emplace_back(num - '0');
        grid.emplace_back(mapper);
    }
    const int n = grid.size(), m = grid[0].size();
    // dijkstra
    set<pair<int, vector<int>>> state_saver; // cost, (i, j, direction, steps_taken)
    state_saver.insert({0, {0, 0, -1, -1}});
    vector<vector<vector<vector<int>>>> cost(n, vector<vector<vector<int>>>(m, vector<vector<int>>(4, vector<int>(4, INF))));

    // check i, j are valid or not
    auto isValidPosition = [&](int i, int j, int steps)
    {
        if(i >= 0 && j >= 0 && i < n && j < m && steps < 3) return 1;
        return 0;
    };
    while(!state_saver.empty())
    {
        int curr_cost = (*state_saver.begin()).first;
        int i = (*state_saver.begin()).second[0], j = (*state_saver.begin()).second[1];
        if(i == n - 1 && j == m - 1)
        {
            cout << curr_cost << '\n';
            break;
        }
        int direction = (*state_saver.begin()).second[2], steps = (*state_saver.begin()).second[3];
        state_saver.erase(state_saver.begin());
        for(int k = 0;k < 4;k++)
        {
            int di = i + directions[k][0], dj = j + directions[k][1];
            int next_steps = ((direction == k) ? steps + 1 : 0);
            if((direction == 0 && k == 2) || (direction == 2 && k == 0)) continue;
            if((direction == 1 && k == 3) || (direction == 3 && k == 1)) continue;
            if(isValidPosition(di, dj, next_steps) && (curr_cost + grid[di][dj]) < cost[di][dj][k][next_steps])
            {
                cost[di][dj][k][next_steps] = (curr_cost + grid[di][dj]);
                state_saver.insert({cost[di][dj][k][next_steps], {di, dj, k, next_steps}});
            }
        }
    }   
    // Close the file
    inputFile.close();
    return 0;
}