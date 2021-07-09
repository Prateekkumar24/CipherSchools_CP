#include<bits/stdc++.h>
using namespace std;

int searchInSortedRotated(vector<int> &vec, int st, int end, int element)
{
    if (st > end)
        return -1;
    int mid = st + (end - st) / 2;
    if (vec[mid] == element)
        return mid;

    if (vec[st] <= vec[mid])
    {
        // first segment is sorted
        if (element >= vec[st] && element <= vec[mid])
        {
            return searchInSortedRotated(vec, st, mid - 1, element);
        }
        else
        {
            return searchInSortedRotated(vec, mid + 1, end, element);
        }
    }
    else
    {
        // last segment is sorted
        if (element >= vec[mid] && element <= vec[end])
        {
            return searchInSortedRotated(vec, mid + 1, end, element);
        }
        else
        {
            return searchInSortedRotated(vec, st, mid - 1, element);
        }
    }
}
int main()
{
	int vSize,element;
   cin >> vSize;
        vector<int> v(vSize);
        for (int i = 0; i < v.size(); i++)
        {
            cin >> v[i];
        }
        cin >> element;
        cout << searchInSortedRotated(v, 0,vSize-1,element) << endl;
    
}
