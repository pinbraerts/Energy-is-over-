#ifndef EIO_WIDGET_HPP
#define EIO_WIDGET_HPP

#include "includes.hpp"

struct IWidget {
    virtual void load(Engine& e) = 0;
    virtual void render(Engine& e) = 0;
    // virtual void physics(Engine& e) {}
    virtual void Release() = 0;
};

static D2D1::ColorF str2color(std::wstring str) {
    static std::map<std::wstring, uint32_t> _colors;
    if (_colors.empty()) {
        _colors[L"AliceBlue"] = 0xF0F8FF;
        _colors[L"AntiqueWhite"] = 0xFAEBD7;
        _colors[L"Aqua"] = 0x00FFFF;
        _colors[L"Aquamarine"] = 0x7FFFD4;
        _colors[L"Azure"] = 0xF0FFFF;
        _colors[L"Beige"] = 0xF5F5DC;
        _colors[L"Bisque"] = 0xFFE4C4;
        _colors[L"Black"] = 0x000000;
        _colors[L"BlanchedAlmond"] = 0xFFEBCD;
        _colors[L"Blue"] = 0x0000FF;
        _colors[L"BlueViolet"] = 0x8A2BE2;
        _colors[L"Brown"] = 0xA52A2A;
        _colors[L"BurlyWood"] = 0xDEB887;
        _colors[L"CadetBlue"] = 0x5F9EA0;
        _colors[L"Chartreuse"] = 0x7FFF00;
        _colors[L"Chocolate"] = 0xD2691E;
        _colors[L"Coral"] = 0xFF7F50;
        _colors[L"CornflowerBlue"] = 0x6495ED;
        _colors[L"Cornsilk"] = 0xFFF8DC;
        _colors[L"Crimson"] = 0xDC143C;
        _colors[L"Cyan"] = 0x00FFFF;
        _colors[L"DarkBlue"] = 0x00008B;
        _colors[L"DarkCyan"] = 0x008B8B;
        _colors[L"DarkGoldenrod"] = 0xB8860B;
        _colors[L"DarkGray"] = 0xA9A9A9;
        _colors[L"DarkGreen"] = 0x006400;
        _colors[L"DarkKhaki"] = 0xBDB76B;
        _colors[L"DarkMagenta"] = 0x8B008B;
        _colors[L"DarkOliveGreen"] = 0x556B2F;
        _colors[L"DarkOrange"] = 0xFF8C00;
        _colors[L"DarkOrchid"] = 0x9932CC;
        _colors[L"DarkRed"] = 0x8B0000;
        _colors[L"DarkSalmon"] = 0xE9967A;
        _colors[L"DarkSeaGreen"] = 0x8FBC8F;
        _colors[L"DarkSlateBlue"] = 0x483D8B;
        _colors[L"DarkSlateGray"] = 0x2F4F4F;
        _colors[L"DarkTurquoise"] = 0x00CED1;
        _colors[L"DarkViolet"] = 0x9400D3;
        _colors[L"DeepPink"] = 0xFF1493;
        _colors[L"DeepSkyBlue"] = 0x00BFFF;
        _colors[L"DimGray"] = 0x696969;
        _colors[L"DodgerBlue"] = 0x1E90FF;
        _colors[L"Firebrick"] = 0xB22222;
        _colors[L"FloralWhite"] = 0xFFFAF0;
        _colors[L"ForestGreen"] = 0x228B22;
        _colors[L"Fuchsia"] = 0xFF00FF;
        _colors[L"Gainsboro"] = 0xDCDCDC;
        _colors[L"GhostWhite"] = 0xF8F8FF;
        _colors[L"Gold"] = 0xFFD700;
        _colors[L"Goldenrod"] = 0xDAA520;
        _colors[L"Gray"] = 0x808080;
        _colors[L"Green"] = 0x008000;
        _colors[L"GreenYellow"] = 0xADFF2F;
        _colors[L"Honeydew"] = 0xF0FFF0;
        _colors[L"HotPink"] = 0xFF69B4;
        _colors[L"IndianRed"] = 0xCD5C5C;
        _colors[L"Indigo"] = 0x4B0082;
        _colors[L"Ivory"] = 0xFFFFF0;
        _colors[L"Khaki"] = 0xF0E68C;
        _colors[L"Lavender"] = 0xE6E6FA;
        _colors[L"LavenderBlush"] = 0xFFF0F5;
        _colors[L"LawnGreen"] = 0x7CFC00;
        _colors[L"LemonChiffon"] = 0xFFFACD;
        _colors[L"LightBlue"] = 0xADD8E6;
        _colors[L"LightCoral"] = 0xF08080;
        _colors[L"LightCyan"] = 0xE0FFFF;
        _colors[L"LightGoldenrodYellow"] = 0xFAFAD2;
        _colors[L"LightGreen"] = 0x90EE90;
        _colors[L"LightGray"] = 0xD3D3D3;
        _colors[L"LightPink"] = 0xFFB6C1;
        _colors[L"LightSalmon"] = 0xFFA07A;
        _colors[L"LightSeaGreen"] = 0x20B2AA;
        _colors[L"LightSkyBlue"] = 0x87CEFA;
        _colors[L"LightSlateGray"] = 0x778899;
        _colors[L"LightSteelBlue"] = 0xB0C4DE;
        _colors[L"LightYellow"] = 0xFFFFE0;
        _colors[L"Lime"] = 0x00FF00;
        _colors[L"LimeGreen"] = 0x32CD32;
        _colors[L"Linen"] = 0xFAF0E6;
        _colors[L"Magenta"] = 0xFF00FF;
        _colors[L"Maroon"] = 0x800000;
        _colors[L"MediumAquamarine"] = 0x66CDAA;
        _colors[L"MediumBlue"] = 0x0000CD;
        _colors[L"MediumOrchid"] = 0xBA55D3;
        _colors[L"MediumPurple"] = 0x9370DB;
        _colors[L"MediumSeaGreen"] = 0x3CB371;
        _colors[L"MediumSlateBlue"] = 0x7B68EE;
        _colors[L"MediumSpringGreen"] = 0x00FA9A;
        _colors[L"MediumTurquoise"] = 0x48D1CC;
        _colors[L"MediumVioletRed"] = 0xC71585;
        _colors[L"MidnightBlue"] = 0x191970;
        _colors[L"MintCream"] = 0xF5FFFA;
        _colors[L"MistyRose"] = 0xFFE4E1;
        _colors[L"Moccasin"] = 0xFFE4B5;
        _colors[L"NavajoWhite"] = 0xFFDEAD;
        _colors[L"Navy"] = 0x000080;
        _colors[L"OldLace"] = 0xFDF5E6;
        _colors[L"Olive"] = 0x808000;
        _colors[L"OliveDrab"] = 0x6B8E23;
        _colors[L"Orange"] = 0xFFA500;
        _colors[L"OrangeRed"] = 0xFF4500;
        _colors[L"Orchid"] = 0xDA70D6;
        _colors[L"PaleGoldenrod"] = 0xEEE8AA;
        _colors[L"PaleGreen"] = 0x98FB98;
        _colors[L"PaleTurquoise"] = 0xAFEEEE;
        _colors[L"PaleVioletRed"] = 0xDB7093;
        _colors[L"PapayaWhip"] = 0xFFEFD5;
        _colors[L"PeachPuff"] = 0xFFDAB9;
        _colors[L"Peru"] = 0xCD853F;
        _colors[L"Pink"] = 0xFFC0CB;
        _colors[L"Plum"] = 0xDDA0DD;
        _colors[L"PowderBlue"] = 0xB0E0E6;
        _colors[L"Purple"] = 0x800080;
        _colors[L"Red"] = 0xFF0000;
        _colors[L"RosyBrown"] = 0xBC8F8F;
        _colors[L"RoyalBlue"] = 0x4169E1;
        _colors[L"SaddleBrown"] = 0x8B4513;
        _colors[L"Salmon"] = 0xFA8072;
        _colors[L"SandyBrown"] = 0xF4A460;
        _colors[L"SeaGreen"] = 0x2E8B57;
        _colors[L"SeaShell"] = 0xFFF5EE;
        _colors[L"Sienna"] = 0xA0522D;
        _colors[L"Silver"] = 0xC0C0C0;
        _colors[L"SkyBlue"] = 0x87CEEB;
        _colors[L"SlateBlue"] = 0x6A5ACD;
        _colors[L"SlateGray"] = 0x708090;
        _colors[L"Snow"] = 0xFFFAFA;
        _colors[L"SpringGreen"] = 0x00FF7F;
        _colors[L"SteelBlue"] = 0x4682B4;
        _colors[L"Tan"] = 0xD2B48C;
        _colors[L"Teal"] = 0x008080;
        _colors[L"Thistle"] = 0xD8BFD8;
        _colors[L"Tomato"] = 0xFF6347;
        _colors[L"Turquoise"] = 0x40E0D0;
        _colors[L"Violet"] = 0xEE82EE;
        _colors[L"Wheat"] = 0xF5DEB3;
        _colors[L"White"] = 0xFFFFFF;
        _colors[L"WhiteSmoke"] = 0xF5F5F5;
        _colors[L"Yellow"] = 0xFFFF00;
        _colors[L"YellowGreen"] = 0x9ACD32;
    }
    auto iter = _colors.find(str);
    if (iter == _colors.end())
        return D2D1::ColorF::Black;
    else return iter->second;
}

static std::wistream& operator>>(std::wistream& stream, D2D1::ColorF& color) {
    std::wstring str;
    stream >> str;
    if (str[0] == L'#') {
        uint32_t c = std::stoi(str.substr(1));
        color = D2D1::ColorF(c);
    }
    else {
        color = str2color(str);
    }
    return stream;
}

#endif // !EIO_WIDGET_HPP
