/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc.o -> r_llc_proc_collision_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_llc_proc_collision_check(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = r_llc_proc_id_get(0);
  uVar2 = 0x23;
  if (((uVar1 != param_1) && (uVar2 = 0, uVar1 < 10)) && ((1 << (uVar1 & 0x1f) & 0x260U) != 0)) {
    uVar2 = 0x2a;
  }
  return uVar2;
}

