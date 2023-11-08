#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file" << std::endl;
		exit(EXIT_FAILURE);
	}
	Bitcoin btc;
	btc.setDB("data.csv");
	btc.setFileName(argv[1]);
	btc.processData();

	//system("leaks btc");

	return 0;
}
