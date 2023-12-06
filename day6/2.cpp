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
    string _time, _distance;
    int time = 0, distance = 0;
    int i_c = 0;
    while (getline(inputFile, query))
    {
        istringstream iss(query);
        int number;
        while (iss >> number)
        {
            if(i_c == 0)
            {
                _time+=to_string(number);
            }
            else
            {
                _distance+=to_string(number);
            }
        }
        i_c++;
    }

    // main logic
    time = stoll(_time);
    distance = stoll(_distance);
    // fint the lower_bound
    int l = 0;int r = time - 1;
    while(l <= r)
    {
        int mid = l + (r - l)/2;
        int remaining_time = time - mid;
        int total_distance = mid * remaining_time;
        if(total_distance > distance)
        {
            r = mid - 1;
            continue;
        }
        int left_total_distance = (mid - 1) * (remaining_time + 1);
        int right_total_distance = (mid + 1) * (remaining_time - 1);
        if(left_total_distance > right_total_distance) r = mid - 1;
        else l = mid + 1;
    }

    // fint the upper_bound
    int lb = l;
    l = 0,r = time - 1;
    while(l <= r)
    {
        int mid = l + (r - l)/2;
        int remaining_time = time - mid;
        int total_distance = mid * remaining_time;
        if(total_distance > distance)
        {
            l = mid + 1;
            continue;
        }
        int left_total_distance = (mid - 1) * (remaining_time + 1);
        int right_total_distance = (mid + 1) * (remaining_time - 1);
        if(left_total_distance > right_total_distance) r = mid - 1;
        else l = mid + 1;
    }
    int ub = r + 1;
    cout << (ub - lb) << '\n';

    // TC = O(log(time)), SC = O(1)

    // Close the file
    inputFile.close();

	return 0;
}