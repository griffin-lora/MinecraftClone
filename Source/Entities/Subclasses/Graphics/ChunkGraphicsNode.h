#pragma once
#include "GraphicsNode.h"

class ChunkGraphicsNode : public virtual GraphicsNode {
    public:
        struct Mesh {
            using Vertex = Vector3f;

            struct Triangle {
                std::array<Vertex, 3> vertices;
            };

            struct UVTriangle {
                std::array<Vector2f, 3> vertices;
            };

            std::vector<Triangle> triangles;
            std::vector<UVTriangle> uvTriangles;

            static Vertex CreateVertex(u_char x, u_char y, u_char z);
        };
    private:
        bool buffersGenerated = false;
        GLuint vertexBuffer;
        GLuint uvBuffer;

        std::mutex meshMutex;
        Mesh mesh;
    public:
        static void Initialize();

        GIVE_TYPE_ID_1(12, GraphicsNode)

        DELETE_ILLEGAL_CONSTRUCTORS(ChunkGraphicsNode)
        explicit ChunkGraphicsNode(const Vector3f& position, GLuint vertexBuffer, GLuint uvBuffer, const Mesh& mesh);
        virtual ~ChunkGraphicsNode() {}

        void UseMesh(std::function<void(Mesh&)> context);
        void UseMeshConst(std::function<void(const Mesh&)> context);

        virtual void Render(const glm::mat4& viewProjection) override;
};