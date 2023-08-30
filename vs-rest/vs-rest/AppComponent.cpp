#include "AppComponent.hpp"
#include "controller/MyController.hpp"

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

	auto myController = std::make_shared<MyController>(m_createdDependencies.objectMapper);
	m_createdDependencies.httpRouter->addController(myController);
}

const DependenciesContainer &AppComponent::getAppDependencies() const
{
	return m_createdDependencies;
}