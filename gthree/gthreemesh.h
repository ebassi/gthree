#ifndef __GTHREE_MESH_H__
#define __GTHREE_MESH_H__

#if !defined (__GTHREE_H_INSIDE__) && !defined (GTHREE_COMPILATION)
#error "Only <gthree/gthree.h> can be included directly."
#endif

#include <gthree/gthreeobject.h>
#include <gthree/gthreematerial.h>
#include <gthree/gthreegeometry.h>

G_BEGIN_DECLS

#define GTHREE_TYPE_MESH      (gthree_mesh_get_type ())
#define GTHREE_MESH(inst)     (G_TYPE_CHECK_INSTANCE_CAST ((inst), \
                                                             GTHREE_TYPE_MESH, \
                                                             GthreeMesh))
#define GTHREE_IS_MESH(inst)  (G_TYPE_CHECK_INSTANCE_TYPE ((inst),    \
                                                             GTHREE_TYPE_MESH))

typedef struct {
  GthreeObject parent;
} GthreeMesh;

typedef struct {
  GthreeObjectClass parent_class;

} GthreeMeshClass;

GthreeMesh *gthree_mesh_new (GthreeGeometry *geometry,
                             GthreeMaterial *material);
GType gthree_mesh_get_type (void) G_GNUC_CONST;

G_END_DECLS

#endif /* __GTHREE_MESH_H__ */
