#include <string>
#include <vector>
#include <iostream>

std::string getString(char x)
{
	std::string s(1, x);
	return s;
}

std::string add(const std::string& a, const std::string& b)
{
	std::vector<int> a_dig;
	std::vector<int> b_dig;
	std::vector<int> sum;
	for (char element : a)
	{
		a_dig.push_back(std::stoi(getString(element)));
	}
	for (char element : b)
	{
		b_dig.push_back(std::stoi(getString(element)));
	}
	int size1 = a_dig.size();
	int size2 = b_dig.size();

	if (size1 < size2)
	{
		int diff = size2 - size1;
		a_dig.insert(a_dig.begin(), diff, 0);
	}
	else if (size2 < size1) 
	{
		int diff = size1 - size2;
		b_dig.insert(b_dig.begin(), diff, 0);
	}

	for (int i = 0; i < a_dig.size(); ++i)
	{
		sum.push_back(a_dig[i] + b_dig[i]);
	}

	for (int i = sum.size() - 1; i > 0; --i)
	{
		if (sum[i] >= 10)
		{
			sum[i - 1] += 1;
			sum[i] -= 10;
		}
	}
	std::string output = "";
	for (int el : sum)
	{
		output += std::to_string(el);
	}
	return output;
}

bool areAllDigits(const std::string& str) 
{
	for (char c : str)
	{
		if (!std::isdigit(c))
		{
			return false;
		}
	}
	return true;
}

int main()
{
	std::string x, y;
	while (true)
	{
		std::cout << "Enter x: ";
		std::cin >> x;
		if (!areAllDigits(x))
		{
			std::cout << "Wrong input!\n";
			continue;
		}

		std::cout << "Enter y: ";
		std::cin >> y;
		if (!areAllDigits(y))
		{
			std::cout << "Wrong input!\n";
			continue;
		}
		
		std::cout << "Press Enter to compute the answer: ";
		std::cin.get();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
		std::cout << add(x, y) << "\n---------------------\n";
	}

	return 0;
}
