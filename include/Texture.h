#ifndef TEXTURE_H
#define TEXTURE_H

#include "Resource.h"
#include "TGAReader.h"
#include "BasicStructs.h"

class Asset;

class Texture : public Resource 
{
public:
    // Constructors/Destructors
    Texture();
    virtual ~Texture();

    // Accessors
    Asset* GetData() { return m_texture; }
    ImageInfo* GetImageInfo() { return &m_imageInfo; }

    // Methods
    void Serialize(std::ostream& _stream) override;
    void Deserialize(std::istream& _stream) override;
    void ToString() override;
    void Load(string _guid);

    // Members
    static ObjectPool<Texture>* Pool;

private:
    ImageInfo m_imageInfo;
    Asset* m_texture;
};

#endif // TEXTURE_H
