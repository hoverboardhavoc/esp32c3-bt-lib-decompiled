/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_param_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
r_lld_con_param_update
          (int param_1,int param_2,int param_3,int param_4,undefined2 param_5,int param_6,
          undefined2 param_7)

{
  int iVar1;
  undefined4 uVar2;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar1 == 0) {
    uVar2 = 0xc;
  }
  else {
    if (*(char *)(iVar1 + 0x46) == '\0') {
      *(int *)(iVar1 + 0x38) = param_6 << 5;
      *(short *)(iVar1 + 0x3c) = (short)(param_3 << 2);
      *(undefined1 *)(iVar1 + 0x46) = 1;
      *(undefined2 *)(iVar1 + 0x44) = param_7;
      *(short *)(iVar1 + 0x40) = (short)(param_2 << 2);
      *(int *)(iVar1 + 0x34) = param_4 << 2;
      *(undefined2 *)(iVar1 + 0x3e) = param_5;
      if (((uint)(param_4 << 2) < *(uint *)(iVar1 + 100)) && (1 < *(byte *)(iVar1 + 0x94))) {
        r_lld_con_tx_len_update();
      }
    }
    else {
      r_assert_param(*(char *)(iVar1 + 0x46),0,"lld_con.c",0xee2);
    }
    *(undefined2 *)(iVar1 + 0x42) = 0;
    uVar2 = 0;
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar2;
}

