#include <iostream>

int main()
{

	int a, x, n;
	std::cout << "This program computes a^x mod n " << std::endl;
	std::cout << "using the method of repeated squares" << std::endl;
	std::cout << "a x n" << std::endl;
	
	try {
		std::cin >> a >> x >> n;
		if(n==0)
			throw( (char*)"div by 0!");
		if(x<0 || a<0)
			throw ( (char*)"positives only pls!");
	}
	catch(char* e) {
		std::cout << e << "\nexiting.." << std::endl;
		return 1;
	}
	
	if(a<0)
		a *= -1;

	
	int tot, ans;
	tot = 0;
	ans = 1;
	
	while(tot<(x-1))	//don't overshoot
	{
		ans *= (a*a)%n;	//square and mult
		ans %= n;		//mod the ans
		tot += 2;
	}
	if(x-tot == 1)	//still 1 to go
	{
		ans *= a;
		ans %= n;
	}
	
	std::cout << ans << std::endl;
	
	return 0;
}
