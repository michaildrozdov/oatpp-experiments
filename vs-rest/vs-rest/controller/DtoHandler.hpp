#ifndef DTO_HANDLER_H_INCLUDED
#define DTO_HANDLER_H_INCLUDED

#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "../dto/SingleStringDto.hpp"

class DtoHandler : public oatpp::web::server::HttpRequestHandler {
private:
	std::shared_ptr<oatpp::data::mapping::ObjectMapper> m_objectMapper;
public:
	/**
   * Constructor with object mapper.
   * @param objectMapper - object mapper used to serialize objects.
   */
	DtoHandler(const std::shared_ptr<oatpp::data::mapping::ObjectMapper>& objectMapper)
		: m_objectMapper(objectMapper)
	{}

	/**
   * Handle incoming request and return outgoing response.
   */
	std::shared_ptr<OutgoingResponse> handle(const std::shared_ptr<IncomingRequest>& request) override {
		auto message = SingleStringDto::createShared();
		message->statusCode = 1024;
		message->message = "Hello DTO!";
		return ResponseFactory::createResponse(Status::CODE_200, message, m_objectMapper);
	}
};
#endif // DTO_HANDLER_H_INCLUDED