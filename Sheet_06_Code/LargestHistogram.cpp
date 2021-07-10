//Largest Histogram problem using stack
#include<bits/stdc++.h>
using namespace std;

//function to get maximum area
int MaxArea(int arr[],int n){
    stack <int> s;
    int res=0;
    int tp;
    int curr;
    //loop to find previous smaller element and also keep record of area with current processing element
    for(int i=0;i<n;i++){
        while(s.empty()==false && arr[s.top()]>=arr[i]){
            tp=s.top();s.pop();
            curr=arr[tp]* (s.empty() ? i : i - s.top() - 1);
            res=max(res,curr);
        }
        s.push(i);
    }
    //loop for items which donot have next smaller,find prev. smaller and find its area
    while(s.empty()==false){
        tp=s.top();s.pop();
        curr=arr[tp]* (s.empty() ? n : n - s.top() - 1);
        res=max(res,curr);
    }
    
    return res;
    
}

int main() 
{ 
    int arr[];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
	}
    cout<<MaxArea(arr,n);
    return 0; 
}

