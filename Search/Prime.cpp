#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

std::vector<int> P;

bool prime(int&);

int main()
{
	int T, I, max; // P and max are declared in an outer scope in order to minimize the time in building the vector again and again, for every iteration. We append the vector only when max is updated.
	I = 3;
	max = 2;
	std::cin >> T;
	while(T-- > 0)
	{
		int *a, m, n;
		m = 0;
		std::cin >> n;
		a = new int[n];
		for(int i = 0; i < n; i++)
		{
			std::cin >> a[i];
			m = (a[i] > m) ? a[i] : m;
		}
		if(m < 2)
			return(0); // Invalid input.
		if((m > max) && (m % 2 == 1))
			max = m;
		P.push_back(2);
		for(I; I <= max; I+=2)
		{
			if(prime(I))
				P.push_back(I);
		}
		
		for(int i = 0; i < n; i++)
		{
			std::vector<int>::iterator j = find(P.begin(), P.end(), a[i]);
			if(j != P.end())
				std::cout << a[i]  << " ";
		}
		std::cout << std::endl;
	}
}

bool prime(int &n)
{
	for(std::vector<int>::iterator i = P.begin(); i != P.end(); ++i) // Iterator implementation.
	{
		if(n % *i == 0)
			return(false);
	}
	return(true);
}
