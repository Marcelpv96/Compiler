// GCD

a = $0;
b = $1;

while (b != 0)
{
  t = b;
  b = a % b;
  a = t;
}

return a;
