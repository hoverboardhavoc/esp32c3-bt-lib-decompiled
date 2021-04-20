/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> nvds.o -> r_nvds_lock
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_nvds_lock(void)

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
    bStack_19 = bStack_17 & 0xfd;
    (*_LANCHOR0)(aiStack_14[0] + 1,1,&bStack_19,_LANCHOR0);
  }
  return iVar1;
}

