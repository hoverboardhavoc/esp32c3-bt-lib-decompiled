/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld.o -> lld_le_pkt_err_en
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
  
  lld_pkt_record_en = (undefined1)param_1;
  _DAT_60031000 = (param_1 ^ 1) << 9 | _DAT_60031000 & 0xfffffdff;
  for (uVar1 = 0; iVar2 = r_sdk_config_get_opts(), uVar1 < *(byte *)(iVar2 + 0xd);
      uVar1 = uVar1 + 1 & 0xff) {
    (&lld_le_pkt_env)[uVar1] = 0;
  }
  return 0;
}

