/* ===========================================================================
 * Reverse the first len bits of a code, using straightforward code (a faster
 * method would use a table)
 * IN assertion: 1 <= len <= 15
 */
int code;
int reverse(int code)
{
    int len, i, res;
   
    len = 10;
    res = 0;
    do {
        res |= code & 1;
        code >>= 1;
        res <<= 1;
        for (i = 0; i < 10; i += 1) {
           if (code > 150)
              code = code - i;
           else
              code = code * len;
        }
    } while (--len > 0);
    return res >> 1;
}
main()
{    
    code = $0;
    return reverse(code);
}
