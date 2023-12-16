#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define nl cout << "\n"
#define debug(x) cout << #x << "--> " << x << endl;

signed main()
{
    // Open the input file
    ifstream inputFile("input.txt");
    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
        return 1;
    }
    // Read input from file
    string query;
    long long result = 0;

    while (getline(inputFile, query)) {
        
    }
    
    auto get_hash = [&](string & label)
    {
        int hash = 0;
        for(int i = 0;i < (int)label.length();i++)
        {
            char current_character = label[i];
            hash+=int(current_character);
            hash*=17;
            hash%=256;
        }
        return hash;
    };

    multiset<pair<int, string>> boxes[256];
    unordered_map<string, int> label_index, label_focal_length;
    for(int i = 0;i < (int)query.length();i++)
    {
        string label;
        int j = i;
        while(query[j] != '-' && query[j] != '=')
        {
            label.push_back(query[j]);
            j++;
        }
        int hash = get_hash(label);
        if(query[j] == '-')
        {
            if(label_index[label])
            {
                boxes[hash].erase(boxes[hash].find({label_index[label], label}));
                label_index[label] = 0;
            }
            i = j + 1;
        }
        else
        {
            int focal = query[j + 1] - '0';
            int index = label_index[label];
            if(index)
            {
                boxes[hash].erase(boxes[hash].find({index, label}));
            }
            label_focal_length[label] = focal;
            int curr_index = (index ? index : 1);
            if(!index && boxes[hash].size()) curr_index = (*boxes[hash].rbegin()).first + 1;
            boxes[hash].insert({curr_index, label});
            label_index[label] = curr_index;
            i = j + 2;
        }
    }

    for(int i = 0;i < 256;i++)
    {
        if(boxes[i].size())
        {
            // for(auto [_, label] : boxes[i]) cout << "(" << label << " = " << label_focal_length[label] << ")\n";
            int multiply = 1;
            int sum = 0;
            for(auto & [_, label] : boxes[i])
            {
                sum+=(label_focal_length[label] * multiply * (i + 1));
                multiply++;
            }
            result+=sum;
        }
    }
    cout << result << '\n';
    // Close the file
    inputFile.close();
    return 0;
}