class Solution {
public:
    string simplifyPath(string path) {
        string ok;
        vector<string> store;
        int i=1,n=path.size();
        while(i<n)
        {
            while(i<n && path[i]=='/')
                i++;
            while(i<n && path[i]!='/')
                ok+=path[i++];
            if(ok==".." && store.size())
                store.pop_back();
            else if(ok.size() && ok!="." && ok!="..")
                store.push_back(ok);
            ok.clear();
        }
        ok="/";
        for(auto str:store)
        {
            ok+=str;
            ok+="/";
        }
        if(ok.size()>1)
            ok.pop_back();
        return ok;
    }
};