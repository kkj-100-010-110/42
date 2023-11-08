#include <iostream>
#include <cctype>
#include <string>

int main(int argc, char **argv)
{
	std::string result = "";

	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j]; j++)
				//char(std::toupper(argv[i][j]));
				result += static_cast<char>(std::toupper(argv[i][j]));
		}
		std::cout << result;
		result = "";
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;

	return 0;
}
