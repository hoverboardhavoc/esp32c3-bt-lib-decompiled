/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> nvds.o -> r_nvds_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_nvds_get(byte *param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 auStack_18 [2];
  byte bStack_16;
  int iStack_14;
  
  iVar1 = 7;
  if (sdk_cfg_priv_opts != '\0') {
    iVar1 = (**(code **)(_r_modules_funcs_p + 0x230))
                      (auStack_18,&iStack_14,*(code **)(_r_modules_funcs_p + 0x230));
    if (iVar1 == 0) {
      if (*param_1 < bStack_16) {
        iVar1 = 4;
      }
      else {
        (*_LANCHOR0)(iStack_14 + 3,param_2,_LANCHOR0);
        *param_1 = bStack_16;
      }
    }
    else {
      *param_1 = 0;
    }
  }
  return iVar1;
}

