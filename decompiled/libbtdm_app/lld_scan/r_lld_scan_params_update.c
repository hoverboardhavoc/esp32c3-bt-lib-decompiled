/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  
  iVar1 = _lld_scan_env;
  if (_lld_scan_env == 0) {
    uVar3 = 0xc;
  }
  else {
    if (param_1 == 0) {
      *(undefined4 *)(_lld_scan_env + 8) = 0xffffffff;
    }
    else {
      iVar2 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
      *(uint *)(iVar1 + 8) = param_1 * 0x20 + iVar2 & 0xfffffff;
    }
    if (param_2 != (void *)0x0) {
      memcpy((void *)(iVar1 + 0xe),param_2,6);
    }
    (**(code **)(_r_ip_funcs_p + 0x42c))(*(code **)(_r_ip_funcs_p + 0x42c));
    uVar3 = 0;
  }
  return uVar3;
}

