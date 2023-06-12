//
// Created by Marian on 5/25/2023.
//

#include <iostream>
#include "../rt.h"

/// \fn    draw_robot()
/// \brief Funkcja rysująca robota
///
void draw_robot() {
    CImage img(700, 700);
    glm::vec3 color_orange(255,165,0);  // orange
    glm::vec3 color_red(0.9,0.1,0.1);   // red
    glm::vec3 color_green(0.1,0.9,0.1); // green
    glm::vec3 color_blue(0,0,255);      // blue

    ///----------------------------- Rysowanie okręgu ------------------------------------------------------------------
    glm::vec3 pp(0.0,0.6,1.0);  // Środek okręgu
    float radius = 0.1f;    // Promień okręgu
    img.drawCircle(pp, radius, color_orange);   // Rysowanie okręgu

    ///----------------------------- Rysowanie prostokąta centalnego ---------------------------------------------------
    glm::vec3 pp0(0.15, 0.45, 1);
    glm::vec3 pp1(-0.15, 0.45, 1);
    glm::vec3 pp2(-0.15, -0.05, 1);
    glm::vec3 pp3(0.15, -0.05, 1);

    // rysowanie prostokąta
    img.drawLine(pp0, pp1, color_red);
    img.drawLine(pp1, pp2, color_red);
    img.drawLine(pp2, pp3, color_red);
    img.drawLine(pp3, pp0, color_red);

    ///----------------------------- Rysowanie prostokąta prawy górny --------------------------------------------------
    float scaling_X = 1.0f;         // skalowania po osi X
    float scaling_Y = 0.2f;         // skalowania po osi Y
    float translation_X = -0.35f;   // translacja po osi X
    float translation_Y = 0.36f;    // translacja po osi Y
    glm::mat3x3 matrix_scaling {{scaling_X,0,0}, {0,scaling_Y,0}, {translation_X,translation_Y,1}}; // Macierz prostokąta
    PRINT_MAT3(matrix_scaling);

    // skalowania i translacja wierzchołków
    pp0 = matrix_scaling * pp0;
    pp1 = matrix_scaling * pp1;
    pp2 = matrix_scaling * pp2;
    pp3 = matrix_scaling * pp3;

    // rysowanie prostokąta
    img.drawLine(pp0, pp1, color_green);
    img.drawLine(pp1, pp2, color_green);
    img.drawLine(pp2, pp3, color_green);
    img.drawLine(pp3, pp0, color_green);

    ///----------------------------- Rysowanie prostokąta lewy górny ---------------------------------------------------
    translation_X = 0.7f; // translacja po osi X
    translation_Y = 0.0f; // translacja po osi Y
    matrix_scaling = {{1,0,0}, {0,1,0}, {translation_X,translation_Y,1}}; // Macierz prostokąta
    PRINT_MAT3(matrix_scaling);

    // translacja wierzchołków
    pp0 = matrix_scaling * pp0;
    pp1 = matrix_scaling * pp1;
    pp2 = matrix_scaling * pp2;
    pp3 = matrix_scaling * pp3;

    // rysowanie prostokąta
    img.drawLine(pp0, pp1, color_green);
    img.drawLine(pp1, pp2, color_green);
    img.drawLine(pp2, pp3, color_green);
    img.drawLine(pp3, pp0, color_green);

    ///----------------------------- Rysowanie prostokąta lewy dolny ---------------------------------------------------
    //=============================================
    //Macierz obrotu wokół punktu (0, 0) o kąt (theta)
    //      {{cos(theta),sin(theta),0}, {-sin(theta),cos(theta),0}, {0,0,1}}
    //=============================================
    float theta = glm::radians(-45.0f);
    translation_X = -0.22f; // translacja po osi X
    translation_Y = -0.22f; // translacja po osi Y

    glm::mat3x3 matrix_rotation{
            {std::cos(theta), std::sin(theta),0},
            {-std::sin(theta), std::cos(theta),0},
            {translation_X,translation_Y,1}
    }; // Macierz prostokąta

    PRINT_MAT3(matrix_rotation);

    // translacja i obrót wierzchołków
    pp0 = matrix_rotation * pp0;
    pp1 = matrix_rotation * pp1;
    pp2 = matrix_rotation * pp2;
    pp3 = matrix_rotation * pp3;

    // rysowanie prostokąta
    img.drawLine(pp0, pp1, color_blue);
    img.drawLine(pp1, pp2, color_blue);
    img.drawLine(pp2, pp3, color_blue);
    img.drawLine(pp3, pp0, color_blue);

    ///----------------------------- Rysowanie prostokąta prary dolny ---------------------------------------------------
    translation_X = -0.49f; // translacja po osi X
    translation_Y = -0.49f; // translacja po osi Y

    theta = glm::radians(90.0f);
    matrix_rotation = {
            {std::cos(theta), std::sin(theta),0},
            {-std::sin(theta), std::cos(theta),0},
            {translation_X,translation_Y,1}
    }; // Macierz prostokąta
    PRINT_MAT3(matrix_rotation);

    // translacja i obrót wierzchołków
    pp0 = matrix_rotation * pp0;
    pp1 = matrix_rotation * pp1;
    pp2 = matrix_rotation * pp2;
    pp3 = matrix_rotation * pp3;

    // rysowanie prostokąta
    img.drawLine(pp0, pp1, color_blue);
    img.drawLine(pp1, pp2, color_blue);
    img.drawLine(pp2, pp3, color_blue);
    img.drawLine(pp3, pp0, color_blue);
    ///=====================================================================================================================
    img.save("robot.png");
    cv::imshow("ROBOT", img.getImage());
    cv::waitKey();
}
