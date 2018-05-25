/*
 * Psuedo random number sequence
 *
 * Computes x = (7^5 * x) mod (2^31 - 1)
 * without overflowing 31 bits:
 *      (2^31 - 1) = 127773 * (7^5) + 2836
 * From "Random number generators: good ones are hard to find",
 * Park and Miller, Communications of the ACM, vol. 31, no. 10,
 * October 1988, p. 1195.
 *
 */
int seed;
int random(int seed)
{ int lo, hi, x;
  lo = seed % 127773;
  hi = seed / 127773;
  x = 16807 * lo - 2836 * hi;
  if (x <= 0)
    x += 0x7FFFFFFF;
  return x % 0x8FFFFFFF;
}
main()
{ seed = 282844563;
  return random(seed);
}
