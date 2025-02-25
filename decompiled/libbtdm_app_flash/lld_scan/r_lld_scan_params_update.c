/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_params_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_scan_params_update(uint param_1,int param_2,void *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = _lld_scan_env;
  if (_lld_scan_env == 0) {
    uVar3 = 0xc;
  }
  else {
    if (param_1 == 0) {
      *(undefined4 *)(_lld_scan_env + 8) = 0xffffffff;
    }
    else {
      iVar2 = r_lld_read_clock();
      *(uint *)(iVar1 + 8) = iVar2 + param_1 * 0x20 & 0xfffffff;
    }
    if (param_3 != (void *)0x0) {
      memcpy((void *)(iVar1 + 0xe),param_3,6);
    }
    iVar2 = r_sdk_config_get_opts_ext();
    if ((*(uint *)(iVar2 + 0x28) & 8) != 0) {
      iVar2 = r_sdk_config_get_opts_ext();
      if (*(byte *)(iVar2 + 0x2c) < 3) {
        r_ble_log_internal_x2(0x40010004,param_2 << 0x10 | param_1,*(undefined4 *)(iVar1 + 8));
      }
    }
    r_lld_scan_restart();
    uVar3 = 0;
  }
  return uVar3;
}

