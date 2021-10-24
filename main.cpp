#include <SFML/Graphics.hpp>
#include "cMatrix.h"
#include "cVector.h"
#include "cCube.hpp"
#include "ctm.h"
#include <iostream>
#include <iterator>
#include <vector>

int funkcja(std::vector<int> &tablica)
{
    return std::size(tablica);
}

int main()
{
//aplikacja konsolowa


//    cVector V0(3, 4);
//    cVector V1=V0;

//    double tablica0[] = {1,0,0,1,
//                         0,1,0,1,
//                         0,0,1,0,
//                         0,0,0,1
//                          };
//
//    double tablica1[] = {1,2,3,1};
//
//    cMatrix M0(4,1);
//    cMatrix M1(4);
//    cMatrix M3(4,1) ;
//    M0.mFill(tablica1,4);
//   std::cout <<  M0 << endl;
//    std::cout << std::endl;
//
//    M1.mFill(tablica0,16);
//    M1.mShow();
//    std::cout << std::endl;
//
//    //M0.addMatrix(M1);
//    //M0.multiMatrix(M1);
//    //std::cout << "mnozenie start" << std::endl;
//    M3 = M0 * M1;// * M1;
//    //std::cout << "mnozenie wykonane" << std::endl;
//    M3.mShow();
//    std::cout << std::endl;
//
//   M0.mShow();

//aplikacja okienkowa
    const int width = 400, height = 300;
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(width, height), "SFML window");

    // create an empty shape
    sf::ConvexShape convex;

    //creating cube object
    cCube kostka(width/2, height/2, 100);
//cCube kostka(0, 0, 100);
    //kostka.fillVector2d();
    //std::cout << "kostka" << std::endl;
//    kostka.print();

    //kostka.rotateX(0.1);
    //Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }

        // Clear screen
        app.clear();

        // Draw the sprite
        //app.draw(convex);
        //kostka.print();
        kostka.rotateX(0.00002);
        kostka.rotateY(0.0001);
//        kostka.rotateZ(0.0001);

        //kostka.addPerspective();
        kostka.update();

        //ctm::rotationX(kostka, 0.1);
        app.draw(kostka);

        // draw it
        //app.draw(vertices, 4, sf::Lines);

        // Update the window
        app.display();
        //kostka.reverseUpdate();
    }
//    std::cout << "po petli" << std::endl;
    //kostka.print();
    std::cout << "return 0" << std::endl;
    return 0;
}
