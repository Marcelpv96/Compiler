/* test the use of 'break' (when implemented for bonus points) */
k = 22;
j = 1;
while (j < 1000)
{
   k = k + j;
   if (k > 1000)
      break;
   k = k + 10;
   j = j << 1;
}
return k;

