/*
 * The Collatz conjecture is an unsolved conjecture in mathematics. It is named
 * after Lothar Collatz, who first proposed it in 1937. The conjecture is also
 * known as the 3n + 1 conjecture, the Ulam conjecture (after Stanislaw Ulam),
 * the Syracuse problem, as the hailstone sequence or hailstone numbers, or as
 * Wondrous numbers as per Godel, Escher, Bach. It asks whether a certain kind
 * of number sequence always ends in the same way, regardless of the starting
 * number.
 *
 * Paul Erdos said about the Collatz conjecture, "Mathematics is not yet ready
 * for such problems." He offered $500 for its solution.
 *
 * Consider the following operation on an arbitrary positive integer:
 * - If the number is even, divide it by two.
 * - If the number is odd, triple it and add one.
 *
 * The Collatz conjecture is: This process will eventually reach the number 1,
 * regardless of which positive integer is chosen initially.
 *
 * Given a positive input value, this program prints the number of steps to
 * reach 1.
 *
 * From: Wikipedia "http://en.wikipedia.org/wiki/Hailstone_number"
 */

n = $0;

for (steps = 0; n != 1; steps++)
{
  if (n % 2 == 0)
    n /= 2;
  else
    n = 3*n + 1;
}

return steps;
