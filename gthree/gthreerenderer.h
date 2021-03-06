#ifndef __GTHREE_RENDERER_H__
#define __GTHREE_RENDERER_H__

#if !defined (__GTHREE_H_INSIDE__) && !defined (GTHREE_COMPILATION)
#error "Only <gthree/gthree.h> can be included directly."
#endif

#include <gthree/gthreescene.h>
#include <gthree/gthreecamera.h>
#include <gthree/gthreematerial.h>

G_BEGIN_DECLS


#define GTHREE_TYPE_RENDERER      (gthree_renderer_get_type ())
#define GTHREE_RENDERER(inst)     (G_TYPE_CHECK_INSTANCE_CAST ((inst), \
                                                            GTHREE_TYPE_RENDERER, \
                                                            GthreeRenderer))
#define GTHREE_IS_RENDERER(inst)  (G_TYPE_CHECK_INSTANCE_TYPE ((inst), \
                                                            GTHREE_TYPE_RENDERER))

struct _GthreeRenderer {
  GObject parent;
};

typedef struct {
  GObjectClass parent_class;

} GthreeRendererClass;

GthreeRenderer *gthree_renderer_new ();
GType gthree_renderer_get_type (void) G_GNUC_CONST;

void gthree_renderer_set_size              (GthreeRenderer *renderer,
                                            int             width,
                                            int             height);
void gthree_renderer_set_autoclear         (GthreeRenderer *renderer,
                                            gboolean        auto_clear);
void gthree_renderer_set_autoclear_color   (GthreeRenderer *renderer,
                                            gboolean        clear_color);
void gthree_renderer_set_autoclear_depth   (GthreeRenderer *renderer,
                                            gboolean        clear_depth);
void gthree_renderer_set_autoclear_stencil (GthreeRenderer *renderer,
                                            gboolean        clear_stencil);
void gthree_renderer_set_clear_color       (GthreeRenderer *renderer,
                                            GdkRGBA        *color);
void gthree_renderer_clear                 (GthreeRenderer *renderer);
void gthree_renderer_render                (GthreeRenderer *renderer,
                                            GthreeScene    *scene,
                                            GthreeCamera   *camera,
                                            gboolean        force_clear);

G_END_DECLS

#endif /* __GTHREE_RENDERER_H__ */
