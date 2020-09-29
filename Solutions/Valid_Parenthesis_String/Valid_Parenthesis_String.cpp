class Solution
{

public:
    bool checkValidString(string s)
    {
        stack<int> main, star;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                main.push(i);
            else if (s[i] == '*')
                star.push(i);
            else
            {
                if (!main.empty())
                    main.pop();
                else if (!star.empty())
                    star.pop();
                else
                    return false;
            }
        }

        while (!main.empty())
        {
            if (star.empty())
                return false;
            else if (main.top() < star.top())
            {
                main.pop();
                star.pop();
            }
            else
                return false;
        }

        return true;
    }
};