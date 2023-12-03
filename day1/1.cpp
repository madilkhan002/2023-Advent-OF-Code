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
    int result = 0;
    while (getline(inputFile, query)) {
        int first_digit = -1, last_digit = -1;
        for(char & curr_char : query)
        {
        	if(isdigit(curr_char))
        	{
        		if(first_digit == -1) first_digit = curr_char - '0';
        		last_digit = curr_char - '0';
        	}
        } 
        result+=(first_digit*10 + last_digit);
    }
    printf("%d\n", result);
    // Close the file
    inputFile.close();

	return 0;
}