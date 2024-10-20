#include "../include/Texture.h"
#include "../include/SpriteAnim.h"
#include "../include/SpriteSheet.h"
#include "../include/BasicStructs.h"

ObjectPool<Texture>* Texture::Pool = nullptr;

Texture::Texture() 
{
    m_imageInfo = { };
    m_texture = nullptr;
}

Texture::~Texture() 
{
}

void Texture::Load(string _guid) 
{
    TGAReader r = TGAReader();
    m_texture = r.LoadTGAFromFile(_guid, &m_imageInfo);
}

void Texture::Serialize(std::ostream& _stream) 
{
    SerializeAsset(_stream, m_texture);
}

void Texture::Deserialize(std::istream& _stream) 
{
    TGAReader r = TGAReader();
    DeserializeAsset(_stream, m_texture);
    r.ProcessAsset(m_texture, &m_imageInfo);
}

void Texture::ToString() 
{
    cout << "TEXTURE" << endl;
    m_texture->ToString();
    Resource::ToString();
}
