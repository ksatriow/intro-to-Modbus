# Intro To Modbus
This repository provide practical documentation using Modbus integrated with all Microcontroller

This project allows you to practice Modbus for all **Microcontroller**. It can be used as an alternative to `Premium Course` and offers useful features and customization using sensor.

It has been written **100% in C**. ❤️

![](/assets/modbus.jpg)

# Table of Contents
* [Resource](#resource)
    * [Tools](#tools)
    * [Software](#software)
* [Download](#download)
* [Sample Project](#sample-project)
* [Protocol](#protocol)
    * [MQTT](#mqtt)
    * [LoRa](#lora)
    * [WiFi](#wifi)
* [Step](#step)
* [Contribution](#contribution)
* [License](#license)

### Spread Some :heart:
[![GitHub followers](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/ksatriow)  [![Linkedin](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/kukuh-satrio-wibowo/) 

# Resource

This resources is all you need to implement this project

## Tools
* [Arduino Nano](https://www.arduino.cc/en/pmwiki.php?n=Main/ArduinoBoardNano)
* [STM32](https://alselectro.wordpress.com/2018/11/18/stm32f103-bluepill-getting-started-with-arduino-core/)
* [ESP32](https://makeradvisor.com/esp32-development-boards-review-comparison/)
* [PM800](https://www.se.com/ww/en/product-range-presentation/918-powerlogic-pm800-series/)
* [DHT22](https://learn.adafruit.com/dht)
* [Relay](https://randomnerdtutorials.com/guide-for-relay-module-with-arduino/)
* [Servo](https://www.arduino.cc/reference/en/libraries/servo/)
* [RS485](https://www.lammertbies.nl/comm/info/rs-485)
* [ESP32 CAM](https://randomnerdtutorials.com/esp32-cam-video-streaming-face-recognition-arduino-ide/)
* [LoRa Ebyte](https://www.mischianti.org/2019/10/15/lora-e32-device-for-arduino-esp32-or-esp8266-specs-and-basic-usage-part-1/)

## Software
* [Arduino IDE](https://www.arduino.cc/en/software)
* [Node Js](https://nodejs.org/en/)
* [NodeRed](https://nodered.org/)
* [Lora Ebyte](https://github.com/xreef/LoRa_E32_Series_Library)

# Download

You can download the resources in here
 


# Sample Project

Modbus Dashboard Arduino Nano [here](https://drive.google.com/file/d/1CxAxw0Gray2S3W_t7_ukUqG_CtLuLOVO/view?usp=sharing) 
Modbus Dashboard ES32 [here](https://drive.google.com/file/d/1GDzSGdal77F_KD4pnuZhEQZ5CB_iB7EQ/view?usp=sharing)
Modbus Dashboard STM32 [here](https://drive.google.com/file/d/1c_MFyv9rzcxqOYhDzN8kAOSUK-KZSq0C/view?usp=sharing)

# Protocol
IoT communication protocols are modes of communication that protect and ensure optimum security to the data being exchanged between connected devices. The IoT devices are typically connected to the Internet via an IP (Internet Protocol) network. (https://www.kelltontech.com/kellton-tech-blog/internet-of-things-protocols-standards)

## MQTT
MQTT is an OASIS standard messaging protocol for the Internet of Things (IoT). It is designed as an extremely lightweight publish/subscribe messaging transport that is ideal for connecting remote devices with a small code footprint and minimal network bandwidth. (https://mqtt.org/)

## LoRa
LoRa is a wireless modulation technique derived from Chirp Spread Spectrum (CSS) technology. It encodes information on radio waves using chirp pulses - similar to the way dolphins and bats communicate! LoRa modulated transmission is robust against disturbances and can be received across great distances. LoRaWAN is a media access control (MAC) protocol for wide area networks. It is designed to allow low-powered devices to communicate with Internet-connected applications over long range wireless connections. (https://www.thethingsnetwork.org/docs/lorawan/what-is-lorawan/)

## WiFi
Wi-Fi is a term for certain types of WLAN that use specifications in the 802.11 family. The term Wi-Fi was created by an organization called the Wi-Fi Alliance, which oversees tests that certify product interoperability. A wireless LAN node that provides a public Internet connection via Wi-Fi from a given location is called a hot spot. Many airports, hotels, and fast-food facilities offer public access to Wi-Fi networks. (https://searchnetworking.techtarget.com/tutorial/Wireless-protocols-learning-guide)

# Step
Procedurw to create this project 

- [ ] Buy the Tools
- [ ] Download the software
- [ ] Build use schematic in document
- [ ] Display in NodeRed

# Contribution

I highly encourage the community to step forward and improve this library further. You can fix any reported bug, propose or implement new features, write tests, etc.

Here is a quick list of things to remember -
* Check the open issues before creating a new one,
* Help me in reducing the number of open issues by fixing any existing bugs,
* Check the roadmap to see if you can help in implementing any new feature,
* You can contribute by writing unit and integration tests for this library,
* If you have any new idea that aligns with the goal of this library, feel free to raise a feature request and discuss it.

# About The Author

### Kukuh Satrio Wibowo

Skilled Android, DevOps and IoT Engineer with 3+ years of hands-on experience supporting, automating, and optimizing mission critical deployments in AWS, leveraging configuration management, CI/CD, and DevOps processes. 

<a href="https://www.linkedin.com/in/kukuh-satrio-wibowo/"><img src="https://github.com/aritraroy/social-icons/blob/master/linkedin-icon.png?raw=true" width="60"></a>


# License

```
Copyright 2021 kukuhsw

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
