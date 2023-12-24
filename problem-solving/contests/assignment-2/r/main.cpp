/*
101

- 2 ^ n - 1, I can create 2 ^ n - 1 out of two numbers whose sum is 2 ^ n - 1
- Any number xor itself is 0
- If you want to generate any number using another number
  - x ^ target = z
  - then x ^ z = target
- 0 xor any number is the number
- 1 xor any even number is number + 1
- 1 xor any odd number is number - 1
- 2 xor any even number is number + 2
- 2 xor any odd number is number - 2


- Identity requires 3 numbers (don't use 1 to 14 amd target)
- n % 3 == 1
  - If number == 0, put 4 ^ 5 ^ 6 ^ 7 instead of last identity
  - Identity, number
- n % 3 == 2
  - If number == 0, put 4 ^ 5 ^ 6 ^ 10 ^ 13 instead of last identity
  - Identity, x xor y for target
- n % 3 == 0
  - If number == 0, identities
  - Identity, x xor y for z, z xor w for target
*/

typedef unsigned int uint;
typedef unsigned long long ulong;

int main()
{
  return 0;
}
