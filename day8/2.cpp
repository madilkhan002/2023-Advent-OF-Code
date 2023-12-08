#include <bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a, int b){if(a<b) swap(a,b);if(b==0) return a;return gcd(a%b,b);}
int lcm(int a,int b){return (a/gcd(a,b))*b;}

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
    int input = 0;
    string sequence;
    vector<string>end_with_A;
    while (getline(inputFile, query))
    {
        if(input == 0)
        {
            sequence = query;
            input+=1;
            continue;
        }
        stringstream iss(query);
        string node, left, right;
        iss >> node >> left >> right;
        graph[node].emplace_back(left);
        graph[node].emplace_back(right);
        if(node[2] == 'A')
        {
            end_with_A.emplace_back(node);
        }
    }
    int n = sequence.length();
    auto find_first_Z = [&](string start)
    {
        int counter = 0, i = 0;
        while(start[2] != 'Z')
        {
            start = graph[start][(sequence[i] == 'L' ? 0 : 1)];
            counter++;
            i++;
            if(i == n) i = 0;
        }
        return counter;
    };

    int result = 1;
    for(string start : end_with_A)
    {
        result = lcm(result, find_first_Z(start));
    }
    cout << result << '\n';
    inputFile.close();
    return 0;
}