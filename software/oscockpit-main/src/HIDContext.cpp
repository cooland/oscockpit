#include "HIDContext.h"

HIDContext::HIDContext()
{
    //ctor
}

HIDContext::~HIDContext()
{
    //dtor
}

int HIDContext::init()
{
    if (!hid_init()==0){
        return -1;
    }
    return 1;
}
