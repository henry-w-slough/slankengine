

struct Vector3 {
    float x;
    float y;
    float z;
};


struct Transform {
    Vector3 position{0, 0, 0};
    Vector3 rotation{0, 0, 0};
    Vector3 scale{0, 0, 0}; 
};