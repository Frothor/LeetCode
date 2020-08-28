class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        for(int i = 1; i <= n; i++){
            if(i%3 == 0 && i%5 == 0)
                result.push_back("FizzBuzz");
            else if(i%3 == 0)
                result.push_back("Fizz");
             else if(i%5 == 0)
                result.push_back("Buzz");
            else
                result.push_back(to_string(i));
        }
        return result;
    }
}; 

//Fastest
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        bool flag;
        vector<string> output;
        string currOutput;
        for(int i = 1; i<=n; i++) {
            // flag = false;
            currOutput = "";
            
            if(i%3 == 0) {
                currOutput.append("Fizz");
                // flag = true;
            }
            if(i%5 == 0) {
                currOutput.append("Buzz");
                // flag = true;
            }
            if(!currOutput.size()) {
                currOutput.append(to_string(i));
                cout<<to_string(i);
            }
            output.push_back(currOutput);
        }
        return output;
    }
};