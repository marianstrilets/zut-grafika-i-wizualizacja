//
// Created by Marian on 5/25/2023.
//

#include <iostream>
#include "../rt.h"

/// /// Funkcja rysujca dwa trójkąta i okręg
void draw_triangles() {

    CImage img(1000, 1000);

    glm::vec3 color1(0.9,0.1,0.1); // red
    glm::vec3 color2(0.1,0.9,0.1); // green
    glm::vec3 color3(255,165,0);   // orange

    // draw circle
    glm::vec3 pp(0.0,0.0,1.0);
    float radius = 0.1f;
    img.drawCircle(pp, radius, color3);

    // triangle vertices
    glm::vec3 pp0(0.4, 0.3, 1);
    glm::vec3 pp1(-0.4, 0.3, 1);
    glm::vec3 pp2(0.4, -0.3, 1);

    // draws triangle in 2D
    img.drawLine(pp0, pp1, color1);
    img.drawLine(pp1, pp2, color1);
    img.drawLine(pp2, pp0, color1);

    // translation
    float tX = 0.2f; // OX translation
    float tY = 0.1f; // OY translation
    glm::mat3x3 mTrans {{1,0,0}, {0,1,0}, {tX,tY,1}}; // translation matrix
    PRINT_MAT3(mTrans);

    // translation of vertices
    pp0 = mTrans * pp0;
    pp1 = mTrans * pp1;
    pp2 = mTrans * pp2;

    // draws triangle after translation
    img.drawLine(pp0, pp1, color2);
    img.drawLine(pp1, pp2, color2);
    img.drawLine(pp2, pp0, color2);

    img.save("robot.png");
    cv::imshow("ROBOT", img.getImage());
    cv::waitKey();

}
