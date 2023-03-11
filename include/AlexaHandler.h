#ifndef ALEXA_HANDLER_H_
#define ALEXA_HANDLER_H_

#include <fauxmoESP.h>
#include "SmartAssistantHandler.h"

class AlexaHandler : public SmartAssistantHandler
{
public:
    AlexaHandler(JarvisDesk *desk, const char *deviceName);

    void setup() override;
    void loop() override;
    static void HandleStateChange(unsigned char, const char *, bool, unsigned char);

private:
    fauxmoESP mFauxmo;
    unsigned char mDeviceId;
};

#endif
