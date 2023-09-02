#ifndef APP_COMPONENT_H_INCLUDED
#define APP_COMPONENT_H_INCLUDED

#include "oatpp/network/virtual_/client/ConnectionProvider.hpp"
#include "../src/DependenciesContainer.hpp"

class TestComponent
{
public:
	TestComponent();
	~TestComponent() = default;
	const DependenciesContainer &getAppDependencies() const;
	std::shared_ptr<oatpp::network::ClientConnectionProvider> getClientConnectionProvider() const;
private:
	DependenciesContainer m_createdDependencies;
	std::shared_ptr<oatpp::network::virtual_::Interface> m_virtualInterface;
	std::shared_ptr<oatpp::network::ClientConnectionProvider> m_clientConnectionProvider;
};


#endif // APP_COMPONENT_H_INCLUDED