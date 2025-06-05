/*
 * Last changed at upstream commit 3ff529142f6e2707d57b10eb87ac8d86e9098b88
 * https://github.com/espressif/esp32c3-bt-lib/commit/3ff529142f6e2707d57b10eb87ac8d86e9098b88
 * Upstream date: 2025-06-05 11:04:06 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(4713a69)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_sw_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_cca_sw_free(void)

{
  if (p_lld_cca != 0) {
    if (*(int *)(p_lld_cca + 0x28) != 0) {
      (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
      *(undefined4 *)(p_lld_cca + 0x28) = 0;
    }
    (**(code **)(_r_osi_funcs_p + 0x7c))(p_lld_cca,*(code **)(_r_osi_funcs_p + 0x7c));
    p_lld_cca = 0;
  }
  return;
}

