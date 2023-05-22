#include "src/game/envfx_snow.h"

const GeoLayout tvhead_geo[] = {
	GEO_CULLING_RADIUS(1000),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 0, 0, 0, -90, 0),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, tvhead_root_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, tvhead_root_mesh_layer_6),
				GEO_DISPLAY_LIST(LAYER_ALPHA, tvhead_root_mesh_layer_4),
				GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 0, -133, -90, 0, 0),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_ALPHA, 0, 0, 0, tvhead_Lwing1_mesh_layer_4),
					GEO_OPEN_NODE(),
						GEO_DISPLAY_LIST(LAYER_ALPHA, tvhead_Lwing2_skinned_mesh_layer_4),
						GEO_ANIMATED_PART(LAYER_ALPHA, 0, 120, 0, tvhead_Lwing2_mesh_layer_4),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
				GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 0, 133, 79, -90, -90),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_ALPHA, 0, 0, 0, tvhead_Rwing1_mesh_layer_4),
					GEO_OPEN_NODE(),
						GEO_DISPLAY_LIST(LAYER_ALPHA, tvhead_Rwing2_skinned_mesh_layer_4),
						GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 120, 0, 0, 101, 0),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_ALPHA, 0, 0, 0, tvhead_Rwing2_mesh_layer_4),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, tvhead_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, tvhead_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, tvhead_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};