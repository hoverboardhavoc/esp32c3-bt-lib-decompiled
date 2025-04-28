/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_tx_len_update_for_rate
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_con_tx_len_update_for_rate(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = *(int *)(&lld_con_env + param_1 * 4);
  uVar2 = 0xc;
  if (iVar1 != 0) {
    if (param_2 == 4) {
      (**(code **)(_r_ip_funcs_p + 0x3c4))
                (*(undefined4 *)(iVar1 + 100),*(code **)(_r_ip_funcs_p + 0x3c4));
      uVar2 = 0;
    }
    else {
      uVar2 = 0;
      if (*(ushort *)(&byte_tx_time + (uint)*(byte *)(iVar1 + 0x94) * 2) <
          *(ushort *)(&byte_tx_time + param_2 * 2)) {
        (**(code **)(_r_ip_funcs_p + 0x3c4))
                  (param_2,*(undefined4 *)(iVar1 + 100),*(code **)(_r_ip_funcs_p + 0x3c4));
        uVar2 = 0;
      }
    }
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar2;
}

