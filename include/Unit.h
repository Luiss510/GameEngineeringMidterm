#ifndef UNIT_H
#define UNIT_H

#include "Resource.h"
#include "SoundEffect.h"

class Unit : public Resource
{
public:
    // Constructors/Destructors
    Unit();
    virtual ~Unit();

    // Methods
    void Serialize(std::ostream& _stream) override;
    void Deserialize(std::istream& _stream) override;
    void ToString() override;
    void AssignNonDefaultValues() override;

    // Members
    static ObjectPool<Unit>* Pool;

private:
    // Members
    SoundEffect* m_soundEffect;
};

#endif // UNIT_H
