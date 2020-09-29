class Solution
{

public:
    bool backspaceCompare(string S, string T)
    {
        stack<char> s;
        for (char e : S)
        {
            if (e != '#')
            {
                s.push(e);
            }
            else if (!s.empty())
            {
                s.pop();
            }
        }

        stack<char> t;
        for (char e : T)
        {
            if (e != '#')
            {
                t.push(e);
            }
            else if (!t.empty())
            {
                t.pop();
            }
        }

        if (s.size() != t.size())
            return false;

        while (!s.empty())
        {
            char tmp = s.top();
            s.pop();
            if (t.top() != tmp)
            {
                return false;
            }
            t.pop();
        }
        return true;
    }
};

//Same
class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {
        stack<char> s1, t1;
        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] == '#' && !s1.empty())
            {
                s1.pop();
            }
            else if (S[i] != '#')
                s1.push(S[i]);
        }
        for (int i = 0; i <= T.length() - 1; i++)
        {
            if (T[i] == '#' && !t1.empty())
                t1.pop();
            else if (T[i] != '#')
                t1.push(T[i]);
        }
        if (s1 == t1)
            return true;
        return false;
    }
};