#pragma once
#include <string>
#include <sstream>
using namespace std;
class Tuple
{
private:
	string paraOne;
	string paraTwo;
public:
	Tuple(string first, string second) : paraOne(first), paraTwo(second) {}
	string toString()
	{
		stringstream out;
		out << "(" << paraOne << ", " << paraTwo << ")";
		return out.str();
	}
};

