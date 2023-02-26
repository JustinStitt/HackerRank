# def s(l):
#     return "{:.10f}".format(
#         sum(
#             [
#                 min(abs(u - v), u + 27 - v + 1, 27 - u + v + 1) * 0.4487989505128 + 1
#                 for (u, v) in zip(l, l[1:])
#             ]
#         )
#         + 1
#     )

# s = lambda l: "{:.10f}".format(
#     sum(
#         [
#             min(abs(u - v), u + 28 - v, 28 - u + v) * 0.4487989505128 + 1
#             for (u, v) in zip(l, l[1:])
#         ]
#     )
#     + 1
# )

# [
#     print(s([ord(c) for c in input().replace(" ", "[").replace("'", "\\")]))
#     for _ in range(int(input()))
# ]

list(
    map(
        lambda l: print(
            "{:.10f}".format(
                sum(
                    [
                        min(abs(u - v), u + 28 - v, 28 - u + v) * 0.4487989505128 + 1
                        for (u, v) in zip(l, l[1:])
                    ]
                )
                + 1
            )
        ),
        [
            [ord(c) for c in input().replace(" ", "[").replace("'", "\\")]
            for _ in range(int(input()))
        ],
    )
)

# [
#     print(
#         "{:.10f}".format(
#             sum(
#                 [
#                     min(abs(u - v), u + 27 - v + 1, 27 - u + v + 1) * 0.4487989505128
#                     + 1
#                     for (u, v) in zip(k, k[1:])
#                 ]
#             )
#             + 1
#         )
#         for k in (list(ord(c) for c in input().replace(" ", "[").replace("'", "\\")))
#     )
#     for _ in range(int(input()))
# ]
