#pragma once

#include "Resource.hpp"

class ResourceManager
{
private:
    Resource* resource; //Wskaznik typu Resource o nazwie resource.
public:

    ResourceManager()
    {
        resource = new Resource(); // ResourceManager tworzy obiekt Resource
    }

    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;

    double get()
    {
        return resource -> get();
    }

    ~ResourceManager() {
        delete resource; //Usuwanie obiektu Resource
    }
};
