#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char DEVICE_LOGIN_NAME[]  = "eca1b2e2-2216-4c93-b1c2-40ed68aae3cc";

const char SSID[]               = "IoTProject";    // Network SSID (name)
const char PASS[]               = "qwertyuiop";    // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[]  = "z642gFtRuON1XC#rTR6KHPy?4";    // Secret device password


float pitch_IoT;
float roll_IoT;
int servo1_IoT;
int servo2_IoT;

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(pitch_IoT, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(roll_IoT, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(servo1_IoT, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(servo2_IoT, READ, ON_CHANGE, NULL);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
