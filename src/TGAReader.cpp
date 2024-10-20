#include "../include/TGAReader.h"
#include "../include/AssetController.h"
#include "../include/SpriteAnim.h"
#include "../include/SpriteSheet.h"
#include "../include/BasicStructs.h"

TGAReader::TGAReader() 
{
    m_header = { };
    m_data = nullptr;
}

void TGAReader::ProcessAsset(Asset* _rawTGA, ImageInfo* _imageInfo) 
{
    memcpy(&m_header, _rawTGA->GetData(), sizeof(TGAHeader));

    // Check if format is supported
    M_ASSERT((m_header.DataTypeCode == 2), "Can only handle image type 2");
    M_ASSERT((m_header.BitsPerPixel == 24 || m_header.BitsPerPixel == 32), "Can only handle pixel depths of 24, and 32");
    M_ASSERT((m_header.ColourMapType == 0), "Can only handle colour map types of 0");

    // Calculate data offset in asset buffer
    int dataOffset = sizeof(TGAHeader);
    dataOffset += m_header.IDLength;
    dataOffset += m_header.ColourMapType * m_header.ColourMapLength;

    _imageInfo->Width = m_header.Width;
    _imageInfo->Height = m_header.Height;
    _imageInfo->BitsPerPixel = m_header.BitsPerPixel;
    _imageInfo->DataOffset = dataOffset;
}

Asset* TGAReader::LoadTGAFromFile(string _file, ImageInfo* _imageInfo) 
{
    // Read the file into an asset
    m_data = AssetController::Instance().GetAsset(_file);
    ProcessAsset(m_data, _imageInfo);
    return m_data;
}
