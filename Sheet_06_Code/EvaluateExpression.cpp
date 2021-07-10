//code to evaluate expression using STl  library.
#include<bits/stdc++.h>
using namespace std;
//function to set precedence of evaluation. since * and / have equal and higher precedence than + and - .
void pushResult(vector<pair<int, char>>& result, string num) {
        int n = stoi(num);
        if (result.back().second == '*') {
            result.back().first *= n;
        } else if (result.back().second == '/') {
            result.back().first /= n;
        } else {
            result.push_back(pair<int, char>(n, '\0'));
        }
}
//function to evaluate and perform operation on given string.
int calculate(string s) {
	//use pair to store oerand and operator.
        vector<pair<int, char>> result;
        result.push_back(pair<int, char>(0, '+'));
        string num = "";
        //loop through to find operand and push it into num
        for (int i = 0; i < s.size(); i++) {
            char op = s[i];
            if ((op < '0' || op > '9') && num != "")  {
                pushResult(result, num);
                num = "";
            }
            //loop to store operator in results
            if (op == '+' || op == '-' || op == '*' || op == '/') {
                result.back().second = op;
                continue;
            }
            if (op >= '0' && op <= '9') {
                num += op;
            }
        }
        if (num != "") {
            pushResult(result, num);
        }
        //perform sum and subtraction
        int sum = 0;
        for (int i = 0; i < result.size() - 1; i++) {
            if (result[i].second == '+') {
                sum += result[i + 1].first;
            } else {
                sum -= result[i + 1].first;
            }
        }
        return sum;
    }
    
   
int main()
{
	string str;
	cin>>str;
	cout<<calculate(str);
	return 0;
}
