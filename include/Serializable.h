#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include "StandardIncludes.h"

class Serializable
{
public:
    // Constructors/Destructors
    Serializable() {}
    virtual ~Serializable() {}

    // Methods
    virtual void Serialize(std::ostream& _stream) = 0;
    virtual void Deserialize(std::istream& _stream) = 0;
};

#endif // SERIALIZABLE_H
