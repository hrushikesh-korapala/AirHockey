# AirHockey
## Dependencies
``` bash
sudo apt-get install libopusfile-dev
sudo apt-get install libxmp-dev
sudo apt-get install libfluidsynth-dev
sudo apt-get install libwavpack-dev
sudo apt-get install libfreetype6-dev
```
## Testing
``` bash
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
make -j
./bin/SDLTest 
```