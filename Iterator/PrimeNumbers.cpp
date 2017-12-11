#include<iostream>
#include<vector>

using namespace std;

std::vector<int> P;

bool prime(int&);
void print();

int main()
{
	int max;
	std::cin >> max;
	if(max < 2)
		return(0); // Invalid input.
	P.push_back(2);
	for(int i = 3; i <= max; i+=2)
	{
		if(prime(i))
			P.push_back(i);
	}
	std::cout << "Prime numbers found up to " << max << ":\n";
	print();
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

void print()
{
	
	for(auto i = P.begin(); i != P.end(); ++i) // Auto data type assignment.
		std::cout << *i << "\t";
	std::cout << std::endl;
}
