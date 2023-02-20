# DummyApp1

The DummyApp1 is an example application integrating the OpenLicenseModule. 
Once the license key is inserted, the application will verify it with every start. If you wish to change the key, delete the application settings file.

Linux:

`rm ~/.config/DummyOrg1/DummyApp1.conf`

Windows: 

delete Licensekey registry key at Computer\HKEY_CURRENT_USER\SOFTWARE\DummyOrg1\DummyApp1


## Supported operating systems
 - Linux(Ubuntu 22, Linux Mint 21)
 - Windows10, Windows11 
 
### Linux
Intall these to libraries.

`sudo apt install qt6-base-dev libqt6websockets6-dev libbotan-2-dev cmake build-essential libgl1-mesa-dev`

Download project and navigete to folder with the DummyApp1

`cd /path/to/DummyApp1`

Run cmake

`cmake .`

Make

`make`

Copy the application binary to a folder (e.g., /opt/DummyApp1/)

`cp DummyApp1 /opt/DummyApp1`

Run the application 

`/opt/DummyApp1/DummyApp1`


Although the deskop file could be provided, it seems unnecessary due to the nature of the application.

### Windows
install Qt6 with QtCreator

install MS Visual Studio 19 Tools

The most straightforward is to build the project with QT6 kit in release mode directly in Qt Creator IDE. For the demostration Qt 6.3.2 (installed int C:\Qt\) will be used, but feel free to substitute the version.

Copy the compiled application binary and module library to an empty folder.

`cp /path/to/build/folder/DummyApp1.exe /path/to/install/folder/`

Create an environment by running the command in command prompt

`C:\Qt\6.3.2\msvc2019_64\bin\qtenv2.bat`

use windeploy tool to deploy the application

`C:\Qt\6.3.2\msvc2019_64\bin\windeployqt.exe /path/to/DummyApp1.exe`

Copy botan.dll library to application directory

`cp /path/to/project/src/OpenLicenseCommunication/win64/botan.dll /path/to/folder/with/DummyApp1.exe/`


