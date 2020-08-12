# LeetCode Pascal's Triangle II Solution

## 1. Solution
Idea : is A Simple One Find Out Pascal's Triangle in A 2D Matrix And Return Matrix[rowIndex]
```
Time Complexcity   O(K*K)
Space Complexcity  O(K * K)
```
```c++
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>ans(rowIndex+1);
        for(int i=0;i<=rowIndex;i++){
            ans[i].resize(i+1);
            ans[i][0] = ans[i][i] = 1;
            for(int j=1;j<i;j++){
                ans[i][j] = ans[i-1][j-1]+ans[i-1][j];
            }
        }
        return ans[rowIndex];
    }
```

## 2. Solution Using One Extra Row
Idea :
**Use Two 1D Array** Use 1st Array To Find New Value And 2nd Array To Hold Previous Array Value For Reuse It

### Let's Take An Example
```
		One Inportant Thing As We can See very Last And  very First Element Always 1 So keep That  Assign Before getting Into Inner loop
		
	for Input - 5
	Index                             Array 
	
	    1                       Array1  = [  ]         --> Use Array2[j] = Array1[j-1] + Array1[j];
	                            Array2  =  [ 1 ]      now do Array1 = Array2 for Next Step
								
		2	                   Array1   = [1 ]          --> Use formula
								Array2  =  [ 1 1 ]    now do Array1 = Array2 for Next Step
								
		3                     Array1    = [ 1 1 ]       --> Use formula
		                       Array2  =  [ 1 2 1 ]    now do Array1 = Array2 for Next Step
								
		4                     Array1    = [ 1 2 1 ]      --> Use formula
		                       Array2  =  [ 1 3 3 1 ]    now do Array1 = Array2 for Next Step
							   
		5                     Array1    = [ 1 3 3 1 ]     --> Use formula
		                       Array2  =  [ 1 4 6 4 1 ]    now do Array1 = Array2 for Next Step

Lastly Return  [ 1 4 6 4 1 ]   <== answer
```
```
Time Complexcity   O(K*K)
Space Complexcity  O(2 * K)
```
```c++
    vector<int> getRow(int rowIndex) {
        vector<int>ans,temp;
        for(int i = 0;i<=rowIndex;i++){
            temp.resize(i+1);
            temp[0] = temp[i] = 1;
            for(int j=1;j<i;j++)temp[j] = ans[j-1] + ans[j];
            ans = temp;
        }
        return ans;
    }
```

## 3.Solution Using O ( K ) Space
```
Time Complexcity   O(K*K)
Space Complexcity  O( K)
```
```c++
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1, 0);
        ans[0] = 1;
        for(int index=1; index<rowIndex+1; index++)
            for(int j=index; j>=1; j--)
                ans[j] += ans[j-1];
        return ans;
    }
```

## 4.Most Efficent Solution Using FormulaCredit -https://leetcode.com/lkjhlkjhasdf1 For This Idea

```
Time Complexcity  O( K )
Space Complexcity O( K )
```
```c++
 vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1);
        ans[0] = 1;
        for(int index=1; index<rowIndex+1; index++)
            ans[index]=(long)ans[index-1]*(rowIndex-index+1)/index;
        return ans;
    }
```

[Link to original post](https://leetcode.com/problems/pascals-triangle-ii/discuss/787241/C%2B%2B-Four-Simple-Solutions-O(-K*K-)-or-O(2*K)-or-O(-k-)-less-space)