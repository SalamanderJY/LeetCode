char* multiply(char* num1, char* num2) 
{
    if (*num1 == '0' || *num2 == '0') {
        return "0";
    }
    char* ret = (char *)malloc((strlen(num1) + strlen(num2) + 1) * sizeof(char));
    memset(ret, '0', sizeof(char) * (strlen(num1) + strlen(num2) + 1));
    char* p1 = num1 + strlen(num1) - 1;
    char* p2 = num2 + strlen(num2) - 1;
    /* move to the lowest position to multiply */
    ret += strlen(num1) + strlen(num2);
    *ret-- = '\0';
    char* end = ret;
    while (1) {
        int sum = (*p1 - '0') * (*p2 - '0') + (*ret - '0');
        *ret = '0' + sum % 10;
        ret--;
        *ret += sum / 10;
        if (p1 != num1) {
            p1--;
        }
        else {
            if (p2 == num2) {
                break;
            }
            p1 = num1 + strlen(num1) - 1;
            p2--;
            ret = --end;
        }
    }
    if (*ret == '0') {
        return ret + 1;
    }
    return ret;
}
