class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        int total = 0;
        for (int x = 1; x < timeSeries.size(); ++x)
        {
            int diff = timeSeries[x] - timeSeries[x - 1];
            if (diff >= duration)
            {
                total += duration;
            }
            else
            {
                total += diff;
            }
        } // end for
        return total + duration;
    } // findPoisonedDuration(...)
};    // 1, 4

/*
d = 2
1 2 5 6 8 11


if difference between a[i] and a[i-1] is >= duration
then make new interval
*/