#ifndef ASSET_CONTROLLER_H
#define ASSET_CONTROLLER_H

#include "StandardIncludes.h"
#include "StackAllocator.h"
#include "Asset.h"

class AssetController : public Singleton<AssetController>
{
public:
    // Constructors/Destructors
    AssetController();
    virtual ~AssetController();

    // Methods
    void Initialize(int _stackSize);
    void Clear();
    Asset* GetAsset(string _guid);

    // Members
    static StackAllocator* Stack;

private:
    // Members
    map<string, Asset*> m_assets;
};

#endif // ASSET_CONTROLLER_H
