#ifndef SMART_ASSISTANT_HANDLER_H_
#define SMART_ASSISTANT_HANDLER_H_
#include "JarvisDesk.h"

class SmartAssistantHandler
{
public:
    SmartAssistantHandler(JarvisDesk *desk, const char *deviceName);
    virtual ~SmartAssistantHandler();

    virtual void setup() = 0;
    virtual void loop() = 0;

protected:
    JarvisDesk *mDesk;
    const char *mDeviceName;
};

#endif
