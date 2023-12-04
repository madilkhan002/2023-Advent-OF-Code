#include <bits/stdc++.h>
using namespace std;

// difference array
signed main()
{
	// Open the input file
    ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        cerr << "Error opening the file." << endl;
        return 1;
    }
    
    // initialize the array according to the size of input
    const int n = 193;
    int arr[n] = {};

    // Read and print each line from the file
    string query;
    long long result = 0;
    int i = 0;
    while (getline(inputFile, query)) {
        // Use stringstream to extract numbers
        istringstream iss(query);
        unordered_set<int>winnings;
        // Extract each number and store it in the vector
        int number;
        int card_input_counter = 0;
        int total_matches = 0;
        while (iss >> number) {
            if(card_input_counter < 10)
            {
                winnings.insert(number);
                card_input_counter+=1;
            }
            else
            {
                if(winnings.find(number) != winnings.end())
                {
                    total_matches+=1;
                }
            }
        }
        if(i > 0) arr[i]+=arr[i - 1];
        if(i + total_matches + 1 < n && total_matches) arr[i + total_matches + 1]-=(arr[i] + 1);
        if(i + 1 < n && total_matches) arr[i + 1]+=(arr[i] + 1);
        result+=(arr[i] + 1);  
        i++;
    }
    cout << result << '\n';
    // Close the file
    inputFile.close();

	return 0;
}