# Ccards
A card game written in c , with a basic bot as the  other player. [Rules.](rules.md)

## Prerequisites
to build : 
 *    [cmake](https://cmake.org/) (vers. > 3.0.0) 
 *    [ninja](https://github.com/ninja-build/ninja)

 to run: 
 * [for windows mingw should be installed, but no promises](https://dev.to/gamegods3/how-to-install-gcc-in-windows-10-the-easier-way-422j)
 
## Download
To download just: \
     `git clone https://github.com/o-dka/Ccards.git`  \
or click on a tag and dowload a zip file (binaries are there too sometimes, but aren't recommended).
then
 ```
     mkdir build 
     cmake -G Ninja -S /src -B /build
     cd build && ninja (cd build ;; ninja) on windows in powershell
 ```
 
 there should be a `Ccards_0_0_*` file, launch it.
## What if I want to change something?
The `deck_config.h` file is here! \
You can change the characters that appear in the middle of the card, the printing of it and values that are presented.
Some options I advise not to change, like max values and deck sizes. 
You will need to re-build the program if you want settings to change.
