#ifndef UVR_IMPLEMENTATION_BASE_HPP
#define UVR_IMPLEMENTATION_BASE_HPP

#include "uvr_base.hpp"

namespace uvr
{
namespace implementation
{
	
template<class BEType>
class BackendConstructor
{
	static Backend* construct(void* params)
	{
		return new BEType(params);
	}
};

typedef Backend* (*be_constructor_function)(void*);
unsigned int registerBackend(const std::string& name,uvr::implementation::be_constructor_function becf);

}
}

#endif


