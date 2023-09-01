#ifndef BASIC_HANDLER_H_INCLUDED
#define BASIC_HANDLER_H_INCLUDED

#include "oatpp/web/server/HttpConnectionHandler.hpp"
/**
 * Custom Request Handler
 */
class BasicHandler : public oatpp::web::server::HttpRequestHandler {
public:

	/**
	 * Handle incoming request and return outgoing response.
	 */
	std::shared_ptr<OutgoingResponse> handle(const std::shared_ptr<IncomingRequest>& request) override {
		return ResponseFactory::createResponse(Status::CODE_200, "Hello World!");
	}

};

#endif // BASIC_HANDLER_H_INCLUDED
