#include <WiFiManager.h>

#include "JarvisDesk.h"
#include "AlexaHandler.h"

WiFiManager wifiManager;
JarvisDesk desk(HandsetPresets::One, HandsetPresets::Three);
AlexaHandler alexa(&desk, "Standing Desk");

void setup()
{
    Serial.begin(9600);
    delay(500);
    wifiManager.setDebugOutput(false);

    wifiManager.setConfigPortalTimeout(120);
    bool connected = wifiManager.autoConnect("AutoConnectAP", "JarvisDesk8266");

    if (!connected)
    {
        Serial.println("Failed to connect to WiFi");
    } else 
    {
        Serial.println("Connected to WiFi");
    }

    desk.setup();
    alexa.setup();
}

bool test = false;

void loop()
{
    desk.loop();
    alexa.loop();
}
