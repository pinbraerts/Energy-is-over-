#ifndef EIO_GAME_HPP
#define EIO_GAME_HPP

#include "Widget.hpp"

struct Resources {
    std::map<std::wstring, HMODULE> modules;
    std::map<std::wstring, Factory> factories;

    void load(std::wstring path, std::vector<IWidget*>& ws) {
        std::wifstream source(path);

        while (source) {
            std::wstring name;
            source >> name;

            if (name.empty()) return;
            else if (name == L"import") {
                source >> name;
                HMODULE m = modules[name] = LoadLibrary(name.append(L".dll").c_str());
                Info i = (Info)GetProcAddress(m, "info");
                if (i == nullptr)
                    throw Error{};
                const char* x = i();
                while (x != nullptr && *x != '\0') {
                    size_t l = strlen(x);

                    factories[stows(x)] = (Factory)GetProcAddress(m, std::string("factory").append(x).c_str());

                    x += l + 1;
                }
                continue;
            }

            Factory f;
            auto i1 = factories.lower_bound(name);
            if (i1 == factories.end() || i1->first != name) {
                HMODULE m;
                auto iter = modules.lower_bound(name);
                if (iter == modules.end() || iter->first != name)
                    m = modules.insert(iter, { name, LoadLibrary(name.append(L".dll").c_str()) })->second;
                else
                    m = iter->second;

                f = factories.insert(i1, { name, (Factory)GetProcAddress(m, "factory") })->second;
                if (f == nullptr)
                    throw Error{};
            }
            else
                f = i1->second;

            if (IWidget* w = f(source))
                ws.push_back(w);
        }
    }

    ~Resources() {
        for (auto& m : modules)
            FreeLibrary(m.second);
    }
};

#endif // !EIO_GAME_HPP
