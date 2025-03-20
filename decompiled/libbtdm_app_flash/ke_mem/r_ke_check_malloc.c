/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
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
    psVar2 = *(short **)(r_assert_err + ((param_2 + iVar5 & 3U) + 4) * 4);
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

