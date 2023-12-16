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
    string query;
    long long result = 0;

    while (getline(inputFile, query)) {
        
    }
    int hash = 0;
    for(int i = 0;i < (int)query.size();i++)
    {
        char current_character = query[i];
        if(current_character == ',')
        {
            result+=hash;
            hash = 0;
            continue;
        }
        hash+=int(current_character);
        hash*=17;
        hash%=256;
    }

    cout << result + hash << '\n';
    // Close the file
    inputFile.close();
    return 0;
}