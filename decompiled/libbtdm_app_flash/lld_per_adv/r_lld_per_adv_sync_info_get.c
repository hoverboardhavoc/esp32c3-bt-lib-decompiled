/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_sync_info_get
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
  void *__src;
  int iVar2;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar2 = *(int *)(&lld_per_adv_env + param_1 * 4);
  uVar1 = 0xc;
  if (iVar2 != 0) {
    *param_2 = *(undefined4 *)(iVar2 + 4);
    *param_3 = *(undefined2 *)(iVar2 + 0x4c);
    if ((*(char *)(iVar2 + 0x3d) == '\0') ||
       (__src = (void *)(iVar2 + 0x34), *(short *)(iVar2 + 0x4c) != *(short *)(iVar2 + 0x3a))) {
      __src = (void *)(iVar2 + 0x2f);
    }
    memcpy(param_4,__src,5);
    uVar1 = 0;
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar1;
}

