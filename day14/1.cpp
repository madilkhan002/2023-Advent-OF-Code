#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define nl cout << "\n"
#define debug(x) cout << #x << "--> " << x << endl;

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
    string query;
    vector<string> graph;
    int result = 0;

    while (getline(inputFile, query)) {
        graph.emplace_back(query);
    }
    
    const int n = graph.size(), m = graph[0].size();
    for(int j = 0;j < m;j++)
    {
        int block = n, used = 0;
        for(int i = 0;i < n;i++)
        {
            if(graph[i][j] == 'O')
            {
                result+=(block - used);
                used++;
            }
            else if(graph[i][j] == '#')
            {
                block = (n - i - 1);
                used = 0;
            }
        }
    }

    cout << result << '\n';
    // Close the file
    inputFile.close();
    return 0;
}