#ifndef GAME_INIT_H
#define GAME_INIT_H

#include <PR/ultratypes.h>
#include <PR/gbi.h>
#include <PR/os_cont.h>
#include <PR/os_message.h>

#include "types.h"
#include "memory.h"
#include "config.h"

#define MARIO_ANIMS_POOL_SIZE 0x4000
#define DEMO_INPUTS_POOL_SIZE 0x800

#include "libcart/include/cart.h"
#include "libcart/ff/ff.h"
#include "cursed_mirror_maker.h"

struct GfxPool {
    Gfx buffer[GFX_POOL_SIZE];
    struct SPTask spTask;
};

struct DemoInput {
    u8 timer; // time until next input. if this value is 0, it means the demo is over
    s8 rawStickX;
    s8 rawStickY;
    u8 buttonMask;
};

enum ZBmodes {
    KEEP_ZBUFFER = 0,
    CLEAR_ZBUFFER = 1,
};

extern struct Controller gControllers[MAXCONTROLLERS];
extern OSContStatus gControllerStatuses[MAXCONTROLLERS];
extern OSContPadEx gControllerPads[MAXCONTROLLERS];
extern OSMesgQueue gGameVblankQueue;
extern OSMesgQueue gGfxVblankQueue;
extern OSMesg gGameMesgBuf[1];
extern OSMesg gGfxMesgBuf[1];
extern struct VblankHandler gGameVblankHandler;
extern uintptr_t gPhysicalFramebuffers[3];
extern uintptr_t gPhysicalZBuffer;
extern void *gMarioAnimsMemAlloc;
extern void *gDemoInputsMemAlloc;
extern struct SPTask *gGfxSPTask;
extern Gfx *gDisplayListHead;
extern u8 *gGfxPoolEnd;
extern struct GfxPool *gGfxPool;
extern u8 gControllerBits;
extern u8 gBorderHeight;
#ifdef VANILLA_STYLE_CUSTOM_DEBUG
extern u8 gCustomDebugMode;
#endif
extern u8 *gAreaSkyboxStart[AREA_COUNT];
extern u8 *gAreaSkyboxEnd[AREA_COUNT];
#ifdef EEP
extern s8 gEepromProbe;
#endif
#ifdef SRAM
extern s8 gSramProbe;
#endif

extern void (*gGoddardVblankCallback)(void);
extern struct Controller* const gPlayer1Controller;
extern struct Controller* const gPlayer2Controller;
extern struct Controller* const gPlayer3Controller;
extern struct Controller* const gPlayer4Controller;
extern struct DemoInput *gCurrDemoInput;
extern u16 gDemoInputListID;
extern struct DemoInput gRecordedDemoInput;

// this area is the demo input + the header. when the demo is loaded in, there is a header the size
// of a single word next to the input list. this word is the current ID count.
extern struct DmaHandlerList gMarioAnimsBuf;
extern struct DmaHandlerList gDemoInputsBuf;

extern u8 gMarioAnims[];
extern u8 gDemoInputs[];

extern u16 sRenderingFramebuffer;
extern u32 gGlobalTimer;

void setup_game_memory(void);
void thread5_game_loop(UNUSED void *arg);
void clear_framebuffer(s32 color);
void clear_viewport(Vp *viewport, s32 color);
void make_viewport_clip_rect(Vp *viewport);
void init_rcp(s32 resetZB);
void end_master_display_list(void);
void render_init(void);
void select_gfx_pool(void);
void display_and_vsync(void);

extern Bool32 gSupportsLibpl;
extern Bool32 gIsGliden;

#define MAX_FILES 251
extern u8 cmm_level_entry_version[MAX_FILES];
extern FRESULT mount_success;
extern FRESULT global_code;
extern u8 cmm_level_entry_count;
extern TCHAR *cmm_level_dir_name;
extern TCHAR *cmm_hack_dir_name;
extern struct cmm_sram_config cmm_sram_configuration;

void create_level_file_path(TCHAR * buffer, TCHAR * filename, TCHAR * suffix);
struct cmm_level_save_header * get_level_info_from_filename(char * filename);
void load_level_files_from_sd_card(void);
u8 level_file_exists(char * filename);

#endif // GAME_INIT_H
