/*
 * File: z_en_test2.c
 * Overlay: ovl_En_Test2
 * Description: Objects affected by the Lens of Truth
 */

#include "z_en_test2.h"
#include "unk.h"

#define FLAGS 0x00000090

#define THIS ((EnTest2*)thisx)

void EnTest2_Init(Actor* thisx, GlobalContext* globalCtx);
void EnTest2_Update(Actor* thisx, GlobalContext* globalCtx);

const ActorInit En_Test2_InitVars = {
    ACTOR_EN_TEST2,
    ACTORCAT_BG,
    FLAGS,
    GAMEPLAY_KEEP,
    sizeof(EnTest2),
    (ActorFunc)EnTest2_Init,
    (ActorFunc)Actor_Noop,
    (ActorFunc)EnTest2_Update,
    (ActorFunc)NULL,
};

#if 0
// static InitChainEntry sInitChain[] = {
static InitChainEntry D_80A3E74C[] = {
    ICHAIN_VEC3F(scale, 1, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 8000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 800, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 2500, ICHAIN_STOP),
};

#endif

static s16 D_80A3E75C[0x12] = {
    0x180, 0x17F, 0x76, 0x190, 0x190, 0x190, 0x1BC, 0x1E0, 0x1E0, 0x190, 0x190, 0x190, 0x190, 0, 0, 0, 0, 0,
};

// element size 0xC
typedef struct E6B0 {
    s8 unk_0;
    char unk_8[0x4];
} E6B0;
static E6B0f D_80A3E6B0[1] = { 0x06000040 }; // s or u?

extern InitChainEntry D_80A3E74C[4];
extern void func_80A3E4EC(Actor* actor, GlobalContext* globalCtx); /* extern */
extern void func_80A3E524(Actor* this, GlobalContext* globalCtx);  /* extern */

/* #pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Test2/EnTest2_Init.s") */
void EnTest2_Init(Actor* thisx, GlobalContext* globalCtx) {
    s16 actorParams;
    EnTest2* this = THIS;

    Actor_ProcessInitChain(&this->actor, D_80A3E74C);
    if ((this->actor.params == 0xB) || (this->actor.params == 0xC)) {
        this->actor.flags |= 0x20;
    }
}

/* #pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Test2/EnTest2_Update.s") */
void EnTest2_Update(Actor* thisx, GlobalContext* globalCtx) {
    ObjectContext* objectCtx;
    s32 index;
    void* temp_v0_2;
    EnTest2* this = THIS;

    objectCtx = &globalCtx->objectCtx;
    index = Object_GetIndex(objectCtx, D_80A3E75C[this->actor.params]);
    if (index < 0) {
        Actor_MarkForDeath(&this->actor);
        return;
    }
    if (Object_IsLoaded(objectCtx, index) != 0) {
        /* /1* 0x01C *1/ s16 params; // Configurable variable set by the actor's spawn data; original name: "args_data"
         */
        temp_v0_2 = &D_80A3E6B0[this->actor.params];
        this->actor.objBankIndex = (s8)index;
        this->actor.draw = func_80A3E524;
        if (temp_v0_2->unk8 != 0) {
            Actor_SetObjectSegment(globalCtx, &this->actor);
            /* void* Lib_SegmentedToVirtual(void* ptr); */
            this->unk_144 = Lib_SegmentedToVirtual(temp_v0_2->unk8);
        }
        if (globalCtx->roomCtx.currRoom.unk5 != 0) {
            this->actor.update = func_80A3E4EC;
            return;
        }
        this->actor.update = Actor_Noop;
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Test2/func_80A3E4EC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Test2/func_80A3E524.s")
