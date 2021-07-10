 #include<bits/stdc++.h>
 using namespace std;
 int getTrailing0InFactorial(int num) {
        if(num<0)
            return -1;
 
        int count = 0;
        for (int i = 5; (num/i) > 0; i=i*5) {
            count = count + num/i;
        }
        return count;
    }
    int main()
    {
    	int n;
    	cin>>n;
    	cout<<getTrailing0InFactorial(n);
    	return 0;
	}
