/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  return;
}

