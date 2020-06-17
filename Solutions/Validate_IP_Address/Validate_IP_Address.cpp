class Solution {
public:
    string validIPAddress(string IP) {
        regex v4("((25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])\.){3}(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])");
        if(regex_match(IP, v4))
            return "IPv4";
        
        regex v6("((([0-9a-fA-F]){1,4})\\:){7}(([0-9a-fA-F]){1,4})");
        if(regex_match(IP, v6))
            return "IPv6";
        
        return "Neither";
    }
};

/*
Fastest:
class Solution {
public:
    string validIPAddress(string IP) {
        if (validIPV4(IP))
            return "IPv4";
        else if (validIPV6(IP))
            return "IPv6";
        else 
            return "Neither";
    }

private:
    bool validIPV4(string IP) {
        if (count(IP.begin(), IP.end(), '.') != 3)
            return false;
        
        vector<string> parts = split(IP, '.');
        if (parts.size()!=4)
            return false;
        
        for(string part:parts) {
             if (part.empty() || (part.size() > 3) || (part.size() > 1 && part[0] == '0'))  
                return false;
        
            for(char c: part) {
                if(!isdigit(c))
                    return false;
            }
        
            if(stoi(part) > 255)
                return false;
        }
        
        return true;
    }
    
    bool validIPV6(string IP) {
        if (count(IP.begin(), IP.end(), ':') != 7)
            return false;
        
        vector<string> parts = split(IP, ':');
        if (parts.size() != 8)
            return false;
        
        for (string part: parts) {
            if (part.empty() || part.size() > 4)
                return false;
            
            for (char c: part) {
                if (!isdigit(c) && (!isalpha(c)) || toupper(c) > 'F')
                    return false;
            } 
        }
        
        return true;
    }
    
    vector<string> split(string str, char c) {
        vector<string> parts;
        string part;
        istringstream in(str);
        
        while(getline(in, part, c)) {
            parts.push_back(part);
        }
        return parts;
    }
}; 
*/