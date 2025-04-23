/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_params_update
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
  uint uVar4;
  
  iVar1 = _lld_scan_env;
  if (_lld_scan_env == 0) {
    uVar3 = 0xc;
  }
  else {
    uVar4 = 0xffffffff;
    if (param_1 != 0) {
      iVar2 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
      uVar4 = param_1 * 0x20 + iVar2 & 0xfffffff;
    }
    *(uint *)(iVar1 + 8) = uVar4;
    if (param_2 != (void *)0x0) {
      memcpy((void *)(iVar1 + 0xe),param_2,6);
    }
    (**(code **)(_r_ip_funcs_p + 0x42c))(*(code **)(_r_ip_funcs_p + 0x42c));
    uVar3 = 0;
  }
  return uVar3;
}

