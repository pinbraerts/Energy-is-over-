#ifndef EIO_GAMEPAD_HPP
#define EIO_GAMEPAD_HPP

#include "includes.hpp"
#include <xinput.h>
#pragma comment(lib, "xinput")

struct Gamepad {
    XINPUT_STATE states[2];
    unsigned char current_state = 0;
    float dead_zone = 0.1f;
    DWORD id = XUSER_MAX_COUNT;

    Gamepad() {
        try_reconnect();

        if (connected()) {
            previous() = current();
        }
    }

    inline XINPUT_STATE& current() {
        return states[current_state];
    }
    inline XINPUT_STATE& previous() {
        return states[!current_state];
    }
    inline const XINPUT_STATE& current() const {
        return states[current_state];
    }
    inline const XINPUT_STATE& previous() const {
        return states[!current_state];
    }
    inline bool connected() {
        return id < XUSER_MAX_COUNT;
    }
    void try_reconnect() {
        id = XUSER_MAX_COUNT;

        for (DWORD i = 0; i < XUSER_MAX_COUNT; ++i) {
            if (XInputGetState(i, &current()) == ERROR_SUCCESS) {
                id = i;
            }
        }
    }
    void update_state() {
        if (!connected()) {
            try_reconnect();
            if (!connected()) return;
        }
        current_state = !current_state;
        if (XInputGetState(id, &current()) != ERROR_SUCCESS) {
            id = XUSER_MAX_COUNT;
            return;
        }
        D2D1_VECTOR_2F stick = left_stick();
        float mod = abs(stick);
        if (mod < dead_zone) {
            current().Gamepad.sThumbLX = current().Gamepad.sThumbLY = 0;
        }
        else {
            mod = (mod - dead_zone) / (1 - dead_zone);
            normalize(stick) *= mod;
            current().Gamepad.sThumbLX = (short)(mod * current().Gamepad.sThumbLX);
            current().Gamepad.sThumbLY = (short)(mod * current().Gamepad.sThumbLY);
        }
        stick = right_stick();
        mod = abs(stick);
        if (mod < dead_zone) {
            current().Gamepad.sThumbRX = current().Gamepad.sThumbRY = 0;
        }
        else {
            mod = (mod - dead_zone) / (1 - dead_zone);
            normalize(stick) *= mod;
            current().Gamepad.sThumbRX = (short)(mod * current().Gamepad.sThumbRX);
            current().Gamepad.sThumbRY = (short)(mod * current().Gamepad.sThumbRY);
        }
    }
    inline D2D1_VECTOR_2F right_stick() const {
        return { (float)current().Gamepad.sThumbRX / SHORT_MAX / 2, -(float)current().Gamepad.sThumbRY / SHORT_MAX / 2 };
    }
    inline D2D1_VECTOR_2F left_stick() const {
        return { (float)current().Gamepad.sThumbLX / SHORT_MAX / 2, -(float)current().Gamepad.sThumbLY / SHORT_MAX / 2 };
    }
    inline float left_trigger() const {
        return (float)current().Gamepad.bLeftTrigger / 255.0f;
    }
    inline float right_trigger() const {
        return (float)current().Gamepad.bRightTrigger / 255.0f;
    }
    inline D2D1_RECT_F dpad() const {
        return {
            (float)pressed(Button::Left),
            (float)pressed(Button::Up),
            (float)pressed(Button::Right),
            (float)pressed(Button::Down),
        };
    }
    enum class Button {
        A = XINPUT_GAMEPAD_A,
        B = XINPUT_GAMEPAD_B,
        X = XINPUT_GAMEPAD_X,
        Y = XINPUT_GAMEPAD_Y,
        Start = XINPUT_GAMEPAD_START,
        Back = XINPUT_GAMEPAD_BACK,
        Left = XINPUT_GAMEPAD_DPAD_LEFT,
        Up = XINPUT_GAMEPAD_DPAD_UP,
        Right = XINPUT_GAMEPAD_DPAD_RIGHT,
        Down = XINPUT_GAMEPAD_DPAD_DOWN,
        LS = XINPUT_GAMEPAD_LEFT_THUMB,
        RS = XINPUT_GAMEPAD_RIGHT_THUMB,
        RB = XINPUT_GAMEPAD_RIGHT_SHOULDER,
        LB = XINPUT_GAMEPAD_LEFT_SHOULDER,
    };
    inline bool pressed(Button b) const {
        return current().Gamepad.wButtons & (size_t)b;
    }
};

#endif // !EIO_GAMEPAD_HPP
