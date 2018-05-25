// Factorial with recursion, this requires rewriting yacc productions and rules
// Otherwise, this does not compile
// You may leave this problem to fix later after all other tasks have been done
int fac(int n)
{ if (n <= 1)
    return 1;
  return n * fac(n-1);
}
main()
{ return fac($0);
}
