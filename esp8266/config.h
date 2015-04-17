/* 
  CONFIG.H - esp8266 configuration class

  Copyright (c) 2014 Luc Lebosse. All rights reserved.
 
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef CONFIG_h
#define CONFIG_h

#include <Arduino.h>

//pin used to stop bridge loop
#define INTERRUPT_PIN 2
#define RESET_CONFIG_PIN 2

//flags
#define AP_MODE            1
#define CLIENT_MODE        2
#define DHCP_MODE          1 
#define STATIC_IP_MODE     2
#define BRIDGE_MODE        1
#define FRONT_END_MODE     2


//position in EEPROM
//AP mode = 1; Station client mode = 2
#define EP_WIFI_MODE       0    //1 byte = flag
#define EP_SSID            1    //33 bytes 32+1 = string  ; warning does not support multibyte char like chinese
#define EP_PASSWORD        34   //65 bytes 64 +1 = string ;warning does not support multibyte char like chinese
#define EP_IP_MODE         99   //1 byte = flag
#define EP_IP_VALUE        100  //17 bytes xxx.xxx.xxx\0 = string
#define EP_MASK_VALUE      117  //17 bytes xxx.xxx.xxx\0 = string
#define EP_GATEWAY_VALUE   134  //17 bytes xxx.xxx.xxx\0 = string
#define EP_USAGE_VALUE     151  //1 byte = flag
#define EP_BAUD_RATE       168  //7 bytes = string (if integer value => save 4 bytes but need to create new interger function for eprom that will take more than 4 bytes)

//default values
#define DEFAULT_WIFI_MODE       AP_MODE
#define DEFAULT_SSID            "ESP8266"
#define DEFAULT_PASSWORD        "12345678"
#define DEFAULT_IP_MODE         STATIC_IP_MODE
#define DEFAULT_IP_VALUE        "192.168.0.1"
#define DEFAULT_MASK_VALUE      "255.255.255.0"
#define DEFAULT_GATEWAY_VALUE   DEFAULT_IP_VALUE
#define DEFAULT_USAGE_MODE     BRIDGE_MODE
#define DEFAULT_BAUD_RATE      "9600"

#define EEPROM_SIZE 256 //max is 512
#define MAX_SSID_LENGH 32
#define MAX_PASSWORD_LENGH 64
#define MAX_IP_LENGH 17
#define MAX_BAUD_LENGH 6

class CONFIG
{
  public:
  static bool read_string(word pos, char byte_buffer[], word size_max);
  static bool read_byte(word pos, byte * value);
  static bool write_string(word pos, const char * byte_buffer, word size_buffer);
  static bool write_byte(word pos, const byte value);
  static bool reset_config();
  static void print_config();
};

#endif