# B-CPP-500-PAR-5-1-rtype-martin.vanaud

`git clone git@github:EpitechPromo2025/...`

`git submodule update --init raylib/`

`mkdir -p Builds && cd Builds`

`conan install .. --build=missing -s compiler.libcxx=libstdc++11 -c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=True`
 
`cmake ..`

`cmake --build . -- -j 4`
