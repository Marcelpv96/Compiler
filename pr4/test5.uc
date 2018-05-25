// test integers + floats
main()
{ float p;
  int n, m;
  p = 1.0;
  n = $0;
  m = $1;
  while (m > 0)
  { if (m % 2 == 1)
    { p *= n;
      m--;
    }
    else
    { n *= n;
      m >>= 1;
    }
  }
  n = p;
  return n;
}
