p = 1;
n = $0;
m = $1;

while (m > 0)
{
  if (m % 2 == 1)
  { p *= n;
    m--;
  }
  else
  { n *= n;
    m >>= 1;
  }
}

return p;
