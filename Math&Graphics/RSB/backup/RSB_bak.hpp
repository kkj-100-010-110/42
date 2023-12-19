#pragma once

#include "Parse_bak.hpp"

namespace RSB
{
	// ex00
	uint32_t adder(uint32_t a, uint32_t b);

	// ex01
	uint32_t multiplier(uint32_t a, uint32_t b);

	// ex02
	uint32_t gray_code(uint32_t n);

	// ex03
	bool eval_formula(const std::string &formula);

	// ex04
	void print_truth_table(const std::string &formula);

	// ex05
	std::string negation_normal_form(const std::string &formula);
}