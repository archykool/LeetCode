class Solution {
public:
    string newString(string ss) {
        int j = 0;
        for (int i = 0; i < ss.length(); i++) {
        // for (int i = ss.length; i > 0; i--) {
            if (ss[i] != '#'){
                ss[j] = ss[i];
                j++;
            } else if (j > 0){
            // } else {
                j--;
            }
        }
        ss.resize(j);
        return ss;
    }

    bool backspaceCompare(string s, string t) {
        return newString(s) == newString(t);
    }
};