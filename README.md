# Fully Functional Keylogger  

## Introduction  

I took this [Udemy Course](https://www.udemy.com/how-to-create-an-advanced-keylogger-from-scratch-for-windows "Build an Advanced Keylogger using C++ for Ethical Hacking! - Created by Ermin Kreponic") to improve my programming knowledge in C++, and also, because I want to learn about CMake build system generator, I will use CMake for this application.

This is advanced fully functional keylogger build from scratch with C++ for Windows only. **This keylogger is capable of recording all the keyboard and mouse input!** It can even record independent of the language settings because it logs the physical keys on the keyboard first. Next, by using an arbitrary keymap with human friendly names, it translates the machine keys to something that we can understand. It also possesses mail sending capabilities so you can just schedule the logfile to be sent via mail, lets say every 12 hours. In addition to this, it will also keep the logfile encrypted. Therefore, there is another program which will be able to decrypt the logfile.

**Please use the code for education purpose only! If you choose to use this keylogger for any illegal or immoral purposes, you risk losing a lot. This is only for educational purposes. The keylogger that you are going to build will be able to cause some serious damage, so please use it in a legal and responsible way.**

## Progress of the project

| Task                                        | Current Status                              |
|---------------------------------------------|---------------------------------------------|
| Added main.cpp in ./src                 |   in progress :negative_squared_cross_mark: |
| Added KeyConstrants.h in ./include/ |   Done        :white_check_mark:            |
| Added Helper.h in ./include/        |   Done        :white_check_mark:            |
| Added Base64.h in ./include/        |   Done        :white_check_mark:            |
| Added IO.h in ./include/            |   Done        :white_check_mark:            | 

### Info about Headers

* Base64.h: Modified version of *Base64 Algorithm* for encoding *Encryption* and *Decription*.

* IO.h: All functions for *input / output* operations like:
creating files, reading from them, finding paths etc.