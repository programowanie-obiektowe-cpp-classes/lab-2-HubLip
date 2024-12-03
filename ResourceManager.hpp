#pragma once

#include "Resource.hpp"

class ResourceManager {
private:
    Resource* resource; // Wskaźnik do zarządzanego obiektu Resource

public:
    // Konstruktor domyślny
    ResourceManager() : resource(new Resource()) {}

    // Konstruktor kopiujący
    ResourceManager(const ResourceManager& res) 
        : resource(new Resource(*res.resource)) {} // Tworzymy nowy obiekt Resource jako kopię

    // Operator przypisania kopiujący
    ResourceManager& operator=(const ResourceManager& res) {
        if (this == &res) { // Zabezpieczenie przed samoprzydziałem
            return *this;
        }

        // Usuwamy aktualny zasób
        delete resource;

        // Tworzymy nową kopię zasobu
        resource = new Resource(*res.resource);

        return *this;
    }

    // Konstruktor przenoszący
    ResourceManager(ResourceManager&& res) noexcept 
        : resource(res.resource) { // Przenosimy wskaźnik
        res.resource = nullptr;   // Ustawiamy wskaźnik źródła na nullptr
    }

    // Operator przypisania przenoszący
    ResourceManager& operator=(ResourceManager&& res) noexcept {
        if (this == &res) { // Zabezpieczenie przed samoprzydziałem
            return *this;
        }

        // Usuwamy aktualny zasób
        delete resource;

        // Przenosimy wskaźnik
        resource = res.resource;
        res.resource = nullptr; // Ustawiamy wskaźnik źródła na nullptr

        return *this;
    }

    // Metoda get, która deleguje wywołanie do zarządzanego obiektu Resource
    double get() {
        return resource->get();
    }

    // Destruktor
    ~ResourceManager() {
        delete resource; // Zwolnienie zarządzanego zasobu
    }
};
