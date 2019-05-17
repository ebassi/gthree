#include <math.h>

#include "gthreelinebasicmaterial.h"
#include "gthreetypebuiltins.h"

typedef struct {
  GdkRGBA color;
} GthreeLineBasicMaterialPrivate;

enum {
  PROP_0,

  PROP_COLOR,

  N_PROPS
};

static GParamSpec *obj_props[N_PROPS] = { NULL, };

G_DEFINE_TYPE_WITH_PRIVATE (GthreeLineBasicMaterial, gthree_line_basic_material, GTHREE_TYPE_MATERIAL)

static void
gthree_line_basic_material_finalize (GObject *obj)
{
  GthreeLineBasicMaterial *line_basic = GTHREE_LINE_BASIC_MATERIAL (obj);
  GthreeLineBasicMaterialPrivate *priv = gthree_line_basic_material_get_instance_private (line_basic);

  G_OBJECT_CLASS (gthree_line_basic_material_parent_class)->finalize (obj);
}

static void
gthree_line_basic_material_real_set_params (GthreeMaterial *material,
                                       GthreeProgramParameters *params)
{
  GthreeLineBasicMaterial *line_basic = GTHREE_LINE_BASIC_MATERIAL (material);
  GthreeLineBasicMaterialPrivate *priv = gthree_line_basic_material_get_instance_private (line_basic);

  GTHREE_MATERIAL_CLASS (gthree_line_basic_material_parent_class)->set_params (material, params);
}

static void
gthree_line_basic_material_real_set_uniforms (GthreeMaterial *material,
                                         GthreeUniforms *uniforms,
                                         GthreeCamera   *camera)
{
  GthreeLineBasicMaterial *line_basic = GTHREE_LINE_BASIC_MATERIAL (material);
  GthreeLineBasicMaterialPrivate *priv = gthree_line_basic_material_get_instance_private (line_basic);
  GthreeUniform *uni;

  GTHREE_MATERIAL_CLASS (gthree_line_basic_material_parent_class)->set_uniforms (material, uniforms, camera);

  uni = gthree_uniforms_lookup_from_string (uniforms, "diffuse");
  if (uni != NULL)
    gthree_uniform_set_color (uni, &priv->color);
}

static gboolean
gthree_line_basic_material_needs_uv (GthreeMaterial *material)
{
  return FALSE;
}

static GthreeShadingType
gthree_line_basic_material_needs_normals (GthreeMaterial *material)
{
  return FALSE;
}

static gboolean
gthree_line_basic_material_needs_camera_pos (GthreeMaterial *material)
{
  return FALSE;
}

static GthreeColorType
gthree_line_basic_material_needs_colors (GthreeMaterial *material)
{
  return FALSE;
}

static void
gthree_line_basic_material_set_property (GObject *obj,
                                    guint prop_id,
                                    const GValue *value,
                                    GParamSpec *pspec)
{
  GthreeLineBasicMaterial *line_basic = GTHREE_LINE_BASIC_MATERIAL (obj);

  switch (prop_id)
    {
    case PROP_COLOR:
      gthree_line_basic_material_set_color (line_basic, g_value_get_boxed (value));
      break;

    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (obj, prop_id, pspec);
    }
}

static void
gthree_line_basic_material_get_property (GObject *obj,
                                    guint prop_id,
                                    GValue *value,
                                    GParamSpec *pspec)
{
  GthreeLineBasicMaterial *line_basic = GTHREE_LINE_BASIC_MATERIAL (obj);
  GthreeLineBasicMaterialPrivate *priv = gthree_line_basic_material_get_instance_private (line_basic);

  switch (prop_id)
    {
    case PROP_COLOR:
      g_value_set_boxed (value, &priv->color);
      break;

    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (obj, prop_id, pspec);
    }
}

static void
gthree_line_basic_material_class_init (GthreeLineBasicMaterialClass *klass)
{
  GObjectClass *gobject_class = G_OBJECT_CLASS (klass);
  GthreeMaterialClass *material_class = GTHREE_MATERIAL_CLASS (klass);

  gobject_class->set_property = gthree_line_basic_material_set_property;
  gobject_class->get_property = gthree_line_basic_material_get_property;
  gobject_class->finalize = gthree_line_basic_material_finalize;

  material_class->set_params = gthree_line_basic_material_real_set_params;
  material_class->set_uniforms = gthree_line_basic_material_real_set_uniforms;
  material_class->needs_uv = gthree_line_basic_material_needs_uv;
  material_class->needs_normals = gthree_line_basic_material_needs_normals;
  material_class->needs_camera_pos = gthree_line_basic_material_needs_camera_pos;
  material_class->needs_colors = gthree_line_basic_material_needs_colors;

  obj_props[PROP_COLOR] =
    g_param_spec_boxed ("color", "Color", "Color",
                        GDK_TYPE_RGBA,
                        G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);

  g_object_class_install_properties (gobject_class, N_PROPS, obj_props);
}

static void
gthree_line_basic_material_init (GthreeLineBasicMaterial *line_basic)
{
  GthreeLineBasicMaterialPrivate *priv = gthree_line_basic_material_get_instance_private (line_basic);

  priv->color.red = 1.0;
  priv->color.green = 1.0;
  priv->color.blue = 1.0;
  priv->color.alpha = 1.0;
}

GthreeLineBasicMaterial *
gthree_line_basic_material_new (void)
{
  return g_object_new (gthree_line_basic_material_get_type (), NULL);
}

const GdkRGBA *
gthree_line_basic_material_get_color (GthreeLineBasicMaterial *line_basic)
{
  GthreeLineBasicMaterialPrivate *priv = gthree_line_basic_material_get_instance_private (line_basic);

  return &priv->color;
}

void
gthree_line_basic_material_set_color (GthreeLineBasicMaterial *line_basic,
                                 const GdkRGBA *color)
{
  GthreeLineBasicMaterialPrivate *priv = gthree_line_basic_material_get_instance_private (line_basic);

  if (gdk_rgba_equal (color, &priv->color))
    return;

  priv->color = *color;

  gthree_material_set_needs_update (GTHREE_MATERIAL (line_basic), TRUE);

  g_object_notify_by_pspec (G_OBJECT (line_basic), obj_props[PROP_COLOR]);
}