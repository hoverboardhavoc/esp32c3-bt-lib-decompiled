/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app -> arch_main.o -> r_rwip_eif_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * r_rwip_eif_get(int param_1)

{
  if (param_1 == 0) {
    _g_eif_api = *(undefined4 *)(_r_h4tl_eif_p + 0x18);
    _DAT_00013264 = *(undefined4 *)(_r_h4tl_eif_p + 0x1c);
    _DAT_0001326c = *(undefined4 *)(_r_h4tl_eif_p + 0x20);
    _DAT_00013268 = *(undefined4 *)(_r_h4tl_eif_p + 0x24);
    return &g_eif_api;
  }
  (**(code **)(_r_plf_funcs_p + 0xc))(0,"arch_main.c",0x8ab,*(code **)(_r_plf_funcs_p + 0xc));
  return (undefined *)0x0;
}

