/*
 * Last changed at upstream commit a3f7d7ffa2b261b1415042d8b7cd457cc2b4b1de
 * https://github.com/espressif/esp32c3-bt-lib/commit/a3f7d7ffa2b261b1415042d8b7cd457cc2b4b1de
 * Upstream date: 2021-12-28 18:10:18 +0800
 * Upstream subject: Update ESP32-C3 and ESP32-S3 bt lib (33175c8)
 * Source: libbtdm_app -> lld_init.o -> r_lld_init_evt_end_type_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_lld_init_evt_end_type_get(void)

{
  uint uVar1;
  
  uVar1 = (**(code **)(_r_ip_funcs_p + 0x7c4))(*(code **)(_r_ip_funcs_p + 0x7c4));
  if (uVar1 != 0) {
    uVar1 = (uint)g_initor_evt_end_abort;
  }
  return uVar1;
}

