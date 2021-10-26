#pragma once
#include "BlockHandler.h"

class TexturedCubeBlockHandler : public virtual BlockHandler {
    protected:
        virtual Block::TextureId TextureIdFor(Block::Face face) const = 0;
    public:
        GIVE_TYPE_ID_1(15, BlockHandler)

        DELETE_ILLEGAL_CONSTRUCTORS(TexturedCubeBlockHandler)
        explicit TexturedCubeBlockHandler() {}
        virtual ~TexturedCubeBlockHandler() {}

        virtual bool HasMesh(const Block&) const override;
        virtual bool IsTransparent(const Block&, const Block&) const override;
        virtual void GenerateFaceMesh(ChunkGraphicsNode::Mesh& chunkMesh, const Vector3u& position, const Block& block, Block::Face face) const override;
};