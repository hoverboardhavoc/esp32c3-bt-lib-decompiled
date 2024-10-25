/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_ch_map_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_con_ch_map_update(int param_1,void *param_2,undefined2 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar2 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar2 != 0) {
    if (*(char *)(iVar2 + 0x46) == '\0') {
      *(undefined2 *)(iVar2 + 0x44) = param_3;
      *(undefined1 *)(iVar2 + 0x46) = 2;
      memcpy((void *)(iVar2 + 0x34),param_2,5);
      uVar1 = 0;
      goto _L773;
    }
    r_assert_param(*(char *)(iVar2 + 0x46),0,"lld_con.c",0xf16);
  }
  uVar1 = 0xc;
_L773:
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar1;
}

