#ifndef MY_SERVER_H_INCLUDED
#define MY_SERVER_H_INCLUDED

#include "DependenciesContainer.hpp"

class MyServer
{
public:
	MyServer(const DependenciesContainer& dependencies);
	~MyServer() = default;
	void run();
private:
	DependenciesContainer m_dependencies;
};

#endif // MY_SERVER_H_INCLUDED