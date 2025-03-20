/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
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
    psVar5 = *(short **)(r_ble_log_internal_x2 + ((param_2 + iVar6 & 3U) + 4) * 4);
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
_L44:
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
_L45:
      (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
      iVar6 = r_sdk_config_get_opts_ext();
      if ((*(uint *)(iVar6 + 0x28) & 2) != 0) {
        iVar6 = r_sdk_config_get_opts_ext();
        if (*(byte *)(iVar6 + 0x2c) < 3) {
          r_ble_log_internal_x3(0x40250006,param_2,param_1,psVar1);
        }
      }
      return psVar1;
    }
  }
  if (psVar1 == (short *)0x0) {
    r_assert_param(param_1,param_2,"ke_mem.c",0x150);
    r_platform_reset(0xf2f2f2f2);
    psVar1 = (short *)0x0;
    goto _L45;
  }
  goto _L44;
}

