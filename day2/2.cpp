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
    while (getline(inputFile, query)) {
        // Use stringstream to extract numbers
        istringstream iss(query);
        // Extract each number and store it in the vector
        int number;
        bool skipID = true;
        int mx_red = 0, mx_green = 0, mx_blue = 0;
        int turn = 0;
        int value = 0;
        while (iss >> number) {
            if(skipID)
            {
                skipID = false;
                continue;
            }
            if(!turn) value = number;
            else
            {
                if(number == 1) mx_red = max(mx_red, value);   
                if(number == 2) mx_green = max(mx_green, value);   
                if(number == 3) mx_blue = max(mx_blue, value);   
            }
            turn^=1;
        }
        result+=(mx_red*1LL*mx_blue*1LL*mx_green);
    }
    cout << result << '\n';
    // Close the file
    inputFile.close();

	return 0;
}