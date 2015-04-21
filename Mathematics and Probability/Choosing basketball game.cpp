/*
  You have a basketball hoop and someone says that you can play one of two games.
  Game 1: You get one shot to make the hoop.
  Game 2: You get three shots and you have to make two of three shots.
  Ifp is the probability of making a particular shot, for which values ofp should you
  pick one game or the other?
*/

/*
Probability of winning Game 1:
The probability of winning Game 1 is p, by definition.

Probability of winning Game 2:
Let s(k,n) be the probability of making exactly k shots out of n. The probability of
winning Game 2 is the probability of making exactly two shots out of three OR making
all three shots. In other words:
P(winning) = s(2,3) + s(3,3)

The probability of making all three shots is:
s(3,3) = p^3

The probability of making exactly two shots is:
P(making 1 and 2, and missing 3)
+ P(making 1 and 3, and missing 2)
+ P(missing 1, and making 2 and 3)
= p * p * (1 - p)   +   p * (1 - p) * p   +   (1 - p) * p * p
= 3 (1 - p) p^2
Adding these together, we get:
= p^3 + 3 (1 - p) p^2
= p^3 + 3p^2 - 3p^3
= 3p^2 - 2p^3

Which game should you play?
You should play Game 1 if P(Game 1) > P(Game 2):
p > 3p^2 - 2p^3.
1 > 3p - 2p^2
2p^2 - 3p + 1 > 0
(2p - l)(p - 1) > 0

Both terms must be positive, or both must be negative. But we know p < 1, so p - 1
< 0.This means both terms must be negative.

2p - 1 < 0
2p < 1
p < .5

So, we should play Gamel if p < .5. 
If p = 0, 0.5, or 1, then P (Game 1) = P(Game 2), so it doesn't matter which game we play.

*/

