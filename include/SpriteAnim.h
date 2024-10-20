#ifndef SPRITEANIM_H
#define SPRITEANIM_H

#include "Resource.h"

class SpriteAnim : Resource
{
public:
    float m_ClipCurrent;  // This is the declaration of m_ClipCurrent
    //float m_clipCurrent;
    // Constructors/Destructors
    SpriteAnim();
    virtual ~SpriteAnim();

    // Accessors
    short GetClipCurrent() { return (short)m_ClipCurrent; }

    // Methods
    virtual void Serialize(std::ostream& _stream);
    virtual void Deserialize(std::istream& _stream);
    virtual void ToString();

    void ClearMemory();
    void Create(short _clipStart, short _clipCount, float _clipSpeed);
    void Update();

    // Members
    static ObjectPool<SpriteAnim>* Pool;

private:
    // Members
    short m_clipStart;
    short m_clipCount;
    short m_clipEnd;
    float m_clipSpeed;
};

#endif // SPRITEANIM_H
