// test functions
int fac(int n)
{ int fac;
  fac = 1;
  while (n > 0)
    fac *= n--;
  return fac;
}
main()
{ return fac($0);
}
