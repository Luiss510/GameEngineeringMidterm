#include "../include/Resource.h"
#include "../include/AssetController.h"
#include "../include/Serializable.h"
#include "../include/Asset.h"
#include "../include/SpriteAnim.h"
#include "../include/SpriteSheet.h"
#include "../include/BasicStructs.h"

ObjectPool<Resource>* Resource::Pool = nullptr;


Resource::Resource()
{
}

Resource::~Resource()
{
}

void Resource::AssignNonDefaultValues()
{
}

void Resource::ToString()
{
    cout << "BASE_RESOURCE" << endl;
}


void Resource::Serialize(std::ostream& _stream)
{
    
}

void Resource::Deserialize(std::istream& _stream)
{
    
}

void Resource::SerializeAsset(std::ostream& _stream, Asset* _asset)
{
    byte guidLength = 0;
    if (_asset != nullptr)
    {
        guidLength = static_cast<byte>(_asset->GetGUID().length());
    }
    _stream.write(reinterpret_cast<char*>(&guidLength), sizeof(guidLength));

    if (guidLength > 0)
    {
        _stream.write(_asset->GetGUID().c_str(), guidLength);
    }
}

void Resource::DeserializeAsset(std::istream& _stream, Asset*& _asset)
{
    byte guidLength = 0;
    _stream.read(reinterpret_cast<char*>(&guidLength), sizeof(byte));

    if (guidLength > 0)
    {
        char guid[255];
        _stream.read(guid, guidLength);
        guid[guidLength] = '\0'; // Null-terminate the string

        // Assuming AssetController has a method to get an asset by its GUID
        _asset = AssetController::Instance().GetAsset(std::string(guid));
    }
}
