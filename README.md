# B-CPP-500-PAR-5-1-rtype

![image](https://github.com/EpitechPromo2025/B-CPP-500-PAR-5-1-rtype-martin.vanaud/.github/files/rtype.jpg)

For those of you who may not know this best-selling video game, which accounts for countless lost hours
of our childhood, here is a little introduction.

This game is informally called a Horizontal Shmup (e.g. Shoot’em’up), and while R-Type is not the first one of
its category, this one has been a huge success amongst gamers in the 90’s, and had several ports, spin-offs,
and 3D remakes on modern systems.
Other similar and well known games are the Gradius series and Blazing Star on Neo Geo.

This version will be a network game, where one-to-four
players will be able to fight together the evil Bydos!

## Installation

Use the package manager [pip](https://pip.pypa.io/en/stable/) to install foobar.

```bash
git clone git@github:EpitechPromo2025/...

git submodule update --init raylib/

mkdir -p Builds && cd Builds

conan install .. --build=missing -s compiler.libcxx=libstdc++11 -c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=True
 
cmake ..

cmake --build . -- -j 4
```

## Usage

### Creating a system
```bash
```

### Adding a packet
```bash
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate and read the [CONTRIBUTING.md](https://github.com/EpitechPromo2025/B-CPP-500-PAR-5-1-rtype-martin.vanaud/CONTRIBUTING.md)

## License
[MIT](https://choosealicense.com/licenses/mit/)