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
    unordered_map<string,int>word_to_digit = {
        {"one", 1}, {"two", 2}, {"three", 3},
        {"four", 4}, {"five", 5}, {"six", 6},
        {"seven", 7}, {"eight", 8}, {"nine", 9}
    };
    int result = 0;
    while (getline(inputFile, query)) {
        int first_digit = -1, last_digit = -1;
        int n = query.length();
        for(int i = 0;i < n;i++)
        {
            char curr_char = query[i];
        	if(isdigit(curr_char))
        	{
        		if(first_digit == -1) first_digit = curr_char - '0';
        		last_digit = curr_char - '0';
        	}
            for(int j = 0; j < 3;j++)
            {
                if(word_to_digit.find(query.substr(i,3 + j)) != word_to_digit.end())
                {
                    int digit = word_to_digit[query.substr(i, 3 + j)];
                    if(first_digit == -1) first_digit = digit;
                    last_digit = digit;
                }
            }
        } 
        result+=(first_digit*10 + last_digit);
    }
    printf("%d\n", result);
    // Close the file
    inputFile.close();

	return 0;
}