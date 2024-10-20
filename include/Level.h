#ifndef LEVEL_H
#define LEVEL_H

#include "Unit.h"

class Level : public Resource
{
public:
    // Constructors / Destructors
    Level();
    ~Level();

    // Methods
    void Serialize(std::ostream& _stream) override;
    void Deserialize(std::istream& _stream) override;
    void ToString() override;
    void AssignNonDefaultValues() override;

private:
    // Members
    int m_mapSizeX;
    int m_mapSizeY;
    float m_gameTime;
    vector<Unit*> m_units;
    // And other interesting level members
};

#endif // LEVEL_H
