/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> hci_msg.o -> r_hci_pack_bytes
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int r_hci_pack_bytes(int *param_1,int *param_2,uint param_3,uint param_4,size_t param_5)

{
  int iVar1;
  
  iVar1 = 1;
  if (*param_1 + param_5 <= param_3) {
    iVar1 = 0;
    if (param_4 != 0) {
      iVar1 = (uint)(param_4 < *param_2 + param_5) << 1;
      memcpy((void *)*param_2,(void *)*param_1,param_5);
    }
    *param_1 = *param_1 + param_5;
    *param_2 = *param_2 + param_5;
  }
  return iVar1;
}

