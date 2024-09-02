/*
 * Last changed at upstream commit d874f55e1132416fe18293ae1aa9ac73c40b3261
 * https://github.com/espressif/esp32c3-bt-lib/commit/d874f55e1132416fe18293ae1aa9ac73c40b3261
 * Upstream date: 2024-09-02 19:56:58 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(8ce789b)
 * Source: libbtdm_app -> ble_util_buf.o -> ble_util_buf_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ble_util_buf_reset(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 0;
  do {
    iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if ((uint)*(byte *)(iVar2 + 0x10) <= (uVar1 & 0xff)) {
      emi_reset_em_mapping_by_offset
                (*(undefined2 *)(_p_ble_util_buf_env + (uVar1 + 0x20) * 8 + 0xc));
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 != 0xc);
  iVar2 = 0;
  do {
    iVar3 = iVar2 + 0x2c;
    iVar2 = iVar2 + 1;
    emi_reset_em_mapping_by_offset(*(undefined2 *)(_p_ble_util_buf_env + iVar3 * 8 + 0xc));
  } while (iVar2 != 10);
  return;
}

