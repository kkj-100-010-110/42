#include "Span.hpp"

#define LINE "-------------------------------------------------" 

void    test1_NormalCase(void);
void    test2_MoreElements(void);
void    test3_OutOfCapacity(void);
void    test4_NotEnoughElement(void);
void    test5_addRange(void);

int main(void)
{
    std::cout << LINE << std::endl;
    test1_NormalCase();
    std::cout << LINE << std::endl;
    test2_MoreElements();
    std::cout << LINE << std::endl;
    test3_OutOfCapacity();
    std::cout << LINE << std::endl;
    test4_NotEnoughElement();
    std::cout << LINE << std::endl;
    test5_addRange();
    return (0);
}

void    test1_NormalCase(void)
{
    std::cout <<  "(case1: nomal operation)" <<  std::endl;
    Span    sp = Span(5);
    Span    copy = Span(5);

    sp.addNumber(5);
    sp.addNumber(2);
    sp.addNumber(8);
    sp.addNumber(3);
    sp.addNumber(12);
    copy = sp;
    std::cout << "shortestSpan: " << copy.shortestSpan() << std::endl;
    std::cout << "longestSpan : " << copy.longestSpan() << std::endl;
}

void    test2_MoreElements(void)
{
    std::cout <<  "(case2: more elements)" <<  std::endl;
    Span    sp = Span(10000);
    
    for (int i = 5000; i < 10000; i++)
        sp.addNumber(i);
    for (int i = 0; i < 5000; i++)
        sp.addNumber(i);
	std::cout << "max: " << *std::max_element(sp.getContainer().begin(), sp.getContainer().end()) << "\n";
	std::cout << "min: " << *std::min_element(sp.getContainer().begin(), sp.getContainer().end()) << "\n";
    std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
    std::cout << "longestSpan : " << sp.longestSpan() << std::endl;
}

void    test3_OutOfCapacity(void)
{
    std::cout <<  "(case3: out of capacity)" <<  std::endl;
    Span    sp = Span(10);

    srand(time(NULL));
    for (int i = 0; i < 10; i++)
        sp.addNumber(rand() % 10);
    try
    {
        sp.addNumber(42);
    }
    catch(const std::exception& e)
	{
		std::cerr <<  e.what() <<  "\n";
	}
}

void    test4_NotEnoughElement(void)
{
    std::cout <<  "(case4: not enough element)" <<  std::endl;
    Span    sp = Span(1);

    sp.addNumber(42);
    try
    {
        sp.shortestSpan();
    }
    catch(const std::exception& e)
	{
		std::cerr <<  e.what() <<  "\n";
	}
    try
    {
        sp.longestSpan();
    }
    catch(const std::exception& e)
	{
		std::cerr <<  e.what() <<  "\n";
	}
}

void    test5_addRange(void)
{
    std::cout <<  "(case5: add by range)" <<  std::endl;
	std::vector<int> v(10, 5);
    Span sp(11);
	sp.addNumber(3);
	std::cout << "Span size: " << sp.getContainer().size() << "\n";

    try
    {
		sp.addRange(std::begin(v), std::end(v));
		std::cout << "Span size: " << sp.getContainer().size() << "\n";
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan : " << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr <<  e.what() <<  "\n";
    }

}
