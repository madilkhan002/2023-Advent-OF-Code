#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll const mod = 1e18;
ll power(ll a, ll b) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}

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
    long long result = 0;
    while (getline(inputFile, query)) {
        // Use stringstream to extract numbers
        istringstream iss(query);
        unordered_map<int,int>winnings;
        // Extract each number and store it in the vector
        int number;
        int count = 0;
        int total_match = 0;
        while (iss >> number) {
            if(count < 5) winnings[number] = 1;
            else
            {
                if(winnings.find(number) != winnings.end())
                {
                    total_match+=1;
                }
            }
            count+=1;
        }
        if(total_match) result+=power(2,total_match - 1);
    }
    cout << result << '\n';
    // Close the file
    inputFile.close();

	return 0;
}