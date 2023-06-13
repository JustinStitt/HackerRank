"""
NOTE AFTER SUBMITTING:

can just do `return n % 2 == 0` lol 😂
"""
ALICE = 0
BOB = 1


class Solution:
    def determineWinner(self, n: int) -> int:
        cache = dict()

        cache[(1, ALICE)] = BOB
        cache[(1, BOB)] = ALICE

        for i in range(2, n + 1):
            choices = [i - x for x in range(1, i) if i % x == 0]

            any_choice_has_alice_win = False
            any_choice_has_bob_win = False

            # print(f"{cache=} {choices=} {i=}")
            for choice in choices:
                if cache[(choice, BOB)] == ALICE:
                    any_choice_has_alice_win = True
                if cache[(choice, ALICE)] == BOB:
                    any_choice_has_bob_win = True

            cache[(i, ALICE)] = ALICE if any_choice_has_alice_win else BOB
            cache[(i, BOB)] = BOB if any_choice_has_bob_win else ALICE

        return cache[(n, ALICE)]

    def divisorGame(self, n: int) -> bool:
        return self.determineWinner(n) == ALICE


"""
Idea 1:

> make a `decision` tree that shows all possible outcomes.
    - alpha-beta pruning style

Idea 2:

> recursive backtracking algo, keep trying outcomes.
    - seems loose

Idea 3 (DP) most promising!:

> build up possibilities starting with simpler case; like n = 1, then n = 2, n = 3, etc.
    - DP

"""

"""
Notes:
> primality may matter, but can always choose x = 1 such that (n-1) is played.

>

"""
