#include<bits/stdc++.h>
using namespace std;
 bool isExist(int matrix[4][4], int targetValue) {


        int i = 0;
        int j = 3;


        //i - number of rows
        //j -  number of cols
        while (i < 4 && j >= 0) {
            int currentElement = matrix[i][j];

            if (currentElement == targetValue) {
                return true;
            }
            if (currentElement > targetValue) {
                j--;
            } else {
                i++;
            }
        }

        return false;
    }
    int main()
    {
    	int matrix[][4] = {{1, 2, 3, 4}, 
	                      {5, 6, 7, 8}, 
		                  {9, 10, 11, 12}, 
		                  {13, 14, 15, 16}};
	    cout<<isExist(matrix,8);
	    return 0;


	}


