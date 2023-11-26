#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x807bdc5c..0x807bdd7c
UNKNOWN_FUNCTION(kcl_header_init);
// PAL: 0x807bdd7c..0x807bddbc
UNKNOWN_FUNCTION(unk_807bdd7c);
// PAL: 0x807bddbc..0x807bddfc
UNKNOWN_FUNCTION(unk_807bddbc);
// PAL: 0x807bddfc..0x807bdf54
UNKNOWN_FUNCTION(unk_807bddfc);
// PAL: 0x807be12c..0x807be3c4
UNKNOWN_FUNCTION(unk_807be12c);
// PAL: 0x807be3c4..0x807bf4c0
UNKNOWN_FUNCTION(unk_807be3c4);
// PAL: 0x807bf4c0..0x807c01e4
UNKNOWN_FUNCTION(unk_807bf4c0);
// PAL: 0x807c01e4..0x807c0884
UNKNOWN_FUNCTION(unk_807c01e4);
// PAL: 0x807c0884..0x807c0f00
UNKNOWN_FUNCTION(kcl_triangle_collides_two_points);
// PAL: 0x807c0f00..0x807c1514
UNKNOWN_FUNCTION(unk_807c0f00);
// PAL: 0x807c1514..0x807c1b0c
UNKNOWN_FUNCTION(kcl_triangle_collides_one_point);
// PAL: 0x807c1c8c..0x807c1de8
UNKNOWN_FUNCTION(unk_807c1c8c);
// PAL: 0x807c1de8..0x807c1f80
UNKNOWN_FUNCTION(kcl_find_tri_list_and_prepare_cached);
// PAL: 0x807c1f80..0x807c1fac
UNKNOWN_FUNCTION(unk_807c1f80);
// PAL: 0x807c1fac..0x807c21f4
UNKNOWN_FUNCTION(unk_807c1fac);
// PAL: 0x807c21f4..0x807c2410
UNKNOWN_FUNCTION(unk_807c21f4);
// PAL: 0x807c2410..0x807c243c
UNKNOWN_FUNCTION(kcl_triangle_collides);
// PAL: 0x807c243c..0x807c24c0
UNKNOWN_FUNCTION(unk_807c243c);
// PAL: 0x807c24c0..0x807c25cc
UNKNOWN_FUNCTION(unk_807c24c0);

#ifdef __cplusplus
}
#endif

#include "KCollision.hpp"

namespace Field {
class KCollisionOctree {
public:
  /* Given the KCL representation of a prism, this function can compute the prism vertex
   positions. Vertex1 is already known, and this function computes vertex2 if enrm is enrm2 and
   vertex 3 if enrm is enrm 1 */
  static EGG::Vector3f getVertex(f32 height, const EGG::Vector3f& vertex1, const EGG::Vector3f& fnrm,
		  const EGG::Vector3f& enrm3, const EGG::Vector3f& enrm);
  // finds block that contains position
  u16* searchBlock(const EGG::Vector3f& pos);
  // Sets sphere-octree-collision detection parameters
  void prepareCollisionTest(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask);
  void prepareCollisionTestSphere(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, f32 radius);

private:
  EGG::Vector3f* pos_data;
  EGG::Vector3f* nrm_data;
  KCollisionPrism* prism_data;
  u8* block_data;
  f32 prism_thickness;
  EGG::Vector3f area_min_pos;
  u32 area_x_width_mask;
  u32 area_y_width_mask;
  u32 area_z_width_mask;
  u32 block_width_shift;
  u32 area_x_blocks_shift;
  u32 area_xy_blocks_shift;
  f32 sphere_radius;

  // --- Sphere-octree collision detection parameters
  EGG::Vector3f pos;
  // I think this is for support of directional collision checking (wall is only one way solid)
  // Pretty much a collision is triggered only when the movement vector has an acute angle with the prism face normal
  EGG::Vector3f prevPos;
  EGG::Vector3f movement; // pos - prevPos
  f32 radius;
  // This mask can be used to only count collision with certain KCL attribute base types. The n-th bit in this mask signifies if KCL of base type n will count towards collision
  u32 typeMask;
  // index of prisms near pos (collision candidates). They exist in the same octree leaf block as pos
  u16* prismIndexes;

  u8 _[0x290 - 0x6c];

  u16* cachedPrismIndexes;
  EGG::Vector3f cachedPos;
  f32 cachedRadius;
};
}
