#ifndef __GTHREE_ANIMATION_ACTION_H__
#define __GTHREE_ANIMATION_ACTION_H__

#if !defined (__GTHREE_H_INSIDE__) && !defined (GTHREE_COMPILATION)
#error "Only <gthree/gthree.h> can be included directly."
#endif

#include <gio/gio.h>
#include <gthree/gthreetypes.h>
#include <gthree/gthreeenums.h>

G_BEGIN_DECLS

#define GTHREE_TYPE_ANIMATION_ACTION      (gthree_animation_action_get_type ())
#define GTHREE_ANIMATION_ACTION(inst)     (G_TYPE_CHECK_INSTANCE_CAST ((inst),  \
                                                  GTHREE_TYPE_ANIMATION_ACTION, \
                                                  GthreeAnimationAction))
#define GTHREE_ANIMATION_ACTION_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GTHREE_TYPE_ANIMATION_ACTION, GthreeAnimationActionClass))
#define GTHREE_IS_ANIMATION_ACTION(inst)  (G_TYPE_CHECK_INSTANCE_TYPE ((inst),  \
                                                  GTHREE_TYPE_ANIMATION_ACTION))
#define GTHREE_ANIMATION_ACTION_GET_CLASS(inst) (G_TYPE_INSTANCE_GET_CLASS ((inst), GTHREE_TYPE_ANIMATION_ACTION, GthreeAnimationActionClass))


struct _GthreeAnimationAction {
  GObject parent;
};

typedef struct {
  GObjectClass parent_class;
} GthreeAnimationActionClass;


G_DEFINE_AUTOPTR_CLEANUP_FUNC (GthreeAnimationAction, g_object_unref)

GType gthree_animation_action_get_type (void) G_GNUC_CONST;

G_END_DECLS

#endif /* __GTHREE_ANIMATION_ACTION_H__ */