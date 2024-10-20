#include "../include/SoundEffect.h"
#include "../include/SpriteAnim.h"
#include "../include/SpriteSheet.h"
#include "../include/BasicStructs.h"

ObjectPool<SoundEffect>* SoundEffect::Pool = nullptr;

SoundEffect::SoundEffect()
{
    m_effect = nullptr;
}

SoundEffect::~SoundEffect()
{
}

void SoundEffect::AssignNonDefaultValues()
{
    m_effect = AssetController::Instance().GetAsset("assets/SoundEffect.wav");
    Resource::AssignNonDefaultValues();
}

void SoundEffect::Serialize(std::ostream& _stream)
{
    SerializeAsset(_stream, m_effect);
    Resource::Serialize(_stream);
}

void SoundEffect::Deserialize(std::istream& _stream)
{
    DeserializeAsset(_stream, m_effect);
    Resource::Deserialize(_stream);
}

void SoundEffect::ToString()
{
    cout << "SOUND EFFECT" << endl;
    m_effect->ToString();
    Resource::ToString();
}
