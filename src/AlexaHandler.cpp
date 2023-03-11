#include "AlexaHandler.h"

AlexaHandler::AlexaHandler(JarvisDesk *desk, const char *deviceName)
    : SmartAssistantHandler(desk, deviceName)
{
}

void AlexaHandler::setup()
{
    mDeviceId = mFauxmo.addDevice(this->mDeviceName);
    mFauxmo.setPort(80);
    mFauxmo.enable(true);

    JarvisDesk *desk = this->mDesk;
    unsigned char deskDeviceId = mDeviceId;

    mFauxmo.onSetState([desk, deskDeviceId](unsigned char deviceId, const char *deviceName, bool state, unsigned char value) {
        Serial.printf("[MAIN] Device #%d (%s) state: %s value: %d\n", deviceId, deviceName, state ? "ON" : "OFF", value);

        if (deviceId == deskDeviceId && state)
        {
            int castedVal = (int)value;
            Serial.printf("Got value: %d\n", castedVal);
            // Stand
            switch (castedVal)
            {
            case 1: // 1% --> ~4
            case 2: 
            case 3: 
            case 4: 
                // Preset 1
                desk->requestPreset(HandsetPresets::One);
                break;
            case 5: // 2% --> ~6
            case 6: 
                // Preset 2
                desk->requestPreset(HandsetPresets::Two);
                break;
            case 7: // 3% --> ~9
            case 8:
            case 9:
                // Preset 3
                desk->requestPreset(HandsetPresets::Three);
                break;
            case 10: // 4% --> ~11
            case 11: 
            case 12: 
                // Preset 4
                desk->requestPreset(HandsetPresets::Four);
                break;
            case 254: // 100% --> 254+
            case 255:
                desk->requestStand();
                break;
            default:
                // Unknown
                break;
            }

        } else if (deviceId == deskDeviceId && !state)
        {
            // Sit
            desk->requestSit();
        }
    });
}

void AlexaHandler::loop()
{
    mFauxmo.handle();
}
