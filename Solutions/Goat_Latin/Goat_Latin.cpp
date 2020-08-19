class Solution {
public:
    string toGoatLatin(string S) 
    {
        // result
        string goatLatin = "";
        
        static const string VOWELS = "aAeEiIoOuU";
        
        // to keep count of how many "a"s to add
        size_t count = 1;
        
		// for spliting sentence to words
        std::istringstream ss(S); 
        
    	while (ss)
	    { 
        	std::string word; 
        	ss >> word;
            
		    // convert word to goat latin according to case
            if(!word.empty())
            {
                goatLatin += VOWELS.find(word[0]) != string::npos ? word + "ma" + std::string(count, 'a') + " " : word.substr(1, word.length() - 1) + word[0] + "ma" +  std::string(count, 'a') + " ";
            }
             
            // increment for next word
            count ++;
	    }
		// return sentence without last space
        return goatLatin.substr(0, goatLatin.length() - 1);
    }
};

//Fastest
class Solution {
public:
    bool is_vovel(char ch){
      ch = tolower(ch);
      if(ch =='a' || ch =='e' || ch =='i' || ch =='o' || ch =='u')
        return true;
     return false;
    }
    
    string toGoatLatin(string str) {
      stringstream ss(str);
      string temp, succ = "maa", ans = "";
      while(!ss.eof()){
        ss >> temp;
        if(!is_vovel(temp[0])){
         char tp = temp[0];
         temp.erase(temp.begin());
         temp.push_back(tp);
      }
      temp += succ;
      succ.push_back('a');
      ans += (temp + ' ');
     }     
     return ans.substr(0,ans.size() - 1);
   }
};