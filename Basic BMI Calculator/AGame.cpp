#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#define NOMINMAX
#include <Windows.h>

double calculateBMI(int height, double weight);
void printResults(std::string name, std::string surname, int age, double weight, int height, std::string gender);
std::string end();
void ignoreLine();
int ageFunc();
double weightFunc();
double heightFunc();
std::string fullName();
std::string genderFunc();

double calculateBMI(int height, double weight)
{
	//*10000 for printing the result in decimals
	double body_mass_index{(weight * 10000) / (height * height )};
	return body_mass_index;
}

void printResults(std::string name, std::string surname, int age, double weight, int height, std::string gender)
{
	std::cout << "\nFull name: " << name << " " << surname << '\n';
	Sleep(300);
	std::cout << "Age: " << age << '\n';
	Sleep(300);
	std::cout << "Height: " << height << "cm" << '\n';
	Sleep(300);
	std::cout << "Weight: " << weight << "kg" << '\n';
	Sleep(300);
	std::cout << "Gender: " << gender << "\n\n";
	Sleep(300);
	std::string cosmetics{ "Calculating body mass index...\n" };
	for (char& c : cosmetics)
	{
		std::cout << c;
		Sleep(50);
	}
	{
		std::cout << std::setprecision(3);
		double bMI{ calculateBMI(height, weight) };
		std::cout << "\nYour body mass index is: " << bMI << " ";

		if ((bMI < 25) && (bMI > 18.5))
		{
			std::cout << "(NORMAL WEIGHT)\n";
		}
		else if (bMI < 18.5)
		{
			std::cout << "(UNDER WEIGHT)\n";
		}
		else if ((bMI > 25) && (bMI < 30))
		{
			std::cout << "(OVER WEIGHT)\n";
		}
		else if (bMI > 30)
		{
			std::cout << "(OBESE)\n";
		}
	}
}

std::string end()
{
	std::cout << "\nEnter anything to terminate, 'again' to restart the program.\n";
	std::string end{};
	std::getline(std::cin >> std::ws, end);
	std::cout << '\n';
	return end;
}

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int ageFunc()
{
	while (true)
	{
		int func_age{};
		std::cout << "Enter your age: ";
		std::cin >> func_age;
		if (std::cin.fail())
		{
			std::cin.clear();
			ignoreLine();
			std::cout << "Invalid input. Try again.\n";
		}
		else
		{
			ignoreLine();
			return func_age;
		}	
	}
}

double weightFunc()
{
	while (true)
	{
		std::cout << "Enter your weight(kg): ";
		double func_weight{};
		std::cin >> func_weight;
		
		if (std::cin.fail())
		{
			std::cin.clear();
			ignoreLine();
			std::cout << "Invalid input. Try again.\n";
		}
		else if (func_weight == 0.0)
		{
			std::cerr << "Error: 0.0 entered.\n";
			ignoreLine();
		}
		else
		{
			ignoreLine();
			return func_weight;
		}
	}
}


double heightFunc()
{
	while (true)
	{
		std::cout << "Enter your height(cm): ";
		double func_height{};
		std::cin >> func_height;
		
		if (std::cin.fail())
		{
			std::cin.clear();
			ignoreLine();
			std::cout << "Invalid input. Try again.\n";
		}
		else if (func_height == 0.0)
		{
			std::cerr << "Error: 0.0 entered.\n";
			ignoreLine();
		}
		else
		{
			ignoreLine();
			return func_height;
		}
	}
}

std::string fullName()
/* This function asks and returns name the first time it is called,
	surname the second time it is called. After surname is entered,
	the s_count is reverted to 1 to make function re-usable.*/
{
	for (static int s_count{ 1 }; s_count <= 2; )
	{
		if (s_count == 1)									//ask and return name
		{
			std::cout << "Enter your name: ";
			std::string name_func{};
			std::getline(std::cin >> std::ws, name_func);
			++s_count;										//add 1 to s_count for second call
			return name_func;
		}
		else if (s_count == 2)								//ask and return surname
		{
			std::cout << "Enter your surname: ";
			std::string surname_func{};
			std::getline(std::cin >> std::ws, surname_func);
			--s_count;										//revert s_count to 1
			return surname_func;
		}
	}
}

std::string genderFunc()
{
	while (true)
	{
		std::cout << "Gender: ";
		std::string gender_func{};
		std::getline(std::cin >> std::ws, gender_func);
		
		if (gender_func == "Male" || gender_func == "male" || gender_func == "Man" || gender_func == "man" ||
			gender_func == "Female" || gender_func == "female" || gender_func == "Woman" || gender_func == "woman")
		{
			return gender_func;
		}
		else
			std::cout << "Ooops! Try again.\n";
	}
}

int main()
{
	while (true)
	{
		std::string name{ fullName() };
		std::string surname{ fullName() };
		int age{ ageFunc() };
		double weight{ weightFunc() };
		double height{ heightFunc() };
		std::string gender{ genderFunc() };

		printResults(name, surname, age, weight, height, gender);
	
		std::string choice{ end() };												// for the loop
		if ((choice != "again") && (choice != "Again"))
			break;
	}

	return 0;
}