/*
 * Last changed at upstream commit e9ad3d704f1034310de8f747d503ea5443df6b67
 * https://github.com/espressif/esp32c3-bt-lib/commit/e9ad3d704f1034310de8f747d503ea5443df6b67
 * Upstream date: 2023-09-15 17:47:18 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(29996e0)
 * Source: libbtdm_app -> lld.o -> lld_le_pkt_err_en
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_le_pkt_err_en(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  _LANCHOR1 = (undefined1)param_1;
  _DAT_60031000 = (param_1 ^ 1) << 9 | _DAT_60031000 & 0xfffffdff;
  for (uVar1 = 0; iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
      uVar1 < *(byte *)(iVar2 + 0xd); uVar1 = uVar1 + 1 & 0xff) {
    (&lld_le_pkt_env)[uVar1] = 0;
  }
  return 0;
}

