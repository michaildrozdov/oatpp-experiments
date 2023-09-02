#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/network/Server.hpp"
#include "MyServer.hpp"
#include "AppComponent.hpp"

#pragma comment(lib,"WS2_32")

int main() {

	/* Init oatpp Environment */
	oatpp::base::Environment::init();

	/* AppComponent class implicitly creates all needed components to run the app*/
	AppComponent appComponents;
	MyServer server(appComponents.getAppDependencies());

	/* Run App */
	server.run();

	/* Destroy oatpp Environment */
	oatpp::base::Environment::destroy();

	return 0;
}

