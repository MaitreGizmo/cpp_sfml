//
// Created by guill on 16.01.2022.
//

#ifndef CPP_SFML_MAINWINDOW_H
#define CPP_SFML_MAINWINDOW_H

#include <vector>
#include <string>

#include <SFML/Graphics.hpp>

#include "WorldBloc.h"

namespace cpp_sfml {

   class MainWindow {
   public:
      MainWindow(unsigned width, unsigned height, const std::string &title);

      void render();

   private:
      unsigned    _width;
      unsigned    _height;
      std::string _title;

      sf::RenderWindow _window;

      std::vector<WorldBloc> _world;

      void dispatchEvents();

      void displayFrame();

      void close();

      void loadMap();
   };

}

#endif //CPP_SFML_MAINWINDOW_H
