#ifndef EIO_WIDGET_HPP
#define EIO_WIDGET_HPP

#include "includes.hpp"

struct IWidget {
    virtual void load(Engine& e) = 0;
    virtual void render(Engine& e) = 0;
    // virtual void physics(Engine& e) {}
    virtual void Release() = 0;
};

static D2D1::ColorF str2color(std::string str) {
    static std::map<std::string, uint32_t> _colors;
    if (_colors.empty()) {
        _colors["AliceBlue"] = 0xF0F8FF;
        _colors["AntiqueWhite"] = 0xFAEBD7;
        _colors["Aqua"] = 0x00FFFF;
        _colors["Aquamarine"] = 0x7FFFD4;
        _colors["Azure"] = 0xF0FFFF;
        _colors["Beige"] = 0xF5F5DC;
        _colors["Bisque"] = 0xFFE4C4;
        _colors["Black"] = 0x000000;
        _colors["BlanchedAlmond"] = 0xFFEBCD;
        _colors["Blue"] = 0x0000FF;
        _colors["BlueViolet"] = 0x8A2BE2;
        _colors["Brown"] = 0xA52A2A;
        _colors["BurlyWood"] = 0xDEB887;
        _colors["CadetBlue"] = 0x5F9EA0;
        _colors["Chartreuse"] = 0x7FFF00;
        _colors["Chocolate"] = 0xD2691E;
        _colors["Coral"] = 0xFF7F50;
        _colors["CornflowerBlue"] = 0x6495ED;
        _colors["Cornsilk"] = 0xFFF8DC;
        _colors["Crimson"] = 0xDC143C;
        _colors["Cyan"] = 0x00FFFF;
        _colors["DarkBlue"] = 0x00008B;
        _colors["DarkCyan"] = 0x008B8B;
        _colors["DarkGoldenrod"] = 0xB8860B;
        _colors["DarkGray"] = 0xA9A9A9;
        _colors["DarkGreen"] = 0x006400;
        _colors["DarkKhaki"] = 0xBDB76B;
        _colors["DarkMagenta"] = 0x8B008B;
        _colors["DarkOliveGreen"] = 0x556B2F;
        _colors["DarkOrange"] = 0xFF8C00;
        _colors["DarkOrchid"] = 0x9932CC;
        _colors["DarkRed"] = 0x8B0000;
        _colors["DarkSalmon"] = 0xE9967A;
        _colors["DarkSeaGreen"] = 0x8FBC8F;
        _colors["DarkSlateBlue"] = 0x483D8B;
        _colors["DarkSlateGray"] = 0x2F4F4F;
        _colors["DarkTurquoise"] = 0x00CED1;
        _colors["DarkViolet"] = 0x9400D3;
        _colors["DeepPink"] = 0xFF1493;
        _colors["DeepSkyBlue"] = 0x00BFFF;
        _colors["DimGray"] = 0x696969;
        _colors["DodgerBlue"] = 0x1E90FF;
        _colors["Firebrick"] = 0xB22222;
        _colors["FloralWhite"] = 0xFFFAF0;
        _colors["ForestGreen"] = 0x228B22;
        _colors["Fuchsia"] = 0xFF00FF;
        _colors["Gainsboro"] = 0xDCDCDC;
        _colors["GhostWhite"] = 0xF8F8FF;
        _colors["Gold"] = 0xFFD700;
        _colors["Goldenrod"] = 0xDAA520;
        _colors["Gray"] = 0x808080;
        _colors["Green"] = 0x008000;
        _colors["GreenYellow"] = 0xADFF2F;
        _colors["Honeydew"] = 0xF0FFF0;
        _colors["HotPink"] = 0xFF69B4;
        _colors["IndianRed"] = 0xCD5C5C;
        _colors["Indigo"] = 0x4B0082;
        _colors["Ivory"] = 0xFFFFF0;
        _colors["Khaki"] = 0xF0E68C;
        _colors["Lavender"] = 0xE6E6FA;
        _colors["LavenderBlush"] = 0xFFF0F5;
        _colors["LawnGreen"] = 0x7CFC00;
        _colors["LemonChiffon"] = 0xFFFACD;
        _colors["LightBlue"] = 0xADD8E6;
        _colors["LightCoral"] = 0xF08080;
        _colors["LightCyan"] = 0xE0FFFF;
        _colors["LightGoldenrodYellow"] = 0xFAFAD2;
        _colors["LightGreen"] = 0x90EE90;
        _colors["LightGray"] = 0xD3D3D3;
        _colors["LightPink"] = 0xFFB6C1;
        _colors["LightSalmon"] = 0xFFA07A;
        _colors["LightSeaGreen"] = 0x20B2AA;
        _colors["LightSkyBlue"] = 0x87CEFA;
        _colors["LightSlateGray"] = 0x778899;
        _colors["LightSteelBlue"] = 0xB0C4DE;
        _colors["LightYellow"] = 0xFFFFE0;
        _colors["Lime"] = 0x00FF00;
        _colors["LimeGreen"] = 0x32CD32;
        _colors["Linen"] = 0xFAF0E6;
        _colors["Magenta"] = 0xFF00FF;
        _colors["Maroon"] = 0x800000;
        _colors["MediumAquamarine"] = 0x66CDAA;
        _colors["MediumBlue"] = 0x0000CD;
        _colors["MediumOrchid"] = 0xBA55D3;
        _colors["MediumPurple"] = 0x9370DB;
        _colors["MediumSeaGreen"] = 0x3CB371;
        _colors["MediumSlateBlue"] = 0x7B68EE;
        _colors["MediumSpringGreen"] = 0x00FA9A;
        _colors["MediumTurquoise"] = 0x48D1CC;
        _colors["MediumVioletRed"] = 0xC71585;
        _colors["MidnightBlue"] = 0x191970;
        _colors["MintCream"] = 0xF5FFFA;
        _colors["MistyRose"] = 0xFFE4E1;
        _colors["Moccasin"] = 0xFFE4B5;
        _colors["NavajoWhite"] = 0xFFDEAD;
        _colors["Navy"] = 0x000080;
        _colors["OldLace"] = 0xFDF5E6;
        _colors["Olive"] = 0x808000;
        _colors["OliveDrab"] = 0x6B8E23;
        _colors["Orange"] = 0xFFA500;
        _colors["OrangeRed"] = 0xFF4500;
        _colors["Orchid"] = 0xDA70D6;
        _colors["PaleGoldenrod"] = 0xEEE8AA;
        _colors["PaleGreen"] = 0x98FB98;
        _colors["PaleTurquoise"] = 0xAFEEEE;
        _colors["PaleVioletRed"] = 0xDB7093;
        _colors["PapayaWhip"] = 0xFFEFD5;
        _colors["PeachPuff"] = 0xFFDAB9;
        _colors["Peru"] = 0xCD853F;
        _colors["Pink"] = 0xFFC0CB;
        _colors["Plum"] = 0xDDA0DD;
        _colors["PowderBlue"] = 0xB0E0E6;
        _colors["Purple"] = 0x800080;
        _colors["Red"] = 0xFF0000;
        _colors["RosyBrown"] = 0xBC8F8F;
        _colors["RoyalBlue"] = 0x4169E1;
        _colors["SaddleBrown"] = 0x8B4513;
        _colors["Salmon"] = 0xFA8072;
        _colors["SandyBrown"] = 0xF4A460;
        _colors["SeaGreen"] = 0x2E8B57;
        _colors["SeaShell"] = 0xFFF5EE;
        _colors["Sienna"] = 0xA0522D;
        _colors["Silver"] = 0xC0C0C0;
        _colors["SkyBlue"] = 0x87CEEB;
        _colors["SlateBlue"] = 0x6A5ACD;
        _colors["SlateGray"] = 0x708090;
        _colors["Snow"] = 0xFFFAFA;
        _colors["SpringGreen"] = 0x00FF7F;
        _colors["SteelBlue"] = 0x4682B4;
        _colors["Tan"] = 0xD2B48C;
        _colors["Teal"] = 0x008080;
        _colors["Thistle"] = 0xD8BFD8;
        _colors["Tomato"] = 0xFF6347;
        _colors["Turquoise"] = 0x40E0D0;
        _colors["Violet"] = 0xEE82EE;
        _colors["Wheat"] = 0xF5DEB3;
        _colors["White"] = 0xFFFFFF;
        _colors["WhiteSmoke"] = 0xF5F5F5;
        _colors["Yellow"] = 0xFFFF00;
        _colors["YellowGreen"] = 0x9ACD32;
    }
    auto iter = _colors.find(str);
    if (iter == _colors.end())
        return D2D1::ColorF::Black;
    else return iter->second;
}

static std::istream& operator>>(std::istream& stream, D2D1::ColorF& color) {
    std::string str;
    stream >> str;
    if (str[0] == '#') {
        size_t c = std::stoi(str.substr(1));
        color = D2D1::ColorF(c);
    }
    else {
        color = str2color(str);
    }
    return stream;
}

#endif // !EIO_WIDGET_HPP
