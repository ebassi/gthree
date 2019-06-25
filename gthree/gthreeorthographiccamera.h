#ifndef __GTHREE_ORTHOGRAPHIC_CAMERA_H__
#define __GTHREE_ORTHOGRAPHIC_CAMERA_H__

#if !defined (__GTHREE_H_INSIDE__) && !defined (GTHREE_COMPILATION)
#error "Only <gthree/gthree.h> can be included directly."
#endif

#include <gthree/gthreecamera.h>

G_BEGIN_DECLS


#define GTHREE_TYPE_ORTHOGRAPHIC_CAMERA      (gthree_orthographic_camera_get_type ())
#define GTHREE_ORTHOGRAPHIC_CAMERA(inst)     (G_TYPE_CHECK_INSTANCE_CAST ((inst), \
                                                                     GTHREE_TYPE_ORTHOGRAPHIC_CAMERA, \
                                                                     GthreeOrthographicCamera))
#define GTHREE_IS_ORTHOGRAPHIC_CAMERA(inst)  (G_TYPE_CHECK_INSTANCE_TYPE ((inst), \
                                                                     GTHREE_TYPE_ORTHOGRAPHIC_CAMERA))

struct _GthreeOrthographicCamera {
  GthreeCamera parent;
};

typedef struct {
  GthreeCameraClass parent_class;

} GthreeOrthographicCameraClass;

GType gthree_orthographic_camera_get_type (void) G_GNUC_CONST;

GthreeOrthographicCamera *gthree_orthographic_camera_new (float left, float right,
                                                          float top, float bottom,
                                                          float near, float far);

void  gthree_orthographic_camera_set_left   (GthreeOrthographicCamera *orthographic,
                                             float                     left);
float gthree_orthographic_camera_get_left   (GthreeOrthographicCamera *orthographic);
void  gthree_orthographic_camera_set_right  (GthreeOrthographicCamera *orthographic,
                                             float                     right);
float gthree_orthographic_camera_get_right  (GthreeOrthographicCamera *orthographic);
void  gthree_orthographic_camera_set_top    (GthreeOrthographicCamera *orthographic,
                                             float                     top);
float gthree_orthographic_camera_get_top    (GthreeOrthographicCamera *orthographic);
void  gthree_orthographic_camera_set_bottom (GthreeOrthographicCamera *orthographic,
                                             float                     bottom);
float gthree_orthographic_camera_get_bottom (GthreeOrthographicCamera *orthographic);

G_END_DECLS

#endif /* __GTHREE_ORTHOGRAPHICCAMERA_H__ */