/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> nvds.o -> f_nvds_del
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int f_nvds_del(void)

{
  int iVar1;
  byte bStack_19;
  undefined1 uStack_18;
  byte bStack_17;
  int aiStack_14 [3];
  
  iVar1 = 7;
  if ((sdk_cfg_priv_opts != '\0') &&
     (iVar1 = (**(code **)(_r_modules_funcs_p + 0x230))
                        (&uStack_18,aiStack_14,*(code **)(_r_modules_funcs_p + 0x230)), iVar1 == 0))
  {
    if ((bStack_17 & 2) == 0) {
      iVar1 = 5;
    }
    else {
      bStack_19 = bStack_17 & 0xfb;
      (*DAT_000106f4)(aiStack_14[0] + 1,1,&bStack_19,DAT_000106f4);
    }
  }
  return iVar1;
}

