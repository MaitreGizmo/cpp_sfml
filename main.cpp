#include <iostream>
#include <cstdlib>
#include <limits>
#include <vector>

#include <SFML/Graphics.hpp>

using namespace std;

void dispatchEvents();

void displayFrame();

sf::RenderWindow        _window;
vector<sf::VertexArray> _vertices = {};

int main() {
   _window.create(sf::VideoMode(800, 600), "cpp_sfml / SFML Works !");

   while (_window.isOpen()) {
      dispatchEvents();

      displayFrame();
   }

   cout << "Press ENTER to quit ...";
   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   return EXIT_SUCCESS;
}

void dispatchEvents() {
   sf::Event e;

   while (_window.pollEvent(e)) {
      switch (e.type) {
         case sf::Event::Closed:
            _window.close();
            break;
      }
   }
}

void displayFrame() {
   _window.clear();

   _window.display();
}