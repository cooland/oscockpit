#ifndef HIDCONTEXT_H
#define HIDCONTEXT_H

#include "hidapi.h"

#define MSX_STR 255
#define VID 0x27d9
#define PID 0x16c0

class HIDContext
{
    public:
        HIDContext();
        virtual ~HIDContext();
        int init();

    protected:
    private:
};

#endif // HIDCONTEXT_H
