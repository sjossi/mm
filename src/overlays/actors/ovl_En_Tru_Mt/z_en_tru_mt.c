/*
 * File: z_en_tru_mt.c
 * Overlay: ovl_En_Tru_Mt
 * Description: Koume's Target Game - Koume on Broom
 */

#include "z_en_tru_mt.h"

#define FLAGS 0x00000039

#define THIS ((EnTruMt*)thisx)

void EnTruMt_Init(Actor* thisx, GlobalContext* globalCtx);
void EnTruMt_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnTruMt_Update(Actor* thisx, GlobalContext* globalCtx);
void EnTruMt_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80B76A64(EnTruMt* this, GlobalContext* globalCtx);
void func_80B76BB8(EnTruMt* this, GlobalContext* globalCtx);
void func_80B76C38(EnTruMt* this, GlobalContext* globalCtx);

#if 0
const ActorInit En_Tru_Mt_InitVars = {
    ACTOR_EN_TRU_MT,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_TRU,
    sizeof(EnTruMt),
    (ActorFunc)EnTruMt_Init,
    (ActorFunc)EnTruMt_Destroy,
    (ActorFunc)EnTruMt_Update,
    (ActorFunc)EnTruMt_Draw,
};

// static ColliderSphereInit sSphereInit = {
static ColliderSphereInit D_80B77510 = {
    { COLTYPE_NONE, AT_NONE, AC_ON | AC_TYPE_PLAYER, OC1_ON | OC1_TYPE_ALL, OC2_TYPE_1, COLSHAPE_SPHERE, },
    { ELEMTYPE_UNK0, { 0xF7CFFFFF, 0x00, 0x00 }, { 0xF7CFFFFF, 0x00, 0x00 }, TOUCH_NONE | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
    { 0, { { 0, 0, 0 }, 22 }, 100 },
};

// static DamageTable sDamageTable = {
static DamageTable D_80B7753C = {
    /* Deku Nut       */ DMG_ENTRY(1, 0x0),
    /* Deku Stick     */ DMG_ENTRY(1, 0x0),
    /* Horse trample  */ DMG_ENTRY(1, 0x0),
    /* Explosives     */ DMG_ENTRY(1, 0x0),
    /* Zora boomerang */ DMG_ENTRY(1, 0x0),
    /* Normal arrow   */ DMG_ENTRY(1, 0xF),
    /* UNK_DMG_0x06   */ DMG_ENTRY(1, 0x0),
    /* Hookshot       */ DMG_ENTRY(1, 0x0),
    /* Goron punch    */ DMG_ENTRY(1, 0x0),
    /* Sword          */ DMG_ENTRY(1, 0x0),
    /* Goron pound    */ DMG_ENTRY(1, 0x0),
    /* Fire arrow     */ DMG_ENTRY(1, 0xF),
    /* Ice arrow      */ DMG_ENTRY(1, 0xF),
    /* Light arrow    */ DMG_ENTRY(1, 0xF),
    /* Goron spikes   */ DMG_ENTRY(1, 0x0),
    /* Deku spin      */ DMG_ENTRY(1, 0x0),
    /* Deku bubble    */ DMG_ENTRY(1, 0x0),
    /* Deku launch    */ DMG_ENTRY(1, 0x0),
    /* UNK_DMG_0x12   */ DMG_ENTRY(1, 0x0),
    /* Zora barrier   */ DMG_ENTRY(1, 0x0),
    /* Normal shield  */ DMG_ENTRY(1, 0x0),
    /* Light ray      */ DMG_ENTRY(1, 0x0),
    /* Thrown object  */ DMG_ENTRY(1, 0x0),
    /* Zora punch     */ DMG_ENTRY(1, 0x0),
    /* Spin attack    */ DMG_ENTRY(1, 0x0),
    /* Sword beam     */ DMG_ENTRY(1, 0x0),
    /* Normal Roll    */ DMG_ENTRY(1, 0x0),
    /* UNK_DMG_0x1B   */ DMG_ENTRY(1, 0x0),
    /* UNK_DMG_0x1C   */ DMG_ENTRY(1, 0x0),
    /* Unblockable    */ DMG_ENTRY(1, 0x0),
    /* UNK_DMG_0x1E   */ DMG_ENTRY(1, 0x0),
    /* Powder Keg     */ DMG_ENTRY(1, 0x0),
};

#endif

extern ColliderSphereInit D_80B77510;
extern DamageTable D_80B7753C;

extern UNK_TYPE D_060004C8;
extern UNK_TYPE D_0601AA60;

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tru_Mt/func_80B76030.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tru_Mt/func_80B76110.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tru_Mt/func_80B76188.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tru_Mt/func_80B761FC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tru_Mt/func_80B76368.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tru_Mt/func_80B763C4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tru_Mt/func_80B76440.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tru_Mt/func_80B76540.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tru_Mt/func_80B76600.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tru_Mt/func_80B7679C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tru_Mt/func_80B768F0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tru_Mt/func_80B76924.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tru_Mt/func_80B76980.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tru_Mt/func_80B76A64.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tru_Mt/func_80B76BB8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tru_Mt/func_80B76C38.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tru_Mt/EnTruMt_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tru_Mt/EnTruMt_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tru_Mt/EnTruMt_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tru_Mt/func_80B76ED4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tru_Mt/func_80B77008.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tru_Mt/func_80B77078.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tru_Mt/func_80B77354.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Tru_Mt/EnTruMt_Draw.s")
