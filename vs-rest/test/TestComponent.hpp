#ifndef APP_COMPONENT_H_INCLUDED
#define APP_COMPONENT_H_INCLUDED

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include "../src/DependenciesContainer.hpp"

class TestComponent
{
public:
	TestComponent();
	~TestComponent() = default;
	const DependenciesContainer &getAppDependencies() const;
private:
	DependenciesContainer m_createdDependencies;
};


#endif // APP_COMPONENT_H_INCLUDED