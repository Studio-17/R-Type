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

## Installation

Download the latest version of our project on [our website](https://charles-app-zeta.vercel.app/download)

(To run a server on your local machine, please pull the image, and run the container using the following commands)
```bash
[sudo] docker pull martinvanaud/r-type_server

[sudo] docker run -dp 8080:${your-port} r-type_server
```

## Usage

### Creating a system
```c++
--- MySystem.hpp

class MySystem {
    public:
        MySystem() {};

        ~MySystem() = default;

        void operator()(Registry &registry,
                        Sparse_array<component::cnetwork_queue_t> &netqueue,
                        Sparse_array<component::component1_t> &component1,
                        Sparse_array<component::component2_t> &component2) {};

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
--- MyPacket.hpp

struct packet_mypacket {
    uint16_t foo;
    uint16_t bar;
    uint16_t foobar;
};

std::vector &serialized_packet = serialize_header::serializeHeader<packet_position>(NETWORK_SERVER_TO_CLIENT::PACKET_TYPE::MYPACKET, packet_mypacket)
---
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate and read the [CONTRIBUTING.md](https://github.com/EpitechPromo2025/B-CPP-500-PAR-5-1-rtype-martin.vanaud/blob/master/CONTRIBUTING.md)

## License
[MIT](https://choosealicense.com/licenses/mit/)