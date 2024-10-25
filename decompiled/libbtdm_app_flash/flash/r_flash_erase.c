/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> flash.o -> r_flash_erase
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_flash_erase(uint param_1,int param_2,size_t param_3)

{
  undefined4 uVar1;
  
  if (sdk_cfg_priv_opts == '\0') {
    uVar1 = 0x1f;
  }
  else {
    uVar1 = 0x12;
    if ((DAT_00010218 == param_1) && (param_2 + param_3 < DAT_00010214)) {
      memset((void *)(param_2 + _LANCHOR0),0xff,param_3);
      return 0;
    }
  }
  return uVar1;
}

