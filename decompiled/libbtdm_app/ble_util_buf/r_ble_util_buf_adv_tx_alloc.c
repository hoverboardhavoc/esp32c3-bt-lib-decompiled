/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> ble_util_buf.o -> r_ble_util_buf_adv_tx_alloc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 r_ble_util_buf_adv_tx_alloc(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 < 0x675) {
    (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
    iVar1 = (**(code **)(_r_modules_funcs_p + 0x40))
                      (_p_ble_util_buf_env + 0x18,*(code **)(_r_modules_funcs_p + 0x40));
    (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
    if (iVar1 != 0) {
      iVar2 = (**(code **)(_r_plf_funcs_p + 0x9c))
                        (*(undefined2 *)(iVar1 + 4),param_1,*(code **)(_r_plf_funcs_p + 0x9c));
      if (iVar2 == 0) {
        return *(undefined2 *)(iVar1 + 4);
      }
      (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
      (**(code **)(_r_modules_funcs_p + 0x44))
                (_p_ble_util_buf_env + 0x18,iVar1,*(code **)(_r_modules_funcs_p + 0x44));
      (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
    }
  }
  return 0;
}

