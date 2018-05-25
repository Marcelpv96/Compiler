// test short-circuit evaluation, input $0==2 should not give div by zero
main()
{ if ($0 != 2 && $1 % ($0-2) != 0)
    return 1;
  else
    return 0;
}
