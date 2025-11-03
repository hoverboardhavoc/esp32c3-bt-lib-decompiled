/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> hci.o -> r_hci_evt_mask_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

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
        r_assert_param(param_2,"hci.c",0x525);
        return 0;
      }
    }
    else if (param_2 != 4) {
      r_assert_err(0,"hci.c",0x540);
      return 0;
    }
    memcpy(&hci_env,param_1,8);
  }
  return 0;
}

