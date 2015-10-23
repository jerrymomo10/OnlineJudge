#include <cstdio>
#include <climits>
#include <cstdlib>
class Solution{
public:
	int divide(int dividend,int divisor)
	{
		if(divisor==0)return INT_MAX;
		if(dividend==INT_MIN){
			if(divisor==-1) return INT_MAX;
			else if(divisor==1)  return dividend;
			else return ((divisor&1)==1)?divide(dividend+1,divisor):divide(dividend>>1,divisor>>1);
		} 
		if(divisor==INT_MIN) return 0;

		int sign = (dividend>0)^(divisor>0)?-1:1;
		unsigned abs_divided = abs(dividend);
		unsigned abs_divisor = abs(divisor);
		int result = 0;
		while(abs_divided>=abs_divisor)
		{
			long long temp = abs_divisor,mul = 1;
			while(abs_divided>=(temp<<1))
			{
				temp<<=1;
				mul<<=1;
			}
			abs_divided -= temp;
			result += mul;
		}
		return sign==1? result:-result;
	}
	};
int main()
{
	Solution s;
	printf("%d",s.divide(INT_MAX,1));
	return 0;
}
