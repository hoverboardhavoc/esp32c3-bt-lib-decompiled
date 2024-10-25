/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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

