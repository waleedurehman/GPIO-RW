GPIO-RW
-------
Read and Write GPIO RaspberryPi 3 Model B+

System
------
LINUX FEDORA CINNAMON_X64 Release 28

Kernel
4.17.7-200.fc28.x86_64

.C Files
--------

The C library "libtoggle.c" provides basic GPIO Read and Write Operations.

The C program "toggle.c" can set, clear or read any of the 3 mentioned GPIO pins 17, 22, and 27.

Compile and Run
---------------
*  `git clone https://github.com/waleedurehman/GPIO-RW.git`

*  `cd GPIO-RW`

*  `chmod 777 test.sh`

*  `make`

*  `./toggle --help`

The program will not run on your local machine since it tries
to access the GPIO of the RPi. It may result in a "mmap error".

To run this program on your RPi compile and run this program as
mentioned above.

Make will create a shared library "libtoggle.so". This may create
an error saying no shared library exists. To solve this get the
path where you cloned the repository.

*  `cd GPIO-RW`

*  `pwd`

*  `LD_LIBRARY_PATH=/....../GPIO-RW`







Source: https://elinux.org/RPi_GPIO_Code_Samples
