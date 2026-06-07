#include "config_manager.hpp"
#include <fstream>
#include <algorithm>

namespace core
{

    bool ConfigManager::save()
    {
        std::ofstream file(_filename);

        if (!file.is_open())
            return false;

        for (const auto &section : _data)
        {
            file << "[" << section.first << "]\n";

            for (const auto &kv : section.second)
            {
                file << kv.first
                     << "="
                     << kv.second
                     << "\n";
            }

            file << "\n";
        }

        return true;
    }

    bool ConfigManager::load()
    {
        std::ifstream file(_filename);

        if (!file.is_open())
        {
            setValue("Display", "fullscreen", "true");
            setValue("Display", "width", "1920");
            setValue("Display", "height", "1080");

            save();
            return true;
        }
    }

    std::string ConfigManager::getString(const std::string &section, const std::string &key, const std::string &defaultValue)
    {
        auto sectionIt = _data.find(section);

        if (sectionIt == _data.end())
            return defaultValue;

        auto keyIt = sectionIt->second.find(key);

        if (keyIt == sectionIt->second.end())
            return defaultValue;

        return keyIt->second;
    }

    int ConfigManager::getInt(const std::string &section, const std::string &key, int defaultValue)
    {
        try
        {
            return std::stoi(getString(section, key, std::to_string(defaultValue)));
        }
        catch (...)
        {
            return defaultValue;
        }
    }

    float ConfigManager::getFloat(const std::string &section, const std::string &key, float defaultValue)
    {
        try
        {
            return std::stof(getString(section, key, std::to_string(defaultValue)));
        }
        catch (...)
        {
            return defaultValue;
        }
    }

    bool ConfigManager::getBool(const std::string &section, const std::string &key, bool defaultValue)
    {
        std::string value = getString(section, key, defaultValue ? "true" : "false");

        std::transform(value.begin(), value.end(), value.begin(),
                       [](unsigned char c)
                       {
                           return static_cast<char>(std::tolower(c));
                       });

        return value == "true" || value == "1" || value == "yes" || value == "on";
    }

    void ConfigManager::setValue(const std::string &section, const std::string &key, const std::string &value)
    {
        _data[section][key] = value;
    }
}