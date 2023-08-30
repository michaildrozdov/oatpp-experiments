#ifndef DEPENDENCIES_CONTAINER_H_INCLUDED
#define DEPENDENCIES_CONTAINER_H_INCLUDED

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"

// For the poor man's dependency injection
struct DependenciesContainer
{
	std::shared_ptr<oatpp::network::ServerConnectionProvider> connectionProvider;
	std::shared_ptr<oatpp::data::mapping::ObjectMapper> objectMapper;
	std::shared_ptr<oatpp::web::server::HttpRouter> httpRouter;
	std::shared_ptr<oatpp::network::ConnectionHandler> connectionHandler;
};

#endif // DEPENDENCIES_CONTAINER_H_INCLUDED