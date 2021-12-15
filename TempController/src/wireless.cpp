#include "wireless.h"

esp_now_peer_info_t slave;

#define CHANNEL 3
#define PRINTSCANRESULTS 0
#define DELETEBEFOREPAIR 0

void InitESPNow()
{
    esp_err_t ret = esp_now_init();

    if (ret != ESP_OK)
    {
        Serial.println("esp now init falied");
        ESP.restart();
    }
    bool isPaired = manageSlave();
    if (!isPaired)
    {
        Serial.println("esp now init falied");
        ESP.restart();
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
            else if (addStatus == ESP_ERR_ESPNOW_NOT_INIT)
            {
                // How did we get so far!!
                Serial.println("ESPNOW Not Init");
                return false;
            }
            else if (addStatus == ESP_ERR_ESPNOW_ARG)
            {
                Serial.println("Invalid Argument");
                return false;
            }
            else if (addStatus == ESP_ERR_ESPNOW_FULL)
            {
                Serial.println("Peer list full");
                return false;
            }
            else if (addStatus == ESP_ERR_ESPNOW_NO_MEM)
            {
                Serial.println("Out of memory");
                return false;
            }
            else if (addStatus == ESP_ERR_ESPNOW_EXIST)
            {
                Serial.println("Peer Exists");
                return true;
            }
            else
            {
                Serial.println("Not sure what happened");
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