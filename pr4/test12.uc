// test local/global vars with type coercion
int n;
main()
{
  float p, m;
  p = 1.2;
  n = p;	// local float to global int
  m = n;	// global int to local float
  m = 1.0 + m;
  n = m;
  return n;
}
