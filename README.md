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
<img width="236" alt="Screen Shot 2022-12-03 at 9 28 24 PM" src="https://user-images.githubusercontent.com/44142919/205474727-52765594-7b35-4a41-8f35-1a9ea1dbeea9.png">



Make sure your LED strip and ESP32 are connected as shown below in the diagram.


Once this is done click the PlatformIO home button to open up the main PLatformIO interface. Click on Open Project and select the unzipped LEDStripController folder.

Once this project is open, navigate to the main.cpp file. You will need to edit/double check a few things. First, ensure that the numOfLeds is set to the correct number of leds for your personal NeoPixel LED strip. Also, insure the #define DATA_PIN is set to the pin on your ESP32 that the data wire from the NeoPixel is connected to. Finally, change the ssid and password values to the wifi network you will be using. 




