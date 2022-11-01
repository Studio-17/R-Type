git submodule update --init vcpkg

cd vcpkg
./bootstrap-vcpkg.bat
./vcpkg integrate install
./vcpkg install asio
./vcpkg install nlohmann-json

cd ..
cmake -B Builds -G "Visual Studio 17 2022" -S . -DCMAKE_BUILD_TYPE=Debug
cmake --build Builds --config Debug