#include "src/game/envfx_snow.h"

const GeoLayout roboto2_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 0, 0, 0, -180, 0),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, robozo2_root_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 132, -34, -89, -90, 90),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, robozo2_claw1_mesh_layer_1),
					GEO_OPEN_NODE(),
						GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 43, 0, robozo2_claw2_mesh_layer_1),
						GEO_OPEN_NODE(),
							GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 43, 0, 0, 110, 0),
							GEO_OPEN_NODE(),
								GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, robozo2_claw3_mesh_layer_1),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 236, 0, robozo2_head_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, robozo2_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};