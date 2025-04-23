/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> hci_tl.o -> r_hci_acl_tx_data_alloc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_hci_acl_tx_data_alloc(uint param_1,uint param_2)

{
  byte *pbVar1;
  int iVar2;
  undefined1 *puVar3;
  
  pbVar1 = (byte *)(**(code **)(_r_plf_funcs_p + 0x20))(*(code **)(_r_plf_funcs_p + 0x20));
  if (((param_1 & 0xfff) < (uint)*pbVar1) && (param_1 >> 0xe == 0)) {
    iVar2 = 0;
    if ((param_2 < 0xfc) &&
       (iVar2 = (**(code **)(_r_ip_funcs_p + 0xc4))(param_2,*(code **)(_r_ip_funcs_p + 0xc4)),
       iVar2 == 0)) {
      puVar3 = (undefined1 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x1103,0,0x1a,1,*(code **)(_r_modules_funcs_p + 200));
      *puVar3 = 1;
      (**(code **)(_r_ip_funcs_p + 0x8c))(*(code **)(_r_ip_funcs_p + 0x8c));
      hci_tl_env = 1;
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}

