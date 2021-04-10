# HACK36_2021
HACK36 project repository

* Project name: Olyauha

* Track: Women's safety

* Team: valentin_video_monitoring

* Contributors: 
    1. Anton Belyi (MIPT, Russia)
    2. Dmitry Anokhov (MPEI, Russia)

* Tech stack:
    1. c++
    2. cmake
    3. bash

* Idea:
    After discussing women's safety theme with
    female part of Karelia programming community,
    we realized that some women feel unsafe while being outside
    the house, especially alone or close to night.
    We came up with idea of that mobile application.
    We believe it could make live a bit safier for women.

* Functionality:
    1. Ability to look on map depending on geolocation.
    2. Map has different rates of danger on it.
    3. People can give their own rates and comments for 
    different locations.
    4. It has allert button, if user click it, ither users closer
    to first user recieve push-notification.
    5. It may also be possible that allert button would be able
    to notify closest police department.
    6. Of course, in order to prevent false-notifications,
    person would recieve warning

* Implementation:
    1. In large perspective our application
    requires advanced database, graphics, server manipulation
    2. We prepared out little working prototype.
    3. We haven't implemented visual part yet, 
    but console application works fine, and even stores data 
    on computer after build.

* How to build and run: (Linux or Windows+msys2)
    1. mkdir some_folder
    2. cd some_folder
    3. git clone https://github.com/antonis-white/HACK36_2021.git .
    4. mkdir build
    5. cd build
    6. cmake ..
    7. make
    8. cd ..
    9. ./run.sh
