class Solution {
public:
    int findComplement(int num) {
        int temp = num;
        int i = 1;
        while (temp > 1)
        {
            temp >>= 1;
            i <<= 1;
        }
        i <<= 1;
        return (i - 1) ^ num;
    }
};