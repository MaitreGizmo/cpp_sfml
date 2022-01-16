//
// Created by guill on 16.01.2022.
//

#include <iostream>

#include "MainWindow.h"
#include "Settings.h"

using namespace std;
using namespace cpp_sfml;
using namespace sf;

MainWindow::MainWindow(unsigned width, unsigned height, const string &title) {
   _width  = width;
   _height = height;
   _title  = title;
}

void MainWindow::render() {
   _window.create(VideoMode(_width, _height), _title, Style::Close);

//   createTestVertices();

   loadMap();

   while (_window.isOpen()) {
      dispatchEvents();


      displayFrame();
   }
}

void MainWindow::dispatchEvents() {
   Event e;

   while (_window.pollEvent(e)) {
      switch (e.type) {
         case sf::Event::Closed:
            close();
            break;
      }
   }
}

void MainWindow::displayFrame() {
   _window.clear();

   // display world
   for (WorldBloc bloc: _world) {
      _window.draw(bloc.getVertex());
   }

   _window.display();
}

void MainWindow::close() {
   _window.close();
}

void MainWindow::loadMap() {
   Image map;
   map.loadFromFile(R"(C:\workspace\cpp_sfml\ressources\map_1.bmp)");

   for (int x = 0; x < 80; ++x) {
      float posX = x * WORLD_BLOC_SIZE;

      for (int y = 0; y < 40; ++y) {
         Color color = map.getPixel(x, y);

         Vector2f pos(posX, y * WORLD_BLOC_SIZE);

         WorldBloc bloc(pos, color, WORLD_BLOC_SIZE);

         _world.push_back(bloc);
      }
   }
}


