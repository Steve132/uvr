#ifndef UVR_BASE_H
#define UVR_BASE_H

#include<vector>
#include<string>

namespace uvr
{

struct Matrix4x4d
{
public:
	double data[4][4];
};

struct dimensions_t
{
	unsigned int x;
	unsigned int y;
	dimensions_t(unsigned int tx=0,unsigned int ty=0):
		x(tx),y(ty)
	{}
};

class Viewport
{
public:
	dimensions_t offset;
	dimensions_t size;
	Viewport()
	{}
	virtual ~Viewport()
	{}
};

class Distortion
{
public:
	struct Coord
	{
		float u,v;
	};
	
	class Map
	{
	public:
		std::vector<Coord> data;
		dimensions_t size;
	};
	
	virtual Map computeMap(unsigned int width,unsigned int height=0) const;
	virtual Coord distort(float uin,float vin) const = 0;
	virtual ~Distortion()
	{}
};

class Eye
{
public:
	virtual Matrix4x4d getIntrinsicMatrix() const=0;
	virtual const Distortion& getDistortion() const=0;
	virtual const Viewport& getViewport() const=0;
	virtual ~Eye()
	{}
};

class Headset
{
public:
	const unsigned int num_eyes;
	virtual const Eye& getEye(unsigned int eye_id) const=0;
	virtual const Viewport& getViewport() const = 0;
	Headset(const unsigned int tnum_eyes):
		num_eyes(tnum_eyes)
	{}
};

class Backend
{
public:
	virtual const Headset& getHeadset()=0;
};

const std::vector<std::string>& listAvailableBackends(void* params);
Backend* constructBackend(const std::string&,void* params);

}

#endif