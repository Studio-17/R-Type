/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** loadfile
*/

#include <nlohmann/json.hpp>

std::vector<std::unique_ptr<Object::IObject>> loadGenericObjects(std::string const &filepath)
{
    nlohmann::json jsonData;
    std::vector<std::unique_ptr<Object::IObject>> objects;
    std::map<std::string, std::unique_ptr<Object::IObject> (*)(nlohmann::json const &jsonData)> allConstruct {
        {"button", takeComponent<Object::Button>},
        {"text", takeComponent<Object::Text>},
        {"image", takeComponent<Object::Image>},
    };

    try {
        jsonData = getJsonData(filepath);
    } catch (Error::FileError const &e) {
        std::cerr << e.what() << std::endl;
        return {};
    }
    for (auto oneData : jsonData) {
        std::string type = oneData.value("type", "default");
        std::function<std::unique_ptr<Object::IObject>(nlohmann::json const &jsonData)> func;

        if (type == "default")
            throw Error::FileError("undefined type in " + filepath + " configuration file");
        try {
            func = allConstruct.at(type);
        } catch (std::out_of_range const &e) {
            throw Error::FileError("type " + type + " is undefined");
        }
        objects.emplace_back(func(oneData));
    }
    return objects;
}