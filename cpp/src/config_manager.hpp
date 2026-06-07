#pragma once

#include <string>
#include <unordered_map>

namespace core
{
    class ConfigManager
    {
    public:
        static ConfigManager &get()
        {
            static ConfigManager instance;
            return instance;
        }

        bool load();
        bool save();

        std::string getString(
            const std::string& section,
            const std::string& key,
            const std::string& defaultValue = "");

        int getInt(
            const std::string& section,
            const std::string& key,
            int defaultValue = 0);

        float getFloat(
            const std::string& section,
            const std::string& key,
            float defaultValue = 0.0f);

        bool getBool(
            const std::string& section,
            const std::string& key,
            bool defaultValue = false);

        void setValue(
            const std::string& section,
            const std::string& key,
            const std::string& value);

    private:
        ConfigManager() = default;

        std::unordered_map<
            std::string,
            std::unordered_map<std::string, std::string>
        > _data;

        const std::string _filename = "config.ini";
    };
}