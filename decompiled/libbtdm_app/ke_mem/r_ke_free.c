/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app -> ke_mem.o -> r_ke_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ke_free(short *param_1)

{
  ushort uVar1;
  short *psVar2;
  short *psVar3;
  int iVar4;
  short sVar5;
  uint uVar6;
  short *psVar7;
  short *psVar8;
  
  if (param_1 == (short *)0x0) {
    (**(code **)(_r_plf_funcs_p + 0xc))(0,"ke_mem.c",0x19b,*(code **)(_r_plf_funcs_p + 0xc));
  }
  psVar8 = param_1 + -2;
  if (param_1[-2] != -0x7cc8) {
    (**(code **)(_r_plf_funcs_p + 0xc))(param_1,"ke_mem.c",0x1a3,*(code **)(_r_plf_funcs_p + 0xc));
  }
  param_1[-2] = -0xff1;
  uVar1 = param_1[-1];
  uVar6 = 0;
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  do {
    while (iVar4 = (**(code **)(_r_modules_funcs_p + 300))
                             (uVar6,param_1,*(code **)(_r_modules_funcs_p + 300)), iVar4 == 0) {
      uVar6 = uVar6 + 1 & 0xff;
      if (uVar6 == 4) {
_L69:
        (**(code **)(_r_plf_funcs_p + 8))(0,"ke_mem.c",0x1c3,*(code **)(_r_plf_funcs_p + 8));
        psVar7 = (short *)0x0;
        goto _L73;
      }
    }
    psVar2 = *(short **)(&r_plf_funcs_p + (uVar6 + 4) * 4);
    if (uVar6 == 4) {
      if (psVar2 == (short *)0x0) goto _L69;
      break;
    }
  } while (psVar2 == (short *)0x0);
  if (param_1 <= psVar2) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"ke_mem.c",0x1c4,*(code **)(_r_plf_funcs_p + 8));
  }
  psVar7 = (short *)0x0;
  do {
    psVar3 = psVar2;
    if (psVar3 == (short *)0x0) {
_L73:
      *(short **)(psVar7 + 2) = psVar8;
      param_1[0] = 0;
      param_1[1] = 0;
      *(short **)(param_1 + 2) = psVar7;
      param_1[-1] = uVar1;
      param_1[-2] = -0x5aa6;
_L78:
                    /* WARNING: Could not recover jumptable at 0x000104c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_osi_funcs_p + 0x18))();
      return;
    }
    if (*psVar3 != -0x5aa6) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"ke_mem.c",0x1cc,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((short *)((uint)(ushort)psVar3[1] + (int)psVar3) == psVar8) {
      uVar6 = (uint)(ushort)psVar3[1] + (uint)uVar1;
      iVar4 = *(int *)(psVar3 + 2);
      sVar5 = (short)(uVar6 * 0x10000 >> 0x10);
      psVar3[1] = sVar5;
      if (iVar4 == (uVar6 & 0xffff) + (int)psVar3) {
        psVar3[1] = sVar5 + *(short *)(iVar4 + 2);
        iVar4 = *(int *)(iVar4 + 4);
        *(int *)(psVar3 + 2) = iVar4;
        if (iVar4 != 0) {
          *(short **)(iVar4 + 8) = psVar3;
        }
      }
      goto _L78;
    }
    if (psVar8 < psVar3) {
      if (psVar7 == (short *)0x0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"ke_mem.c",0x1e7,*(code **)(_r_plf_funcs_p + 8));
      }
      *(short **)(psVar7 + 2) = psVar8;
      param_1[-2] = -0x5aa6;
      *(short **)(param_1 + 2) = psVar7;
      if (psVar3 == (short *)((int)psVar8 + (uint)uVar1)) {
        *(undefined4 *)param_1 = *(undefined4 *)(psVar3 + 2);
        if (*(int *)(psVar3 + 2) != 0) {
          *(short **)(*(int *)(psVar3 + 2) + 8) = psVar8;
        }
        param_1[-1] = psVar3[1] + uVar1;
      }
      else {
        *(short **)param_1 = psVar3;
        *(short **)(psVar3 + 4) = psVar8;
        param_1[-1] = uVar1;
      }
      goto _L78;
    }
    psVar2 = *(short **)(psVar3 + 2);
    psVar7 = psVar3;
  } while( true );
}

