
void towers_of_hanoi(int n, Pole start, Pole goal, Pole temp)
{
  if (n == 0) return;                       // base case
  towers_of_hanoi(n-1, start, temp, goal);  // Recursive call: n-1 rings
  move(start, goal);                        // Move bottom disk to goal
  towers_of_hanoi(n-1, temp, goal, start);  // Recursive call, n-1 rings
}