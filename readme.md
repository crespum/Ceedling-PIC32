# Ceedling + PIC32 + Harmony boilerplate

This project intends to be a boilerplate for integrating unit testing in a PIC32 environment. It contains a sample unit test for a Neopixel. The I2C drivers have also been enabled using Harmony to show how to compile and link them.


## Prerequisites
The tests has just been run on Linux (Debian).

1. Install [MPLAB X IDE](http://www.microchip.com/mplab/mplab-x-ide)
2. Install [XC32 1.43](http://www.microchip.com/mplab/compilers) at `/opt/microchip/xc32/v1.43/`
3. Install [Harmony v1.11](http://www.microchip.com/mplab/mplab-harmony) at `/opt/microchip/harmony/v1_11/`. Be careful not to use version 2.x which is currently in a beta stage.
4. Open MPLAB, go to *Tools > Plugins Downloads* and install the Harmony Configurator v1.0.10.0 **DO NOT INSTALL v2**
5. Install [ceedling](https://github.com/ThrowTheSwitch/ceedling) using `sudo gem install ceedling`

These paths can be modified at `project.yml` and `test/simulation/sim_test_fixture.rb`.

## Build and compile the project
1. Open MPLAB
2. Click *File > Open Project* and go to the *firmware* folder and select the folder test_ceedling.X
3. Right click on the project name (left panel) and click *Set as Main Project*
4. Now we need to generate the Harmony related files. Go to *Tools > Embedded > MPLAB Harmony Configurator* and once inside click the button in the top to generate the code.
5. Now click *Clean and build*

## Build, compile and run the unit tests
There are some basic commands for executing ceedling from `$PROJECT_PATH/firmware`:

   * `rake test:all` runs all tests in the MPLAB-SIM Simulator using the Microchip Debugger (MDB).
   * `rake release` generates the `.hex` output.

## Acknowledgements

The main tools used here (Ceedling, Unity and CMock) have been developed by the [Throw The Switch community](http://www.throwtheswitch.org/). Thanks for your work!

The project is based on [this repository](https://github.com/ThrowTheSwitch/CeedlingExample_Microchip) for 16 bit PICs. A detailed explanation of how to setup this project can be read in [this other blog post](http://spin.atomicobject.com/2012/10/22/getting-started-with-tdd-for-microchips-pics/).

The book [Test-Driven Development for Embedded C](https://pragprog.com/book/jgade/test-driven-development-for-embedded-c) by James W. Grenning is a great introduction to Unit Testing in embedded devices. Some other people has also written great [posts](http://dmitryfrank.com/articles/unit_testing_embedded_c_applications) on this topic.
