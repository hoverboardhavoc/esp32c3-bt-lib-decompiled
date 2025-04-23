/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> hci.o -> r_hci_evt_mask_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_hci_evt_mask_set(void *param_1,uint param_2)

{
  byte *pbVar1;
  int iVar2;
  byte *pbVar3;
  
  if (param_2 == 3) {
    memcpy(&hci_env,param_1,8);
    iVar2 = 0;
    pbVar3 = &hci_env;
    do {
      pbVar1 = &hci_rsvd_evt_msk + iVar2;
      iVar2 = iVar2 + 1;
      *pbVar3 = *pbVar1 | *pbVar3;
      pbVar3 = pbVar3 + 1;
    } while (iVar2 != 8);
  }
  else {
    if (param_2 < 4) {
      if (param_2 != 2) {
        (**(code **)(_r_plf_funcs_p + 0xc))(param_2,"hci.c",0x51c,*(code **)(_r_plf_funcs_p + 0xc));
        return 0;
      }
    }
    else if (param_2 != 4) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"hci.c",0x537,*(code **)(_r_plf_funcs_p + 8));
      return 0;
    }
    memcpy(&hci_env,param_1,8);
  }
  return 0;
}

