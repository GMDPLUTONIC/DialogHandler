#pragma once
#include <Geode/Geode.hpp>
#include <unordered_map>
#include <viper.better_dialog/include/Main.hpp>
#include <fmt/core.h>
#include <fmt/format.h>

using namespace geode::prelude;

namespace MainFileUitl
{
    static void intperFile(std::string key) {
        std::filesystem::path configDir = Mod::get()->getConfigDir() / fmt::format("{}.json",key);
        if (!std::filesystem::exists(configDir)) {
            std::filesystem::path configDir = std::filesystem::current_path() / "dialogs" / fmt::format("{}.json",key); // for some old mod just in case ig
            if (!std::filesystem::exists(configDir)) {
                return;
            }
        }
         if (std::filesystem::exists(configDir)) {
            std::ifstream file(std::filesystem::path(configDir), std::ios::in | std::ios::binary);
                if (file.is_open()) {
                    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
                    file.close();
                    auto js = matjson::parse(content).unwrapOrDefault();
                    auto dialog = DialogApi::createWithJson(js);
                    dialog->animateInRandomSide();
                    dialog->addToMainScene();
                }
         }
    }
} // namespace MainFileUitl
