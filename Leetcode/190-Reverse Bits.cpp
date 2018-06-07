class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
		int i = 0;
		uint32_t result = 0;
		if (n == 0) return 0;
		while (i<32)
		{
			result += n % 2;
			i++;
			if (i < 32)
			{
				result = result << 1;
				n = n >> 1;
			}
			else break;
		}
		return result;
    }
};