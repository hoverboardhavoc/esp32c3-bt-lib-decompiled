/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> ke_mem.o -> r_ke_check_malloc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool r_ke_check_malloc(int param_1,int param_2)

{
  uint uVar1;
  short *psVar2;
  uint uVar3;
  short *psVar4;
  int iVar5;
  
  uVar1 = (param_1 + 3U & 0xfffffffc) + 4;
  if (uVar1 < 0xc) {
    uVar1 = 0xc;
  }
  iVar5 = 0;
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  do {
    psVar2 = *(short **)(&r_osi_funcs_p + ((param_2 + iVar5 & 3U) + 4) * 4);
    if (psVar2 == (short *)0x0) {
      r_assert_err(0,"ke_mem.c",0xbd);
    }
    psVar4 = (short *)0x0;
    for (; psVar2 != (short *)0x0; psVar2 = *(short **)(psVar2 + 2)) {
      if (*psVar2 != -0x5aa6) {
        r_assert_err(0,"ke_mem.c",0xc2);
      }
      uVar3 = (uint)(ushort)psVar2[1];
      if (((uVar1 <= uVar3) && ((uVar1 + 0xc <= uVar3 || (*(int *)(psVar2 + 4) != 0)))) &&
         ((psVar4 == (short *)0x0 || (uVar3 < (ushort)psVar4[1])))) {
        psVar4 = psVar2;
      }
    }
    if ((psVar4 != (short *)0x0) && ((uint)(ushort)psVar4[1] < uVar1 + 0xc)) {
      uVar1 = (uint)(ushort)psVar4[1];
    }
  } while ((iVar5 != 3) && (iVar5 = iVar5 + 1, psVar4 == (short *)0x0));
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return psVar4 != (short *)0x0;
}

