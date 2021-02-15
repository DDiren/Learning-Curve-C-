#include "constants.h" // namespace for gravity constant
#include <iostream>

// function prototypes
bool askWhatToDo();
double ballDrop(double seconds);
double enterHeight();
double enterSeconds();
void calculateSpecificHeight(double second, double height);
void calculateHeight(int seconds, double height);
void showFiveSeconds();
void showSpecificSecond();
void end();

bool askWhatToDo()
{
	std::cout << "Calculate all 5 seconds(Y) or calculate a specific second(N)?: ";
	char answer{};
	std::cin >> answer;

	if (answer == 'y') // Make sure that the answer is either 'y', 'Y', 'n' or 'N'.
		return true;
	else if (answer == 'Y')
		return true;
	else if (answer == 'n')
		return false;
	else if (answer == 'N')
		return false;
	else
		std::cout << "\nError: Enter \'y\', \'Y\', \'n\' or \'N\' only.\n\n";
}


double ballDrop(double seconds) // Calculates the distance fallen after each second
{
	double fallDistance{ constants::gravity * (seconds * seconds) / 2 };
	return fallDistance;
}

double enterHeight() // Get the height of the tower from the user
{
	std::cout << "Enter the height of the tower in meters: ";
	double height{};
	std::cin >> height;

	return height;
}

double enterSeconds() // Get the specific seconds from the user
{
	std::cout << "Enter the specific second: ";
	double specificsecond{};
	std::cin >> specificsecond;

	return specificsecond;
}

void calculateSpecificHeight(double second, double height) // calculates the height of the ball at specific second
{
	double result{ height - ballDrop(second) };

	if (result <= 0)
		std::cout << "At " << second << " seconds, the ball is on the ground.\n";
	else
		std::cout << "At " << second << " seconds, the ball is at height: " << result << " meters." << '\n';
}

void calculateHeight(int seconds, double height) // Subtracts fallen distance from tower height
{
	double result{ height - ballDrop(seconds) };

	if (result <= 0) // declare the ball on ground if number is equeal or below zero 
		std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
	else
		std::cout << "At " << seconds << " seconds, the ball is at height: " << result << " meters." << '\n';
}

void showFiveSeconds() // if first input is 'y', this function executes
{
	const double currentHeight{ enterHeight() };

	if (currentHeight > 0)
	{
		calculateHeight(0, currentHeight);
		calculateHeight(1, currentHeight);
		calculateHeight(2, currentHeight);
		calculateHeight(3, currentHeight);
		calculateHeight(4, currentHeight);
		calculateHeight(5, currentHeight);
	}
	else
		std::cout << "\nError: Please enter a floating number over 0 ONLY!\n\n";
}

void showSpecificSecond() // if first input is 'n', this function executes
{
	const double currentHeight{ enterHeight() };
	const double specificSecond{ enterSeconds() };

	if (currentHeight, specificSecond > 0)
		calculateSpecificHeight(specificSecond, currentHeight);
	else
		std::cout << "\n\nError: Please enter a floating number over 0 ONLY!\n\n";
}

void end()
{
	std::cout << "\nEnter anything to continue.\n\n";
	int x{};
	std::cin >> x;
}

int main()
{
	bool answer{ askWhatToDo() };

	if (answer == true)
	{
		showFiveSeconds();
		end();
	}
	else if (answer == false)
	{
		showSpecificSecond();
		end();
	}
	else
	{
		end();
		return 0;
	}
}