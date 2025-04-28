/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> nvds.o -> r_nvds_lock
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int r_nvds_lock(void)

{
  int iVar1;
  byte bStack_19;
  undefined1 uStack_18;
  byte bStack_17;
  int aiStack_14 [3];
  
  iVar1 = 7;
  if ((sdk_cfg_priv_opts != '\0') && (iVar1 = r_nvds_browse_tag(&uStack_18,aiStack_14), iVar1 == 0))
  {
    bStack_19 = bStack_17 & 0xfd;
    (*DAT_00010694)(aiStack_14[0] + 1,1,&bStack_19,DAT_00010694);
  }
  return iVar1;
}

