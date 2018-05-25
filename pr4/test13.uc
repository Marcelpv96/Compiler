// test variable as a boolean value (requires conversion to short circuit code)
main()
{
   int n, m;

   n = $0;
   m = $1;

   if (n && m > 0) // converts n to short-circuit
     return 1;
   else
     return 0;
}
