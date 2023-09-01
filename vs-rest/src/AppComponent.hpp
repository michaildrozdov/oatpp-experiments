#ifndef APP_COMPONENT_H_INCLUDED
#define APP_COMPONENT_H_INCLUDED

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include "DependenciesContainer.hpp"

class AppComponent
{
public:
	AppComponent();
	~AppComponent() = default;
	const DependenciesContainer &getAppDependencies() const;
private:
	DependenciesContainer m_createdDependencies;
};


#endif // APP_COMPONENT_H_INCLUDED