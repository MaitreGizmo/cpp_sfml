//
// Created by guill on 16.01.2022.
//

#ifndef MAIN_CPP_SETTINGS_H
#define MAIN_CPP_SETTINGS_H

#include <string>

namespace cpp_sfml {

   static const unsigned    WINDOW_WIDTH    = 1600;
   static const unsigned    WINDOW_HEIGHT   = 800;
   static const std::string WINDOW_TITLE    = "CPP_SFML";
   static const float       WORLD_BLOC_SIZE = 20;

   enum class WorldBlocType {
      BACKGROUND = 0,
      FLOOR
   };
}

#endif //MAIN_CPP_SETTINGS_H
