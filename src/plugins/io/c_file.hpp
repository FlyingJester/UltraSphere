#pragma once
#include "io.hpp"
#include <cstdio>

namespace Turbo{

class CFile : public IO{
    FILE *file_;
    const bool r_, w_;
public:
    CFile(FILE *, bool r, bool w);
    CFile() = delete;
    virtual ~CFile();

    bool seekable() override { return true; }
    
    // Accepts SEEK_SET, SEEK_CUR, and SEEK_END
    bool seek(unsigned offset, int whence) override;
    
    bool read(void *to, unsigned n_bytes) override;
    bool write(const void *from, unsigned n_bytes) override;

    int size() override;
    int at() override;
    
    bool readable() override;
    bool writable() override;

    bool writeByte(unsigned char c) override;
    unsigned char readByte() override;

    static bool CFileConstructor(JSContext *ctx, unsigned argc, JS::Value *vp);
    static void CFileFinalizer(JSFreeOp *fop, JSObject *obj);

};

} // namespace Turbo
