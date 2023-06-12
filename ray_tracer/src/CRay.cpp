//
//  CRay.cpp
//  rt
//
//  Created by Radoslaw Mantiuk on 22/01/2023.
//

#include "rt.h"

glm::vec3 CRay::primaryRay(const CCamera& cam, float fx, float fy){
    CRayTrace rayTrace;
    glm::mat3 matrix;
    glm::vec3 rightVector = {fx,fy,1};
    rayTrace.compPrimaryRayMatrix(cam, matrix);
    pos = cam.eyep;
    dir = glm::normalize(matrix * rightVector);
    return dir;
}
