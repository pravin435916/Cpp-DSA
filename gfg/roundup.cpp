string roundToNearest(string str)
{
    int last = str.back() - '0';
    int n = str.length();
    if (last > 5)
    {
        str[n - 1] = '0'; 
        int carryPos = n - 2;
        while (carryPos >= 0)
        {
            if (str[carryPos] == '9')
            {
                str[carryPos] = '0';
                carryPos--;
            }
            else
            {
                str[carryPos] += 1; 
                break;
            }
        }
        if (carryPos < 0)
        {
            str = '1' + str;
        }
    }
    else
    {
        str[n - 1] = '0';
    }
    return str;
}