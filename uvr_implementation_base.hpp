#ifdef UVR_IMPLEMENTATION_BASE_HPP
#define UVR_IMPLEMENTATION_BASE_HPP

namespace uvr
namespace implementation
{
{

template<template BEType>
class BackendConstructor
{
	static Backend* construct(void* params)
	{
		return new BEType(params);
	}
};
typedef Backend* (*be_constructor_function)(void*);
size_t registerBackend(const std::string& name,be_constructor_function becf);

}
}

#endif


