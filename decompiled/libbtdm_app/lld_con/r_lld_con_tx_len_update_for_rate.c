/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_tx_len_update_for_rate
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_con_tx_len_update_for_rate(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar2 = *(int *)(&lld_con_env + param_1 * 4);
  uVar1 = 0xc;
  if (iVar2 != 0) {
    if (param_2 == 4) {
      (**(code **)(_r_ip_funcs_p + 0x3c4))
                ((uint)*(byte *)(iVar2 + 0x94),*(undefined4 *)(iVar2 + 100),
                 *(code **)(_r_ip_funcs_p + 0x3c4));
      uVar1 = 0;
    }
    else {
      uVar1 = 0;
      if (*(ushort *)(&byte_tx_time + (uint)*(byte *)(iVar2 + 0x94) * 2) <
          *(ushort *)(&byte_tx_time + param_2 * 2)) {
        (**(code **)(_r_ip_funcs_p + 0x3c4))
                  (*(undefined4 *)(iVar2 + 100),*(code **)(_r_ip_funcs_p + 0x3c4));
        uVar1 = 0;
      }
    }
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar1;
}

