#include <bits/stdc++.h>
using namespace std;

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
    vector<string>matrix;
    while (getline(inputFile, query)) {
        matrix.emplace_back(query);
    }

    // main logic
    int n = matrix.size();
    int m = matrix[0].size();
    // check does number has adjacent symbol
    auto find_adjacent_symbol = [&](int i, int j)
    {
        vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{-1,1},{1,-1}};
        for(auto & direction : directions)
        {
            int di = i + direction[0], dj = j + direction[1];
            if(di >= 0 && dj >= 0 && di < n && dj < m && !isdigit(matrix[di][dj]) && matrix[di][dj]!='.')
            {
                return true;
            }
        }
        return false;
    };
    // find all numbers
    for(int i = 0;i < n;i++)
    {
        for(int j = 0; j < m;j++)
        {
            bool isDigit = isdigit(matrix[i][j]);
            bool isValidNumber = false;
            int num = 0;
            while(j < m && isdigit(matrix[i][j]))
            {
                if(!isValidNumber) isValidNumber = find_adjacent_symbol(i,j);
                num*=10;
                num+=(matrix[i][j] - '0');
                j++;
            }
            if(isDigit) j--;
            if(isValidNumber)result+=num;
        }
    }
    cout << result << endl;
    // Close the file
    inputFile.close();

	return 0;
}