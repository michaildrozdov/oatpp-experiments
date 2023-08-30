#include "MyServer.hpp"
#include "controller/MyController.hpp"
#include "oatpp/network/Server.hpp"

MyServer::MyServer(const DependenciesContainer& dependencies)
{
	m_dependencies = dependencies;

	auto myController = std::make_shared<MyController>(m_dependencies.objectMapper);
	m_dependencies.httpRouter->addController(myController);
}

void MyServer::run()
{
	/* Create server which takes provided TCP connections and passes them to HTTP connection handler */
	oatpp::network::Server server(m_dependencies.connectionProvider, m_dependencies.connectionHandler);

	/* Print info about server port */
	OATPP_LOGI("MyServer", "Server running on port %s", m_dependencies.connectionProvider->getProperty("port").getData());

	/* Run server */
	server.run();
}