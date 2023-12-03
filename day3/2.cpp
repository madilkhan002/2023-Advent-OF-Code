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
            if(di >= 0 && dj >= 0 && di < n && dj < m && !isdigit(matrix[di][dj]) && matrix[di][dj] == '*')
            {
                return (di * n) + dj;
            }
        }
        return -1;
    };
    // find all numbers
    unordered_map<int, vector<int>> adjacent_numbers_to_star;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0; j < m;j++)
        {
            unordered_set<int>star_position;
            bool isDigit = isdigit(matrix[i][j]);
            bool isValidNumber = false;
            int num = 0;
            while(j < m && isdigit(matrix[i][j]))
            {
                int position = find_adjacent_symbol(i,j);
                if(position > 1) star_position.insert(position);
                num*=10;
                num+=(matrix[i][j] - '0');
                j++;
            }
            if(isDigit) j--;
            for(auto & position : star_position)
            {
                adjacent_numbers_to_star[position].emplace_back(num);
            }
        }
    }
    // find start with 2 adjacent number
    for(auto & [_, adjacent_numbers] : adjacent_numbers_to_star)
    {
        if((int)adjacent_numbers.size() == 2) result+=(adjacent_numbers[0]*1LL*adjacent_numbers[1]);
    }
    cout << result << endl;
    // Close the file
    inputFile.close();

	return 0;
}