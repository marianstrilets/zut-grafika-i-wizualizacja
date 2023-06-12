
#include <iostream>
#include "rt.h"

extern void draw_robot();
extern void draw_triangles();
extern void matrix_projection(CRayTrace &rayTrace);



/// r1.9
int main (int argc, char * const argv[]) {

    ///--- Przekształcenia geometryczne z wykorzystaniem biblioteki GLM (ćw.2) --
    //draw_triangles();
    //draw_robot();
    std::cout << std::endl << "\tray tracing ..."<< std::endl;

    ///------------ Obliczanie parametrów macierzy rzutowania (ćw.3) ------------
    CScene scene;
    scene.create(); // definiuje przykładowe parametry sceny
    if(scene.cam.width == 0) {
        std::cout << "WARNING: scene not defined" << std::endl;
        return -1;
    }

    ///---------------------- Macierz rzutowania (ćw.4) -------------------------
    CRayTrace rt;
    matrix_projection(rt);

    ///------------- Obliczanie kierunku promienia pierwotnego (ćw.5) -----------
    CRay ray;

    //------------------------------------
    CCamera cam;
    cam.eyep = {0,0,10};
    cam.lookp = {0,0,0};
    cam.up = {0,1,0};
    cam.fov = 50;
    cam.width = 500;
    cam.height = 400;
    //------------------------------------

    glm::vec3 dir1;
    /*
    glm::vec3 dir2;
    glm::vec3 dir3;
    glm::vec3 dir4;
    glm::vec3 dir5;
    */

    float fx1;
    float fy1;

    /*
    float fx2;
    float fy2;
    float fx3;
    float fy3;
    float fx4;
    float fy4;
    float fx5;
    float fy5;
    */

    dir1 = ray.primaryRay(cam, fx1, fy1);
    /*
    dir2 = ray.primaryRay(cam, fx2, fy2);
    dir3 = ray.primaryRay(cam, fx3, fy3);
    dir4 = ray.primaryRay(cam, fx4, fy4);
    dir5 = ray.primaryRay(cam, fx5, fy5);
     */

    PRINT_MAT3(dir1);
    /*
    PRINT_MAT3(dir2);
    PRINT_MAT3(dir3);
    PRINT_MAT3(dir4);
    PRINT_MAT3(dir5);

    */

    COutput results;




    /// computes primary ray matrix
    // glm::mat3 ray_matrix;
    // CRayTrace::compPrimaryRayMatrix(scene.cam, ray_matrix);
    // std::cout << "Camera projection matrix:" << std::endl;
    // PRINT_MAT3(ray_matrix);

    /// computes ray direction for sample pixel positions
    // ...


    /// creates raster image object
    // CImage image(scene.cam.width, scene.cam.height);

    /// main loop

            /// position of the image point
            /// ...

            /// primary ray
            /// ...

            /// background color
            // results.col = {0,0,0};
            /// secondary ray counter
            // results.tree = 0;
            /// ray energy
            // results.energy = 1.0f;
            
            /// rendering
            /// rt.rayTrace(scene, ray, results);

            /// handles pixel over-saturation
            // if(results.col.x > 1 || results.col.y > 1 || results.col.z > 1) {
            //    results.col = {1,1,1};
            //}

            /// writes pixel to output image
            // image.setPixel(i, j, results.rgb);


    /// writes image to disk file with gamma correction
    // image.save("output.png", true);

    // cv::imshow("image", image.getImage());
    // cv::waitKey();
    
    std::cout << std::endl << std::endl;
    return 0;
}
