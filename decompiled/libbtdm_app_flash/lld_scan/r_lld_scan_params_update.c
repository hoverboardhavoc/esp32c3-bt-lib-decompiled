/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_params_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_scan_params_update(int param_1,void *param_2)

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
      *(uint *)(iVar1 + 8) = param_1 * 0x20 + iVar2 & 0xfffffff;
    }
    if (param_2 != (void *)0x0) {
      memcpy((void *)(iVar1 + 0xe),param_2,6);
    }
    r_lld_scan_restart();
    uVar3 = 0;
  }
  return uVar3;
}

