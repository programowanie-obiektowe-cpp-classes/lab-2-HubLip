#pragma once

#include "Resource.hpp"

class ResourceManager
{
private:
    Resource *resource; //Wskaznik typu Resource o nazwie resource.
public:

    ResourceManager()
    {
        resource = new Resource(); // ResourceManager tworzy obiekt Resource
    }

    //Poprawne kopiowanie czyli przy kopiowaniu ResourceManager, nowy obiekt ma miec swoja wlasna kopie obiektu Resource
    ResourceManager(const ResourceManager& res)
    {
        resource = new Resource(*res.resource); //uzywamy *res poniewaz chcemy skopiowac sam obiekt a nie adres na jaki wskaznik wskazuje
    }

    ResourceManager& operator=(const ResourceManager& res)
    {
        if (this == &res) //&res zwraca adres res, samo res jest referencja do obiektu typu ResourceManager zatem aby odniesc sie do adresu trzeba uzyc &res (& to operator adresu).
        {
            return *this;
        }

        delete resource;

        resource = new Resource(*res.resource);

        return *this;
    }

    double get()
    {
        return resource -> get();
    }

    ~ResourceManager() {
        delete resource; //Usuwanie obiektu Resource
    }
};
