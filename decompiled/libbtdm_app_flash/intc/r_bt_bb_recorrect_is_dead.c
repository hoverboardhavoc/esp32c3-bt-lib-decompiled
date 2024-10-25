/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> intc.o -> r_bt_bb_recorrect_is_dead
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_bt_bb_recorrect_is_dead(void)

{
  char cVar1;
  
  cVar1 = '\x03';
  do {
    if (2 < (_DAT_6001186c >> 0x10 & 0xf) - 6) {
      return 0;
    }
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  return 1;
}

