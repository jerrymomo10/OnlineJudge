class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,multiset<string> > mp;
        for(auto s:strs)
        {
            auto t = s;
            strsort(s);
            mp[s].insert(t);
        }
        vector<vector<string>> result;
        for(auto m:mp)
        {
            vector<string> anagram(m.second.begin(),m.second.end());
            result.push_back(anagram);
        }
        return result;
    }
    void strsort(string& s)
    {
        int count[26] = {},n=s.size();
        for(int i=0;i<n;i++)
        {
            count[s[i]-'a']++;
        }
        int p = 0;
        string t(n,'a');
        for(int j=0;j<26;j++)
        {
            for(int i=0;i<count[j];i++)
            {
                t[p] += j;
                p++;
            }
        }
        s = t;
    }
};
int main() {
    Solution so;
    vector<string> strs={"eat","tea","tan","ate","nat","bat"};
    auto res = so.groupAnagrams(strs);
    for(auto i=res.cbegin();i<res.cend();i++)
    {
        for(auto j=(*i).begin();j<(*i).end();j++)
        {
            cout<<*j<<' ';
        }
        cout<<endl;
    }
    //cout << "Hello, World!" << endl;
    return 0;
}
