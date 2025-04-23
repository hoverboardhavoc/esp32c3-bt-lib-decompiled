/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> nvds.o -> f_nvds_del
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int f_nvds_del(void)

{
  int iVar1;
  byte bStack_19;
  undefined1 uStack_18;
  byte bStack_17;
  int aiStack_14 [3];
  
  iVar1 = 7;
  if ((sdk_cfg_priv_opts != '\0') && (iVar1 = r_nvds_browse_tag(&uStack_18,aiStack_14), iVar1 == 0))
  {
    if ((bStack_17 & 2) == 0) {
      iVar1 = 5;
    }
    else {
      bStack_19 = bStack_17 & 0xfb;
      (*DAT_0001069c)(aiStack_14[0] + 1,&bStack_19,DAT_0001069c);
    }
  }
  return iVar1;
}

