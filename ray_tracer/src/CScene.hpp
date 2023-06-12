//
//  CScene.hpp
//  rt
//
//  Created by Radoslaw Mantiuk on 22/01/2023.
//

#ifndef CScene_hpp
#define CScene_hpp


/// \class CCamera
/// \brief Klasa z parametrami kamery
///
class CCamera {
public:
    /// Dane kamery
    int width = 500;    // Rozdzielczość pozioma w pikselach
    int height = 400;   // Rozdzielczość pionowa w pikselach
    float fov = 50;     // Pole widzenia, zakres <0,180)
    glm::vec3 eyep = {0,0,10};  // Pozycja kamery
    glm::vec3 lookp = {0,0,0};  // Punkt docelowy kamery
    glm::vec3 up = {0,1,0};     // Orientacja kamery
};


/// \class CLight
/// \brief Class with light source parameters.
///
class CLight  {
public:
    glm::vec3 pos; ///< Light position.
    glm::vec3 color; ///< Light color.
    
    CLight() {
        color = {1,1,1};
    }
    
    explicit CLight(const glm::vec3& pos) {
        this->pos = pos;
    }
};


/// \class CScene
/// \brief Container for the scene components.
///
class CScene {
public:
    CCamera cam; ///< Camera object.
    std::vector<CObject*> objectList; ///< List of geometric objects.
    std::vector<CLight> lightList; ///< List of the light sources.
    
public:
    void create();

};



#endif /* CScene_hpp */
