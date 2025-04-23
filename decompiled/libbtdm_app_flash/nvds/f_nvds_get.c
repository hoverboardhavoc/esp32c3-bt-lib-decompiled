/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> nvds.o -> f_nvds_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int f_nvds_get(byte *param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 auStack_18 [2];
  byte bStack_16;
  int iStack_14;
  
  iVar1 = 7;
  if (sdk_cfg_priv_opts != '\0') {
    iVar1 = r_nvds_browse_tag(auStack_18,&iStack_14);
    if (iVar1 == 0) {
      if (*param_1 < bStack_16) {
        iVar1 = 4;
      }
      else {
        (*nvds_env)(iStack_14 + 3,param_2,nvds_env);
        *param_1 = bStack_16;
      }
    }
    else {
      *param_1 = 0;
    }
  }
  return iVar1;
}

