/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_tx_len_update_for_rate
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_con_tx_len_update_for_rate(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar2 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar2 == 0) {
    uVar1 = 0xc;
    goto _L836;
  }
  if (param_2 == 4) {
    uVar1 = *(undefined4 *)(iVar2 + 100);
    param_2 = (uint)*(byte *)(iVar2 + 0x94);
_L841:
    r_lld_con_tx_len_update(param_2,uVar1);
  }
  else if (*(ushort *)(&byte_tx_time + (uint)*(byte *)(iVar2 + 0x94) * 2) <
           *(ushort *)(&byte_tx_time + param_2 * 2)) {
    uVar1 = *(undefined4 *)(iVar2 + 100);
    goto _L841;
  }
  uVar1 = 0;
_L836:
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar1;
}

