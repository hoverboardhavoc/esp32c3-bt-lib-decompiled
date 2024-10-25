/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_scan.o -> ble_ll_scan_channel_setting
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ble_ll_scan_channel_setting(uint param_1)

{
  int iVar1;
  
  iVar1 = r_ble_ll_qa_config_get();
  if (param_1 != 0) {
    param_1 = (uint)(byte)"TX PTI [ACT_SCAN] [EN%d] [%d] \n"[param_1 + 7];
  }
  *(short *)(iVar1 + 0x18) = (short)param_1;
  return;
}

