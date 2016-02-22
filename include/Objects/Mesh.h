
#ifndef MESH_H
#define MESH_H

#include "..\Core\MathUtils.h"
#include "..\Core\Array.h"

class Mesh
{
public:
    Array<Array<int>> m_faces;
    Array<Vector> m_vertices;
    Array<Vector> m_normals;
    Array<int> m_indices;
    Array<real> m_u;
    Array<real> m_v;
    int m_triangleCount;
    int m_vertexCount;

    Mesh(const char* filename);

    Mesh(const Mesh& mesh);

    ~Mesh();

    Mesh& operator=(const Mesh& mesh);
};

#endif