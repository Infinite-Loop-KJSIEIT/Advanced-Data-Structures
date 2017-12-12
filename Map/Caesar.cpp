#include<iostream>
#include<map>
#include<string>

using namespace std;

std::map<char, int> C;
char *A;

void fetch(std::string&, int&);

int main()
{
	int I = 0;
	A = new char[26];
	for(char c = 'a'; c <= 'z'; c++) // Lower case words only.
	{
		A[I] = c;
		C[c] = I++;
	}
  do
  {
     std::string S;
     int o;
     std::cout << "Enter string:\n";
     cin >> S;
     std::cout << "Enter offest: ";
     cin >> o;
     std::cout << "Please make a choice:\n1. Encrypt\t2. Decrypt\t3. Exit\n";
     cin >> I;
     switch(I)
     {
      case 1:
        fetch(S, o);
        break;
      case 2:
        o *= -1;
        fetch(S, o);
        break;
      default:
        I = 3;
        break;
     }
  }while(I != 3);
  return(0);
}

void fetch(std::string &S, int &o)
{
	for(int i = 0; i < S.length(); i++)
	{
		int t = (C[S[i]] + o) % 26;
		t = (t < 0) ? (26 + t) : t; // Corrects negative offsets.
		S[i] = A[t];
	}
	std::cout << S << std::endl;
  }
