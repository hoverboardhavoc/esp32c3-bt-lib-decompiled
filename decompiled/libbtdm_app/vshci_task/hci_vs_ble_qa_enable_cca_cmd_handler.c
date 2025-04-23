/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> vshci_task.o -> hci_vs_ble_qa_enable_cca_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
hci_vs_ble_qa_enable_cca_cmd_handler(undefined1 param_1,undefined1 *param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (**(code **)(_r_modules_funcs_p + 200))
                    (0x1101,param_3,0xfd13,2,*(code **)(_r_modules_funcs_p + 200));
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  bVar1 = *(char *)(iVar3 + 0x19) != '\x01';
  if (!bVar1) {
    bt_bb_tx_cca_set(*param_2,0x100 - (((int)(char)param_2[1] >> 7 ^ (uint)(byte)param_2[1]) -
                                       ((int)(char)param_2[1] >> 7) & 0xff),0,0,0,0,0,0);
  }
  *(bool *)iVar2 = bVar1;
  *(undefined1 *)(iVar2 + 1) = param_1;
  (**(code **)(_r_ip_funcs_p + 0x8c))(iVar2,*(code **)(_r_ip_funcs_p + 0x8c));
  return 0;
}

