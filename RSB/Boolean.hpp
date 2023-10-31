#ifndef BOOLEAN_HPP_
#define BOOLEAN_HPP_

#include <iostream>
#include <bitset>
#include <string>

// ex00
// time complexity is O(n)
// while loop
// uint32_t adder(uint32_t a, uint32_t b)
// {
//     uint32_t carry;

//     while (b != 0)
//     {
//         carry = a & b;
//         a = a ^ b;
//         b = carry << 1;
//     }
//     return a;
// }

// recursion
uint32_t adder(uint32_t a, uint32_t b)
{
    return b == 0 ? a : adder(a ^ b, (a & b) << 1);
}

// ex01
uint32_t multiplier(uint32_t a, uint32_t b)
{
    uint32_t result = 0;

    for (int i = 0; b != 0; b >>= 1, i++)
    {
        if (b & 1)
            result = adder(result, a << i);
    }

    return result;
}

// ex02
uint32_t gray_code(uint32_t n)
{
    return n ^ (n >> 1);
}

// ex03

// class AST
// {
//     char element;
//     AST* right;
//     AST* left;
// public:
//     AST()
//     :
//     {}
// };

// bool eval_formular(const std::string& formular)
// {

// }

#endif