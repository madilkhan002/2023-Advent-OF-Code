#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	// Open the input file
    ifstream inputFile("input.txt");
    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    // reading input
    string query;
    int result = 0;
    vector<int>time, distance;
    int i_c = 0;
    while (getline(inputFile, query))
    {
        istringstream iss(query);
        int number;
        while (iss >> number)
        {
            if(i_c == 0) time.emplace_back(number);
            else distance.emplace_back(number);
        }
        i_c++;
    }
    // main logic
    int n = time.size();
    for(int i = 0;i < n;i++)
    {
        int _time = time[i];
        int _distance = distance[i];
        int counter = 0;
        for(int hold = 1; hold <= _time;hold++)
        {
            int remaining_time = _time - hold;
            int total_distance = hold * remaining_time;
            if(total_distance > _distance) counter+=1;
        }
        if(!result && counter) result = 1;
        result*=counter;
    }

    cout << result << '\n';
    // TC = O(N * time), SC = O(N)
    // N = length of time array

    // Close the file
    inputFile.close();

	return 0;
}