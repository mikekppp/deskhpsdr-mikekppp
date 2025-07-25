# deskHPSDR by DL1BZ

<img src="https://github.com/dl1bz/deskhpsdr/blob/master/release/deskhpsdr/screenshot.png" width="1024px" />

This is a hamradio application for SDR devices with HPSDR protocol 1 and 2, based at codeparts of [piHPSDR](https://github.com/dl1ycf/pihpsdr). But anywhere, it's not piHPSDR and has no backward dependencies to piHPSDR. My goal was to make an more optimzed version running with Desktop-OS like Linux and macOS, what means I don't support small displays less as 1280x600 like such for Raspberry Pi or similiar devices. In the case mini-display you need to fallback to piHPSDR, deskHPSDR don't support this anymore.

**deskHPSDR need a screen size 1280x600 at minimum or higher** for best GUI experiences, that's one of the difference against piHPSDR. deskHPSDR hasn't a special Client-Server-Mode like pihpsdr (make no sense, we HAVE network-connected SDR devices yet).

My main focus of deskHPSDR development, the improvements and additional functions against piHPSDR is the Hermes Lite 2 SDR Transceiver and his similar devices based on the same hardware platform like the Square-SDR. Other SDR devices can be used too if supported, but I cannot check it. The second focus is macOS, which is my primary development environment for deskHPSDR. Normally all should be running with Linux too. The third focus is Fonie/SSB/Digimodes and less CW. This SDR software app is made for SDR transceiver used in Hamradio, less for wide-range RX-only SDR devices. If you agree with me and my ideas, deskHPSDR can be very useful for you. If not, look around for other solutions.

More information about the develop progress of deskHPSDR can be found here in my Blog:<br>
[https://hamradio.bzsax.de/category/hamradio/deskhpsdr/](https://hamradio.bzsax.de/category/hamradio/deskhpsdr/) (German language only).

## deskHPSDR was forked once from pihpsdr - <br>but is now no more comparable with piHPSDR !

piHPSDR was first developed by John Melton, G0ORX/N6LYT a few years ago.<br>Later Christoph, DL1YCF, had continued the development of piHPSDR. His version [https://github.com/dl1ycf/pihpsdr](https://github.com/dl1ycf/pihpsdr) is the most up-to-date version of piHPSDR and  is actively being developed by him up to now.<br><br>So his codebase of piHPSDR was my starting point end of October, 2024. But anyway, there is and will be no direct collaboration between piHPSDR and deskHPSDR.<br><br>
Today deskHPSDR go an entire own way. deskHPSDR has got many new functions they are not available in piHPSDR. Things that deskHPSDR doesn't need have also been removed, they exist furthermore in piHPSDR, but are no longer as parts of deskHPSDR. deskHPSDR is a kind of evolution from piHPSDR with completely different objectives.

## Requirements

* a modern Desktop-OS like Linux or macOS with installed developer tools like compiler, linker etc.
* a large screensize starts at 1280x600 or higher
* basic knowledge: how to use your OS, a shell, a text editor and how to compile applications from source code
* *macOS only*: please read the ```COMPILE.macOS``` first
* *Linux only*: please read the ```COMPILE.linux``` first
* a SDR device or transceiver, which supports HPSDR protocol 1 (older) or 2 (newer) like the Hermes Lite 2, the ANAN or similiar devices. Soapy-API based SDR can be used too, but with limitations because of the Soapy-API implementation. Per default Soapy-API is disabled, if needed you must activate Soapy-API support in the ```make.config.deskhpsdr``` as an user-defined option
* a very good running network without any issues (Ethernet preferred, WiFi not recommended) and an DHCP server inside (without DHCP is possible too, but more complicated or difficult working with the SDR devices)
* for Hermes Lite 2 specific notes look into the ```Notes_if_using_HERMES-Lite-2.md```

## I want use now deskHPSDR. What I need to do ?

deskHPSDR is published exclusively as source code only. You need to clone this Github repository and compile the app before you can use it. Please read all included instructions carefully to avoid installation errors by yourself. Additional notes you can find too under the discussion tab of this project. Please have a look there too from time to time.<br>
I will never publish any ready-compiled binaries, neither for macOS nor for Linux. The task of compiling it yourself remains.

## The further development of deskHPSDR

My work is not completed (are software projects ever finished ???). I have some ideas, what I need to add too. You need to understand this branch as "work in progress". I ever check my code here with my test environment: Intel iMac 21" i5 and Macbook Air M1 running both with macOS 14.7.1 aka Sonoma and my SDR tranceiver Hermes-Lite 2 in combination with my homebrew-LDMOS-PA 600W. My focus is Fonie/SSB and Digimode/FT8+FT4, less CW.

## Latest Changes

**CHANGES are moved now to the [Discussions tab, category CHANGELOG deskhpsdr](https://github.com/dl1bz/deskhpsdr/discussions/categories/changelog-deskhpsdr).**

### Version 2.6.0 (final version [current])

On March 4, 2025 the **first final version 2.6 of deskHPSDR** is published. This version will not get any brand-new base functions, only bugfixes if any become known or improvements if I think there's still something to be done yet. Further development will start later from version 2.7.x after a short break in development.<br>
**Changes / Corrections after Version 2.5 and implement into 2.6**
- some minor code adjustments for better program and functions logic (dependencies and correlations), remove/change code which is not supported at all compilers and linkers for better compatibility and interoperability between macOS and Linux
- add two new level bars for MicLvl and ALCLvl if analog S-Meter is selected
- new design for the MicLvl meter and assign now the Mic Gain Level for MicLvl meter from the WDSP audio chain
- if selected **Optimize_for_Touch** in Radio Menu change some sliders to spin-buttons for better experience at slider surface (with spin-buttons instead sliders we can increase the preciseness of adjust values at touch operation)
- relation between RX panadapter and waterfall now adjustable in Display Menu
- add a worldmap as background for the RX panadapter (in the ```make.config.deskhpsdr``` set WMAP=ON)
- change band borders in the RX panadapter (vertical red lines) from US (default) to IARU Reg. 1 (if want use set in the ```make.config.deskhpsdr``` REGION1=ON)
- if using a Hermes Lite 2 you can use Autogain now (like in Thetis), set if want using in the ```make.config.deskhpsdr``` AUTOGAIN=ON
- background color of the slider surface can be user-defined now in the Screen Menu
- slider geometry is adjustable now via a Slider Surface Resize Factor in the Screen Menu
- add TUNE Drv and Audio Input Selection into the slider surface for direct access (go to TX Menu no more required)

### Version 2.5.x (first developer version [deprecated])
- completed: if using Hermes-Lite 2 add autogain regulation as option for RxPGA gain (need insert AUTOGAIN=ON in ```make.config.deskhpsdr```)
- completed: fix a segmentation fault of deskHPSDR if using SDR-RX-only devices like SDRplay via Soapy-API after start the SDR device
- completed: if using Hermes-Lite 2 activate CL1 input for inject external 10 MHz reference (e.g. with a GPSDO)
- completed: add (if in duplex mode) the audio level monitoring in the separated TX window too (feature request by CU2ED)
- completed: remove "horizontal stacking" display option for panadapter in screen menu, that disturbs a lot of my changed GUI design
- completed: remove all old piHPSDR Client-Server code, deskHPSDR doesn't support this "One-App-Limited" Client-Server concept
- completed: fix some display errors if horizontal screen resolution >= 1280px and duplex selected (issue by CU2ED, tnx)
- completed: show own callsign in upper left corner of RX panadapter, callsign is configurable in Radio menu (feature request by CU2ED)
- completed: show S meter values if using analogue S meter (feature request by CU2ED)
- completed: if using Hermes Lite 2 TX power slider show now TX output in W (step-size 0.1W) instead of a scale between 0-100
- completed: add more keyboard shortcuts (feature request by DH0DM)
- under development: begin implementation to full-automatic control the RxPGA gain if using a Hermes Lite 2
- completed: merge the new PEAK label feature from piHPSDR into deskHPSDR and add an option for show the peak label as S-Meter values instead of dbm
- completed: add an option for using 3 Mic profiles, which can save and load different audio settings (CFC, TX-EQ, Limiter, Basebandcompressor) if using different types of Mics with special settings per Mic. Load and save is only possible in modes LSB, USB or DSB. Other modes are not supported. If mode is DIGL or DIGU the access to the RX- and TX-EQ is now blocked, because is it important that the frequency spectrum is not manipulated if using digi modes.
- under development: implementation of a TCI Server, which emulates a SunSDR2Pro device (successful tested with JTDX, RumLogNG, MacLoggerDX)<br>
- completed: add an additional serial device interface option, which can switch ON the RTS and/or DTR signal line during TUNE function and PTT output (feature request by DD8JM for TUNE and by CU2ED for PTT output)
- under development: sereral GUI improvements for show additional status infos on the screen<br>
- under development: make deeper access possible to the whole audio tools like CFC, Compressor, phase rotator for the user<br>
- completed: add an additional, adjustable up to +20db, AF preamp for increasing mic input level if required<br>
- under development: automatic switching of different audio inputs depends from the selected mode with automatic save settings<br>
- completed: remove most of the limitations at 60m band (remove channelizing and other non-essential things)<br>
- completed: add new UDP listener for my RX200 ESP32 project, which send via UDP broadcast data in JSON<br>
  format like forward and reflected power, SWR and show the received and parsed data onscreen<br>
  as panadapter overlay (need now json-c as additional lib, so please install it)<br>
- completed: add new serial device, which can be used as an external PTT input using RTS & CTS signaling similar like Thetis

Things marked as "under development" are not fully tested and have maybe issues.<br>
Things marked as "completed" are tested a longer time and will work without known issues up to now.<br>

Most of the new functions need to be activated in the ```make.config.deskhpsdr``` as compiling option. Please look in the beginning of the  ```Makefile``` and set the needed options only in ```make.config.deskhpsdr```, but don't modify the ```Makefile``` itself !

## Issues and Discussion tab at Github for this project - read carefully !

- the **Issues tab is only for reporting issues, bugs or malfunctions of this app** !
- for all other things please use necessarily the [discussions tab](https://github.com/dl1bz/deskhpsdr/discussions/categories/changelog-deskhpsdr)

## Known problems if using Git for update the code base at your local computer

In the ```Makefile``` I add a comment "don't edit this Makefile". That's I mean so. I'm now add the editable, additional file for this called ```make.config.deskhpsdr```.<br>
But if you have such file yet or edit it and make after this a ```git pull``` , git maybe come back with an error message.<br>
 In this case try this:<br>
```
$ mv make.config.deskhpsdr make.config.deskhpsdr.save
$ git pull
$ rm make.config.deskhpsdr
$ mv make.config.deskhpsdr.save make.config.deskhpsdr
$ git update-index --assume-unchanged make.config.deskhpsdr
```
After this, ```git pull``` should work correct.<br>
Background about this: I made a mistake in the ```.gitignore```, but I correct it in the meantime. ```git pull``` see local changes with this file (if edit) and stop working, because this file is not identical with the file from the upstream master branch.<br>
```git update-index --assume-unchanged make.config.deskhpsdr``` inform git, that this file need to be ignored in the future, so you can edit it how you need.<br>
**If this not help, please delete the complete codebase of deskHPSDR and clone it again, then you have a fresh copy.**<br>

If ```git pull``` failed, you can also try this:<br>
```
$ git pull
$ git reset --hard origin/master
```
This overwrite local changes, which are different from the remote repo at Github.com and set the status equal between local and remote.

## Successful and confirmed Tests I had done up to now

So far, deskHPSDR has been successfully tested on the following systems:<br>
* iMac 21" i5 running macOS 14.7.x aka Sonoma
* Macbook Air M1 running macOS 14.7.x aka Sonoma
* Raspberry Pi5 with NVMe-HAT running 64bit PiOS and X11 environment
* *Raspberry Pi 3B+ works too, but with limitations (panadapter framerate only 10fps, if want more the CPU hasn't enough power)*
* a hamradio friend of mine has checked it on a Desktop Linux Ubuntu LTS for me, works too

**All radio tests are made with my Hermes Lite 2 SDR-Transceiver using HPSDR protocol V1 under macOS 14.7.4.**
**There are no issues with the Hermes Lite 2 and deskHPSDR yet, but it is not possible to check ALL other exist SDR devices.**

## Credits

Big thanks and huge respect to all involved developers for their previous great work on piHPSDR until now and make this application accessible as Open Source under the GPL. Many thanks also to the users who gave me feedback and reported issues which I hadn't noticed by myself.

## Exclusion of any Guarantee and any Warrenty

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

All what you do with this code is at your very own risk. The code is published "as it is" without right of any kind of support or similiar services.
