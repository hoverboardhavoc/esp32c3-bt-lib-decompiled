/*
 * Last changed at upstream commit 55485554203a225ff09a8dfcf5284c46b70aa0bd
 * https://github.com/espressif/esp32c3-bt-lib/commit/55485554203a225ff09a8dfcf5284c46b70aa0bd
 * Upstream date: 2024-07-12 15:45:32 +0800
 * Upstream subject: fix(coex): Fixed coexist LoadProhibited issue(e4ba7f6)
 * Source: libbtdm_app -> coex_schm.o -> coex_schm_ble_scan_stop_interval_num_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint coex_schm_ble_scan_stop_interval_num_get(int param_1,uint param_2,int param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = _coex_schm_btdm_env - param_3 & 0xfffffff;
  if (0x8000000 < uVar2) {
    uVar2 = -(param_3 - _coex_schm_btdm_env & 0xfffffffU);
  }
  if ((int)uVar2 < 0) {
    uVar2 = 0;
  }
  uVar1 = (int)uVar2 / (param_1 << 1) & 0xff;
  uVar2 = (int)uVar2 % (param_1 << 1) >> 1;
  if (uVar2 < param_2) {
    *param_4 = uVar2;
    return uVar1;
  }
  *param_4 = 0;
  return uVar1 + 1 & 0xff;
}

