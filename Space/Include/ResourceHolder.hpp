#pragma once

#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>

#include "Enums.hpp"



template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
    ResourceHolder()
    {
        load(Textures::ID::Landscape, "Media/Textures/Desert.png");
        load(Textures::ID::Spaceship, "Media/Textures/Eagle.png");
    }

	void load(Identifier id, const std::string& filename);

	template <typename Parameter>
	void load(Identifier id, const std::string& filename, const Parameter& secondParam);

	Resource& get(Identifier id);
	const Resource& get(Identifier id) const;


private:
	void insertResource(Identifier id, std::unique_ptr<Resource> resource);


private:
	std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
};



#include "ResourceHolder.inl"
