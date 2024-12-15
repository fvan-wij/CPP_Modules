#pragma once

#include <stack>
#include <string>
#include <array>

class	RPN
{
	public:
		RPN();
		RPN(const std::string&	input);
		RPN(const RPN& rhs);
		RPN& operator=(const RPN& rhs);
		~RPN();

		int	getResult();

		enum OperandSide
		{
			RightHand,
			LeftHand
		};

	private:
		std::stack<int>		_rpnStack;
		int					_result;

		void 				_resolveCalculation(char rpnOperator);
		bool				_isOperand(const std::string& element);
		bool				_isOperator(const std::string& element);
		std::array<int, 2>	_getOperands(std::stack<int>& stack);
};
