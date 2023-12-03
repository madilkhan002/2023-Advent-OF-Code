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
        // Use stringstream to extract numbers
        istringstream iss(query);
        vector<int> numbers;

        // Extract each number and store it in the vector
        int number;
        while (iss >> number) {
            numbers.emplace_back(number);
        }
        int id = numbers[0];
        bool isValidInput = true;
        for(int i = 1;i < int(numbers.size()) - 1 && isValidInput;i++)
        {
            int value = numbers[i];
            int color = numbers[i + 1];
            if(color == 1 && value > 12) isValidInput = false;
            if(color == 2 && value > 13) isValidInput = false;
            if(color == 3 && value > 14) isValidInput = false;
        }
        if(isValidInput)result+=id;
    }
    printf("%d\n", result);
    // Close the file
    inputFile.close();

	return 0;
}