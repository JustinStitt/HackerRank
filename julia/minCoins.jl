
coins = [1,5,10,25]

function minCoinsRecursive(amnt)
    # recursive greedy approach
    if(amnt < 1)
        return 0
    end
    for coin in coins[end:-1:begin]
        if amnt - coin >= 0
            return 1 + minCoins(amnt - coin)
        end
    end
end

function minCoinsDP(amnt)
    dp = [Inf for _ in 1:amnt]
    dp[1] = 1 # to make 1 cent, use 1 coin.
    # bottom-up
    for n in 2:amnt
        for coin in coins
            # will using this coin reduce the
            #number of coins used?
            if n - coin <= 0 break end
                dp[n] = min(dp[n], dp[n-coin] + 1)
        end
    end
    return dp[amnt] |> Int
end
