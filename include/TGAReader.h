#ifndef TGA_READER_H
#define TGA_READER_H

#include "StandardIncludes.h"

class Asset;

#pragma pack(push,1) // Enable memory packing
typedef struct 
{
    char IDLength;           // Size of ID field that follows 18 byte header (0 usually)
    char ColourMapType;      // Type of colour map 0=none, 1=has palette
    char DataTypeCode;       // Type of image 0=none,1=indexed,2=rgb,3=grey,+8=rle packed
    short ColourMapStart;    // First colour map entry in palette
    short ColourMapLength;   // Number of colours in palette
    char ColourMapDepth;     // Number of bits per palette entry 15,16,24,32
    short x_Origin;          // Image x origin
    short y_Origin;          // Image y origin
    short Width;             // Image width in pixels
    short Height;            // Image height in pixels
    char BitsPerPixel;       // The size of each colour value. 8, 16, 24 or 32 bpp
    char ImageDescriptor;    // Imaged descriptor byte
} TGAHeader;
#pragma pack(pop) // Disable memory packing

typedef struct 
{
    short Width;
    short Height;
    short BitsPerPixel;
    short DataOffset;
} ImageInfo;

class TGAReader 
{
public:
    // Constructors/Destructors
    TGAReader();
    virtual ~TGAReader() {}

    // Methods
    void ProcessAsset(Asset* _rawTGA, ImageInfo* _imageInfo);
    Asset* LoadTGAFromFile(string _file, ImageInfo* _imageInfo);

private:
    TGAHeader m_header;
    Asset* m_data;
};

#endif // TGA_READER_H
