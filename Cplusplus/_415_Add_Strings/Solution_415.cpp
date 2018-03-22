class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string res = "";
        while (i >= 0 || j >= 0 || carry == 1) {
            int n1 =  i >= 0 ? num1.at(i) - '0' : 0;
            int n2 =  j >= 0 ? num2.at(j) - '0' : 0;
            int sum = n1 + n2 + carry;
            carry = sum / 10;
            res = to_string(sum % 10) + res;
            i--;
            j--;
        }
        return res;
    }
};