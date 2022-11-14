# B-CPP-500-PAR-5-1-rtype

![image](https://github.com/EpitechPromo2025/B-CPP-500-PAR-5-1-rtype-martin.vanaud/blob/master/.github/files/rtype.jpg)

For those of you who may not know this best-selling video game, which accounts for countless lost hours
of our childhood, here is a little introduction.

This game is informally called a Horizontal Shmup (e.g. Shoot’em’up), and while R-Type is not the first one of
its category, this one has been a huge success amongst gamers in the 90’s, and had several ports, spin-offs,
and 3D remakes on modern systems.
Other similar and well known games are the Gradius series and Blazing Star on Neo Geo.

This version will be a network game, where one-to-four
players will be able to fight together the evil Bydos!



[![My Skills](https://skills.thijs.gg/icons?i=cpp,docker,git)](https://skills.thijs.gg)

## Installation

### Client

You can download the latest version of our client project on [our website](https://charles-app-zeta.vercel.app/download).

Or if you want to run it manually do the following commands :

```bash
git clone git@github:EpitechPromo2025/...

git submodule update --init vcpkg

cd vcpkg/
./bootstrap-vcpkg.sh
./vcpkg integrate install
./vcpkg install

cd ../
cmake -B Builds/ -DCMAKE_BUILD_TYPE=Release
cmake --build Builds/ --config Release
```

### Server

To run a server on your local machine, please pull the image, and run the container using the following commands :
```bash
[sudo] docker pull martinvanaud/r-type_server

[sudo] docker run -dp 8080:${your-port} r-type_server
```

## Usage

### Creating a component

```c++
--- MyComponent.hpp

namespace component {
    struct my_component {
        ...
    };
}
```

### Creating a system
```c++
--- MySystem.hpp

class MySystem {
    public:
        MySystem() {};

        ~MySystem() = default;

        void operator()(Registry &registry,
                        ...Sparse_array<component::component1_t> &component1) {};

    protected:

    private:
};

---

--- Main.cpp

    void configureMySystem(Registry &_registry) {

        MySystem _anAmazingSystem
        
        _registry.register_component<component::component1_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
        _registry.register_component<component::component2_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});

        _registry.add_system(_anAmazingSystem, _registry.get_components<component::component1_t>(), _registry.get_components<component::component2_t>());

        Entity e = _registry.spawn_entity();

        component::component1_t component1 = { foo, fizz };
        _registry.add_component<component::component1_t>(_registry.entity_from_index(e), std::move(component1));

        component::component2_t component2 = { bar, buzz, foo };
        _registry.add_component<component::component2_t>(_registry.entity_from_index(e), std::move(component2));

    }

    int main() {
        
        Registry _registry;

        configureMySystem(_registry);

        while (true) {
            _registry.run_systems();
        }

    }

  ---
```

### Adding a packet
```c++
--- Serialization.hpp

namespace NETWORK_SERVER_TO_CLIENT {
    enum PACKET_TYPE {
        ...
        MYPACKET
    };
};

---

--- MyPacket.hpp

struct packet_mypacket {
    uint16_t foo;
    uint16_t bar;
    uint16_t foobar;
};

std::vector &serialized_packet = serialize_header::serializeHeader<packet_mypacket>(NETWORK_SERVER_TO_CLIENT::PACKET_TYPE::MYPACKET, packet_mypacket)
---
```

## Customization

You can customize the aspect of your client via JSON configuration files.

### Textures

```JSON
--- assets.json

"myAssets": {
    "title": "myAssets",
    "nbFrame": 2,
    "texture": "Path/To/MyAssets.png",
    "scale": 2
}
```

### Images

```JSON
--- images.json

"myImage": {
    "ref": "myImage",
    "textureId": "myAssets",
    "position": [0, 0],
    "sound": "mySound",
    "velocity": 0,
    "scene": 0,
    "direction": [0, 0]
}
```

### Buttons

```JSON
--- buttons.json

"myButton": {
    "ref": "myButton",
    "textureId": "myTexture",
    "position": [0, 0],
    "nbFrame": 3,
    "audio": "mySound",
    "text": {
        "text": "myTextToPrint",
        "color": [150, 150, 150, 255],
        "size": 40,
        "position": [120, 30]
    },
    "scene": 4,
    "callback-type": "myCallBack"
},
```

### Sounds
```JSON
--- sounds.json

"mySound": {
    "title": "mySound",
    "soundPath": "Path/To/My/Sound.ogg"
},
```

### Texts
```JSON
--- texts.json

"myText": {
    "ref": "myText",
    "text": "myTextToPrint",
    "color": [150, 150, 150, 255],
    "size": 50,
    "position": [1300, 225],
    "scene": 10
},
```

Add a new scene just like this, and set the id of your scene where you want your entity to be printed :

```c++
--- Constant.hpp

enum SCENE {
    ...
    MYSCENE
};
```

You also customize the different types of enemies that the server will make apear.

### Enemies

```JSON
--- Enemy.json

"myEnemy": {
    "direction": [-1, 0],
    "hitbox": [10, 10],
    "velocity": 4,
    "type": 6,
    "rect": [34, 33],
    "health": 1
},

--- Serialization.hpp

// Add the type of your new enemy

enum ENTITY_TYPE {
    ...
    MyEnemyType
};
```

### Leveling

You can also design yourself the different level of your game. <br/>
To add new level simply add file ".txt" in the Assets/Maps folder and that's it ! <br/>
Now draw inside your new file your level. <br/>
By default, 0 is representing and empty space, 1 a class 1 spaceship, 2 a class two spachip, 3 a big robot.

```txt
---myMap.txt

1000333
3330233
3333333
1230000

```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate and read the [CONTRIBUTING.md](https://github.com/EpitechPromo2025/B-CPP-500-PAR-5-1-rtype-martin.vanaud/blob/master/CONTRIBUTING.md)

## Documentation

You can find our Doxygen documentation here :
[Doygen doumentation](https://myepitech.github.io/index.html).

## License
[MIT](https://choosealicense.com/licenses/mit/)