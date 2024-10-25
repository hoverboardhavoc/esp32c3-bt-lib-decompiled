/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> ke_mem.o -> r_ke_malloc
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
  uint uVar4;
  short *psVar5;
  int iVar6;
  
  uVar2 = (param_1 + 3U & 0xfffffffc) + 4;
  if (uVar2 < 0xc) {
    uVar2 = 0xc;
  }
  iVar6 = 0;
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  while( true ) {
    psVar5 = *(short **)(r_assert_err + ((param_2 + iVar6 & 3U) + 4) * 4);
    if (psVar5 == (short *)0x0) {
      r_assert_err(0,"ke_mem.c",0x10b);
    }
    psVar1 = (short *)0x0;
    for (; psVar5 != (short *)0x0; psVar5 = *(short **)(psVar5 + 2)) {
      if (*psVar5 != -0x5aa6) {
        r_assert_err(0,"ke_mem.c",0x110);
      }
      uVar4 = (uint)(ushort)psVar5[1];
      if (((uVar2 <= uVar4) && ((uVar2 + 0xc <= uVar4 || (*(int *)(psVar5 + 4) != 0)))) &&
         ((psVar1 == (short *)0x0 || (uVar4 < (ushort)psVar1[1])))) {
        psVar1 = psVar5;
      }
    }
    if ((psVar1 != (short *)0x0) && ((uint)(ushort)psVar1[1] < uVar2 + 0xc)) {
      uVar2 = (uint)(ushort)psVar1[1];
    }
    if (iVar6 == 3) break;
    iVar6 = iVar6 + 1;
    if (psVar1 != (short *)0x0) {
_L40:
      if ((ushort)psVar1[1] == uVar2) {
        if (*(int *)(psVar1 + 4) == 0) {
          r_assert_err(0,"ke_mem.c",0x15c);
        }
        iVar6 = *(int *)(psVar1 + 4);
        iVar3 = *(int *)(psVar1 + 2);
        *(int *)(iVar6 + 4) = iVar3;
        if (iVar3 != 0) {
          *(int *)(iVar3 + 8) = iVar6;
        }
      }
      else {
        uVar4 = (uint)(ushort)psVar1[1] - (uVar2 & 0xffff);
        psVar1[1] = (short)(uVar4 * 0x10000 >> 0x10);
        psVar1 = (short *)((int)psVar1 + (uVar4 & 0xffff));
      }
      psVar1[1] = (short)uVar2;
      *psVar1 = -0x7cc8;
      psVar1 = psVar1 + 2;
_L41:
      (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
      return psVar1;
    }
  }
  if (psVar1 == (short *)0x0) {
    r_assert_param(param_1,param_2,"ke_mem.c",0x150);
    r_platform_reset(0xf2f2f2f2);
    psVar1 = (short *)0x0;
    goto _L41;
  }
  goto _L40;
}

