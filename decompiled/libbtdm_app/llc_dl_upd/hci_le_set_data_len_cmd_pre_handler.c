/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_dl_upd.o -> hci_le_set_data_len_cmd_pre_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte hci_le_set_data_len_cmd_pre_handler(uint param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(&llc_env + param_1 * 4);
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  bVar1 = 0;
  if (param_1 < *(byte *)(iVar2 + 0xd)) {
    iVar2 = *(int *)(&llc_env + param_1 * 4);
    bVar1 = 0;
    if ((iVar2 != 0) && ((*(byte *)(iVar2 + 0x44) & 3) != 3)) {
      bVar1 = *(byte *)(iVar3 + 0x45) >> 4 & 2;
    }
  }
  return bVar1;
}

