#include "../include/wifi_connector.h"

WifiConnector::WifiConnector(string ssid, string password, int timeout, int baudrate)
    : ssid(ssid), password(password), timeout(timeout), baudrate(baudrate)
{
    Serial.begin(baudrate);
}

bool WifiConnector::connect()
{
    const int delay_ms = 1000;
    int total_delay = 0;

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid.c_str(), password.c_str());
    Serial.print("Connecting to WiFi ..");

    while (WiFi.status() != WL_CONNECTED && total_delay < timeout)
    {
        Serial.print('.');
        delay(delay_ms);
        total_delay += delay_ms;
    }

    if (WiFi.isConnected())
    {
        Serial.println("connect successful");
        return true;
    }
    Serial.println("connect failed");
    return false;
}

bool WifiConnector::disconnect()
{
    if (WiFi.disconnect())
    {
        Serial.println("disconnect successful");
        return true;
    }
    Serial.println("disconnect failed");
    return false;
}

bool WifiConnector::isConnected()
{
    return WiFi.isConnected();
}