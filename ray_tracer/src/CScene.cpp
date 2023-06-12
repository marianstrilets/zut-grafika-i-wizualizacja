//
//  CScene.cpp
//  rt
//
//  Created by Radoslaw Mantiuk on 22/01/2023.
//

#include "rt.h"
#include<fstream>

/// \fn     create(void)
/// \brief  Dodaje komponenty do sceny.
///
void CScene::create() {
    
    lightList.clear();  // czyści wektor z danymi światła
    objectList.clear(); // czyści wektor wskaźników do obiektów

    ///Obliczanie parametrów macierzy rzutowania perspektywicznego na podstawie danych kamery

    // wskazuje na kierunek od pozycji kamery do punktu docelowego kamery
    glm::vec3 look = cam.lookp - cam.eyep;

    glm::vec3 crossUpLook = glm::cross(cam.up, look);
    glm::vec3 u = crossUpLook / glm::length(crossUpLook);

    glm::vec3 crossULook = glm::cross(u, look);
    glm::vec3 v = crossULook / glm::length(crossULook);

    glm::vec3 o = (look / glm::length(look)) *
            (cam.width / (2 * tan(cam.fov / 2))) -
            ( (cam.width / 2.0f) * u + (cam.height / 2.0f) * v);

    /// Macierz rzutowania
    //  Macierz rzutowania jest reprezentacją kamery służącą do obliczania kierunku promieni pierwotnych z uwzględnie-
    //  niem projekcji perspektywicznej sceny. Macierz przyjmuje formę: matrix_projection;

    glm::mat3x3 matrix_projection {
        {u.x,u.y,u.z},
        {v.x,v.y,v.z},
        {o.x,o.y,o.z}
    }; // Macierz rzutowania

    std::cout<< "\n\t-------- TEST CScene::create() (cw.3)-------\n";
    std::cout<<"\tMacierz rzutowania:\n";
    PRINT_MAT3(matrix_projection);
    std::cout<< "\t==============================================\n";

}

