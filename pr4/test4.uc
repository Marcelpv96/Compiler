// test global variables and functions
int counter;
int add(int val)
{ return counter += val;
}
main()
{ add(2);
  return add(-1);
}
