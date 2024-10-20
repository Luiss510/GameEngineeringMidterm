#ifndef ASSET_H
#define ASSET_H

#include "StandardIncludes.h"
#include "ObjectPool.h"

class Asset
{
public:
    // Constructors / Destructors
    Asset();
    virtual ~Asset() { }

    // Accessors
    string GetGUID() { return m_GUID; }
    void SetGUID(string _guid) { m_GUID = _guid; }
    int GetDataSize() { return m_dataSize; }
    void SetDataSize(int _size) { m_dataSize = _size; }
    byte* GetData() { return m_data; }
    void SetData(byte* _data) { m_data = _data; }

    // Methods
    void ToString();
    static ObjectPool<Asset>* Pool;

    void Reset() {
        // Reset the state of the Asset object here
    }

private:
    // Members
    string m_GUID;
    int m_dataSize;
    byte* m_data;
};

#endif // ASSET_H
