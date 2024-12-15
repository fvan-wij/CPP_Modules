#include "RPN.hpp"
#include <sstream>

RPN::RPN() : _result(0)
{

}

RPN::RPN(const std::string&	input) : _result(0)
{
	std::stringstream	ss(input);
	std::string			element;

	while (ss >> element)
	{
		if (_isOperand(element))
		{
			_rpnStack.push(std::stoi(element));
		}
		else if (_isOperator(element))
		{
			_resolveCalculation(element[0]);
		}
		else
		{
			throw std::invalid_argument("wrong input.");
		}
	}
	if (_rpnStack.size() == 1)
	{
		_result = _rpnStack.top();
	}
	else
	{
		throw std::invalid_argument("too many operands or missing operator.");
	}
}

RPN::RPN(const RPN& rhs)
{
	_rpnStack = rhs._rpnStack;
	_result = rhs._result;
}

RPN& RPN::operator=(const RPN& rhs)
{
	if (this == &rhs)
		return *this;

	_rpnStack = rhs._rpnStack;
	_result = rhs._result;

	return *this;
}

RPN::~RPN()
{

}

int	RPN::getResult()
{
	return _result;
}

bool	RPN::_isOperand(const std::string& element)
{
		return (std::isdigit(element[0]) && element.length() == 1);
}

bool	RPN::_isOperator(const std::string& element)
{
		return ((element[0] == '-' || element[0] == '+' || element[0] == '*' || element[0] == '/') && element.length() == 1);
}

std::array<int, 2>	RPN::_getOperands(std::stack<int>& stack)
{
	std::array<int, 2> operands;

	if (stack.size() < 2)
	{
		throw std::runtime_error("too few numbers in stack to resolve calculation.");
	}

	operands[OperandSide::RightHand] = stack.top();
	stack.pop();

	operands[OperandSide::LeftHand] = stack.top();
	stack.pop();

	return operands;
}

void	RPN::_resolveCalculation(char	rpnOperator)
{
	switch (rpnOperator)
	{
		case '+':
			{
				auto operands = _getOperands(_rpnStack);
				_rpnStack.push(operands[OperandSide::LeftHand] + operands[OperandSide::RightHand]);
			}
			break;
		case '-':
			{
				auto operands = _getOperands(_rpnStack);
				_rpnStack.push(operands[OperandSide::LeftHand] - operands[OperandSide::RightHand]);
			}
			break;
		case '*':
			{
				auto operands = _getOperands(_rpnStack);
				_rpnStack.push(operands[OperandSide::LeftHand] * operands[OperandSide::RightHand]);
			}
			break;
		case '/':
			{
				auto operands = _getOperands(_rpnStack);
				if (operands[OperandSide::RightHand] == 0)
				{
					throw std::runtime_error("division by zero.");
				}
				_rpnStack.push(operands[OperandSide::LeftHand] / operands[OperandSide::RightHand]);
			}
			break;
		default: 
			break;
	}
}
