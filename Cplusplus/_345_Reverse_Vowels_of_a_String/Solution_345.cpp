class Solution {
public:
    string reverseVowels(string s) {
        int start = 0, end = (int)s.size() - 1;
        while(start < end){
            while(start < end && !checkVowel(s[start])) start++;
            while(start < end && !checkVowel(s[end])) end--;
            swap(s[start], s[end]);
            start++;
            end--;
        }
        return s;
    }
    
    bool checkVowel(char c) {
        if ('a' == c || 'e' == c || 'i' == c || 'o' == c || 'u' == c
                || 'A' == c || 'E' == c || 'I' == c || 'O' == c || 'U' == c) {
            return true;
        }
        return false;
    }
};
