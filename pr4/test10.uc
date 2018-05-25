// test || and if
main()
{ int i, j;
  i = $0;
  j = $1;
  if (i != 0 || j != 0)
    i = 2;
  else
    j = 4;
  return i + j;
}
