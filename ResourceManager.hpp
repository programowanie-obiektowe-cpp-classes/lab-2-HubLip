#pragma once

#include "Resource.hpp"

class ResourceManager
{
private:
    Resource* resource;
public:

    ResourceManager()
    {
        resource = new Resource(); // ResourceManager tworzy obiekt Resource
    }

    ResourceManager(const ResourceManager&) = delete;
    Resource& operator=(const Resource&) = delete;

    double get (Resource& res)
    {
        return res.get();
    }

    ~ResourceManager() {
        delete resource;
    }
};
