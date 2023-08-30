#include "AppComponent.hpp"
#include "controller/DtoHandler.hpp"

AppComponent::AppComponent()
{
	/**
   *  Create ConnectionProvider component which listens on the port
   */
	m_createdDependencies.connectionProvider =
		oatpp::network::tcp::server::ConnectionProvider::createShared({ "localhost", 8000, oatpp::network::Address::IP_4 });

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

	m_createdDependencies.httpRouter->route("GET", "/hello", std::make_shared<DtoHandler>(m_createdDependencies.objectMapper));
}

const DependenciesContainer &AppComponent::getAppDependencies() const
{
	return m_createdDependencies;
}