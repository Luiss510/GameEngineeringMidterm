
#include "../include/SpriteAnim.h"
#include "../include/SpriteSheet.h"
#include "../include/BasicStructs.h"

ObjectPool<SpriteSheet>* SpriteSheet::Pool;

SpriteSheet::SpriteSheet() {
    m_rows = 0;
    m_columns = 0;
    m_clipSizeX = 0;
    m_clipSizeY = 0;
    speed = 0;
    m_animations.clear();
}

SpriteSheet::~SpriteSheet() {}

double SpriteSheet::getSpeed()
{
    return speed;
}

void SpriteSheet::SetSize(byte _rows, byte _columns, byte _clipSizeX, byte _clipSizeY) {
    m_rows = _rows;
    m_columns = _columns;
    m_clipSizeX = _clipSizeX;
    m_clipSizeY = _clipSizeY;
}

void SpriteSheet::AddAnimation(AnimationNames _name, short _clipStart, short _clipCount, float _clipSpeed) {
    SpriteAnim* anim = SpriteAnim::Pool->GetResource();
    anim->Create(_clipStart, _clipCount, _clipSpeed);
    m_animations[_name] = anim; 
}

void SpriteSheet::setSpeed(float spd)
{
     speed = spd;
}

Rect SpriteSheet::Update(AnimationNames _name) {
    short s = m_animations[_name]->GetClipCurrent();
    short posX = s % m_columns * m_clipSizeX; 
    short posY = s / m_columns * m_clipSizeY;
    Rect r = Rect(posX, posY, posX + m_clipSizeX, posY + m_clipSizeY);
    m_animations[_name]->Update();
    return r;
}

void SpriteSheet::Serialize(std::ostream& _stream) {
    _stream.write(reinterpret_cast<char*>(&m_rows), sizeof(m_rows));
    _stream.write(reinterpret_cast<char*>(&m_columns), sizeof(m_columns));
    _stream.write(reinterpret_cast<char*>(&m_clipSizeX), sizeof(m_clipSizeX));
    _stream.write(reinterpret_cast<char*>(&m_clipSizeY), sizeof(m_clipSizeY));

    int count = m_animations.size();
    _stream.write(reinterpret_cast<char*>(&count), sizeof(count));
    for (auto& a : m_animations) {
        AnimationNames index = a.first;
        _stream.write(reinterpret_cast<char*>(&index), sizeof(index));
        a.second->Serialize(_stream);
    }
    Texture::Serialize(_stream);
}

void SpriteSheet::Deserialize(std::istream& _stream) {
    _stream.read(reinterpret_cast<char*>(&m_rows), sizeof(m_rows));
    _stream.read(reinterpret_cast<char*>(&m_columns), sizeof(m_columns));
    _stream.read(reinterpret_cast<char*>(&m_clipSizeX), sizeof(m_clipSizeX));
    _stream.read(reinterpret_cast<char*>(&m_clipSizeY), sizeof(m_clipSizeY));

    int count;
    _stream.read(reinterpret_cast<char*>(&count), sizeof(count));
    for (int c = 0; c < count; ++c) {
        AnimationNames index;
        _stream.read(reinterpret_cast<char*>(&index), sizeof(index));
        SpriteAnim* anim = SpriteAnim::Pool->GetResource();
        anim->Deserialize(_stream);
        m_animations[index] = anim;
    }
    Texture::Deserialize(_stream);
}

void SpriteSheet::ToString() {
    cout << "SPRITE SHEET: " << endl;
    cout << " Rows: " << (int)m_rows << endl;
    cout << " Columns: " << (int)m_columns << endl;
    cout << " ClipSizeX: " << (int)m_clipSizeX << endl;
    cout << " ClipSizeY: " << (int)m_clipSizeY << endl;
    Resource::ToString();
}

int SpriteSheet::GetCurrentClip(AnimationNames _name)
{
    if (m_animations.count(_name) < 0)
    {
        return 0;
    }
    return m_animations[_name]->GetClipCurrent();
}
