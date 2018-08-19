class Solution {
public:
    int* bestSolution;

    int integerBreak(int n) {
    bestSolution = new int[1000000];
	memset(bestSolution, 0, 1000000);
	// Compute some value in advance
	bestSolution[1] = 1;
	bestSolution[2] = 2;
	bestSolution[3] = 3;
	bestSolution[4] = 4;
	bestSolution[5] = 6;
        
        	if (n == 2)
		return 1;
	else if (n == 3)
		return 2;
	else if (n == 4)
		return 4;
    return findSolution(n);
    }
    
    int findSolution(int N)
{
	int maxValue = 0;
	if (bestSolution[N] != 0)
		return bestSolution[N];
	for (int i = 2; i < N / 2 + 1; i++)
	{
		int tmp = findSolution(i) * findSolution( N - i);
		if (tmp > maxValue)
			maxValue = tmp;
	}
    bestSolution[N] = maxValue;
	return maxValue;
}
    
    
    
    
    
};