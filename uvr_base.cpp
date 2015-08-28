#include<uvr_base.hpp>
#include<map>
namespace uvr
{



namespace 
{
class BackendRegistry
{

public:
	std::map<std::string,be_constructor_function> reg;
	BackendRegistry()
	{}
	~BackendRegistry()
	{}
	
	static BackendRegistry& getInstance()
	{
		static BackendRegistry brinst;
		return brinst;
	}
	void registerBackend(const std::string& name,be_constructor_function bcf)
	{
		reg[name]=bcf;
	}
};

}

namespace implementation
{
unsigned int namehash(const std::string& name)
{
	size_t ho=0;
	for(int i=0;i<name.size();i++)
	{
		ho <<=5;
		int n=name[i];
		ho+=(n & 0x1F);
		ho^= ((n >> 5) & 1) ? 0xFFFFFFFF : 0x00FF00FF;
	}
}
unsigned int registerBackend(const std::string& name,be_constructor_function bcf)
{
	BackendRegistry::getInstance().registerBackend(name,bcf);
	return namehash(name);
}

}










const std::vector<std::string>& listAvailableBackends(void* params);
Backend* constructBackend(const std::string&,void* params);





}