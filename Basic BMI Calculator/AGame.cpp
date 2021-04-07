#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <string>

double calculateBMI(int height, double weight);
void printResults(std::string name, std::string surname, int age, double weight, int height, std::string gender);
std::string end();

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
		Sleep(75);
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
		else if (bMI > 25 || bMI < 30)
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

int main()
{
	bool validity{ true };
	std::string choice{};
	while (validity)
	{
		std::cout << "Enter your name: ";
		std::string name{};
		std::getline(std::cin >> std::ws, name);

		std::cout << "Enter your surname: ";
		std::string surname{};
		std::getline(std::cin >> std::ws, surname);

		std::cout << "Enter your age: ";
		int age{};
		std::cin >> age;

		std::cout << "Enter your weight(kg): ";
		double weight{};
		std::cin >> weight;

		std::cout << "Enter your height(cm): ";
		double height{};
		std::cin >> height;

		std::cout << "Gender: ";
		std::string gender{};
		std::getline(std::cin >> std::ws, gender);

		printResults(name, surname, age, weight, height, gender);
		// for the loop
		choice = end();
		validity = (choice == "again");
	}

	return 0;
}