#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()

bool isAllZero(vector<int> & nums)
{
    for(int & num : nums)
    {
        if(num) return false;
    }
    return true;
}

signed main()
{
	// Open the input file
    ifstream inputFile("input.txt");

    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    // main logic
    string query;
    int result = 0;
    while (getline(inputFile, query))
    {
        stringstream iss(query);
        vector<int>nums;
        int number;
        while(iss >> number)
        {
            nums.emplace_back(number);
        }
        // answer for current sequence
        int sum = 0;
        while(!isAllZero(nums))
        {
            int n = nums.size();
            vector<int> next_nums;
            for(int i = 1;i < n;i++)
            {
                next_nums.emplace_back(nums[i] - nums[i - 1]);
            }
            sum+=nums[n - 1];
            nums = next_nums;
        }
        result += sum;
    }

    cout << result << '\n';
    // Close the file
    inputFile.close();
	return 0;
}