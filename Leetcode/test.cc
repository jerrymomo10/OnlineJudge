#include <string>
#include <iostream>
using namespace std;
class Solution{
public:
	const static string thou[];
	const static string hund[];
	const static string tens[];
	const static string ones[];
	
	string intToRoman(int num){
		string result;
		result += thou[(int)(num/1000)%10];
		result += hund[(int)(num/100)%10];
		result += tens[(int)(num/10)%10];
		result += ones[(int)(num%10)];
		return result;
		}
	};
const string Solution::thou[] = {"","M","MM","MMM"};
const string Solution::hund[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
const string Solution::tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
const string Solution::ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
int main(){
	auto s = new Solution();
	cout<<"The result is: "<<endl;
	cout<<s->intToRoman(3999)<<endl;
	return 0;
	}
