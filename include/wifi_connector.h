#ifndef WIFI_CONNECTOR
#define WIFI_CONNECTOR

#include <Arduino.h>
#include "WiFi.h"
#include <string>

using std::string;

class WifiConnector
{
private:
    string ssid;
    string password;
    int timeout;
    int baudrate;

public:
    WifiConnector(string ssid, string password, int timeout = 10000, int baudrate = 9600);

    bool connect();
    bool disconnect();
    bool isConnected();
};

#endif