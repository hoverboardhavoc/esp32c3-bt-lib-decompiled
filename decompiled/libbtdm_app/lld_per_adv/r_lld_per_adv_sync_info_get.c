/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_per_adv.o -> r_lld_per_adv_sync_info_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
r_lld_per_adv_sync_info_get(int param_1,undefined4 *param_2,undefined2 *param_3,void *param_4)

{
  undefined4 uVar1;
  int iVar2;
  void *__src;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar2 = *(int *)(&lld_per_adv_env + param_1 * 4);
  uVar1 = 0xc;
  if (iVar2 != 0) {
    *param_2 = *(undefined4 *)(iVar2 + 4);
    *param_3 = *(undefined2 *)(iVar2 + 0x4c);
    if ((*(char *)(iVar2 + 0x3d) == '\0') || (*(short *)(iVar2 + 0x4c) != *(short *)(iVar2 + 0x3a)))
    {
      __src = (void *)(iVar2 + 0x2f);
    }
    else {
      __src = (void *)(iVar2 + 0x34);
    }
    memcpy(param_4,__src,5);
    uVar1 = 0;
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar1;
}

