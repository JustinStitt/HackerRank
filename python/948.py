# https://leetcode.com/problems/bag-of-tokens/?envType=daily-question&envId=2024-03-04
class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        score = 0
        tokens = sorted(tokens)

        while len(tokens):
            if power >= tokens[0]:
                score += 1
                power -= tokens[0]
                tokens.pop(0)
                continue

            elif score >= 1:
                new_power = power + tokens[-1]
                if tokens[0] <= new_power and len(tokens) > 1:
                    score -= 1
                    power = new_power
                    tokens.pop()
                    continue

            break

        return score
