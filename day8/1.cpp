#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()

signed main()
{
	// Open the input file
    ifstream inputFile("input.txt");

    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
        return 1;
    }
    // Read and print each line from the file
    string query;
    unordered_map<string, vector<string>> graph;
    int i = 0;
    string sequence;
    queue<string>q;
    while (getline(inputFile, query))
    {
        if(i == 0)
        {
            sequence = query;
            i+=1;
            continue;
        }
        stringstream iss(query);
        string node, left, right;
        iss >> node >> left >> right;
        graph[node].emplace_back(left);
        graph[node].emplace_back(right);
        if(node[2] == 'A')
        {
            q.push(node);
        }
    }

    string curr_node = "AAA";
    i = 0;
    int n = sequence.length();
    // unordered_set<string> used;
    int result = 0;
    while(curr_node != "ZZZ")
    {
        if(sequence[i] == 'L') curr_node = graph[curr_node][0];
        else curr_node = graph[curr_node][1];
        i++;
        result++;
        if(i == n) i = 0;
    }
    cout << result << '\n';
    // Close the file
    inputFile.close();

	return 0;
}