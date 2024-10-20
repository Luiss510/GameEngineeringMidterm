#include "../include/StackAllocator.h"
#include "../include/StandardIncludes.h"
#include "../include/SpriteAnim.h"
#include "../include/SpriteSheet.h"
#include "../include/BasicStructs.h"

#include <iostream>   // for cout, endl
#include <string>     // for std::string
#include <cstring>    // for memset
#include <thread>     // for std::thread


StackAllocator::StackAllocator()
{
    ClearMemory();
}

StackAllocator::~StackAllocator()
{
    ClearMemory();
}

void StackAllocator::AllocateStack(unsigned int _stackSizeBytes)
{
    m_stackStart = new unsigned char[_stackSizeBytes];
    memset(m_stackStart, 0, _stackSizeBytes);
    m_stackPosition = m_stackStart;
    m_stackEnd = m_stackStart + _stackSizeBytes;
}

unsigned char* StackAllocator::GetMemory(unsigned int _sizeBytes)
{
    unsigned char* hold = m_stackPosition;
    if (m_stackPosition + _sizeBytes <= m_stackEnd)
    {
        m_stackPosition += _sizeBytes;
        return hold;
    }

    return nullptr; // Not enough bytes left on stack
}

void StackAllocator::Mark()
{
    m_marker = m_stackPosition;
}

void StackAllocator::FreeToMarker()
{
    m_stackPosition = m_marker;
    *m_stackPosition = 0;
}

void StackAllocator::ClearMemory()
{
    if (m_stackStart != nullptr)
    {
        delete m_stackStart;
    }
    m_marker = nullptr;
    m_stackStart = nullptr;
    m_stackPosition = nullptr;
    m_stackEnd = nullptr;
}
