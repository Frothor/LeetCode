# LeetCode Stream of Characters Solution

## Solution 1
For easily searching a word in O(k), use trie for that. We search for k last queried characters, in order of oldest to newest. So, if we reverse the order of words before inserting, the query order would be from newest to oldest.

If you do it like that, instead of O(k) time when we change k, we can simply have O(1) time for searching the new word, because the newly added character should have a prefix of all characters queried so far, so we only have to look only one level down from where we have searched till now.
```c++
class StreamChecker {
public:
    struct trie
    {
        bool eof;
        struct trie *children[26];
    };
    trie* createNode()
    {
        trie* ret=(trie*)malloc(sizeof(trie));
        ret->eof=false;
        for(int i=0;i<26;++i)
            ret->children[i]=NULL;
        return ret;
    }
    void insert(trie* root,string key)
    {
        trie* temp=root;
        for(char x:key)
        {
            if(temp->children[x-'a']==NULL)
                temp->children[x-'a']=createNode();
            temp=temp->children[x-'a'];
        }
        temp->eof=true;
    }
    trie* root;
    string temp;
    StreamChecker(vector<string>& words) 
    {
        root=createNode();
        for(string x:words)
        {
            reverse(x.begin(),x.end());
            insert(root,x);
        }
    }
    
    bool query(char letter) 
    {
        temp.push_back(letter);
        trie* t=root;
        for(int i=temp.size()-1;i>=0;--i)
        {
            t=t->children[temp[i]-'a'];
            if(t==NULL)
                return false;
            else if(t->eof)
                return true;
        }
        return false;
    }
};
```

[Link to original post](https://leetcode.com/problems/stream-of-characters/discuss/807600/C%2B%2B-simple-Trie-87-time-w-explanation)

## Solution 2

We have 2 things to implement properly here:

* a proper **Trie** struct/class to store all the words provided when we call **StreamChecker** constructor;
* an efficient way to return boolean results for our **query** method.

So, for the first point, while se can do it inside **StreamChecker**, I would strongly advise keeping it separate: it will save memory to just expand an object with bare minimum functionalities (basically just a constructor and an **add** function) and, both in interview and production settings, it just shows cleaner, more modular and maintainable code at the cost of a few extra lines.

Each instance of our **Trie** class (or struct, as I preferred in this case) will just have an array of **26 children** - one for each lowercase letter - and a boolean value **eow** to denote the end of a word.

Its **add** method will take a string and loop through its characters to build a tree, turning them into values in the **0 - 25** range just subtracting **'a'** to then, generating new linked **Trie** pointers and linking them in the matching **children** slot and finally assigning the value of **true** to the **eow** flag of the last node/character in the trie.

Now, **StreamChecker** time!

The first part is relatively straightforward and built on what we just did with **Trie**: we declare a few class variables, all **Trie**-related: **trie** and **curr**, both pointers to that data structure and **queries**, a vector of pointers to them; in the constructor, we just have to feed **trie** all the strings we were provided and we are good to go for this part.

**query** is definitely a bit more of a pickle: first of all, we start initialising our usual **res** variable, set to **false**; then we clean up **tmp** from possible previous runs and normalise again **c** to be in our familiar **0 - 25** range; also, we have to append **trie** to **queries** to be sure to capture new paths starting from this query.

After that, we start checking for all the "open" (more on this later) queries we have, starting from the bottom (I found this approach to be significantly faster and it makes sense, since the bottom tends to have the shortest single-character queries attached): we then check query by query if we have at least one of them matching the final character of a word (ie: **eow == true**), in which case we update **res**.

But we do not stop here: we proceed looping in order to cut out all the unnecessary queries for the next runs and move the still valid ones to **tmp**; we have to do this, otherwise we will keep wasting resources on dead paths.

Think for example if you were passed in the constructor **["voo", "voog", "voov", "vv"]** (slight nod to fellow ETF-investors here!): if your queries were **'v'**, **'o'**, **'v'**, **'v'**, **'o'**, **'o'**, **'v'**, **'p'**, you would have to discard the previous **'v'->'o'** and **'v'->'o'->'o'** paths after the second **'v'** and the first **'p'** respectively, since no path leads there, but **'v'->'v'** would still be a valid match.

I know, it takes a bit of time to visualise and digest it, but try to use my code and print some examples if that helps you :)

After the loop we update **queries** to match it and finally return **res** :)

The code:
```c++
struct Trie {
    Trie *children[26];
    bool eow = false;
    Trie() {
        // initialising all children to NULL
        for (Trie *&e: children) e = NULL;
    }
    void add(string s) {
        // adding new paths to the current Trie, char by char
		Trie *curr = this;
        for (char c: s) {
            // turning c into a 0 - 25 value
			c -= 'a';
            if (!curr->children[c]) curr->children[c] = new Trie();
            curr = curr->children[c];
        }
		// marking the end of a word on the node associated with the last character
        curr->eow = true;
    }
};

class StreamChecker {
public:
    Trie *trie = new Trie(), *curr;
    vector<Trie*> queries, tmp;
    StreamChecker(vector<string>& words) {
        // populating our trie with all the provided words
		for (string w: words) trie->add(w);
    }
    
    bool query(char c) {
        // mandatory variable initialisation/clean up
		bool res = false;
        tmp.clear();
        c -= 'a';
		// updating queries with to catch also the very last one
        queries.push_back(trie);
        for (int i = queries.size() - 1; i > -1; i--) {
            curr = queries[i];
            if (curr && curr->children[c]) {
                // marking res as true if we find a matching path
				res |= curr->children[c]->eow;
				// updating tmp for the next run
                tmp.push_back(curr->children[c]);
            }
        }
		// updating queries to remove dead paths
        queries = tmp;
        return res;
    }
};
```

I have an idea on how to refactor **queries** for better performances - might be working on it later!

Edit, done; I will not repeat the **Trie** part here, showing only **StreamChecker** with my latest changes; it takes less than half time (now I am down to 550ms), not too shabby. Notice that despite having a nominal upper bound of **40000** queries, you hardly need to store a fraction of them, the current ones, so I experimented a bit and saw that you only need to store like **1500** or so of them to pass a tricky test case; minor saving in memory, but still worth it:

```c++
class StreamChecker {
public:
    Trie *trie = new Trie(), *curr;
    Trie* queries[20000];
    int nextAvailable = 0;
    StreamChecker(vector<string>& words) {
        // populating our trie with all the provided words
		for (string w: words) trie->add(w);
    }
    
    bool query(char c) {
        // mandatory variable initialisation/clean up
		bool res = false;
        c -= 'a';
		// updating queries with to catch also the very last one
        queries[nextAvailable++] = trie;
        for (int i = nextAvailable - 1; i > -1; i--) {
            curr = queries[i];
            if (curr->children[c]) {
                // marking res as true if we find a matching path
				res |= curr->children[c]->eow;
                // updating queries
                queries[i] = curr->children[c];
            }
            // otherwise moving the last available query here
            // and leaving the ith element for overwriting
            else swap(queries[--nextAvailable], queries[i]);
        }
        return res;
    }
};
```

[Link to original post](https://leetcode.com/problems/stream-of-characters/discuss/807449/C%2B%2B-Trie-based-Solution-Explained-~25-Time-~60-Space)