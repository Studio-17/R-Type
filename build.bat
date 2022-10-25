conan install . --output-folder cmake-build --build=missing -c tools.system.package_manager:mode=installs -c tools.system.package_manager:sudo=True
cmake -B Builds -G "Visual Studio 17 2022" -DCMAKE_TOOLCHAIN_FILE=cmake-build/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
cmake --build Builds --config Release
