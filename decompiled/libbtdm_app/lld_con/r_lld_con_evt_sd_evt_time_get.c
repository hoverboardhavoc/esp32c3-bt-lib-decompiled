/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_evt_sd_evt_time_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_con_evt_sd_evt_time_get(int param_1,short *param_2,undefined2 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar2 = *(int *)(&lld_con_env + param_1 * 4);
  uVar1 = 2;
  if (iVar2 != 0) {
    uVar1 = 0xff;
    if ((*(short *)(iVar2 + 0x78) != 0) && (*(short *)(iVar2 + 0x76) != 0)) {
      if (param_2 != (short *)0x0) {
        *param_2 = *(short *)(iVar2 + 0x78);
      }
      uVar1 = 0;
      if (param_3 != (undefined2 *)0x0) {
        *param_3 = *(undefined2 *)(iVar2 + 0x76);
      }
    }
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar1;
}

