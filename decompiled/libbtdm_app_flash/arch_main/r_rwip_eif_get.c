/*
 * Last changed at upstream commit 7e73ebf92e5aa995065351043c13d2ac0f00772e
 * https://github.com/espressif/esp32c3-bt-lib/commit/7e73ebf92e5aa995065351043c13d2ac0f00772e
 * Upstream date: 2026-05-19 17:43:45 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(bc853c5)
 * Source: libbtdm_app_flash -> arch_main.o -> r_rwip_eif_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * r_rwip_eif_get(int param_1)

{
  if (param_1 != 0) {
    r_assert_param(0,"arch_main.c",0x8d0);
  }
  _g_eif_api = *(undefined4 *)(_r_h4tl_eif_p + 0x18);
  _DAT_000131b4 = *(undefined4 *)(_r_h4tl_eif_p + 0x1c);
  _DAT_000131bc = *(undefined4 *)(_r_h4tl_eif_p + 0x20);
  _DAT_000131b8 = *(undefined4 *)(_r_h4tl_eif_p + 0x24);
  return &g_eif_api;
}

