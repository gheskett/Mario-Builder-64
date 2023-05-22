#include "src/game/envfx_snow.h"

const GeoLayout giant_tree_geo[] = {
	GEO_CULLING_RADIUS(1500),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, giant_tree_Cylinder_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, giant_tree_Cylinder_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, giant_tree_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, giant_tree_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};