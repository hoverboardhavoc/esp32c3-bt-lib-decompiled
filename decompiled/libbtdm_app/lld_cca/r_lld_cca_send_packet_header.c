/*
 * Last changed at upstream commit ebd6043a8e3c3bbde45ee483895303b9c1229ab5
 * https://github.com/espressif/esp32c3-bt-lib/commit/ebd6043a8e3c3bbde45ee483895303b9c1229ab5
 * Upstream date: 2026-02-06 15:59:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(b7de11e)
 * Source: libbtdm_app -> lld_cca.o -> r_lld_cca_send_packet_header
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_cca_send_packet_header(byte *param_1)

{
  (**(code **)(_r_osi_funcs_p + 0xe4))(0x50,*(code **)(_r_osi_funcs_p + 0xe4));
  (**(code **)(_r_ip_funcs_p + 0x978))(1,*(code **)(_r_ip_funcs_p + 0x978));
  *param_1 = *param_1 | 0x10;
  return;
}

