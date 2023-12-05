#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	// Open the input file
    ifstream inputFile("sample_input.txt");

    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    // Read and print each line from the file
    string query;
    int result = INT_MAX;
    vector<vector<int>> convertors[7];
    vector<int>seeds;
    int i = -1;
    while (getline(inputFile, query))
    {
        if(query.length() == 2)
        {
            i++;
            continue;
        }
        istringstream iss(query);
        vector<int>numbers;
        int number;
        while (iss >> number)
        {
            numbers.emplace_back(number);
        }
        if(i == -1)
        {
            for(int & seed : numbers) seeds.emplace_back(seed);
        }
        else
        {
            convertors[i].emplace_back(numbers);
        }
    }

    for(int & seed : seeds)
    {
        int current_number = seed;
        for(int i = 0;i < 7;i++)
        {
            for(int j = 0; j < (int)convertors[i].size();j++)
            {
                int dest = convertors[i][j][0];
                int src = convertors[i][j][1];
                int gap = convertors[i][j][2];
                if(current_number >= src && current_number <= src + gap)
                {
                    current_number = current_number + (dest - src);
                    break;
                }
            }
        }
        result = min(result, current_number);
    }
    cout << result << '\n';
    // Close the file
    inputFile.close();

	return 0;
}