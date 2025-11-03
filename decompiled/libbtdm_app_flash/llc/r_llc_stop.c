/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llc.o -> r_llc_stop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_stop(int param_1)

{
  uint uVar1;
  
  uVar1 = param_1 << 8 | 1;
  if (*(int *)(&llc_env + param_1 * 4) != 0) {
    r_llc_llcp_state_set(2,3);
  }
  r_ke_state_set(uVar1,0xff);
  r_ke_msg_send_basic(0x104,uVar1,uVar1);
  r_ble_log_internal_x1(0x400f0012,param_1);
  return;
}

