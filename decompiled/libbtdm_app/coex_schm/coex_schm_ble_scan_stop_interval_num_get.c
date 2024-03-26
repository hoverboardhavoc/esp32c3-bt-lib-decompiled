/*
 * Last changed at upstream commit 0698a0dac04e7762ec555dca86bbfa2a631cefa3
 * https://github.com/espressif/esp32c3-bt-lib/commit/0698a0dac04e7762ec555dca86bbfa2a631cefa3
 * Upstream date: 2024-03-26 14:09:42 +0800
 * Upstream subject: feat(ble/controller): Add coexist schm (bb95ac61)
 * Source: libbtdm_app -> coex_schm.o -> coex_schm_ble_scan_stop_interval_num_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint coex_schm_ble_scan_stop_interval_num_get(int param_1,uint param_2,int param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = coex_schm_btdm_env - param_3 & 0xfffffff;
  if (0x8000000 < uVar2) {
    uVar2 = -(param_3 - coex_schm_btdm_env & 0xfffffffU);
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

