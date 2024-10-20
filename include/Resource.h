#ifndef RESOURCE_H
#define RESOURCE_H

#include "Serializable.h"
#include "AssetController.h"

//class Asset; // Forward declaration


class Resource : public Serializable
{
public:
    // Constructor/Destructor
    Resource();
    virtual ~Resource();

    // Methods
    virtual void Serialize(std::ostream& _stream);
    virtual void Deserialize(std::istream& _stream);
    virtual void AssignNonDefaultValues();
    virtual void ToString();

    // Members
    static ObjectPool<Resource>* Pool;


    template <class T>
    void SerializePointer(std::ostream& _stream, T* _pointer)
    {
        byte exists = 1;
        if (_pointer != nullptr)
        {
            _stream.write(reinterpret_cast<char*>(&exists), sizeof(byte));
            _pointer->Serialize(_stream);
        }
        else
        {
            exists = 0;
            _stream.write(reinterpret_cast<char*>(&exists), sizeof(byte));
        }
    }
    template <class T>
    void DeserializePointer(std::istream& _stream, T*& _pointer)
    {
        byte exists = 0;
        _stream.read(reinterpret_cast<char*>(&exists), sizeof(exists));
        if (exists == 1)
        {
            _pointer = T::Pool->GetResource();
            _pointer->Deserialize(_stream);
        }
    }
    void SerializeAsset(std::ostream& _stream, Asset* _asset);
    void DeserializeAsset(std::istream& _stream, Asset*& _asset);

protected:

private:
    //int m_val1 = 0;
    //double m_val2 = 0.0f;
    //char m_val3 = { };
    //Resource* m_subResource = nullptr;
    //Asset* m_asset = nullptr;
    //m_val1 = 2;
    //m_val2 = 2.0f;
    //m_val3 = '2';
    //m_subResource = Resource::Pool->GetResource();
    //m_subResource->m_val1 = 3;
    //m_subResource->m_val2 = 3.0f;
    //m_subResource->m_val3 = '3';
    //m_asset = AssetController::Instance().GetAsset("assets/Emoji.jpg");
};

#endif // RESOURCE_H
