/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> ble_util_buf.o -> r_ble_util_buf_acl_tx_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ble_util_buf_acl_tx_free(int param_1)

{
  uint uVar1;
  code *pcVar2;
  uint uVar3;
  
  uVar1 = param_1 - 0x9c00U >> 10;
  uVar3 = uVar1 & 0xff;
  uVar1 = uVar1 & 0xff;
  if (0xb < uVar3) {
    (**(code **)(_r_plf_funcs_p + 0xc))
              (uVar1,param_1,"ble_util_buf.c",0x18d,*(code **)(_r_plf_funcs_p + 0xc));
  }
  if (uVar3 < *(byte *)(_p_ble_util_buf_env + 0x1bb)) {
    (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
    pcVar2 = *(code **)(_r_modules_funcs_p + 0x4c);
  }
  else {
    (**(code **)(_r_plf_funcs_p + 0xb4))(param_1,*(code **)(_r_plf_funcs_p + 0xb4));
    (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
    pcVar2 = *(code **)(_r_modules_funcs_p + 0x44);
  }
  (*pcVar2)(_p_ble_util_buf_env + 0x10,_p_ble_util_buf_env + (uVar1 + 0x21) * 8,pcVar2);
                    /* WARNING: Could not recover jumptable at 0x000107e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return;
}

