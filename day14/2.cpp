#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define nl cout << "\n"
#define debug(x) cout << #x << "--> " << x << endl;

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
    while (getline(inputFile, query)) {
        graph.emplace_back(query);
    }
    
    const int n = graph.size(), m = graph[0].size();
    unordered_map<string, int> first_state_saver;
    auto tilt_north = [&]()
    {
        for(int j = 0;j < m;j++)
        {
            for(int i = 0;i < n;i++)
            {
                if(graph[i][j] == 'O')
                {
                    int k = i - 1;
                    while(k >= 0 && graph[k][j] == '.')
                    {
                        k--; 
                    }
                    swap(graph[i][j], graph[k + 1][j]);
                }    
            }
        }
    };

    auto tilt_west = [&]()
    {
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(graph[i][j] == 'O')
                {
                    int k = j - 1;
                    while(k >= 0 && graph[i][k] == '.')
                    {
                        k--; 
                    }
                    swap(graph[i][j], graph[i][k + 1]);
                }
            }
        }
    };

    auto tilt_south = [&]()
    {
        for(int j = 0;j < m;j++)
        {
            int block = n, used = 0;
            for(int i = n - 1;i >= 0;i--)
            {
                if(graph[i][j] == 'O')
                {
                    int k = i + 1;
                    while(k < n && graph[k][j] == '.')
                    {
                        k++; 
                    }
                    swap(graph[i][j], graph[k - 1][j]);
                }    
            }
        }
    };

    auto tilt_east = [&]()
    {
        for(int i = 0;i < n;i++)
        {
            for(int j = m - 1;j >= 0;j--)
            {
                if(graph[i][j] == 'O')
                {
                    int k = j + 1;
                    while(k < m && graph[i][k] == '.')
                    {
                        k++; 
                    }
                    swap(graph[i][j], graph[i][k - 1]);
                }
            }
        }
    };


    auto find_result = [&](string & state)
    {
        graph.clear();
        graph.resize(n);
        int curr_result = 0;
        for(int i = 0;i < n;i++)
        {
            graph[i] = state.substr((i*m), m);
        }

        
        for(int j = 0;j < m;j++)
        {
            for(int i = 0;i < n;i++)
            {
                if(graph[i][j] == 'O')
                {
                    curr_result+=(n - i);
                }
            }
        }
        return curr_result;
    };
    int state_number = 1;
    vector<int>cycle;
    unordered_map<int, string> cycle_start_saver;
    while(true)
    {
        string state;
        tilt_north();
        tilt_west();
        tilt_south();
        tilt_east();
        for(auto row : graph)
        {
            state+=row;
        }
        if(first_state_saver.find(state) == first_state_saver.end())
        {
            first_state_saver[state] = state_number;
            state_number++;
        }
        else
        {
            int curr_state = first_state_saver[state];
            if(cycle.size() && cycle[0] == curr_state) break;
            cycle_start_saver[curr_state] = state;
            cycle.emplace_back(curr_state);
        }
    }
    int rem = (1000000000 - state_number)%(int(cycle.size()));
    string result_state = cycle_start_saver[cycle[rem]];
    cout << find_result(result_state) << '\n';
    // Close the file
    inputFile.close();
    return 0;
}