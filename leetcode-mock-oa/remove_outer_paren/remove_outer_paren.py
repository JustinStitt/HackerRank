class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        assert s[0] == "(", "Invalid starting parenthesis"
        assert s[-1] == ")", "Invalid ending parenthesis"
        primitives = []

        num_open, num_closed = 0, 0
        last_primitive_idx = 0

        for i, c in enumerate(s):
            if c == "(":
                num_open += 1
            elif c == ")":
                num_closed += 1

            if num_open == num_closed:  # we have a primitive
                primitives.append(s[last_primitive_idx : i + 1])
                last_primitive_idx = i + 1

        assert len(primitives), "At least one primitive is required"

        # removing `outer parenthesis` just means deleting 0 and -1 indices

        deshelled = [prim[1:-1] for prim in primitives]

        return "".join([x for x in deshelled])
