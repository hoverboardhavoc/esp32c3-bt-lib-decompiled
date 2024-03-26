/*
 * Last changed at upstream commit 0698a0dac04e7762ec555dca86bbfa2a631cefa3
 * https://github.com/espressif/esp32c3-bt-lib/commit/0698a0dac04e7762ec555dca86bbfa2a631cefa3
 * Upstream date: 2024-03-26 14:09:42 +0800
 * Upstream subject: feat(ble/controller): Add coexist schm (bb95ac61)
 * Source: libbtdm_app -> lld_cca.o -> r_lld_cca_send_packet_header
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_cca_send_packet_header(byte *param_1)

{
  (**(code **)(_r_osi_funcs_p + 0xe0))(0x50,*(code **)(_r_osi_funcs_p + 0xe0));
  (**(code **)(_r_ip_funcs_p + 0x978))(1,*(code **)(_r_ip_funcs_p + 0x978));
  *param_1 = *param_1 | 0x10;
  return;
}

