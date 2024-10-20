#include "../include/Asset.h"
#include "../include/SpriteAnim.h"
#include "../include/SpriteSheet.h"
#include "../include/BasicStructs.h"

ObjectPool<Asset>* Asset::Pool;

Asset::Asset()
{
    m_GUID = "";
    m_dataSize = 0;
    m_data = nullptr;
}

void Asset::ToString()
{
    cout << "Asset GUID: " << m_GUID << endl;
    cout << "Asset Data Size: " << m_dataSize << endl;
}