# graduationcap #
This repository houses Arduino code and digital fabrication files from my 2016 high school graduation cap, as well as photographs of the finished product. 

![](http://i.imgur.com/4sUU6XQ.jpg)

insert GIF or video here

## Materials ##
Approximate BOM (not including original cap and tassel): 

#### Crafts ####
* light blue foam
* white foam
* light blue felt
* cute, glittery, wooden lion

#### Hardware ####
* zip ties
* gaffer tape
* clear acrylic, 1/4" thickness

#### Electronics ####
* 9V battery
* Arduino-compatible Pro Mini with ATMega328p
* MAX7219 8 digit, 7 segment display module
* micro-servo motor
* latching-action pushbutton switch

#### Tools ####
* vinyl cutter
* drill press
* disc sander
* hot glue gun
* sewing needle + thread + scissors

#### Software ####
* [Arduino IDE](https://www.arduino.cc/en/Main/Software) (or compatible toolchain, eg. [PlatformIO](http://platformio.org/))
* [Silhouette Studio 3](http://www.silhouetteamerica.com/software)

## Hardware ##


## Software ##
I modified wayoda's [LedControl library](https://github.com/wayoda/LedControl) using a [patch written by giech](https://github.com/wayoda/LedControl/pull/13) for being able to render a greater variety of ASCII characters, as well as myself adding a `setByte()` function myself so I could render upside-down characters. 

As of July 2016, both of these modifications are waiting to be merged upstream. 
If you would like to see these features upstreamed into the LedControl library, please consider voting and/or commenting at the respective pull request pages! 
 
### Compilation Instructions ###
Use the Arduino IDE or PlatformIO

