/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
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
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = _lld_scan_env;
  if (_lld_scan_env == 0) {
    uVar4 = 0xc;
  }
  else {
    uVar2 = 0xffffffff;
    if (param_1 != 0) {
      iVar3 = r_lld_read_clock();
      uVar2 = param_1 * 0x20 + iVar3 & 0xfffffff;
    }
    *(uint *)(iVar1 + 8) = uVar2;
    if (param_3 != (void *)0x0) {
      memcpy((void *)(iVar1 + 0xe),param_3,6);
    }
    r_ble_log_internal_x2(0x40010128,uVar2,param_2 << 0x10 | param_1);
    r_lld_scan_restart();
    uVar4 = 0;
  }
  return uVar4;
}

