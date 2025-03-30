# 7-Segment-Thermometer
A simple project using two onewire thermal sensors an arduino nano and a four digit common cathode seven-segment display

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#Prerequisites">Prerequisites</a></li>
        <li><a href="#Installation">Installation</a></li>
        <li><a href="#building-the-circuit">Building the circuit</a></li>
        <li><a href="#how-it-works">How It Works</a></li>
      </ul>
    </li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contact">Contact</a></li>
        <li><a href="#license">License</a></li>
  </ol>
</details>

## About The Project
This is a simple project created using an Arduino Nano paired with two thermal sensors (DS18B20 or compatible) and a seven-segment display used to show the temperature both inside and outside of my room. 
<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- GETTING STARTED -->
## Getting Started

Replicating the project

### Prerequisites

* Arduino IDE
    * install from the Arduino library manager
        * OneWire.h
        * DallasTemperature.h

### Installation

1. Clone the repo
```sh
git clone https://github.com/enragedcanadiangoose/7-Segment-Thermometer.git
```
2. Open the "./7-Segment-Thermometer/Thermometer/" folder in the Arduino IDE

### Building The Circuit

<img src="schematic/Thermometer.svg" alt="Schematic" width="100%" style="background-color:white">  
<p>You can follow this diagram to replicate the circuit I used, this should let the code function with no modification</p>
<img src="images/breadBoard.jpg" alt="Schematic" width="100%" style="background-color:white">  
<p>Here is the version that I built on a prototyping breadboard, it's a bit of a sloppy prototype but it works</p>

### How It Works

* The Arduino polls the active thermal sensor every 30s for up to keep the data being displayed up to date
    * The display will blank during this time since the Arduino can't draw the display and poll the sensors simultaneously
* The desired thermal sensor is selected using the toggle switch
* The presence of the decimal point indicates if the temperature is positive or negative
    * on = ≥ 0
    * off = ≤ 0
<p align="right">(<a href="#readme-top">back to top</a>)</p>
## Roadmap

<p>At some point a run of PCBs may be ordered</p>
<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Contact
<p>email: astew2693@gmail.com</p>
<p align="right">(<a href="#readme-top">back to top</a>)</p>

## License

<p>see <a href="https://github.com/enragedcanadiangoose/7-Segment-Thermometer/blob/main/LICENSE">LICENSE</a> for details</p>