#ifndef FILE_CONTROLLER_H
#define FILE_CONTROLLER_H

#include "StandardIncludes.h"

class FileController : public Singleton<FileController>
{
public:
    // Constructors/Destructors
    FileController();
    virtual ~FileController();

    bool GetFileReadDone() { return !m_thread.joinable(); }
    bool GetFileReadSuccess() { return m_readSuccess; }

    // Methods
    string GetCurDirectory();
    int GetFileSize(string _filePath);
    bool ReadFile(string _filePath, unsigned char* _buffer, unsigned int _bufferSize);
    void ReadFileAsync(string _filePath, unsigned char* _buffer, unsigned int _bufferSize);
    void setSpeed(float spd);
private:
    FILE* m_handle;
    bool m_readSuccess;
    thread m_thread;
};

#endif // FILE_CONTROLLER_H
