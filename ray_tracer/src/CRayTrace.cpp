//
//  CRayTrace.cpp
//  rt
//
//  Created by Radoslaw Mantiuk on 22/01/2023.
//

#include "rt.h"

/// \fn     multiplyVector(const glm::vec3& vector, double scalar)
/// \brief  Funkcja zwraca wynik mnożenia wektora przez skalar
/// \param  vector - wejściowy wektor
/// \param  scalar - wejściowy scalar
glm::vec3 CRayTrace::multiplyVector(const glm::vec3& vector, double scalar){
    glm::vec3  res;
    res.x = vector.x * scalar;
    res.y = vector.y * scalar;
    res.z = vector.z * scalar;
    return res;
}




/// \fn     compPrimaryRayMatrix(const CCamera& cam, glm::mat3& m)
/// \brief  Obliczanie macierzy projekcji.
/// \param  cam - parametry kamery.
/// \param  m   - Wyjściowa macierz projekcji.
///
bool CRayTrace::compPrimaryRayMatrix(const CCamera& cam, glm::mat3& m) {
    CRayTrace rayTracer;
    // wskazuje na kierunek od pozycji kamery do punktu docelowego kamery
    glm::vec3 look = cam.lookp - cam.eyep;
    glm::vec3 u =  glm::cross(cam.up, look) / glm::length(glm::cross(cam.up, look));
    glm::vec3 v = glm::cross(u, look) / glm::length(glm::cross(u, look));

    //Dokładne obliczanie
    //glm::vec3 o = (look / glm::length(look)) *
    //        (cam.width / (2 * glm::tan(glm::radians(cam.fov / 2.0f)))) -
    //        (rayTracer.multiplyVector(u, (cam.width / 2.0f)) + rayTracer.multiplyVector(v, (cam.height / 2.0f)));

    //Przybliżone obliczanie
    float fovInRadians = (cam.fov * 3.14) / 180;
    glm::vec3 o = (look / glm::length(look)) *
            (cam.width / (2 * glm::tan(fovInRadians/2))) -
            (rayTracer.multiplyVector(u, (cam.width / 2.0f)) + rayTracer.multiplyVector(v, (cam.height / 2.0f)));

    /// Macierz rzutowania
    //  Macierz rzutowania jest reprezentacją kamery służącą do obliczania kierunku promieni pierwotnych z uwzględnie-
    //  niem projekcji perspektywicznej sceny. Macierz przyjmuje formę: matrix_projection;

    m = {
            {u.x,u.y,u.z},
            {v.x,v.y,v.z},
            {o.x,o.y,o.z}
    }; // Macierz rzutowania

    return true;
}


/// \fn rayTrace(CScene scene, CRay& ray, COutput& out)
/// \brief Traces single ray.
/// \param scene Object with all scene components including a camera.
/// \param ray Ray parameter (primary and secondary rays).
/// \param out Object with output color and parameters used in recursion.
///
bool CRayTrace::rayTrace(const CScene& scene, CRay& ray, COutput& out) {

    /// looks for the closest object along the ray path
    /// returns false if there are no intersection

    /// computes 3D position of the intersection point

    /// computes normal vector at intersection point

    /// for each light source defined in the scene

        /// computes if the intersection point is in the shadows

        /// computes diffuse color component

        /// computes specular color component

    /// adds texture for textured spheres

    /// computes ambient color component

    /// if the surface is reflective

        /// if out.tree >= MAX_RAY_TREE return from function

        /// computes the secondary ray parameters (reflected ray)

        /// recursion
        //   rayTrace(scene, secondary_ray, out);


    return true;
}


/// \fn reflectedRay(CRay ray, glm::vec3 n, glm::vec3 pos)
/// \brief Computes parameters of the ray reflected at the surface point with given normal vector.
/// \param ray Input ray.
/// \param n Surface normal vector.
/// \param pos Position of reflection point.
/// \return Reflected ray.
///
CRay CRayTrace::reflectedRay(const CRay& ray, const glm::vec3& n, const glm::vec3& pos) {
    CRay reflected_ray;
    
    return reflected_ray;
}

