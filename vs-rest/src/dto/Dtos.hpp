#ifndef DTOS_H_INCLUDED
#define DTOS_H_INCLUDED

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

/* Begin DTO code-generation */
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * Message Data-Transfer-Object
 */
class SingleStringDto : public oatpp::DTO {

	DTO_INIT(SingleStringDto, DTO /* Extends */);

	DTO_FIELD(Int32, statusCode);   // Status code field
	DTO_FIELD(String, message);     // Message field

};

/* End DTO code-generation */
#include OATPP_CODEGEN_END(DTO)

#endif // DTOS_H_INCLUDED