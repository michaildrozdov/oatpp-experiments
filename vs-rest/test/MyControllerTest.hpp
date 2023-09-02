#ifndef MY_CONTROLLER_TEST_H_INCLUDED
#define MY_CONTROLLER_TEST_H_INCLUDED

#include "oatpp-test/UnitTest.hpp"

class MyControllerTest : public oatpp::test::UnitTest {
public:

	MyControllerTest() : UnitTest("TEST[MyControllerTest]" /* Test TAG for logs */) {}
	void onRun() override;

};

#endif // MY_CONTROLLER_TEST_H_INCLUDED
