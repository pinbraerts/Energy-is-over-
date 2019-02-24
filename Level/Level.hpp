#ifndef EIO_OBJECTS_HPP
#define EIO_OBJECTS_HPP

#include "../include/Engine.hpp"
#include "../include/Widget.hpp"

IWidget* factoryFinish(std::istream& s);
IWidget* factoryPlayer(std::istream& s);
IWidget* factoryMagnetic(std::istream& s);

constexpr char _classes[] = "Finish\0Player\0Magnetic\0";
const char* info();

struct Finish: IWidget, D2D1_RECT_F {
    using D2D1_RECT_F::D2D1_RECT_F;

    Finish(std::istream& s);

    D2D1::ColorF color;
    ID2D1Brush* b = nullptr;

    void load(Engine& e) override;
    void render(Engine& e) override;
    void Release() override;
};

struct Player: IWidget, D2D1_POINT_2F, IBody {
    float radius;
    float energy = 1;

    Player(std::istream& s);

    D2D1::ColorF color = D2D1::ColorF::Black;
    ID2D1Brush* b = nullptr;
    ID2D1Brush* a = nullptr;

    void load(Engine& e) override;
    void render(Engine& e) override;
    void Release() override;

    void check_collisions(Engine& e, const IWidget& other);

    struct Photon: D2D1_POINT_2F, IBody {
        Photon(D2D1_POINT_2F p, D2D1_VECTOR_2F s);

        void render(Engine& e, Player& p);
    };
    std::vector<Photon> photons;

    float last_photon_time = -10.0f;
    float time_between_photons = 0.5f;
    float photon_quant = 10;
    float photon_radius = 1;
    float photon_mass = 1.0f;
    float photon_speed = 20;
};

struct Magnetic: IWidget, D2D1_RECT_F {
    constexpr static float Constant = 0.5f;

    float induction;

    Magnetic(std::istream& s);

    D2D1::ColorF color = D2D1::ColorF::Black;
    ID2D1Brush* b = nullptr;

    void load(Engine& e) override;
    void render(Engine& e) override;
    void Release() override;
};

#endif // !EIO_OBJECTS_HPP
