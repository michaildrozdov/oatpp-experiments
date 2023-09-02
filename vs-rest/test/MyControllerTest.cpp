#include "MyControllerTest.hpp"

#include "../src/controller/MyController.hpp"

#include "MyApiTestClient.hpp"
#include "TestComponent.hpp"

#include "oatpp/web/client/HttpRequestExecutor.hpp"

#include "oatpp-test/web/ClientServerTestRunner.hpp"

void MyControllerTest::onRun() {

	/* Register test components */
	TestComponent testComponent;
	
	/* Create client-server test runner */
	oatpp::test::web::ClientServerTestRunner runner;

	/* Add MyController endpoints to the router of the test server */
	runner.addController(std::make_shared<MyController>(testComponent.getAppDependencies().objectMapper));

	/* Run test */
	runner.run([this, &runner, &testComponent] {

		auto createdDependencies = testComponent.getAppDependencies();

		/* Create http request executor for Api Client */
		auto requestExecutor = oatpp::web::client::HttpRequestExecutor::createShared(
			testComponent.getClientConnectionProvider());

		/* Create Test API client */
		auto client = MyApiTestClient::createShared(requestExecutor, createdDependencies.objectMapper);

		/* Call server API */
		/* Call hello endpoint of MyController */
		auto response = client->getHello();

		/* Assert that server responds with 200 */
		OATPP_ASSERT(response->getStatusCode() == 200);

		/* Read response body as MessageDto */
		auto message = response->readBodyToDto<oatpp::Object<SingleStringDto>>(
			createdDependencies.objectMapper.get());

		/* Assert that received message is as expected */
		OATPP_ASSERT(message);
		//OATPP_ASSERT(message->statusCode->getValue() == 200);
		//OATPP_ASSERT(message->message == "Hello World!");

		}, std::chrono::minutes(10) /* test timeout */);

	/* wait all server threads finished */
	std::this_thread::sleep_for(std::chrono::seconds(1));

}
