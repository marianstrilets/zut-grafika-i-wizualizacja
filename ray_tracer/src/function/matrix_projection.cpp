//
// Created by Marian on 5/25/2023.
//

#include <iostream>
#include "../rt.h"

/// \fn    draw_robot()
/// \brief Funkcja dla testowania macierzy rzutowania
///
void matrix_projection(CRayTrace &rayTrace){

    CCamera cam1;
    CCamera cam2;
    glm::mat3 matrix1;
    glm::mat3 matrix2;

    /// Dane kamery 1
    cam1.eyep = {0,0,10};    // Pozycja kamery
    cam1.lookp = {0,0,0};    // Punkt docelowy kamery
    cam1.up = {0,1,0};       // Orientacja kamery
    cam1.fov = 50;                   // Pole widzenia, zakres <0,180)
    cam1.width = 500;                // Rozdzielczość pozioma w pikselach
    cam1.height = 400;               // Rozdzielczość pionowa w pikselach

    /// Dane kamery 2
    cam2.eyep = {2,5,10};    // Pozycja kamery
    cam2.lookp = {-2,1,0};    // Punkt docelowy kamery
    cam2.up = {0,1,0};       // Orientacja kamery
    cam2.fov = 50;                   // Pole widzenia, zakres <0,180)
    cam2.width = 500;                // Rozdzielczość pozioma w pikselach
    cam2.height = 400;               // Rozdzielczość pionowa w pikselach

    rayTrace.compPrimaryRayMatrix(cam1, matrix1);
    rayTrace.compPrimaryRayMatrix(cam2, matrix2);


    std::cout<< "\t-------- TEST CScene::create() (cw.4)-------\n";
    std::cout << "   Macierz rzutowania (Przyklad 1):\n";
    PRINT_MAT3(matrix1);
    std::cout<<"-------------------------"<<std::endl;
    std::cout << "   Macierz rzutowania (Przyklad 1):\n";
    PRINT_MAT3(matrix2);
    std::cout<< "\t==============================================\n";
}

