#include <bits/stdc++.h>
using namespace std;

// Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array.

vector<int> countDistinct(int A[], int n, int B)
{
    vector<int> ans;
    int i = 0, j = 0;
    map<int, int> mp;
    while (j < n)
    {
        mp[A[j]]++;
        if (j - i + 1 == B)
        {
            ans.push_back(mp.size());
            mp[A[i]]--;
            if (mp[A[i]] == 0)
                mp.erase(A[i]);
            i++;
        }
        j++;
    }
    return ans;
}

int main()
{

    return 0;
}