#include "TestComponent.hpp"

#include "oatpp/web/server/HttpConnectionHandler.hpp"

#include "oatpp/network/virtual_/server/ConnectionProvider.hpp"
#include "oatpp/network/virtual_/Interface.hpp"

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include "oatpp/core/macro/component.hpp"

TestComponent::TestComponent()
{
	/**
   *  Create ConnectionProvider component which listens on the port
   */

	m_virtualInterface = oatpp::network::virtual_::Interface::obtainShared("virtualhost");

	m_createdDependencies.connectionProvider =
		oatpp::network::virtual_::server::ConnectionProvider::createShared(m_virtualInterface);

	/*
	* Create a client connection provider
	*/
	m_clientConnectionProvider =
		oatpp::network::virtual_::client::ConnectionProvider::createShared(m_virtualInterface);

	/**
	 *  Create Router component
	 */
	m_createdDependencies.httpRouter = oatpp::web::server::HttpRouter::createShared();

	/**
	 *  Create ConnectionHandler component which uses Router component to route requests
	 */
	m_createdDependencies.connectionHandler =
		oatpp::web::server::HttpConnectionHandler::createShared(m_createdDependencies.httpRouter);

	/**
	 *  Create ObjectMapper component to serialize/deserialize DTOs in Contoller's API
	 */
	m_createdDependencies.objectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();
}

const DependenciesContainer & TestComponent::getAppDependencies() const
{
	return m_createdDependencies;
}

std::shared_ptr<oatpp::network::ClientConnectionProvider>
	TestComponent::getClientConnectionProvider() const
{
	return m_clientConnectionProvider;
}