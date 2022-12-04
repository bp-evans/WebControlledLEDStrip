# Wireless Control of a LED Srtip through Web Pages

This project was for CSE 598 Programming for IoT. It is an ESP32 bases LED controller that takes commands remotely from users through web page inputs.

# Needed Equipment and Programs
* PlatformIO
* Breadboard
* ESP32 w/ WiFi Capability
* NeoPixel LED strip of any size
* Needed connectors and wires
* Visual Studio Code

To start, make sure you have PlatformIO installed and download the zip of the code. To do this you will need Visual Studio Code.
Once you have Visual Studio Code, navigate to extensions tab and search for Platform IO. Once found, install it.

<picture>
  <source media="(prefers-color-scheme: dark)" srcset="https://user-images.githubusercontent.com/44142919/205474835-3154594d-db0c-4467-bacd-8aa17ec0dc45.png">
  <source media="(prefers-color-scheme: light)" srcset="https://user-images.githubusercontent.com/44142919/205474835-3154594d-db0c-4467-bacd-8aa17ec0dc45.png">
  <img alt="Image Failed to Display">
</picture>

<picture>
  <source media="(prefers-color-scheme: dark)" srcset="https://user-images.githubusercontent.com/44142919/205474867-2f855dcd-ef28-4ecf-887e-450985329384.png">
  <source media="(prefers-color-scheme: light)" srcset="https://user-images.githubusercontent.com/44142919/205474867-2f855dcd-ef28-4ecf-887e-450985329384.png">
  <img alt="Image Failed to Display">
</picture>

Make sure your LED strip and ESP32 are connected as shown below in the diagram.


Once this is done click the PlatformIO home button to open up the main PLatformIO interface. Click on Open Project and select the unzipped LEDStripController folder.

Once this project is open, navigate to the main.cpp file. You will need to edit/double check a few things. First, ensure that the numOfLeds is set to the correct number of leds for your personal NeoPixel LED strip. Also, insure the #define DATA_PIN is set to the pin on your ESP32 that the data wire from the NeoPixel is connected to. Finally, change the ssid and password values to the wifi network you will be using. 




