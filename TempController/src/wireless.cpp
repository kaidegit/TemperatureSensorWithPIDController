#include "wireless.h"
#include "WiFi.h"

esp_now_peer_info_t slave;

#define CHANNEL 0
#define PRINTSCANRESULTS 0
#define DELETEBEFOREPAIR 0

void ESPNow_Init()
{
    esp_err_t ret = esp_now_init();
    WiFi.disconnect();
    if (ret != ESP_OK)
    {
        Serial.println("esp now init falied");
        ESP.restart();
    }
    ScanForSlave();
    if (slave.channel == CHANNEL)
    {
        bool isPaired = manageSlave();
        if (!isPaired)
        {
            Serial.println("esp now paired falied");
            ESP.restart();
        }
    }else{

    }
}

// Check if the slave is already paired with the master.
// If not, pair the slave with master
bool manageSlave()
{
    if (slave.channel == CHANNEL)
    {
        Serial.print("Slave Status: ");
        // check if the peer exists
        bool exists = esp_now_is_peer_exist(slave.peer_addr);
        if (exists)
        {
            // Slave already paired.
            Serial.println("Already Paired");
            return true;
        }
        else
        {
            // Slave not paired, attempt pair
            esp_err_t addStatus = esp_now_add_peer(&slave);
            if (addStatus == ESP_OK)
            {
                // Pair success
                Serial.println("Pair success");
                return true;
            }
            else
            {
                Serial.println("Pair failed");
                return false;
            }
        }
    }
    else
    {
        // No slave found to process
        Serial.println("No Slave found to process");
        return false;
    }
}

void sendData(uint8_t data)
{
    const uint8_t *peer_addr = slave.peer_addr;
    Serial.print("Sending: ");
    Serial.println(data);
    esp_err_t result = esp_now_send(peer_addr, &data, sizeof(data));
    Serial.print("Send Status: ");
    if (result == ESP_OK)
    {
        Serial.println("Success");
    }
    // else if (result == ESP_ERR_ESPNOW_NOT_INIT)
    // {
    //     // How did we get so far!!
    //     Serial.println("ESPNOW not Init.");
    // }
    // else if (result == ESP_ERR_ESPNOW_ARG)
    // {
    //     Serial.println("Invalid Argument");
    // }
    // else if (result == ESP_ERR_ESPNOW_INTERNAL)
    // {
    //     Serial.println("Internal Error");
    // }
    // else if (result == ESP_ERR_ESPNOW_NO_MEM)
    // {
    //     Serial.println("ESP_ERR_ESPNOW_NO_MEM");
    // }
    // else if (result == ESP_ERR_ESPNOW_NOT_FOUND)
    // {
    //     Serial.println("Peer not found.");
    // }
    // else
    // {
    //     Serial.println("Not sure what happened");
    // }
}

void SendTemperature(float temperature)
{
    const uint8_t *peer_addr = slave.peer_addr;
    uint8_t temp_unit = int(temperature);
    uint8_t temp_deci = int(100 * (temperature - temp_unit));
    uint8_t temp_crc = (temp_unit + temp_deci) & 0xff;
    uint8_t magic_start = 0x80;
    uint8_t buffer[4] = {magic_start, temp_unit, temp_deci, temp_crc};
    esp_err_t result = esp_now_send(peer_addr, buffer, sizeof(buffer));
}

void ScanForSlave()
{
    int8_t scanResults = WiFi.scanNetworks();
    // reset on each scan
    bool slaveFound = 0;
    memset(&slave, 0, sizeof(slave));

    Serial.println("");
    if (scanResults == 0)
    {
        Serial.println("No WiFi devices in AP Mode found");
    }
    else
    {
        Serial.print("Found ");
        Serial.print(scanResults);
        Serial.println(" devices ");
        for (int i = 0; i < scanResults; ++i)
        {
            // Print SSID and RSSI for each device found
            String SSID = WiFi.SSID(i);
            int32_t RSSI = WiFi.RSSI(i);
            String BSSIDstr = WiFi.BSSIDstr(i);

            if (PRINTSCANRESULTS)
            {
                Serial.print(i + 1);
                Serial.print(": ");
                Serial.print(SSID);
                Serial.print(" (");
                Serial.print(RSSI);
                Serial.print(")");
                Serial.println("");
            }
            delay(10);
            // Check if the current device starts with `Slave`
            if (SSID.indexOf("Slave") == 0)
            {
                // SSID of interest
                Serial.println("Found a Slave.");
                Serial.print(i + 1);
                Serial.print(": ");
                Serial.print(SSID);
                Serial.print(" [");
                Serial.print(BSSIDstr);
                Serial.print("]");
                Serial.print(" (");
                Serial.print(RSSI);
                Serial.print(")");
                Serial.println("");
                // Get BSSID => Mac Address of the Slave
                int mac[6];
                if (6 == sscanf(BSSIDstr.c_str(), "%x:%x:%x:%x:%x:%x", &mac[0], &mac[1], &mac[2], &mac[3], &mac[4], &mac[5]))
                {
                    for (int ii = 0; ii < 6; ++ii)
                    {
                        slave.peer_addr[ii] = (uint8_t)mac[ii];
                    }
                }

                slave.channel = CHANNEL; // pick a channel
                slave.encrypt = 0;       // no encryption

                slaveFound = 1;
                // we are planning to have only one slave in this example;
                // Hence, break after we find one, to be a bit efficient
                break;
            }
        }
    }

    if (slaveFound)
    {
        Serial.println("Slave Found, processing..");
    }
    else
    {
        Serial.println("Slave Not Found, trying again.");
    }

    // clean up ram
    WiFi.scanDelete();
}