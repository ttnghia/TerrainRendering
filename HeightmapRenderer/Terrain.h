#pragma once
#include "Heightmap.h"
#include "TerrainMultiTexture.h"
using namespace oglplus;

class Terrain
{
    private:
        bool heightmapCreated;
        bool meshCreated;
        float terrainMaxHeight;
        // mesh data gpu buffers
        std::array<Buffer, 4> buffer;
        // mesh data collections
        std::vector<glm::vec3> vertices;
        std::vector<glm::vec2> texCoords;
        std::vector<glm::vec3> normals;
        std::vector<unsigned int> indices;
        // mesh general data
        int meshResolution;
        int terrainResolution;
        // meshSize * meshSize = vertex count
        int meshSize;
        float maxHeight;
        float minHeight;
        // utilities
        VertexArray terrainMesh;
        FragmentShader fragmentShader;
        VertexShader vertexShader;
        Program program;
        Context gl;
        // terrain shadows, generated with heightmap info
        Texture terrainShadowmap;
        // heightmap generator
        Heightmap heightmap;
        // multitexture handling class
        TerrainMultiTexture terrainTextures;

    public:
        void initialize();
        void display();
        void bindBuffers();
        void generateShadowmap(glm::vec3 lightPos);
        // creates a terrain of 2^sizeExponent + 1 size
        void createTerrain(const int heightmapSize);
        void createMesh(const int meshResExponent);
        Heightmap &Heightmap() { return heightmap; }
        TerrainMultiTexture &TerrainTextures() { return terrainTextures; }

        Terrain(Terrain *rhs) { rhs = this; };
        Texture &TerrainShadowmap() { return terrainShadowmap; }
        Terrain();
        ~Terrain();
};

