#ifndef MY_CONTROLLER_H_INCLUDED
#define MY_CONTROLLER_H_INCLUDED

#include "../dto/Dtos.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin Codegen

/**
 * Sample Api Controller.
 */
class MyController : public oatpp::web::server::api::ApiController {
public:
	/**
	 * Constructor with object mapper.
	 * @param objectMapper - default object mapper used to serialize/deserialize DTOs.
	 */
	MyController(std::shared_ptr<ObjectMapper> objectMapper)
		: oatpp::web::server::api::ApiController(objectMapper)
	{}

public:

	ENDPOINT("GET", "/hello", root) {
		auto dto = SingleStringDto::createShared();
		dto->statusCode = 200;
		dto->message = "Hello World!";
		return createDtoResponse(Status::CODE_200, dto);
	}
};

#include OATPP_CODEGEN_END(ApiController) ///< End Codegen

#endif // MY_CONTROLLER_H_INCLUDED