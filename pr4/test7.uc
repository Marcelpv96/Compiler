/* count the bits */
int bitcount(int n)
{ int i, s;
  s = 0;
  for (i = 0; i < 32; i++)
  { s += n & 1;
    n >>= 1;
  }
  return s;
}
main()
{ int s;
  s = bitcount($0);
  return s;
}
