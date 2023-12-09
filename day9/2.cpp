#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()

bool isAllSame(vector<int> & nums)
{
    for(int i = 1;i < (int)nums.size();i++)
    {
        if(nums[i] != nums[i - 1]) return false;
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
        int sum = nums[0];
        int parrity = 0;
        while(!isAllSame(nums))
        {
            int n = nums.size();
            vector<int> next_nums;
            for(int i = 1;i < n;i++)
            {
                next_nums.emplace_back(nums[i] - nums[i - 1]);
            }
            sum+=(parrity == 0 ? -next_nums[0] : next_nums[0]);
            parrity^=1;
            nums = next_nums;
        }
        result += sum;
    }

    cout << result << '\n';
    // Close the file
    inputFile.close();
    return 0;
}