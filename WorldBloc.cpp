//
// Created by guill on 16.01.2022.
//

#include "WorldBloc.h"

using namespace sf;
using namespace std;
using namespace cpp_sfml;

WorldBloc::WorldBloc(sf::Vector2f &pos, sf::Color &color, float size) {
   _position = pos;

   _type = getType(color);

   float x = pos.x;
   float y = pos.y;

   _vertex = sf::VertexArray(PrimitiveType::Quads, 4);

   _vertex[0].position = Vector2f(x + 0000, y + 0000);
   _vertex[1].position = Vector2f(x + 0000, y + size);
   _vertex[2].position = Vector2f(x + size, y + size);
   _vertex[3].position = Vector2f(x + size, y + 0000);

   Color renderColor = getRenderColor();

   _vertex[0].color = renderColor;
   _vertex[1].color = renderColor;
   _vertex[2].color = renderColor;
   _vertex[3].color = renderColor;
}

Vector2f WorldBloc::getPos() {
   return _position;
}

VertexArray WorldBloc::getVertex() {
   return _vertex;
}

WorldBlocType WorldBloc::getType(Color color) {
   if (color.r == 0 && color.g == 255 && color.b == 0)
      return WorldBlocType::FLOOR;

   return WorldBlocType::BACKGROUND;
}

Color WorldBloc::getRenderColor() {
   switch (_type) {
      case WorldBlocType::BACKGROUND:
         return Color(150, 150, 150);
         break;
      case WorldBlocType::FLOOR:
         return Color::Green;
         break;
   }
}