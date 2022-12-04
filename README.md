# Wireless Control of a LED Srtip through Web Pages

This project was for CSE 598 Programming for IoT. It is an ESP32 bases LED controller that takes commands remotely from users through web page inputs.

# Functionality
The ESP32 connected to the LED strip will connect to a wifi network. Once this is done the serial monitor will show the IP address of the ESP32. A user can then enter the IP of the ESP32 into a url bar on any device connected to the same wifi network to open the web pages needed to issue remote commands to the LEF strip.

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

Make sure your LED strip and ESP32 are connected as shown below in the diagram.
<picture>
  <source media="(prefers-color-scheme: dark)" srcset="https://user-images.githubusercontent.com/44142919/205474867-2f855dcd-ef28-4ecf-887e-450985329384.png">
  <source media="(prefers-color-scheme: light)" srcset="https://user-images.githubusercontent.com/44142919/205474867-2f855dcd-ef28-4ecf-887e-450985329384.png">
  <img alt="Image Failed to Display">
</picture>

Once this is done click the PlatformIO home button to open up the main PLatformIO interface. Click on Open Project and select the unzipped LEDStripController folder.
<picture>
  <source media="(prefers-color-scheme: dark)" srcset="https://user-images.githubusercontent.com/44142919/205474927-fe9d1fe1-f3d2-4eea-ae04-2d73b3f9113e.png">
  <source media="(prefers-color-scheme: light)" srcset="https://user-images.githubusercontent.com/44142919/205474927-fe9d1fe1-f3d2-4eea-ae04-2d73b3f9113e.png">
  <img alt="Image Failed to Display">
</picture>

Once this project is open, navigate to the main.cpp file. You will need to edit/double check a few things. First, ensure that the numOfLeds is set to the correct number of leds for your personal NeoPixel LED strip. Also, insure the #define DATA_PIN is set to the pin on your ESP32 that the data wire from the NeoPixel is connected to. Finally, change the ssid and password values to the wifi network you will be using. 
<picture>
  <source media="(prefers-color-scheme: dark)" srcset="https://user-images.githubusercontent.com/44142919/205474978-ce9c8957-f54b-485b-ae8d-288ad479a7de.png">
  <source media="(prefers-color-scheme: light)" srcset="https://user-images.githubusercontent.com/44142919/205474978-ce9c8957-f54b-485b-ae8d-288ad479a7de.png">
  <img alt="Image Failed to Display">
</picture>

Once this is done, and all connections are finalized, click on the PlatformIO icon on the left toolbar and run the upload filesystem using SPIFFS command to load the web pages onto your ESP32 (only need to do this once). Next, click on the upload and monitor command. If this runs correctly part of the output will include an IP address. Enter this IP into the url bar of a web browser for a device on the same wifi network as the ESP32. This will bring up the landing page where you can select which other actions you would like to perform on the LED strip. If all is working well, entering commands on the color selector or pattern selector web pages should show on the LED strip. Remember, the ESP32 and the device you are using to issue remote commands must be on the same wifi network.
<picture>
  <source media="(prefers-color-scheme: dark)" srcset="https://user-images.githubusercontent.com/44142919/205475128-8c814a8d-13e0-4380-982c-3cd72899b71a.png">
  <source media="(prefers-color-scheme: light)" srcset="https://user-images.githubusercontent.com/44142919/205475128-8c814a8d-13e0-4380-982c-3cd72899b71a.png">
  <img alt="Image Failed to Display">
</picture>




