/* test the use of 'break' (when implemented for bonus points) */
k = 22;
for (j = 0; j < 100; j += 1)
{
   k = k + j;
   if (k > 120) 
      break;
   k = k + 10;
}
return k;
