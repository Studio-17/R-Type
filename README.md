# B-CPP-500-PAR-5-1-rtype-martin.vanaud

`sudo docker build -t r-type-container .`

`sudo docker run --rm -v "/home/casimir/Desktop/B-CPP-500-PAR-5-1-rtype-martin.vanaud/:/home/r-type/" -it r-type-container /bin/bash`

`conan install .. --build=missing -c tools.system.package_manager:mode=install`

`cmake ..`

`cmake --build .`
