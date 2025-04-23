/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> ke_mem.o -> r_ke_malloc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

short * r_ke_malloc(int param_1,int param_2)

{
  short *psVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  short *psVar6;
  uint uVar7;
  
  uVar2 = (param_1 + 3U & 0xfffffffc) + 4;
  if (uVar2 < 0xc) {
    uVar2 = 0xc;
  }
  uVar7 = 0;
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  while( true ) {
    psVar6 = *(short **)(&r_plf_funcs_p + ((param_2 + uVar7 & 3) + 4) * 4);
    if (psVar6 == (short *)0x0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"ke_mem.c",0x10b,*(code **)(_r_plf_funcs_p + 8));
    }
    psVar1 = (short *)0x0;
    for (; psVar6 != (short *)0x0; psVar6 = *(short **)(psVar6 + 2)) {
      if (*psVar6 != -0x5aa6) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"ke_mem.c",0x110,*(code **)(_r_plf_funcs_p + 8));
      }
      uVar5 = (uint)(ushort)psVar6[1];
      if (((uVar2 <= uVar5) && ((uVar2 + 0xc <= uVar5 || (*(int *)(psVar6 + 4) != 0)))) &&
         ((psVar1 == (short *)0x0 || (uVar5 < (ushort)psVar1[1])))) {
        psVar1 = psVar6;
      }
    }
    if ((psVar1 != (short *)0x0) && ((uint)(ushort)psVar1[1] < uVar2 + 0xc)) {
      uVar2 = (uint)(ushort)psVar1[1];
    }
    uVar7 = uVar7 + 1 & 0xff;
    if (uVar7 == 4) break;
    if (psVar1 != (short *)0x0) {
_L41:
      if ((ushort)psVar1[1] == uVar2) {
        if (*(int *)(psVar1 + 4) == 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"ke_mem.c",0x15c,*(code **)(_r_plf_funcs_p + 8));
        }
        iVar3 = *(int *)(psVar1 + 4);
        iVar4 = *(int *)(psVar1 + 2);
        *(int *)(iVar3 + 4) = iVar4;
        if (iVar4 != 0) {
          *(int *)(iVar4 + 8) = iVar3;
        }
      }
      else {
        uVar7 = (uint)(ushort)psVar1[1] - (uVar2 & 0xffff);
        psVar1[1] = (short)(uVar7 * 0x10000 >> 0x10);
        psVar1 = (short *)((int)psVar1 + (uVar7 & 0xffff));
      }
      psVar1[1] = (short)uVar2;
      *psVar1 = -0x7cc8;
      psVar1 = psVar1 + 2;
_L45:
      (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
      return psVar1;
    }
  }
  if (psVar1 == (short *)0x0) {
    (**(code **)(_r_plf_funcs_p + 0xc))
              (param_1,param_2,"ke_mem.c",0x150,*(code **)(_r_plf_funcs_p + 0xc));
    (**(code **)(_r_plf_funcs_p + 4))(0xf2f2f2f2,*(code **)(_r_plf_funcs_p + 4));
    psVar1 = (short *)0x0;
    goto _L45;
  }
  goto _L41;
}

