#include <iostream>
#include <limits>
#include <string>
#include <iomanip>

void ignoreLine();
int getNumber();
void checkPrime(int num, bool prime);
bool end();

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool isPrime(int x)			//chek if number is prime
{
	int div{ 1 };
	for (int test{ 2 }; test <= x; ++test)
	{
		if (x % test == 0)
		{
			++div;
		}		
	}
	return (div == 2);
}

int getNumber()
{
	while (true)
	{
		std::cout << "Enter a number: ";
		int number{};
		std::cin >> number;
		if (std::cin.fail())
		{
			std::cin.clear();
			ignoreLine();
			std::cout << "Invalid input. Try again.\n";
		}
		else
		{
			ignoreLine();
			return number;
		}
	}
}

void checkPrime(int num, bool prime)
{
	if (prime)
	{
		std::cout << num << " is a prime number.\n";
	}
	else
	{
		std::cout << num << " is not a prime number.\n";
	}
}

bool end()
{
	std::cout << "\nEnter anything to terminate, again to restart.\n";
	std::string end_command{};
	std::getline(std::cin >> std::ws, end_command);
	std::cout << '\n';
	
	return ((end_command != "again") && (end_command != "Again"));
}

int main()
{
	while (true)
	{
		int num{ getNumber() };
		bool prime{ isPrime(num) };
		checkPrime(num, prime);

		if (end())
			break;
	}
	
	return 0;
}